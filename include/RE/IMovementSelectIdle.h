#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMovementSelectIdle

#include "RE/IMovementInterface.h"  // IMovementInterface


namespace RE
{
	class IMovementSelectIdle : public IMovementInterface
	{
	public:
		inline static const void* RTTI = RTTI_IMovementSelectIdle;


		virtual ~IMovementSelectIdle();		// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
		virtual void	Unk_04(void) = 0;	// 04
		virtual void	Unk_05(void) = 0;	// 05
	};
	STATIC_ASSERT(sizeof(IMovementSelectIdle) == 0x8);
}
