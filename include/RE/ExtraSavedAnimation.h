#pragma once

#include "RE/BGSLoadGameSubBuffer.h"
#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSavedAnimation : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSavedAnimation;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSavedAnimation;


		virtual ~ExtraSavedAnimation();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSavedAnimation; }


		// members
		BGSLoadGameSubBuffer animationBuffer;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraSavedAnimation) == 0x18);
}
