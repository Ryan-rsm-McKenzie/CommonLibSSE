#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


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
	STATIC_ASSERT(sizeof(ExtraLastFinishedSequence) == 0x18);
}
