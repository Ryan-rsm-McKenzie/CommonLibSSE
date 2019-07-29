#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraReflectorRefs

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraReflectorRefs : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraReflectorRefs;


		enum { kExtraTypeID = ExtraDataType::kReflectorRefs };


		virtual ~ExtraReflectorRefs();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kReflectorRefs; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<UInt32> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraReflectorRefs) == 0x28);
}
