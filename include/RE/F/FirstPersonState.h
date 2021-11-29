#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/P/PlayerInputHandler.h"
#include "RE/T/TESCameraState.h"

namespace RE
{
	class NiNode;

	class FirstPersonState :
		public TESCameraState,     // 00
		public PlayerInputHandler  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_FirstPersonState;

		~FirstPersonState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                    // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                    // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;                      // 08

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                          // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;  // 04

		// members
		NiPoint3      lastPosition;             // 30
		NiPoint3      lastFrameSpringVelocity;  // 3C
		NiPoint3      dampeningOffset;          // 48
		std::uint32_t pad54;                    // 54
		NiAVObject*   firstPersonCameraObj;     // 58
		NiNode*       firstPersonFOVControl;    // 60
		float         sittingRotation;          // 68
		float         unk6C;                    // 6C
		float         unk70;                    // 70
		float         currentPitchOffset;       // 74 - [-100, 100]
		float         targetPitchOffset;        // 78 - [-100, 100]
		float         unk7C;                    // 7C
		std::uint32_t unk80;                    // 80
		bool          cameraOverride;           // 84
		bool          cameraPitchOverride;      // 85
		std::uint16_t unk86;                    // 86
		std::uint64_t unk88;                    // 88
	};
	static_assert(sizeof(FirstPersonState) == 0x90);
}
