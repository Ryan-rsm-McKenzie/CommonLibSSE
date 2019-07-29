#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraEncounterZone

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // BGSEncounterZone


namespace RE
{
	class ExtraEncounterZone : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEncounterZone;


		enum { kExtraTypeID = ExtraDataType::kEncounterZone };


		virtual ~ExtraEncounterZone();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEncounterZone; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return encounterZone != a_rhs->encounterZone; }


		// members
		BGSEncounterZone* encounterZone;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEncounterZone) == 0x18);
}
