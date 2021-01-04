#include "SKSE/IAT.h"

#include "SKSE/Logger.h"

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
//#define NOUSER
#define NONLS
//#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
//#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <Windows.h>

namespace SKSE
{
	std::uintptr_t GetIATAddr(std::string_view a_dll, std::string_view a_function)
	{
		return reinterpret_cast<std::uintptr_t>(GetIATPtr(std::move(a_dll), std::move(a_function)));
	}

	std::uintptr_t GetIATAddr(void* a_module, std::string_view a_dll, std::string_view a_function)
	{
		return reinterpret_cast<std::uintptr_t>(GetIATPtr(a_module, std::move(a_dll), std::move(a_function)));
	}

	void* GetIATPtr(std::string_view a_dll, std::string_view a_function)
	{
		return GetIATPtr(REL::Module::get().pointer(), std::move(a_dll), std::move(a_function));
	}

	// https://guidedhacking.com/attachments/pe_imptbl_headers-jpg.2241/
	void* GetIATPtr(void* a_module, std::string_view a_dll, std::string_view a_function)
	{
		assert(a_module);
		auto dosHeader = static_cast<::IMAGE_DOS_HEADER*>(a_module);
		if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
			log::error("Invalid DOS header");
			return nullptr;
		}

		auto  ntHeader = adjust_pointer<::IMAGE_NT_HEADERS>(dosHeader, dosHeader->e_lfanew);
		auto& dataDir = ntHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
		auto  importDesc = adjust_pointer<::IMAGE_IMPORT_DESCRIPTOR>(dosHeader, dataDir.VirtualAddress);

		for (auto import = importDesc; import->Characteristics != 0; ++import) {
			auto name = adjust_pointer<const char>(dosHeader, import->Name);
			if (_stricmp(a_dll.data(), name) != 0) {
				continue;
			}

			auto thunk = adjust_pointer<::IMAGE_THUNK_DATA>(dosHeader, import->OriginalFirstThunk);
			for (std::size_t i = 0; thunk[i].u1.Ordinal; ++i) {
				if (IMAGE_SNAP_BY_ORDINAL(thunk[i].u1.Ordinal)) {
					continue;
				}

				auto importByName = adjust_pointer<IMAGE_IMPORT_BY_NAME>(dosHeader, thunk[i].u1.AddressOfData);
				if (_stricmp(a_function.data(), importByName->Name) == 0) {
					return adjust_pointer<::IMAGE_THUNK_DATA>(dosHeader, import->FirstThunk) + i;
				}
			}
		}

		log::warn("Failed to find {} ({})", a_dll, a_function);
		return nullptr;
	}

	std::uintptr_t PatchIAT(std::uintptr_t a_newFunc, std::string_view a_dll, std::string_view a_function)
	{
		std::uintptr_t origAddr = 0;

		auto oldFunc = GetIATAddr(a_dll, a_function);
		if (oldFunc) {
			origAddr = *reinterpret_cast<std::uintptr_t*>(oldFunc);
			REL::safe_write(oldFunc, a_newFunc);
		} else {
			log::warn("Failed to patch {} ({})", a_dll, a_function);
		}

		return origAddr;
	}
}
