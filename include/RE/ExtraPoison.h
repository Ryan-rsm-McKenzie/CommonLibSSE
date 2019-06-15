#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPoison

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class AlchemyItem;


	class ExtraPoison : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPoison;


		enum { kExtraTypeID = ExtraDataType::kPoison };


		virtual ~ExtraPoison();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPoison; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return poison != a_rhs->poison || count != a_rhs->count; }


		// members
		AlchemyItem*	poison;		// 10
		UInt32			count;		// 18
		UInt32			pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(ExtraPoison) == 0x20);
}
