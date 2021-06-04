#pragma once

namespace RE
{
	struct hkpCdPoint;

	class hkpCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCdPointCollector;

		virtual ~hkpCdPointCollector();  // 00

		// add
		virtual void AddCdPoint(const hkpCdPoint& a_point) = 0;  // 01
		virtual void Reset();                                    // 02 - { earlyOutDistance = 0x7F7FFFEE; }

		// members
		float         earlyOutDistance;  // 08
		std::uint32_t pad0C;             // 0C
	};
	static_assert(sizeof(hkpCdPointCollector) == 0x10);
}
