#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMovementMessageInterface

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementMessageInterface : public IMovementInterface
	{
	public:
		inline static const void* RTTI = RTTI_IMovementMessageInterface;


		virtual ~IMovementMessageInterface();	// 00

		// add
		virtual void	Unk_01(void) = 0;		// 01
		virtual void	Unk_02(void) = 0;		// 02
		virtual void	Unk_03(void) = 0;		// 03
	};
	STATIC_ASSERT(sizeof(IMovementMessageInterface) == 0x8);
}
