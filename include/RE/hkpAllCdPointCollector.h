#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpAllCdPointCollector

#include "RE/hkArray.h"  // hkInplaceArray
#include "RE/hkpCdPointCollector.h"  // hkpCdPointCollector
#include "RE/hkpRootCdPoint.h"  // hkpRootCdPoint


namespace RE
{
	class hkpAllCdPointCollector : public hkpCdPointCollector
	{
	public:
		inline static const void* RTTI = RTTI_hkpAllCdPointCollector;


		virtual ~hkpAllCdPointCollector();								// 00

		// override (hkpCdPointCollector)
		virtual void	AddCdPoint(const hkpCdPoint& a_point) override;	// 01
		virtual void	Reset() override;								// 02 - { hits.size = 0; earlyOutDistance = 0x7F7FFFEE; }


		// members
		hkInplaceArray<hkpRootCdPoint, 8> hits;	// 010
	};
	STATIC_ASSERT(sizeof(hkpAllCdPointCollector) == 0x220);
}
