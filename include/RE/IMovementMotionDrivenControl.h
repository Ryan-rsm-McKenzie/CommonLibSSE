#pragma once

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementMotionDrivenControl : public IMovementInterface
	{
	public:
		virtual ~IMovementMotionDrivenControl();	// 00

		// add
		virtual void	Unk_01(void);				// 01 - pure
		virtual void	Unk_02(void);				// 02 - pure
		virtual void	Unk_03(void);				// 03 - pure
		virtual void	Unk_04(void);				// 04 - pure
		virtual void	Unk_05(void);				// 05 - pure
		virtual void	Unk_06(void);				// 06 - pure
		virtual void	Unk_07(void);				// 07 - pure
		virtual void	Unk_08(void);				// 08 - pure
	};
	STATIC_ASSERT(sizeof(IMovementMotionDrivenControl) == 0x8);
}
