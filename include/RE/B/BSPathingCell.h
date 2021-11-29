#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class BSPathingCell : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPathingCell;

		virtual ~BSPathingCell();  // 00

		// add
		virtual std::uint32_t GetType() const = 0;  // 01 - crc32 hash of class name
		virtual void          Unk_02(void) = 0;     // 02
		virtual void          Unk_03(void) = 0;     // 03
		virtual void          Unk_04(void) = 0;     // 04
		virtual void          Unk_05(void) = 0;     // 05
		virtual void          Unk_06(void) = 0;     // 06
		virtual void          Unk_07(void) = 0;     // 07
		virtual void          Unk_08(void) = 0;     // 08
		virtual void          Unk_09(void) = 0;     // 09
		virtual void          Unk_0A(void) = 0;     // 0A

		// members
		std::uint32_t unk0C;  // 0C
	};
	static_assert(sizeof(BSPathingCell) == 0x10);
}
