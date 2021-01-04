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

			SKSE::log::debug("0x{:08X}: {}", a_obj, name);
		}
	}
}
