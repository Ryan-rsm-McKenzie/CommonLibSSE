#pragma once


namespace RE
{
	struct MovementData
	{
		float	movementX;	// 00
		float	movementY;	// 04
		float	unk08;		// 08
		float	unk0C;		// 0C
		float	unk10;		// 10
		float	unk14;		// 14
		float	unk18;		// 18
		float	unk1C;		// 1C
		UInt32	unk20;		// 20
		UInt8	autoRun;	// 24
		UInt8	runMode;	// 25
		UInt8	unk26;		// 26
		UInt8	unk27;		// 27
		UInt16	unk28;		// 28
		UInt8	unk2A;		// 2A
		UInt8	unk2B;		// 2B
		bool	remapMod;	// 2C
		UInt8	unk2D;		// 2D
		UInt16	unk2E;		// 2E
	};
}
