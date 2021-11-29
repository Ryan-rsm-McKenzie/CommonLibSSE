#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class TESTexture1024 : public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESTexture1024;

		~TESTexture1024() override;  // 00

		// override (TESTexture)
		std::uint32_t GetMaxAllowedSize() override;  // 04 - { return 1024; }
	};
	static_assert(sizeof(TESTexture1024) == 0x10);
}
