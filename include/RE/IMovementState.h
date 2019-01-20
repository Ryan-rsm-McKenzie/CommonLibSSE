#pragma once

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementState : public IMovementInterface
	{
	public:
		virtual ~IMovementState();		// 00

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
		virtual void	Unk_0D(void);	// 0D - pure
		virtual void	Unk_0E(void);	// 0E - pure
		virtual void	Unk_0F(void);	// 0F - pure
		virtual void	Unk_10(void);	// 10 - pure
		virtual void	Unk_11(void);	// 11 - pure
		virtual void	Unk_12(void);	// 12 - pure
		virtual void	Unk_13(void);	// 13 - pure
	};
	STATIC_ASSERT(sizeof(IMovementState) == 0x8);
}
