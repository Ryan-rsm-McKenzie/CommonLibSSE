#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraRagDollData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraRagDollData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRagDollData;


		enum { kExtraTypeID = ExtraDataType::kRagDollData };


		struct Data
		{
			UInt8	unk00;	// 00
			UInt8	pad01;	// 01
			UInt16	pad02;	// 02
			UInt32	pad04;	// 04
			void*	unk08;	// 08 - length == unk00 * 0x1C
			float	unk10;	// 10
			float	unk14;	// 14
			float	unk18;	// 18
			UInt32	pad1C;	// 1C
		};
		STATIC_ASSERT(sizeof(Data) == 0x20);


		virtual ~ExtraRagDollData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kRagDollData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRagDollData) == 0x18);
}
