#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraOcclusionPlaneRefData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraOcclusionPlaneRefData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOcclusionPlaneRefData;


		enum { kExtraTypeID = ExtraDataType::kOcclusionPlaneRefData };


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~ExtraOcclusionPlaneRefData();											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kOcclusionPlaneRefData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOcclusionPlaneRefData) == 0x18);
}
