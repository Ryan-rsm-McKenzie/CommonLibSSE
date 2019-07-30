#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraBiped

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	struct Biped;


	class ExtraBiped : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraBiped;


		enum { kExtraTypeID = ExtraDataType::kBiped };


		virtual ~ExtraBiped();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kBiped; }


		// members
		Biped* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraBiped) == 0x18);
}
