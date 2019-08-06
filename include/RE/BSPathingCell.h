#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSPathingCell

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSPathingCell : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_BSPathingCell;


		virtual ~BSPathingCell();				// 00

		// add
		virtual UInt32	GetType() const = 0;	// 01 - crc32 hash of class name
		virtual void	Unk_02(void) = 0;		// 02
		virtual void	Unk_03(void) = 0;		// 03
		virtual void	Unk_04(void) = 0;		// 04
		virtual void	Unk_05(void) = 0;		// 05
		virtual void	Unk_06(void) = 0;		// 06
		virtual void	Unk_07(void) = 0;		// 07
		virtual void	Unk_08(void) = 0;		// 08
		virtual void	Unk_09(void) = 0;		// 09
		virtual void	Unk_0A(void) = 0;		// 0A


		// members
		UInt32 unk0C;	// 0C
	};
	STATIC_ASSERT(sizeof(BSPathingCell) == 0x10);
}
