#pragma once

#include "RE/NiPoint2.h"


namespace RE
{
	struct MovementData
	{
		NiPoint2	movement;		// 00
		NiPoint2	unk08;			// 08
		float		unk10;			// 10
		float		unk14;			// 14
		float		unk18;			// 18
		float		unk1C;			// 1C
		UInt32		unk20;			// 20
		UInt8		autoRun;		// 24
		UInt8		runMode;		// 25
		UInt8		unk26;			// 26
		bool		fovSlideMode;	// 27
		bool		povScriptMode;	// 28
		bool		povBeastMode;	// 29
		UInt8		unk2A;			// 2A
		UInt8		unk2B;			// 2B
		bool		remapMode;		// 2C
		UInt8		unk2D;			// 2D
		UInt16		unk2E;			// 2E
	};
	STATIC_ASSERT(sizeof(MovementData) == 0x30);
}
