#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MovementControllerNPC

#include "RE/IAnimationSetCallbackFunctor.h"  // IAnimationSetCallbackFunctor
#include "RE/IMovementDirectControl.h"  // IMovementDirectControl
#include "RE/IMovementMessageInterface.h"  // IMovementMessageInterface
#include "RE/IMovementMotionDrivenControl.h"  // IMovementMotionDrivenControl
#include "RE/IMovementPlannerDirectControl.h"  // IMovementPlannerDirectControl
#include "RE/IMovementSelectIdle.h"  // IMovementSelectIdle
#include "RE/MovementControllerAI.h"  // MovementControllerAI


namespace RE
{
	class MovementControllerNPC :
		public MovementControllerAI,			// 000
		public IMovementMessageInterface,		// 120
		public IMovementMotionDrivenControl,	// 128
		public IMovementSelectIdle,				// 130
		public IMovementDirectControl,			// 138
		public IMovementPlannerDirectControl,	// 140
		public IAnimationSetCallbackFunctor		// 148
	{
	public:
		inline static const void* RTTI = RTTI_MovementControllerNPC;


		virtual ~MovementControllerNPC();	// 00

		// add
		virtual void	Unk_0A(void);		// 0A
		virtual void	Unk_0B(void);		// 0B
		virtual void	Unk_0C(void);		// 0C
		virtual void	Unk_0D(void);		// 0D
		virtual void	Unk_0E(void);		// 0E - { return unk1C5 == 0; }
		virtual void	Unk_0F(void);		// 0F - { return unk1C5; }
		virtual void	Unk_10(void);		// 10
		virtual void	Unk_11(void);		// 11
		virtual void	Unk_12(void);		// 12
		virtual void	Unk_13(void);		// 13
		virtual void	Unk_14(void);		// 14


		// members
		UInt64	unk150;	// 150
		UInt64	unk158;	// 158
		UInt64	unk160;	// 160
		UInt64	unk168;	// 168
		UInt64	unk170;	// 170
		UInt64	unk178;	// 178
		UInt64	unk180;	// 180
		UInt64	unk188;	// 188
		UInt64	unk190;	// 190
		UInt64	unk198;	// 198
		UInt64	unk1A0;	// 1A0
		UInt64	unk1A8;	// 1A8
		UInt64	unk1B0;	// 1B0
		UInt64	unk1B8;	// 1B8
		UInt32	unk1C0;	// 1C0
		UInt8	unk1C4;	// 1C4
		UInt8	unk1C5;	// 1C5
		UInt16	unk1C6;	// 1C6
		UInt64	unk1C8;	// 1C8
	};
	STATIC_ASSERT(sizeof(MovementControllerNPC) == 0x1D0);
}
