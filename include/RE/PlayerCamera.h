#pragma once

#include "skse64/GameCamera.h"  // TESCamera

class TESCameraState;


namespace RE
{
	class PlayerCamera : public TESCamera
	{
	public:
		enum CameraState
		{
			kCameraState_FirstPerson = 0,
			kCameraState_AutoVanity,
			kCameraState_VATS,
			kCameraState_Free,
			kCameraState_IronSights,
			kCameraState_Furniture,
			kCameraState_Transition,
			kCameraState_TweenMenu,
			kCameraState_ThirdPerson1,
			kCameraState_ThirdPerson2,
			kCameraState_Horse,
			kCameraState_Bleedout,
			kCameraState_Dragon,
			kNumCameraStates
		};


		PlayerCamera();
		virtual ~PlayerCamera();	// 0

		static PlayerCamera*	GetSingleton();
		void					UpdateThirdPerson(bool a_weaponDrawn);


		// members
		UInt8			unk038[0xB8 - 0x38];			// 038
		TESCameraState*	cameraStates[kNumCameraStates];	// 0B8
		UInt64			unk120;							// 120
		UInt64			unk128;							// 128
		UInt64			unk130;							// 130
		UInt32			unk138;							// 138
		float			worldFOV;						// 13C
		float			firstPersonFOV;					// 140
		UInt32			posX;							// 144
		UInt32			posY;							// 148
		UInt32			posZ;							// 14C
		UInt32			rotX;							// 150
		UInt32			rotY;							// 154
		UInt32			rotZ;							// 158
		UInt32			unk15C;							// 15C
		UInt8			unk160;							// 160
		UInt8			unk161;							// 161
		UInt8			unk162;							// 162 - init'd to 1
		UInt8			unk163;							// 163
		UInt8			unk164;							// 164
		UInt8			unk165;							// 165
		UInt8			pad166[2];						// 166
	};
	STATIC_ASSERT(offsetof(PlayerCamera, cameraStates) == 0x0B8);
	STATIC_ASSERT(offsetof(PlayerCamera, worldFOV) == 0x13C);
	STATIC_ASSERT(offsetof(PlayerCamera, firstPersonFOV) == 0x140);
	STATIC_ASSERT(offsetof(PlayerCamera, posX) == 0x144);
	STATIC_ASSERT(offsetof(PlayerCamera, posY) == 0x148);
	STATIC_ASSERT(offsetof(PlayerCamera, posZ) == 0x14C);
	STATIC_ASSERT(offsetof(PlayerCamera, rotX) == 0x150);
	STATIC_ASSERT(offsetof(PlayerCamera, rotY) == 0x154);
	STATIC_ASSERT(offsetof(PlayerCamera, rotZ) == 0x158);
}
