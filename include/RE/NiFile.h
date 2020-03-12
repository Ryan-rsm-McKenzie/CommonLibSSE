#pragma once

#include <cstdio>

#include "RE/NiBinaryStream.h"


namespace RE
{
	class NiFile : public NiBinaryStream
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiFile;


		enum class OpenMode : UInt32
		{
			kReadOnly = 0,
			kWriteOnly = 1,
			kAppendOnly = 2
		};


		~NiFile();	// 00

		// override (NiBinaryStream)
		virtual bool good() const override;					   // 01 - { return isGood; }
		virtual void seek(SInt32 a_numBytes) override;		   // 02
		virtual void get_info(BufferInfo& a_buf) override;	   // 04
		virtual void set_endian_swap(bool a_doSwap) override;  // 05

		// add
		virtual void   seek(SInt32 a_offset, SInt32 a_from);  // 06
		virtual UInt32 size() const;						  // 07


		// members
		UInt32	   bufferAllocSize;	 // 20
		UInt32	   bufferReadSize;	 // 24
		UInt32	   pos;				 // 28
		UInt32	   pad2C;			 // 2C
		char*	   buffer;			 // 30
		std::FILE* file;			 // 38
		OpenMode   mode;			 // 40
		bool	   isGood;			 // 44
		UInt8	   pad45;			 // 45
		UInt16	   pad46;			 // 46
	};
	STATIC_ASSERT(sizeof(NiFile) == 0x48);
}
