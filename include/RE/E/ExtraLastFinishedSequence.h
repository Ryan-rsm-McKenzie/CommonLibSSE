#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSFixedString.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraLastFinishedSequence : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLastFinishedSequence;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLastFinishedSequence;

		virtual ~ExtraLastFinishedSequence();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLastFinishedSequence; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return lastSequenceName != a_rhs->lastSequenceName; }

		// members
		BSFixedString lastSequenceName;	 // 10
	};
	static_assert(sizeof(ExtraLastFinishedSequence) == 0x18);
}
