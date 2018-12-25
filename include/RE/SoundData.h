#pragma once


namespace RE
{
	struct SoundData
	{
		SoundData();


		// members
		SInt32	unk00;	// 00
		UInt8	unk04;	// 04
		UInt8	pad05;	// 05
		UInt16	pad06;	// 06
		UInt32	unk08;	// 08
		UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(SoundData) == 0x10);
}
