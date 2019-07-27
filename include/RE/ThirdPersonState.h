#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/PlayerInputHandler.h"  // PlayerInputHandler
#include "RE/TESCameraState.h"  // TESCameraState


namespace RE
{
	class NiNode;


	class ThirdPersonState :
		public TESCameraState,		// 00
		public PlayerInputHandler	// 20
	{
	public:
		virtual ~ThirdPersonState();																// 00

		// override (TESCameraState)
		virtual void	OnStateStart() override;													// 01
		virtual void	OnStateEnd() override;														// 02
		virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState) override;				// 03
		virtual void	Unk_04(void) override;														// 04
		virtual void	Unk_05(void) override;														// 05
		virtual void	Unk_06(void) override;														// 06
		virtual void	LoadCameraState(BGSLoadGameBuffer* a_buf) override;							// 07
		virtual void	Unk_08(void) override;														// 08

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04


		// add
		virtual void	Unk_09(void);																// 09 - { return; }
		virtual void	Unk_0A(void);																// 0A - { return; }
		virtual void	UpdatePosOffset(bool a_weaponDrawn);										// 0B
		virtual void	Unk_0C(void);																// 0C
		virtual void	Unk_0D(void);																// 0D
		virtual void	Unk_0E(void);																// 0E
		virtual void	Unk_0F(void);																// 0F


		// members
		NiNode*			cameraNode;					// 30
		NiNode*			controllerNode;				// 38
		NiPoint3		pos;						// 40
		NiPoint3		rot;						// 4C - [-1, 1]
		float			unk58;						// 58
		NiPoint3		posOffsetExpected;			// 5C
		NiPoint3		posOffsetActual;			// 68
		float			zoomMultExpected;			// 74
		float			zoomMultActual;				// 78
		float			totalYawExpected;			// 7C - in radians
		float			totalYawActual;				// 80 - in radians
		float			unk84;						// 84
		float			pitch;						// 88 - [0, 100]
		float			unk8C;						// 8C
		NiPoint3		pos2;						// 90 - valid if pos2Valid != NaN
		float			pos2Valid;					// 9C
		UInt64			unkA0;						// A0
		BSFixedString	unkA8;						// A8
		UInt64			unkB0;						// B0
		UInt64			unkB8;						// B8
		UInt64			unkC0;						// C0
		UInt64			unkC8;						// C8
		UInt64			unkD0;						// D0
		UInt32			unkD8;						// D8
		bool			noMovementOrCombatReady;	// DC
		bool			stateNotActive;				// DD
		UInt16			unkDC;						// DE
		UInt64			unkE0;						// E0
	};
	STATIC_ASSERT(sizeof(ThirdPersonState) == 0xE8);
}
