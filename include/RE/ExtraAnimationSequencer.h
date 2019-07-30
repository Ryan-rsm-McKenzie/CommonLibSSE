#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraAnimationSequencer

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraAnimationSequencer : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAnimationSequencer;


		enum { kExtraTypeID = ExtraDataType::kAnimationSequencer };


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


		virtual ~ExtraAnimationSequencer();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAnimationSequencer; }


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimationSequencer) == 0x18);
}
