#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPoint3.h"
#include "RE/T/TESCamera.h"

namespace RE
{
	class bhkRigidBody;
	class bhkSimpleShapePhantom;
	class NiRefObject;
	class TESCameraState;

	struct CameraStates
	{
		enum CameraState : std::uint32_t
		{
			kFirstPerson = 0,
			kAutoVanity,
			kVATS,
			kFree,
			kIronSights,
			kFurniture,
			kPCTransition,
			kTween,
			kAnimated,
			kThirdPerson,
			kMount,
			kBleedout,
			kDragon,

			kTotal
		};
	};
	using CameraState = CameraStates::CameraState;

	class PlayerCamera :
		public TESCamera,					  // 000
		public BSTSingletonSDM<PlayerCamera>  // 038
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCamera;

		struct Unk120
		{
			NiPointer<bhkSimpleShapePhantom*> unk00;  // 00
			NiPointer<bhkSimpleShapePhantom*> unk08;  // 08
		};
		static_assert(sizeof(Unk120) == 0x10);

		virtual ~PlayerCamera();  // 00

		// override (TESCamera)
		virtual void SetCameraRoot(NiPointer<NiNode> a_root) override;	// 01

		static PlayerCamera* GetSingleton();

		void UpdateThirdPerson(bool a_weaponDrawn);

		// members
		std::uint8_t										 pad039;							  // 039
		std::uint16_t										 pad03A;							  // 03A
		ActorHandle											 cameraTarget;						  // 03C
		BSTSmallArray<TESCameraState*, CameraStates::kTotal> tempReturnStates;					  // 040
		BSTSmartPointer<TESCameraState>						 cameraStates[CameraStates::kTotal];  // 0B8
		Unk120*												 unk120;							  // 120 - ?
		NiPointer<bhkRigidBody>								 rigidBody;							  // 128 - ?
		RefHandle											 objectFadeHandle;					  // 130 - ?
		mutable BSSpinLock									 lock;								  // 134
		float												 worldFOV;							  // 13C
		float												 firstPersonFOV;					  // 140
		NiPoint3											 pos;								  // 144 - ?
		float												 idleTimer;							  // 150 - ?
		float												 yaw;								  // 154 - ? - in radians
		std::uint32_t										 unk158;							  // 158 - ?
		std::uint32_t										 unk15C;							  // 15C - ?
		bool												 allowAutoVanityMode;				  // 160
		bool												 bowZoomedIn;						  // 161
		bool												 isWeapSheathed;					  // 162 - ?
		bool												 isProcessed;						  // 163 - ?
		std::uint8_t										 unk164;							  // 164
		std::uint8_t										 unk165;							  // 165
		std::uint16_t										 pad166;							  // 166
	};
	static_assert(sizeof(PlayerCamera) == 0x168);
}
