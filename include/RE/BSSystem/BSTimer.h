#pragma once


namespace RE
{
	class BSTimer
	{
	public:
		// members
		UInt64 unk00;						   // 00
		UInt32 lastPerformanceCount;		   // 08
		float  clamp;						   // 10
		float  clampRemainder;				   // 14
		float  delta;						   // 18
		float  realTimeDelta;				   // 1C
		UInt32 unk20;						   // 20
		UInt32 unk24;						   // 24
		float  unk28;						   // 28
		UInt32 unk2C;						   // 2C
		UInt32 unk30;						   // 30
		UInt32 unk34;						   // 34
		UInt8  unk38;						   // 38
		UInt8  unk39;						   // 39
		bool   useGlobalTimeMultiplierTarget;  // 3A
		UInt8  pad3B;						   // 3B
		UInt32 pad3C;						   // 3C
	};
	STATIC_ASSERT(sizeof(BSTimer) == 0x40);
}
