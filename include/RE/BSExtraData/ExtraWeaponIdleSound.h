#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


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
		UInt32		  pad1C;   // 1C
	};
	STATIC_ASSERT(sizeof(ExtraWeaponIdleSound) == 0x20);
}
