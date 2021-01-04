#pragma once

#include "RE/N/NiFile.h"

namespace RE
{
	class BSFile : public NiFile
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFile;

		virtual ~BSFile();	// 00

		// override (NiFile)
		virtual void		  seek(std::int32_t a_numBytes) override;					  // 02
		virtual void		  set_endian_swap(bool a_doSwap) override;					  // 05
		virtual void		  seek(std::int32_t a_offset, std::int32_t a_from) override;  // 06
		virtual std::uint32_t size() const override;									  // 07

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
		bool		  useAuxBuffer;				   // 048
		std::uint8_t  pad049;					   // 049
		std::uint16_t pad04A;					   // 04A
		std::uint32_t pad04C;					   // 04C
		char*		  auxBuffer;				   // 050
		std::int32_t  auxTrueFilePos;			   // 058
		std::uint32_t auxBufferMinIndex;		   // 05C
		std::uint32_t auxBufferMaxIndex;		   // 060
		char		  fileName[WinAPI::MAX_PATH];  // 064
		std::uint32_t result;					   // 168
		std::uint32_t ioSize;					   // 16C
		std::uint32_t trueFilePos;				   // 170
		std::uint32_t fileSize;					   // 174
		bool		  virtualAlloc;				   // 178
		std::uint8_t  unk179;					   // 179
		std::uint16_t unk17A;					   // 17A
	};
	static_assert(sizeof(BSFile) == 0x180);
}
