#pragma once

#include "skse64_common/Relocation.h"

#include "RE/Offsets.h"


template <class Ty>
class CRC32Calculator
{
public:
	inline CRC32Calculator() {}
	inline CRC32Calculator(const Ty& a_val)
	{
		operator=(a_val);
	}

	inline operator UInt32()
	{
		return m_checksum;
	}

protected:
	template <std::size_t SIZE = sizeof(Ty)>
	inline CRC32Calculator& operator=(const Ty& a_val)
	{
		typedef void(*Fn)(UInt32*, const void*, UInt32);
		RelocAddr<Fn> fn(CALCULATE_CRC32_SIZE);

		fn(&m_checksum, &a_val, SIZE);
		return *this;
	}

	template <>
	inline CRC32Calculator & operator=<4>(const Ty& a_val)
	{
		typedef void(*Fn)(UInt32*, Ty);
		RelocAddr<Fn> fn(CALCULATE_CRC32_32);

		fn(&m_checksum, a_val);
		return *this;
	}

	template <>
	inline CRC32Calculator & operator=<8>(const Ty& a_val)
	{
		typedef void(*Fn)(UInt32*, Ty);
		RelocAddr<Fn> fn(CALCULATE_CRC32_64);

		fn(&m_checksum, a_val);
		return *this;
	}

	UInt32	m_checksum;
};

template <class Ty>
inline UInt32 CalcCRC32(const Ty& a_val)
{
	CRC32Calculator<Ty> crc(a_val);
	return crc;
}
