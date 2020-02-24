#pragma once


namespace SKSE
{
	bool SafeWriteBuf(std::uintptr_t a_dst, const void* a_src, std::size_t a_count);
	bool SafeWrite8(std::uintptr_t a_dst, UInt8 a_data);
	bool SafeWrite16(std::uintptr_t a_dst, UInt16 a_data);
	bool SafeWrite32(std::uintptr_t a_dst, UInt32 a_data);
	bool SafeWrite64(std::uintptr_t a_dst, UInt64 a_data);
}
