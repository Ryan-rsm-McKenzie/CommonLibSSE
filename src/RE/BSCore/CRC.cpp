#include "RE/BSCore/CRC.h"


namespace RE
{
	namespace Impl
	{
		void CalcCRC32_32(std::uint32_t& a_crc32, std::uint32_t a_data)
		{
			using func_t = decltype(&CalcCRC32_32);
			REL::Relocation<func_t> func{ Offset::CRC32Calculator::SizeOf32 };
			func(a_crc32, a_data);
		}


		void CalcCRC32_64(std::uint32_t& a_crc32, std::uint64_t a_data)
		{
			using func_t = decltype(&CalcCRC32_64);
			REL::Relocation<func_t> func{ Offset::CRC32Calculator::SizeOf64 };
			func(a_crc32, a_data);
		}


		void CalcCRC32_SIZE(std::uint32_t& a_crc32, const void* a_data, std::uint32_t a_size)
		{
			using func_t = decltype(&CalcCRC32_SIZE);
			REL::Relocation<func_t> func{ Offset::CRC32Calculator::SizeOfSize };
			func(a_crc32, a_data, a_size);
		}
	}
}
