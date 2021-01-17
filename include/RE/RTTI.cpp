#include "RE/RTTI.h"

#include "SKSE/Logger.h"

#ifndef NDEBUG
#	define NOGDICAPMASKS
#	define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#	define NOWINSTYLES
#	define NOSYSMETRICS
#	define NOMENUS
#	define NOICONS
#	define NOKEYSTATES
#	define NOSYSCOMMANDS
#	define NORASTEROPS
#	define NOSHOWWINDOW
#	define OEMRESOURCE
#	define NOATOM
#	define NOCLIPBOARD
#	define NOCOLOR
//#define NOCTLMGR
#	define NODRAWTEXT
#	define NOGDI
#	define NOKERNEL
//#define NOUSER
#	define NONLS
//#define NOMB
#	define NOMEMMGR
#	define NOMETAFILE
#	define NOMINMAX
//#define NOMSG
#	define NOOPENFILE
#	define NOSCROLL
#	define NOSERVICE
#	define NOSOUND
#	define NOTEXTMETRIC
#	define NOWH
#	define NOWINOFFSETS
#	define NOCOMM
#	define NOKANJI
#	define NOHELP
#	define NOPROFILER
#	define NODEFERWINDOWPOS
#	define NOMCX

#	include <Windows.h>

#	include <DbgHelp.h>
#endif

namespace RE
{
	namespace RTTI
	{
		void DumpTypeName(void* a_obj)
		{
			assert(a_obj);
			auto vtbl = *static_cast<std::uintptr_t**>(a_obj) - 1;
			auto col = *reinterpret_cast<CompleteObjectLocator**>(vtbl);
			assert(col);
#ifdef _DEBUG
			char buf[0x1000];
			UnDecorateSymbolName(col->typeDescriptor->name + 1, buf, sizeof(buf), UNDNAME_NO_ARGUMENTS);
			auto name = buf;
#else
			auto name = col->typeDescriptor->name;
#endif
			spdlog::info("0x{:08X}: {}", a_obj, name);
		}


		void DumpClassHier(void* a_obj) {
			uintptr_t* vtbl = *static_cast<std::uintptr_t**>(a_obj) - 1;
			auto col = *reinterpret_cast<RTTI::CompleteObjectLocator**>(vtbl);
			SKSE::log::debug("0x{:08X}", a_obj);
			RTTI::BaseClassArray baseClassArray = (col->classDescriptor->baseClassArray);
			for (uint32_t i = 0; i < col->classDescriptor->numBaseClasses; i++) {
				RTTI::BaseClassDescriptor* baseClassDesc = baseClassArray[i];
				RTTI::RVA<RTTI::TypeDescriptor> testTypeDesc = baseClassDesc->typeDescriptor;
#ifdef _DEBUG
				static char buf[0x100];
				UnDecorateSymbolName(testTypeDesc->name + 1, buf, sizeof(buf), UNDNAME_NO_ARGUMENTS);
				auto name = buf;
#else
				auto name = testTypeDesc->name;
#endif
				SKSE::log::debug("base class member offset {0:x}, type: {1:s}", baseClassDesc->pmd.mDisp, name);
			}

		}

	}
}
