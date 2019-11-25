#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSavedAnimation : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSavedAnimation;


		enum { kExtraTypeID = ExtraDataType::kSavedAnimation };


		virtual ~ExtraSavedAnimation();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSavedAnimation; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraSavedAnimation) == 0x18);
}
