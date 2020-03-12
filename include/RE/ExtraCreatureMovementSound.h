#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSSoundHandle.h"
#include "RE/ExtraDataTypes.h"


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
