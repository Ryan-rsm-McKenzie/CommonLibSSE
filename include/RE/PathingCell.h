#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PathingCell

#include "RE/BSPathingCell.h"  // BSPathingCell


namespace RE
{
	class PathingCell : public BSPathingCell
	{
	public:
		inline static const void* RTTI = RTTI_PathingCell;


		virtual ~PathingCell();						// 00

		// override (BSPathingCell)
		virtual UInt32	GetType() const override;	// 01 - "PathingCell"
		virtual void	Unk_02(void) override;		// 02
		virtual void	Unk_03(void) override;		// 03
		virtual void	Unk_04(void) override;		// 04
		virtual void	Unk_05(void) override;		// 05
		virtual void	Unk_06(void) override;		// 06
		virtual void	Unk_07(void) override;		// 07
		virtual void	Unk_08(void) override;		// 08
		virtual void	Unk_09(void) override;		// 09
		virtual void	Unk_0A(void) override;		// 0A


		// members
		FormID	unk10;	// 10
		FormID	cellID;	// 14
	};
	STATIC_ASSERT(sizeof(PathingCell) == 0x18);
}
