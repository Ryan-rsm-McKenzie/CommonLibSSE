#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRoomRefData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRoomRefData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRoomRefData;


		enum { kExtraTypeID = ExtraDataType::kRoomRefData };


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
			UInt64	unk28;	// 28
			UInt64	unk30;	// 30
		};
		STATIC_ASSERT(sizeof(Data) == 0x38);


		virtual ~ExtraRoomRefData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kRoomRefData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRoomRefData) == 0x18);
}
