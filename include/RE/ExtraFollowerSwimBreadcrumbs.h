#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraFollowerSwimBreadcrumbs

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraFollowerSwimBreadcrumbs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFollowerSwimBreadcrumbs;


		enum { kExtraTypeID = ExtraDataType::kFollowerSwimBreadcrumbs };


		struct UnkData
		{
			UInt32	unk00;	// 00
			UInt32	unk04;	// 04
			UInt32	unk08;	// 08
			UInt32	unk0C;	// 0C
			UInt32	unk10;	// 10
			UInt32	unk14;	// 14
			UInt32	unk18;	// 18
			UInt32	unk1C;	// 1C
			UInt32	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(UnkData) == 0x24);


		virtual ~ExtraFollowerSwimBreadcrumbs();		// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFollowerSwimBreadcrumbs; }


		// members
		UInt32					unk10;	// 10
		float					unk14;	// 14
		float					unk18;	// 18
		float					unk1C;	// 1C
		UInt64					unk20;	// 20
		BSSimpleList<UnkData*>	unk28;	// 28
	};
	STATIC_ASSERT(sizeof(ExtraFollowerSwimBreadcrumbs) == 0x38);
}
