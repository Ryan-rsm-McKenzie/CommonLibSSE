#pragma once

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementPlannerDirectControl : public IMovementInterface
	{
	public:
		virtual ~IMovementPlannerDirectControl();	// 00

		// add
		virtual void	Unk_01(void);				// 01 - pure
		virtual void	Unk_02(void);				// 02 - pure
		virtual void	Unk_03(void);				// 03 - pure
		virtual void	Unk_04(void);				// 04 - pure
		virtual void	Unk_05(void);				// 05 - pure
	};
	STATIC_ASSERT(sizeof(IMovementPlannerDirectControl) == 0x8);
}
