#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSStorage : public BSIntrusiveRefCounted
	{
	public:
		virtual ~BSStorage();			// 00

		// add
		virtual void	Unk_01(void);	// 01 - pure
		virtual void	Unk_02(void);	// 02 - pure
		virtual void	Unk_03(void);	// 03 - pure
		virtual void	Unk_04(void);	// 04 - pure
		virtual void	Unk_05(void);	// 05 - pure


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(BSStorage) == 0x20);
}
