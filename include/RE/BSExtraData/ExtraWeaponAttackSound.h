#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


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
		UInt32		  pad1C;   // 1C
	};
	STATIC_ASSERT(sizeof(ExtraWeaponAttackSound) == 0x20);
}
