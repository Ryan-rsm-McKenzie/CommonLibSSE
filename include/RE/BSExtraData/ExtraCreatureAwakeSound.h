#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCreatureAwakeSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCreatureAwakeSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCreatureAwakeSound;


		virtual ~ExtraCreatureAwakeSound();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kCreatureAwakeSound; }


		// members
		BSSoundHandle handle;  // 10
		UInt32		  pad1C;   // 1C
	};
	STATIC_ASSERT(sizeof(ExtraCreatureAwakeSound) == 0x20);
}
