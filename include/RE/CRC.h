#pragma once

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	template <class Ty>
	class CRC32Calculator
	{
	public:
		inline CRC32Calculator()
		{}


		inline CRC32Calculator(const Ty& a_val)
		{
			operator=(a_val);
		}


		inline operator UInt32()
		{
			return _checksum;
		}

	protected:
		template <std::size_t SIZE = sizeof(Ty)>
		inline CRC32Calculator& operator=(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, const void*, UInt32);
			RelocAddr<Fn> fn(CALCULATE_CRC32_SIZE);

			fn(&_checksum, &a_val, SIZE);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<4>(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, Ty);
			RelocAddr<Fn> fn(CALCULATE_CRC32_32);

			fn(&_checksum, a_val);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<8>(const Ty& a_val)
		{
			typedef void(*Fn)(UInt32*, Ty);
			RelocAddr<Fn> fn(CALCULATE_CRC32_64);

			fn(&_checksum, a_val);
			return *this;
		}


		UInt32	_checksum;
	};


	template <class Ty>
	inline UInt32 CalcCRC32(const Ty& a_val)
	{
		CRC32Calculator<Ty> crc(a_val);
		return crc;
	}
}
