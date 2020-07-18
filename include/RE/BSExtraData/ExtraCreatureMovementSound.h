#pragma once

#include "RE/BSAudio/BSSoundHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
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
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraCreatureMovementSound) == 0x20);
}
