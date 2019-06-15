#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PlayerCamera

#include "skse64/GameCamera.h"  // TESCamera
#include "skse64/NiTypes.h"  // NiPoint3


namespace RE
{
	class TESCameraState;


	class PlayerCamera : public TESCamera
	{
	public:
		inline static const void* RTTI = RTTI_PlayerCamera;


		struct CameraStates
		{
			enum CameraState : UInt32
			{
				kFirstPerson = 0,
				kAutoVanity,
				kVATS,
				kFree,
				kIronSights,
				kFurniture,
				kTransition,
				kTweenMenu,
				kThirdPerson1,
				kThirdPerson2,
				kHorse,
				kBleedout,
				kDragon,

				kTotal
			};
		};
		using CameraState = CameraStates::CameraState;


		virtual ~PlayerCamera();	// 00

		static PlayerCamera* GetSingleton();

		void UpdateThirdPerson(bool a_weaponDrawn);


		// members
		UInt8			unk038[0xB8 - 0x38];				// 038
		TESCameraState*	cameraStates[CameraState::kTotal];	// 0B8
		UInt64			unk120;								// 120
		UInt64			unk128;								// 128
		UInt64			unk130;								// 130
		UInt32			unk138;								// 138
		float			worldFOV;							// 13C
		float			firstPersonFOV;						// 140
		NiPoint3		pos;								// 144
		NiPoint3		rot;								// 150
		UInt32			unk15C;								// 15C
		UInt8			unk160;								// 160
		UInt8			unk161;								// 161
		UInt8			unk162;								// 162
		UInt8			unk163;								// 163
		UInt8			unk164;								// 164
		UInt8			unk165;								// 165
		UInt8			pad166[2];							// 166
	};
	STATIC_ASSERT(offsetof(PlayerCamera, cameraStates) == 0x0B8);
	STATIC_ASSERT(offsetof(PlayerCamera, worldFOV) == 0x13C);
	STATIC_ASSERT(offsetof(PlayerCamera, firstPersonFOV) == 0x140);
	STATIC_ASSERT(offsetof(PlayerCamera, pos) == 0x144);
	STATIC_ASSERT(offsetof(PlayerCamera, rot) == 0x150);
}
