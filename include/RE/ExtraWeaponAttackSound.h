#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraWeaponAttackSound

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraWeaponAttackSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWeaponAttackSound;


		enum { kExtraTypeID = ExtraDataType::kWeaponAttackSound };


		virtual ~ExtraWeaponAttackSound();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kWeaponAttackSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraWeaponAttackSound) == 0x20);
}
