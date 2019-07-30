#pragma once

#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiRefObject;


	struct Biped : public BSIntrusiveRefCounted
	{
		struct Data
		{
			UInt64					unk00;	// 00
			UInt64					unk08;	// 08
			UInt64					unk10;	// 10
			UInt64					unk18;	// 18
			NiPointer<NiRefObject>	unk20;	// 20
			UInt64					unk28;	// 28
			UInt64					unk30;	// 30
			UInt64					unk38;	// 38
			UInt64					unk40;	// 40
			UInt64					unk48;	// 48
			UInt64					unk50;	// 50
			UInt64					unk58;	// 58
			void*					unk60;	// 60
			UInt64					unk68;	// 68
			void*					unk70;	// 70
		};
		STATIC_ASSERT(sizeof(Data) == 0x78);


		UInt32	unk0004;		// 0000
		UInt64	unk0008;		// 0008
		Data	unk0010[0x2A];	// 0010
		Data	unk13C0[0x2A];	// 13C0
		UInt64	unk2770;		// 2770
	};
	STATIC_ASSERT(sizeof(Biped) == 0x2778);
}
