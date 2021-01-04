#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraSound : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSound;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSound;

		virtual ~ExtraSound();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSound; }

		// members
		BSSoundHandle phandle;	// 10
		std::uint32_t pad1C;	// 1C
	};
	static_assert(sizeof(ExtraSound) == 0x20);
}
