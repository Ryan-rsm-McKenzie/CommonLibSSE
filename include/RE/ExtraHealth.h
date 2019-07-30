#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHealth

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHealth : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHealth;


		enum { kExtraTypeID = ExtraDataType::kHealth };


		ExtraHealth();
		ExtraHealth(float a_health);
		virtual ~ExtraHealth() = default;												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kHealth; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return health != a_rhs->health; }


		// members
		float	health;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHealth) == 0x18);
}
