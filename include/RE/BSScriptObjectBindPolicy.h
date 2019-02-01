#pragma once

#include "RE/BSTHashMap.h"  // BSTHashMap


namespace RE
{
	namespace BSScript
	{
		class ObjectBindPolicy
		{
		public:
			virtual ~ObjectBindPolicy();	// 00

			// add
			virtual void	Unk_01(void);	// 01 - pure
			virtual void	Unk_02(void);	// 02 - pure
			virtual void	Unk_03(void);	// 03 - pure
			virtual void	Unk_04(void);	// 04 - pure
			virtual void	Unk_05(void);	// 05 - pure
			virtual void	Unk_06(void);	// 06 - pure
			virtual void	Unk_07(void);	// 07 - pure
			virtual void	Unk_08(void);	// 08 - pure
			virtual void	Unk_09(void);	// 09 - pure
			virtual void	Unk_0A(void);	// 0A - pure
			virtual void	Unk_0B(void);	// 0B - pure
			virtual void	Unk_0C(void);	// 0C - pure


			// members
			UInt64							unk08;	// 08
			UInt64							unk10;	// 10
			UInt64							unk18;	// 18
			BSTHashMap<UnkKey, UnkValue>	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(ObjectBindPolicy) == 0x50);
	}
}
