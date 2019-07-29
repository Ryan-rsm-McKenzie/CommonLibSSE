#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraTresPassPackage

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class TESForm;


	class ExtraTresPassPackage : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraTresPassPackage;


		enum { kExtraTypeID = ExtraDataType::kTresPassPackage };


		virtual ~ExtraTresPassPackage();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kTresPassPackage; }


		// members
		TESForm*	unk10;	// 10
		UInt64		unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraTresPassPackage) == 0x20);
}
