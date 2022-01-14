#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraHealth : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraHealth;
		inline static constexpr auto VTABLE = VTABLE_ExtraHealth;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kHealth;

		ExtraHealth();
		explicit ExtraHealth(float a_health);
		~ExtraHealth() override = default;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kHealth; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return health != a_rhs->health; }

		// members
		float         health;  // 10
		std::uint32_t pad14;   // 14
	};
	static_assert(sizeof(ExtraHealth) == 0x18);
}
