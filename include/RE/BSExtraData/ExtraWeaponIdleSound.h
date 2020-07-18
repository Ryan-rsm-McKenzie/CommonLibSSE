#pragma once

#include "RE/BSAudio/BSSoundHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraWeaponIdleSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraWeaponIdleSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kWeaponIdleSound;


		virtual ~ExtraWeaponIdleSound();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kWeaponIdleSound; }


		// members
		BSSoundHandle handle;  // 10
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraWeaponIdleSound) == 0x20);
}
