#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"


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
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraCreatureAwakeSound) == 0x20);
}