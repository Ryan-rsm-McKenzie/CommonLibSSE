#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWeaponIdleSound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWeaponIdleSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWeaponIdleSound;


		enum { kExtraTypeID = ExtraDataType::kWeaponIdleSound };


		virtual ~ExtraWeaponIdleSound();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kWeaponIdleSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraWeaponIdleSound) == 0x20);
}
