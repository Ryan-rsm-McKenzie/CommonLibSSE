#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiBinaryStream

#include <locale>  // use_facet, ctype
#include <string>  // basic_string, char_traits


namespace RE
{
	class NiBinaryStream
	{
	public:
		inline static const void* RTTI = RTTI_NiBinaryStream;


		using int_type = SInt32;
		using pos_type = UInt32;
		using off_type = SInt32;


		NiBinaryStream();
		virtual ~NiBinaryStream();							// 00

		// add
		virtual	bool	is_open() const = 0;				// 01
		virtual void	seek(SInt32 a_numBytes) = 0;		// 02
		virtual UInt32	tell() const;						// 03 - { return _absoluteCurrentPos; }
		virtual void	copy_from(void* a_rhs);				// 04
		virtual void	set_endian_swap(bool a_doSwap) = 0;	// 05

		template <class CharT> bool get(CharT& a_ch);
		template <class CharT> bool read(CharT* a_str, UInt32 a_count);
		template <class CharT> bool put(CharT a_ch);
		template <class CharT> bool write(const CharT* a_str, UInt32 a_count);

	protected:
		using ReadFn = UInt32(NiBinaryStream* a_this, void* a_buffer, UInt32 a_bytes, UInt32* a_componentSizes, UInt32 a_numComponents);
		using WriteFn = UInt32(NiBinaryStream* a_this, const void* a_buffer, UInt32 a_bytes, UInt32* a_componentSizes, UInt32 a_numComponents);


		UInt32 binary_read(void* a_buffer, UInt32 a_totalBytes, UInt32* a_componentSizes, UInt32 a_numComponents = 1);
		UInt32 binary_write(const void* a_buffer, UInt32 a_totalBytes, UInt32* a_componentSizes, UInt32 a_numComponents = 1);


		// members
		UInt32		_absoluteCurrentPos;	// 08
		UInt32		_pad0C;					// 0C
		ReadFn*		_readFn;				// 10
		WriteFn*	_writeFn;				// 18
	};
	STATIC_ASSERT(sizeof(NiBinaryStream) == 0x20);


	template <class CharT>
	inline bool NiBinaryStream::get(CharT& a_ch)
	{
		return read(&a_ch, 1);
	}


	template <class CharT>
	inline bool NiBinaryStream::read(CharT* a_str, UInt32 a_count)
	{
		UInt32 size = sizeof(CharT);
		UInt32 toRead = a_count * size;
		UInt32 bytesRead = binary_read(a_str, toRead, &size);
		return bytesRead == toRead;
	}


	template <class CharT>
	inline bool NiBinaryStream::put(CharT a_ch)
	{
		return write(&a_ch, 1);
	}


	template <class CharT>
	inline bool NiBinaryStream::write(const CharT* a_str, UInt32 a_count)
	{
		UInt32 size = sizeof(CharT);
		UInt32 toWrite = a_count * size;
		UInt32 bytesWritten = binary_write(a_str, toWrite, &size);
		return bytesWritten == toWrite;
	}
}


namespace std
{
	template< class CharT, class Traits, class Allocator >
	inline bool getline(RE::NiBinaryStream& a_input, std::basic_string<CharT, Traits, Allocator>& a_str)
	{
		CharT delim = std::use_facet<std::ctype<CharT>>(std::locale()).widen('\n');
		return getline(a_input, a_str, delim);
	}


	template <class CharT, class Traits, class Allocator>
	inline bool getline(RE::NiBinaryStream& a_input, std::basic_string<CharT, Traits, Allocator>& a_str, CharT a_delim)
	{
		a_str.erase();
		CharT c;
		auto notEOF = a_input.get(c);
		if (notEOF) {
			do {
				if (!std::char_traits<CharT>::eq(c, a_delim)) {
					a_str.push_back(c);
				} else {
					break;
				}

				if (a_str.size() != a_str.max_size()) {
					notEOF = a_input.get(c);
				} else {
					break;
				}
			} while (notEOF);
			return true;
		} else {
			return false;
		}
	}
}
