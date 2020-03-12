#pragma once

#include "RE/NiFile.h"


namespace RE
{
	class BSFile : public NiFile
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFile;


		virtual ~BSFile();	// 00

		// override (NiFile)
		virtual void   seek(SInt32 a_numBytes) override;			   // 02
		virtual void   set_endian_swap(bool a_doSwap) override;		   // 05
		virtual void   seek(SInt32 a_offset, SInt32 a_from) override;  // 06
		virtual UInt32 size() const override;						   // 07

		// add
		virtual void Unk_08(void);	// 08
		virtual void Unk_09(void);	// 09
		virtual void Unk_0A(void);	// 0A
		virtual void Unk_0B(void);	// 0B
		virtual void Unk_0C(void);	// 0C
		virtual void Unk_0D(void);	// 0D
		virtual void Unk_0E(void);	// 0E
		virtual void Unk_0F(void);	// 0F
		virtual void Unk_10(void);	// 10
		virtual void Unk_11(void);	// 11
		virtual void Unk_12(void);	// 12


		// members
		bool   useAuxBuffer;		// 048
		UInt8  pad049;				// 049
		UInt16 pad04A;				// 04A
		UInt32 pad04C;				// 04C
		char*  auxBuffer;			// 050
		SInt32 auxTrueFilePos;		// 058
		UInt32 auxBufferMinIndex;	// 05C
		UInt32 auxBufferMaxIndex;	// 060
		char   fileName[MAX_PATH];	// 064
		UInt32 result;				// 168
		UInt32 ioSize;				// 16C
		UInt32 trueFilePos;			// 170
		UInt32 fileSize;			// 174
		bool   virtualAlloc;		// 178
		UInt8  unk179;				// 179
		UInt16 unk17A;				// 17A
	};
	STATIC_ASSERT(sizeof(BSFile) == 0x180);
}
