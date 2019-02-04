#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHealth : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kHealth };


		virtual ~ExtraHealth();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kHealth; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return health != a_rhs->health; }


		// members
		float	health;	// 10
		float	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHealth) == 0x18);
}
