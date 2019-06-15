#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpWorld

#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpWorld : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpWorld;


		virtual ~hkpWorld();																							// 00

		// override (hkReferencedObject)
		virtual void CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02


		// members
		UInt64	unk010;	// 010
		UInt64	unk018;	// 018
		UInt64	unk020;	// 020
		UInt64	unk028;	// 028
		UInt64	unk030;	// 030
		UInt64	unk038;	// 038
		UInt64	unk040;	// 040
		UInt64	unk048;	// 048
		UInt64	unk050;	// 050
		UInt64	unk058;	// 058
		UInt64	unk060;	// 060
		UInt64	unk068;	// 068
		UInt64	unk070;	// 070
		UInt64	unk078;	// 078
		UInt64	unk080;	// 080
		UInt64	unk088;	// 088
		UInt64	unk090;	// 090
		UInt64	unk098;	// 098
		UInt64	unk0A0;	// 0A0
		UInt64	unk0A8;	// 0A8
		UInt64	unk0B0;	// 0B0
		UInt64	unk0B8;	// 0B8
		UInt64	unk0C0;	// 0C0
		UInt64	unk0C8;	// 0C8
		UInt64	unk0D0;	// 0D0
		UInt64	unk0D8;	// 0D8
		UInt64	unk0E0;	// 0E0
		UInt64	unk0E8;	// 0E8
		UInt64	unk0F0;	// 0F0
		UInt64	unk0F8;	// 0F8
		UInt64	unk100;	// 100
		UInt64	unk108;	// 108
		UInt64	unk110;	// 110
		UInt64	unk118;	// 118
		UInt64	unk120;	// 120
		UInt64	unk128;	// 128
		UInt64	unk130;	// 130
		UInt64	unk138;	// 138
		UInt64	unk140;	// 140
		UInt64	unk148;	// 148
		UInt64	unk150;	// 150
		UInt64	unk158;	// 158
		UInt64	unk160;	// 160
		UInt64	unk168;	// 168
		UInt64	unk170;	// 170
		UInt64	unk178;	// 178
		UInt64	unk180;	// 180
		UInt64	unk188;	// 188
		UInt64	unk190;	// 190
		UInt64	unk198;	// 198
		UInt64	unk1A0;	// 1A0
		UInt64	unk1A8;	// 1A8
		UInt64	unk1B0;	// 1B0
		UInt64	unk1B8;	// 1B8
		UInt64	unk1C0;	// 1C0
		UInt64	unk1C8;	// 1C8
		UInt64	unk1D0;	// 1D0
		UInt64	unk1D8;	// 1D8
		UInt64	unk1E0;	// 1E0
		UInt64	unk1E8;	// 1E8
		UInt64	unk1F0;	// 1F0
		UInt64	unk1F8;	// 1F8
		UInt64	unk200;	// 200
		UInt64	unk208;	// 208
		UInt64	unk210;	// 210
		UInt64	unk218;	// 218
		UInt64	unk220;	// 220
		UInt64	unk228;	// 228
		UInt64	unk230;	// 230
		UInt64	unk238;	// 238
		UInt64	unk240;	// 240
		UInt64	unk248;	// 248
		UInt64	unk250;	// 250
		UInt64	unk258;	// 258
		UInt64	unk260;	// 260
		UInt64	unk268;	// 268
		UInt64	unk270;	// 270
		UInt64	unk278;	// 278
		UInt64	unk280;	// 280
		UInt64	unk288;	// 288
		UInt64	unk290;	// 290
		UInt64	unk298;	// 298
		UInt64	unk2A0;	// 2A0
		UInt64	unk2A8;	// 2A8
		UInt64	unk2B0;	// 2B0
		UInt64	unk2B8;	// 2B8
		UInt64	unk2C0;	// 2C0
		UInt64	unk2C8;	// 2C8
		UInt64	unk2D0;	// 2D0
		UInt64	unk2D8;	// 2D8
		UInt64	unk2E0;	// 2E0
		UInt64	unk2E8;	// 2E8
		UInt64	unk2F0;	// 2F0
		UInt64	unk2F8;	// 2F8
		UInt64	unk300;	// 300
		UInt64	unk308;	// 308
		UInt64	unk310;	// 310
		UInt64	unk318;	// 318
		UInt64	unk320;	// 320
		UInt64	unk328;	// 328
		UInt64	unk330;	// 330
		UInt64	unk338;	// 338
		UInt64	unk340;	// 340
		UInt64	unk348;	// 348
		UInt64	unk350;	// 350
		UInt64	unk358;	// 358
		UInt64	unk360;	// 360
		UInt64	unk368;	// 368
		UInt64	unk370;	// 370
		UInt64	unk378;	// 378
		UInt64	unk380;	// 380
		UInt64	unk388;	// 388
		UInt64	unk390;	// 390
		UInt64	unk398;	// 398
		UInt64	unk3A0;	// 3A0
		UInt64	unk3A8;	// 3A8
		UInt64	unk3B0;	// 3B0
		UInt64	unk3B8;	// 3B8
		UInt64	unk3C0;	// 3C0
		UInt64	unk3C8;	// 3C8
		UInt64	unk3D0;	// 3D0
		UInt64	unk3D8;	// 3D8
		UInt64	unk3E0;	// 3E0
		UInt64	unk3E8;	// 3E8
		UInt64	unk3F0;	// 3F0
		UInt64	unk3F8;	// 3F8
		UInt64	unk400;	// 400
		UInt64	unk408;	// 408
		UInt64	unk410;	// 410
		UInt64	unk418;	// 418
		UInt64	unk420;	// 420
		UInt64	unk428;	// 428
	};
	STATIC_ASSERT(sizeof(hkpWorld) == 0x430);
}
