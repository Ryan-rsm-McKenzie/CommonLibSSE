#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterController

#include "RE/BSBound.h"  // BSBound
#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/hkpCharacterContext.h"  // hkpCharacterContext
#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class bhkBipedOrientationController;
	class bhkCharacterMoveFinishEvent;
	class bhkListShape;
	class hkpEntity;
	class hkVector4;


	class alignas(0x10) bhkCharacterController :
		public NiRefObject,									// 000
		public BSTEventSource<bhkCharacterMoveFinishEvent>	// 010
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterController;


		virtual ~bhkCharacterController();									// 00

		// add
		virtual void	Unk_02(void) = 0;									// 02
		virtual void	Unk_03(void) = 0;									// 03
		virtual void	Unk_04(void) = 0;									// 04
		virtual void	Unk_05(void) = 0;									// 05
		virtual void	GetLinearVelocity(hkVector4& a_velOut) const = 0;	// 06 - might also return hkVector4
		virtual void	SetLinearVelocity(const hkVector4& a_vel) = 0;		// 07
		virtual void	Unk_08(void) = 0;									// 08
		virtual void	Unk_09(void) = 0;									// 09
		virtual void	Unk_0A(void) = 0;									// 0A
		virtual void	Unk_0B(void) = 0;									// 0B
		virtual void	Unk_0C(void) = 0;									// 0C
		virtual void	Unk_0D(void) = 0;									// 0D
		virtual void	Unk_0E(void) = 0;									// 0E
		virtual void	Unk_0F(void) = 0;									// 0F
		virtual void	Unk_10(void) = 0;									// 10
		virtual void	Unk_11(void) = 0;									// 11
		virtual void	Unk_12(void) = 0;									// 12
		virtual void	Unk_13(void) = 0;									// 13


		// members
		UInt64							unk068;						// 068
		float							unk070;						// 070
		float							unk074;						// 074
		UInt64							unk078;						// 078
		UInt64							unk080;						// 080
		float							unk088;						// 088
		float							unk08C;						// 08C - refreshRate?
		float							unk090;						// 090
		float							unk094;						// 094
		float							unk098;						// 098
		float							unk09C;						// 09C
		UInt64							unk0A0;						// 0A0
		UInt64							unk0A8;						// 0A8
		float							unk0B0;						// 0B0
		float							unk0B4;						// 0B4
		UInt64							unk0B8;						// 0B8
		UInt64							unk0C0;						// 0C0
		UInt64							unk0C8;						// 0C8
		UInt64							unk0D0;						// 0D0
		UInt64							unk0D8;						// 0D8
		UInt64							unk0E0;						// 0E0
		UInt64							unk0E8;						// 0E8
		UInt64							unk0F0;						// 0F0
		UInt64							unk0F8;						// 0F8
		UInt64							unk100;						// 100
		UInt64							unk108;						// 108
		UInt64							unk110;						// 110
		UInt64							unk118;						// 118
		BSBound							unk120;						// 120
		BSBound							unk150;						// 150
		UInt64							unk180;						// 180
		UInt64							unk188;						// 188
		bhkBipedOrientationController*	bipedOrientationController;	// 190
		UInt64							unk198;						// 198
		UInt64							unk1A0;						// 1A0
		UInt64							unk1A8;						// 1A8
		NiPoint3						groundNormal;				// 1B0
		UInt32							unk1BC;						// 1BC
		UInt64							unk1C0;						// 1C0
		UInt64							unk1C8;						// 1C8
		UInt64							unk1D0;						// 1D0
		UInt64							unk1D8;						// 1D8
		hkpCharacterContext				characterContext;			// 1E0
		UInt64							unk218;						// 218
		UInt64							unk220;						// 220
		UInt64							unk228;						// 228
		UInt64							unk230;						// 230
		UInt64							unk238;						// 238
		float							unk240;						// 240
		float							fallTime;					// 244
		UInt64							unk248;						// 248
		UInt64							unk250;						// 250
		UInt64							unk258;						// 258
		UInt64							unk260;						// 260
		UInt64							unk268;						// 268
		UInt64							unk270;						// 270
		UInt64							unk278;						// 278
		bhkListShape*					unk280;						// 280
		bhkListShape*					unk288;						// 288
		UInt64							unk290;						// 290
		UInt64							unk298;						// 298
		UInt64							unk2A0;						// 2A0
		UInt64							unk2A8;						// 2A8
		hkpEntity*						groundEntity;				// 2B0
		UInt64							unk2B8;						// 2B8
		hkReferencedObject*				unk2C0;						// 2C0
		hkReferencedObject*				unk2C8;						// 2C8
		UInt64							unk2D0;						// 2D0
		UInt64							unk2D8;						// 2D8
		UInt64							unk2E0;						// 2E0
		UInt64							unk2E8;						// 2E8
		UInt64							unk2F0;						// 2F0
		UInt64							unk2F8;						// 2F8
		UInt64							unk300;						// 300
		UInt64							unk308;						// 308
		UInt64							unk310;						// 310
		UInt64							unk318;						// 318
		UInt64							unk320;						// 320
		UInt64							unk328;						// 328
	};
	STATIC_ASSERT(sizeof(bhkCharacterController) == 0x330);
}
