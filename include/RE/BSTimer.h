#pragma once


namespace RE
{
	class BSTimer
	{
	public:
		UInt64	unk00;		// 00

		UInt32	freqLow;	// 08 (= Frequency.LowPart)
		UInt32	freqHigh;	// 0C (= Frequency.HighPart)

		UInt64	unk10;		// 10
		float	unk18;		// 18
		float	unk1C;		// 1C
		UInt32	unk20;		// 20
		UInt32	unk24;		// 24
		float	unk28;		// 28

		UInt32	unk2C;		// 2C
		UInt32	unk30;		// 30

		UInt32	unk34;		// 34
		UInt8	unk38;		// 38
		UInt8	unk39;		// 39
		UInt8	unk3A;		// 3A
		UInt8	pad3B;		// 3B
		UInt32	pad3C;		// 3C
	};
	STATIC_ASSERT(sizeof(BSTimer) == 0x40);
}
