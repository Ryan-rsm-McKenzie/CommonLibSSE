#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraOutfitItem : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOutfitItem;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOutfitItem;


		virtual ~ExtraOutfitItem();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kOutfitItem; }


		// members
		FormID id;	   // 10 - BGSOutfit
		UInt32 pad14;  // 14
	};
	STATIC_ASSERT(sizeof(ExtraOutfitItem) == 0x18);
}
