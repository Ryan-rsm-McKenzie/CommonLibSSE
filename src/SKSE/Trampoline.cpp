#include "SKSE/Trampoline.h"

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

#ifdef SKSE_SUPPORT_XBYAK
#	include <xbyak/xbyak.h>
#endif

namespace SKSE
{
#ifdef SKSE_SUPPORT_XBYAK
	void* Trampoline::allocate(Xbyak::CodeGenerator& a_code)
	{
		auto result = do_allocate(a_code.getSize());
		log_stats();
		std::memcpy(result, a_code.getCode(), a_code.getSize());
		return result;
	}
#endif

	// https://stackoverflow.com/a/54732489
	void* Trampoline::do_create(std::size_t a_size, std::uintptr_t a_address)
	{
		constexpr std::size_t    gigabyte = static_cast<std::size_t>(1) << 30;
		constexpr std::size_t    minRange = gigabyte * 2;
		constexpr std::uintptr_t maxAddr = std::numeric_limits<std::uintptr_t>::max();

		::DWORD       granularity;
		::SYSTEM_INFO si;
		::GetSystemInfo(&si);
		granularity = si.dwAllocationGranularity;

		std::uintptr_t       min = a_address >= minRange ? detail::roundup(a_address - minRange, granularity) : 0;
		const std::uintptr_t max = a_address < (maxAddr - minRange) ? detail::rounddown(a_address + minRange, granularity) : maxAddr;
		std::uintptr_t       addr;

		::MEMORY_BASIC_INFORMATION mbi;
		do {
			if (!::VirtualQuery(reinterpret_cast<void*>(min), std::addressof(mbi), sizeof(mbi))) {
				log::error("VirtualQuery failed with code: 0x{:08X}"sv, ::GetLastError());
				return nullptr;
			}

			auto baseAddr = reinterpret_cast<std::uintptr_t>(mbi.BaseAddress);
			min = baseAddr + mbi.RegionSize;

			if (mbi.State == MEM_FREE) {
				addr = detail::roundup(baseAddr, granularity);

				// if rounding didn't advance us into the next region and the region is the required size
				if (addr < min && (min - addr) >= a_size) {
					auto mem = ::VirtualAlloc(reinterpret_cast<void*>(addr), a_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
					if (mem) {
						return mem;
					} else {
						log::warn("VirtualAlloc failed with code: 0x{:08X}"sv, ::GetLastError());
					}
				}
			}
		} while (min < max);

		return nullptr;
	}

	void Trampoline::log_stats() const
	{
		auto pct = (static_cast<double>(_size) /
					   static_cast<double>(_capacity)) *
		           100.0;
		log::debug("{} => {}B / {}B ({:05.2f}%)"sv, _name, _size, _capacity, pct);
	}
}
