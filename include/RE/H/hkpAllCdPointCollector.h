#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkpCdPointCollector.h"
#include "RE/H/hkpRootCdPoint.h"

namespace RE
{
	class hkpAllCdPointCollector : public hkpCdPointCollector
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpAllCdPointCollector;

		virtual ~hkpAllCdPointCollector();	// 00

		// override (hkpCdPointCollector)
		virtual void AddCdPoint(const hkpCdPoint& a_point) override;  // 01
		virtual void Reset() override;								  // 02 - { hits.size = 0; earlyOutDistance = 0x7F7FFFEE; }

		// members
		hkInplaceArray<hkpRootCdPoint, 8> hits;	 // 010
	};
	static_assert(sizeof(hkpAllCdPointCollector) == 0x220);
}
