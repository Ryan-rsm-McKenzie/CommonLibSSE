#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPackageStartLocation

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPackageStartLocation : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPackageStartLocation;


		enum { kExtraTypeID = ExtraDataType::kPackageStartLocation };


		virtual ~ExtraPackageStartLocation();											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPackageStartLocation; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraPackageStartLocation) == 0x28);
}
