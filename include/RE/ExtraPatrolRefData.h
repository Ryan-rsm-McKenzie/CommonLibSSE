#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPatrolRefData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPatrolRefData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPatrolRefData;


		enum { kExtraTypeID = ExtraDataType::kPatrolRefData };


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(Data) == 0x28);


		virtual ~ExtraPatrolRefData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPatrolRefData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPatrolRefData) == 0x18);
}
