#pragma once

#include "RE/BSExtraData/Components/BGSLoadGameSubBuffer.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
