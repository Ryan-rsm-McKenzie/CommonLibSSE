#include "SKSE/SafeWrite.h"

#include <cassert>
#include <cstring>
#include <memory>


namespace SKSE
{
	bool SafeWriteBuf(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		DWORD old;
		auto success = VirtualProtect(reinterpret_cast<LPVOID>(a_dst), a_count, PAGE_EXECUTE_READWRITE, std::addressof(old));
		assert(success);

		std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);

		success = VirtualProtect(reinterpret_cast<LPVOID>(a_dst), a_count, old, std::addressof(old));
		assert(success);

		return static_cast<bool>(success);
	}


	bool SafeWrite8(std::uintptr_t a_dst, UInt8 a_data)
	{
		return SafeWriteBuf(a_dst, std::addressof(a_data), sizeof(a_data));
	}


	bool SafeWrite16(std::uintptr_t a_dst, UInt16 a_data)
	{
		return SafeWriteBuf(a_dst, std::addressof(a_data), sizeof(a_data));
	}


	bool SafeWrite32(std::uintptr_t a_dst, UInt32 a_data)
	{
		return SafeWriteBuf(a_dst, std::addressof(a_data), sizeof(a_data));
	}


	bool SafeWrite64(std::uintptr_t a_dst, UInt64 a_data)
	{
		return SafeWriteBuf(a_dst, std::addressof(a_data), sizeof(a_data));
	}
}
