#pragma once

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	template <class T>
	class CRC32Calculator
	{
	public:
		inline CRC32Calculator()
		{}


		inline CRC32Calculator(const T& a_val)
		{
			operator=(a_val);
		}


		inline operator UInt32()
		{
			return _checksum;
		}

	protected:
		template <std::size_t SIZE = sizeof(T)>
		inline CRC32Calculator& operator=(const T& a_val)
		{
			using func_t = void(UInt32&, const void*, UInt32);
			REL::Offset<func_t*> func(Offset::CRC32Calculator::SizeOfSize);

			func(_checksum, &a_val, SIZE);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<4>(const T& a_val)
		{
			using func_t = void(UInt32&, T);
			REL::Offset<func_t*> func(Offset::CRC32Calculator::SizeOf32);

			func(_checksum, a_val);
			return *this;
		}


		template <>
		inline CRC32Calculator& operator=<8>(const T& a_val)
		{
			using func_t = void(UInt32&, T);
			REL::Offset<func_t*> func(Offset::CRC32Calculator::SizeOf64);

			func(_checksum, a_val);
			return *this;
		}


		UInt32	_checksum;
	};


	// String hash calculator got inlined
	class CRC32StringCalculator
	{
	public:
		inline CRC32StringCalculator()
		{}


		inline CRC32StringCalculator(const void* a_str)
		{
			operator=(a_str);
		}


		inline operator UInt32()
		{
			return _checksum;
		}

	protected:
		inline CRC32StringCalculator& operator=(const void* a_str)
		{
			CRC32Calculator<std::uint64_t> checksum(reinterpret_cast<std::uint64_t>(a_str));
			_checksum = checksum;
			return *this;
		}

		UInt32	_checksum;
	};


	template <class T>
	inline UInt32 CalcCRC32(const T& a_val)
	{
		CRC32Calculator<T> crc(a_val);
		return crc;
	}


	template <class T>
	inline UInt32 CalcCRC32String(const T& a_val)
	{
		CRC32StringCalculator crc(a_val);
		return crc;
	}
}
