#pragma once

#include "RE/H/hkpAllCdPointCollector.h"

namespace RE
{
	class bhkCharacterPointCollector : public hkpAllCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharacterPointCollector;

		~bhkCharacterPointCollector() override;  // 00

		// override (hkpAllCdPointCollector)
		void AddCdPoint(const hkpCdPoint& a_point) override;  // 01
		void Reset() override;                                // 02

		// members
		std::uint64_t unk220;  // 220
		std::uint64_t unk228;  // 228
		std::uint64_t unk230;  // 230
		std::uint64_t unk238;  // 238
	};
	static_assert(sizeof(bhkCharacterPointCollector) == 0x240);
}
