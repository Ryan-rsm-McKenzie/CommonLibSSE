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

		~ExtraEncounterZone() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kEncounterZone; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return zone != a_rhs->zone; }

		// members
		BGSEncounterZone* zone;  // 10
	};
	static_assert(sizeof(ExtraEncounterZone) == 0x18);
}
