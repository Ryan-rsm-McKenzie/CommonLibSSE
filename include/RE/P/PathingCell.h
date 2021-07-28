#pragma once

#include "RE/B/BSPathingCell.h"

namespace RE
{
	class PathingCell : public BSPathingCell
	{
	public:
		inline static constexpr auto RTTI = RTTI_PathingCell;

		virtual ~PathingCell();  // 00

		// override (BSPathingCell)
		virtual std::uint32_t GetType() const override;  // 01 - "PathingCell"
		virtual void          Unk_02() override;     // 02
		virtual void          Unk_03() override;     // 03
		virtual void          Unk_04() override;     // 04
		virtual void          Unk_05() override;     // 05
		virtual void          Unk_06() override;     // 06
		virtual void          Unk_07() override;     // 07
		virtual void          Unk_08() override;     // 08
		virtual void          Unk_09() override;     // 09
		virtual void          Unk_0A() override;     // 0A

		// members
		FormID unk10;   // 10
		FormID cellID;  // 14
	};
	static_assert(sizeof(PathingCell) == 0x18);
}
