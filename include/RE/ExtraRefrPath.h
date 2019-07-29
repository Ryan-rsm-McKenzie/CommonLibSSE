#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRefrPath

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRefrPath : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRefrPath;


		enum { kExtraTypeID = ExtraDataType::kRefrPath };


		virtual ~ExtraRefrPath();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRefrPath; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
	};
	STATIC_ASSERT(sizeof(ExtraRefrPath) == 0x68);
}
