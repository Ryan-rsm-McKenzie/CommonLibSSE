#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/E/ExtraDataTypes.h"

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
	static_assert(sizeof(ExtraAnimationSequencer) == 0x18);
}
