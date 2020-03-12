#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/BSTHashMap.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSAnimationSequencer;


	class ExtraAnimationSequencer : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAnimationSequencer;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAnimationSequencer;


		virtual ~ExtraAnimationSequencer();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAnimationSequencer; }


		// members
		BGSAnimationSequencer* sequencer;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimationSequencer) == 0x18);
}
