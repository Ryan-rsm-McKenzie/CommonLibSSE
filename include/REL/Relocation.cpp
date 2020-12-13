#include "REL/Relocation.h"

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

namespace REL
{
	namespace detail
	{
		bool memory_map::open(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			::ULARGE_INTEGER bytes;
			bytes.QuadPart = a_size;

			_mapping = ::OpenFileMappingW(
				FILE_MAP_READ | FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				close();
				return false;
			}

			_view = ::MapViewOfFile(
				_mapping,
				FILE_MAP_READ | FILE_MAP_WRITE,
				0,
				0,
				bytes.QuadPart);
			if (!_view) {
				close();
				return false;
			}

			return true;
		}

		bool memory_map::create(stl::zwstring a_name, std::size_t a_size)
		{
			close();

			::ULARGE_INTEGER bytes;
			bytes.QuadPart = a_size;

			_mapping = ::OpenFileMappingW(
				FILE_MAP_READ | FILE_MAP_WRITE,
				false,
				a_name.data());
			if (!_mapping) {
				_mapping = ::CreateFileMappingW(
					INVALID_HANDLE_VALUE,
					nullptr,
					PAGE_READWRITE,
					bytes.HighPart,
					bytes.LowPart,
					a_name.data());
				if (!_mapping) {
					return false;
				}
			}

			_view = ::MapViewOfFile(
				_mapping,
				FILE_MAP_READ | FILE_MAP_WRITE,
				0,
				0,
				bytes.QuadPart);
			if (!_view) {
				return false;
			}

			return true;
		}

		void memory_map::close()
		{
			if (_view) {
				::UnmapViewOfFile(static_cast<const void*>(_view));
				_view = nullptr;
			}

			if (_mapping) {
				::CloseHandle(_mapping);
				_mapping = nullptr;
			}
		}
	}

	void Module::load_segments()
	{
		auto		dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(_base);
		auto		ntHeader = adjust_pointer<IMAGE_NT_HEADERS64>(dosHeader, dosHeader->e_lfanew);
		const auto* sections = IMAGE_FIRST_SECTION(ntHeader);
		const auto	size = std::min<std::size_t>(ntHeader->FileHeader.NumberOfSections, _segments.size());
		for (std::size_t i = 0; i < size; ++i) {
			const auto& section = sections[i];
			const auto	it = std::find_if(
				 SEGMENTS.begin(),
				 SEGMENTS.end(),
				 [&](auto&& a_elem) {
					 constexpr auto size = std::extent_v<decltype(section.Name)>;
					 const auto		len = std::min(a_elem.first.size(), size);
					 return std::memcmp(a_elem.first.data(), section.Name, len) == 0 &&
							(section.Characteristics & a_elem.second) == a_elem.second;
				 });
			if (it != SEGMENTS.end()) {
				const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
				_segments[idx] = Segment{ _base, _base + section.VirtualAddress, section.Misc.VirtualSize };
			}
		}
	}
}
