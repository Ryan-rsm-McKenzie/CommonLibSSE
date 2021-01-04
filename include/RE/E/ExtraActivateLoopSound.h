#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraActivateLoopSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraActivateLoopSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kActivateLoopSound;

		virtual ~ExtraActivateLoopSound();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kActivateLoopSound; }

		// members
		BSSoundHandle handle;  // 10
		std::uint32_t pad1C;   // 1C
	};
	static_assert(sizeof(ExtraActivateLoopSound) == 0x20);
}
