#pragma once

#include "skse64/GameTypes.h"  // BSIntrusiveRefCounted


namespace RE
{
	class BSIRagdollDriver : public BSIntrusiveRefCounted
	{
	public:
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
		virtual void	Unk_0D(void);	// 0D - pure
	};
	STATIC_ASSERT(sizeof(BSIRagdollDriver) == 0x10);
}
