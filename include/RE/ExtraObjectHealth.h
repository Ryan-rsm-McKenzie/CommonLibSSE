#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraObjectHealth : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kObjectHealth };


		virtual ~ExtraObjectHealth();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kObjectHealth; }


		// members
		float	health;	// 10
		UInt32	pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraObjectHealth) == 0x18);
}
