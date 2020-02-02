#include "RE/CRC.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace Impl
	{
		void CalcCRC32_32(UInt32& a_crc32, UInt32 a_data)
		{
			using func_t = decltype(&CalcCRC32_32);
			REL::Offset<func_t> func(Offset::CRC32Calculator::SizeOf32);
			func(a_crc32, a_data);
		}


		void CalcCRC32_64(UInt32& a_crc32, UInt64 a_data)
		{
			using func_t = decltype(&CalcCRC32_64);
			REL::Offset<func_t> func(Offset::CRC32Calculator::SizeOf64);
			func(a_crc32, a_data);
		}


		void CalcCRC32_SIZE(UInt32& a_crc32, const void* a_data, UInt32 a_size)
		{
			using func_t = decltype(&CalcCRC32_SIZE);
			REL::Offset<func_t> func(Offset::CRC32Calculator::SizeOfSize);
			func(a_crc32, a_data, a_size);
		}
	}
}
