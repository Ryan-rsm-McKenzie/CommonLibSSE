#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPackage

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPackage : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPackage;


		enum { kExtraTypeID = ExtraDataType::kPackage };


		virtual ~ExtraPackage();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPackage; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(ExtraPackage) == 0x28);
}
