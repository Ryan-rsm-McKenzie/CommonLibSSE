#pragma once

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class ActorKnowledge : public NiRefObject
	{
	public:
		virtual ~ActorKnowledge();	// 00

		SInt32 GetDetectionState();


		// members
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
		UInt32	unk18;	// 18
		float	unk1C;	// 1C
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt32	unk40;	// 40
		float	unk44;	// 44
	};
	STATIC_ASSERT(sizeof(ActorKnowledge) == 0x48);
}
