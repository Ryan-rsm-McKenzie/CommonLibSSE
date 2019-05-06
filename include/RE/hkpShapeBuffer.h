#pragma once


namespace RE
{
	struct alignas(0x10) hkpShapeBuffer
	{
		constexpr char& operator[](std::size_t a_idx) { return buf[a_idx]; }

		char buf[512];
	};
}
