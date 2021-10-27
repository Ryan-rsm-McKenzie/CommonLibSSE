#pragma once

#include "RE/G/GFxLogBase.h"
#include "RE/G/GStringDH.h"

namespace RE
{
	class GFxLog;
	class GFxParseControl;

	class GFxStream : public GFxLogBase<GFxStream>
	{
	public:
		virtual ~GFxStream();  // 00

		// members
		GFxLog*          logState;       // 008
		GFxParseControl* parseControl;   // 010
		bool             unk18;          // 018
		std::uint8_t     pad19;          // 019
		std::uint16_t    pad1A;          // 01A
		std::uint32_t    pad1C;          // 01C
		void*            unk20;          // 020
		std::uint16_t    unk28;          // 028
		std::uint16_t    pad2A;          // 02A
		std::uint32_t    pad2C;          // 02C
		GStringDH        fileUrl;        // 030
		std::uint32_t    nextOffset[2];  // 040
		std::uint32_t    nextOffsetIdx;  // 048 - 1-based
		std::uint32_t    seekPos;        // 04C
		std::uint32_t    bufferEndPos;   // 050
		std::uint32_t    bytesFetched;   // 054
		std::uint8_t     unk58;          // 058
		std::uint8_t     pad59;          // 059
		std::uint16_t    pad5A;          // 05A
		std::uint32_t    pad5C;          // 05C
		char*            data;           // 060
		std::uint32_t    bufferSize;     // 068
		char             buffer[0x200];  // 06C
		std::uint32_t    pad26C;         // 26C
	};
	static_assert(sizeof(GFxStream) == 0x270);
}
