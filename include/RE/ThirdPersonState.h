#pragma once

#include "RE/BSFixedString.h"
#include "RE/NiPoint3.h"
#include "RE/NiQuaternion.h"
#include "RE/PlayerInputHandler.h"
#include "RE/TESCameraState.h"


namespace RE
{
	class NiNode;
	class NiPoint2;


	class ThirdPersonState :
		public TESCameraState,		// 00
		public PlayerInputHandler	// 20
	{
	public:
		inline static const void* RTTI = RTTI_ThirdPersonState;


		virtual ~ThirdPersonState();																		// 00

		// override (TESCameraState)
		virtual void	OnStateStart() override;															// 01
		virtual void	OnStateEnd() override;																// 02
		virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState) override;						// 03
		virtual void	GetRotation(NiQuaternion* a_rot) override;											// 04
		virtual void	GetPosition(NiPoint3* a_pos) override;												// 05
		virtual void	Unk_06(void) override;																// 06
		virtual void	LoadCameraState(BGSLoadGameBuffer* a_buf) override;									// 07
		virtual void	Unk_08(void) override;																// 08

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;											// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;	// 04


		// add
		virtual void	SetCameraHandle(RefHandle& a_handle);												// 09 - { return; }
		virtual void	Unk_0A(void);																		// 0A - { return; }
		virtual void	UpdatePosOffset(bool a_weaponDrawn);												// 0B
		virtual bool	IsInCustomMode();																	// 0C
		virtual void	ProcessCameraAngle(bool a_weaponSheathed);											// 0D
		virtual void	Unk_0E(void);																		// 0E
		virtual void	ProcessIdleCameraRot(NiPoint2* a_rot);												// 0F


		// members
		NiNode*			cameraNode;			// 30
		NiNode*			controllerNode;		// 38
		NiPoint3		pos;				// 40
		NiQuaternion	rot;				// 4C - [-1, 1]
		NiPoint3		posOffsetExpected;	// 5C
		NiPoint3		posOffsetActual;	// 68
		float			zoomMultExpected;	// 74
		float			zoomMultActual;		// 78
		float			totalYawExpected;	// 7C - in radians
		float			totalYawActual;		// 80 - in radians
		float			savedZoom;			// 84
		float			pitch;				// 88 - [0, 100]
		float			unk8C;				// 8C
		NiPoint3		collisionPos;		// 90 - valid if collisionPosValid != NaN
		float			collisionPosValid;	// 9C
		UInt64			unkA0;				// A0
		BSFixedString	unkA8;				// A8
		NiQuaternion	unkB0;				// B0
		UInt64			unkC0;				// C0
		UInt64			unkC8;				// C8
		UInt32			unkD0;				// D0
		float			diffRotZ;			// D4
		float			diffRotX;			// D8
		bool			isFreeLook;			// DC
		bool			stateNotActive;		// DD
		UInt16			unkDC;				// DE
		bool			toggleAnimCam;		// E0
		bool			toggleCamMode;		// E1
		UInt16			unkE2;				// E2
		UInt32			unkE4;				// E4
	};
	STATIC_ASSERT(sizeof(ThirdPersonState) == 0xE8);
}
