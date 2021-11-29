#pragma once

#include "RE/H/hkpCharacterProxy.h"

namespace RE
{
	class ahkpCharacterProxy : public hkpCharacterProxy
	{
	public:
		inline static constexpr auto RTTI = RTTI_ahkpCharacterProxy;

		~ahkpCharacterProxy() override;  // 00

		// members
		std::uint64_t unk0F0;  // 0F0
		std::uint64_t unk0F8;  // 0F8
	};
	static_assert(sizeof(ahkpCharacterProxy) == 0x100);
}
