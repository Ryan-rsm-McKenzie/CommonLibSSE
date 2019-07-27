#pragma once

#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/PlayerInputHandler.h"  // PlayerInputHandler
#include "RE/TESCameraState.h"  // TESCameraState


namespace RE
{
	class NiNode;


	class FirstPersonState :
		public TESCameraState,		// 00
		public PlayerInputHandler	// 20
	{
	public:
		virtual ~FirstPersonState();																// 00

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


		// members
		NiPoint3	pos;			// 30
		NiPoint3	velocity;		// 3C
		NiPoint3	acceleration;	// 48 - ?
		UInt32		unk54;			// 54
		NiNode*		cameraNode;		// 58
		NiNode*		controllerNode;	// 60
		UInt32		unk68;			// 68
		float		unk6C;			// 6C
		float		unk70;			// 70
		float		pitchActual;	// 74 - [-100, 100]
		float		pitchExpected;	// 78 - [-100, 100]
		float		unk7C;			// 7C
		UInt64		unk80;			// 80
		UInt64		unk88;			// 88
	};
	STATIC_ASSERT(sizeof(FirstPersonState) == 0x90);
}
