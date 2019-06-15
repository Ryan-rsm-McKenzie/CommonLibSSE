#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraOutfitItem

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraOutfitItem : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOutfitItem;


		enum { kExtraTypeID = ExtraDataType::kOutfitItem };


		virtual ~ExtraOutfitItem();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kOutfitItem; }


		// members
		UInt32	outfitFormID;	// 10 - BGSOutfit
		UInt32	unk14;			// 14
	};
	STATIC_ASSERT(sizeof(ExtraOutfitItem) == 0x18);
}
