#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSEncounterZone;

	class ExtraEncounterZone : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraEncounterZone;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kEncounterZone;

		virtual ~ExtraEncounterZone();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kEncounterZone; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return zone != a_rhs->zone; }

		// members
		BGSEncounterZone* zone;	 // 10
	};
	static_assert(sizeof(ExtraEncounterZone) == 0x18);
}
