#pragma once

#include "RE/BSTArray.h"


namespace RE
{
	class BGSDistantTreeBlock /* : public BSResourceEntry */
	{
	public:
		struct LODGroupInstance
		{
			UInt32	formId;	// 00 - Only the lower 24 bits used
			UInt32	unk04;	// 04
			UInt32	unk08;	// 08
			UInt16	unk0C;	// 0C
			UInt16	alpha;	// 0E - This is Float2Word(fAlpha)
			bool	hidden;	// 10 - alpha <= 0.0f or set by object flags
			UInt8	unk11;	// 11
			UInt16	unk12;	// 12
			// Pretty sure LODGroupInstance is just 0x14 because having this extra UInt32 here breaks the array, but haven't had time to check this further.
			// UInt32	unk14;	// 14
		};
		STATIC_ASSERT(offsetof(LODGroupInstance, formId) == 0x00);
		STATIC_ASSERT(offsetof(LODGroupInstance, alpha) == 0x0E);
		STATIC_ASSERT(offsetof(LODGroupInstance, hidden) == 0x10);


		struct LODGroup
		{
			UInt64						unk00;			// 00
			BSTArray<LODGroupInstance>	lodInstances;	// 08
			UInt32						unk20;			// 20
			bool						unk24;			// 24
		};
		STATIC_ASSERT(offsetof(LODGroup, lodInstances) == 0x08);
		STATIC_ASSERT(offsetof(LODGroup, unk24) == 0x24);


		struct ResourceData
		{
			BSTArray<LODGroup*>	lodGroups;	// 00
			UInt64				unk18;		// 18
			UInt64				unk20;		// 20
			UInt64				unk28;		// 28
			UInt64				unk30;		// 30
			UInt64				unk38;		// 38
			UInt64				unk40;		// 40
			UInt64				unk48;		// 48
			UInt64				unk50;		// 50
			UInt64				unk58;		// 58
			UInt64				unk60;		// 60
			UInt64				unk68;		// 68
			UInt64				unk70;		// 70
			UInt64				unk78;		// 78
			UInt16				unk80;		// 80
			bool				unk82;		// 82
			UInt8				unk83;		// 83
			UInt32				unk84;		// 84
		};
		STATIC_ASSERT(offsetof(ResourceData, lodGroups) == 0x00);
		STATIC_ASSERT(offsetof(ResourceData, unk82) == 0x82);


		// struct ResourceData @ 0x28
	};
}
