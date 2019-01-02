#pragma once

#include "RE/hkpFixedRigidMotion.h"  // hkpFixedRigidMotion
#include "RE/hkpWorldObject.h"  // hkpWorldObject


namespace RE
{
	class hkpSimulationIsland;


	class hkpEntity : public hkpWorldObject
	{
	public:
		virtual ~hkpEntity();		// 00

		// add
		virtual void Unk_06(void);	// 06


		// members
		UInt64					unk0D0;	// 0D0
		UInt64					unk0D8;	// 0D8
		UInt64					unk0E0;	// 0E0
		UInt64					unk0E8;	// 0E8
		UInt64					unk0F0;	// 0F0
		UInt64					unk0F8;	// 0F8
		UInt64					unk100;	// 100
		UInt64					unk108;	// 108
		UInt64					unk110;	// 110
		UInt64					unk118;	// 118
		UInt64					unk120;	// 120
		UInt64					unk128;	// 128
		hkpSimulationIsland*	unk130;	// 130
		UInt64					unk138;	// 138
		UInt64					unk140;	// 140
		UInt64					unk148;	// 148
		hkpFixedRigidMotion		unk150;	// 150
		UInt64					unk290;	// 290
		UInt64					unk298;	// 298
		UInt64					unk2A0;	// 2A0
		UInt64					unk2A8;	// 2A8
		UInt64					unk2B0;	// 2B0
		UInt64					unk2B8;	// 2B8
		UInt64					unk2C0;	// 2C0
		UInt64					unk2C8;	// 2C8
	};
	STATIC_ASSERT(sizeof(hkpEntity) == 0x2D0);
}
