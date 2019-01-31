#pragma once

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementMessageInterface : public IMovementInterface
	{
	public:
		virtual ~IMovementMessageInterface();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - pure
		virtual void	Unk_02(void);	// 02 - pure
		virtual void	Unk_03(void);	// 03 - pure
	};
	STATIC_ASSERT(sizeof(IMovementMessageInterface) == 0x8);
}
