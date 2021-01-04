#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiPoint2.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiQuaternion.h"
#include "RE/P/PlayerInputHandler.h"
#include "RE/T/TESCameraState.h"

namespace RE
{
	class NiNode;

	class ThirdPersonState :
		public TESCameraState,	   // 00
		public PlayerInputHandler  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_ThirdPersonState;

		virtual ~ThirdPersonState();  // 00

		// override (TESCameraState)
		virtual void Begin() override;												 // 01
		virtual void End() override;												 // 02
		virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;	 // 03
		virtual void GetRotation(NiQuaternion& a_rotation) override;				 // 04
		virtual void GetTranslation(NiPoint3& a_translation) override;				 // 05
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;					 // 06
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;					 // 07
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;						 // 08

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;											// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;	// 04

		// add
		virtual void SetCameraHandle(RefHandle& a_handle);		  // 09 - { return; }
		virtual void Unk_0A(void);								  // 0A - { return; }
		virtual void ProcessWeaponDrawnChange(bool a_drawn);	  // 0B
		virtual bool GetFreeRotationMode() const;				  // 0C
		virtual void SetFreeRotationMode(bool a_weaponSheathed);  // 0D
		virtual void UpdateRotation();							  // 0E
		virtual void HandleLookInput(const NiPoint2& a_input);	  // 0F

		// members
		NiAVObject*	  thirdPersonCameraObj;	  // 30
		NiNode*		  thirdPersonFOVControl;  // 38
		NiPoint3	  translation;			  // 40
		NiQuaternion  rotation;				  // 4C - [-1, 1]
		NiPoint3	  posOffsetExpected;	  // 5C
		NiPoint3	  posOffsetActual;		  // 68
		float		  targetZoomOffset;		  // 74
		float		  currentZoomOffset;	  // 78
		float		  targetYaw;			  // 7C - in radians
		float		  currentYaw;			  // 80 - in radians
		float		  savedZoomOffset;		  // 84
		float		  pitchZoomOffset;		  // 88 - [0, 100]
		float		  unk8C;				  // 8C
		NiPoint3	  collisionPos;			  // 90 - valid if collisionPosValid != NaN
		float		  collisionPosValid;	  // 9C
		std::uint64_t unkA0;				  // A0
		BSFixedString animatedBoneName;		  // A8
		NiQuaternion  animationRotation;	  // B0
		std::uint64_t unkC0;				  // C0
		std::uint64_t unkC8;				  // C8
		std::uint32_t unkD0;				  // D0
		NiPoint2	  freeRotation;			  // D4
		bool		  freeRotationEnabled;	  // DC
		bool		  stateNotActive;		  // DD
		std::uint16_t unkDC;				  // DE
		bool		  toggleAnimCam;		  // E0
		bool		  applyOffsets;			  // E1
		std::uint16_t unkE2;				  // E2
		std::uint32_t unkE4;				  // E4
	};
	static_assert(sizeof(ThirdPersonState) == 0xE8);
}
