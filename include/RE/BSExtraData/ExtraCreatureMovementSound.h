#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSAudio/BSSoundHandle.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraCreatureMovementSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCreatureMovementSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCreatureMovementSound;


		virtual ~ExtraCreatureMovementSound();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kCreatureMovementSound; }


		// members
		BSSoundHandle handle;  // 10
		UInt32		  pad1C;   // 1C
	};
	STATIC_ASSERT(sizeof(ExtraCreatureMovementSound) == 0x20);
}
