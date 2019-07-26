#pragma once

#include "skse64/GameRTTI.h"  // RTTI_DetectionState

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class DetectionState : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_DetectionState;


		virtual ~DetectionState();	// 00


		// members
		SInt32	level;	// 10
		UInt8	unk14;	// 14
		UInt8	unk15;	// 15
		UInt8	unk16;	// 16
		UInt8	pad17;	// 17
		float	unk18;	// 18
		UInt32	unk1C;	// 1C
		UInt32	unk20;	// 20
		UInt32	unk24;	// 24
		float	unk28;	// 28
		UInt32	unk2C;	// 2C
		UInt32	unk30;	// 30
		UInt32	unk34;	// 34
		float	unk38;	// 38
		UInt32	unk3C;	// 3C
		UInt32	unk40;	// 40
		UInt32	unk44;	// 44
	};
	STATIC_ASSERT(sizeof(DetectionState) == 0x48);
}
