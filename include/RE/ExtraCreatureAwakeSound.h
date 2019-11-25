#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCreatureAwakeSound : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCreatureAwakeSound;


		enum { kExtraTypeID = ExtraDataType::kCreatureAwakeSound };


		virtual ~ExtraCreatureAwakeSound();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCreatureAwakeSound; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraCreatureAwakeSound) == 0x20);
}
