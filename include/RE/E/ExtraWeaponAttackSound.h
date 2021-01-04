#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraWeaponAttackSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWeaponAttackSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWeaponAttackSound;

		virtual ~ExtraWeaponAttackSound();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kWeaponAttackSound; }

		// members
		BSSoundHandle handle;  // 10
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraWeaponAttackSound) == 0x20);
}
