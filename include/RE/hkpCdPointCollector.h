#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCdPointCollector


namespace RE
{
	struct hkpCdPoint;


	class hkpCdPointCollector
	{
	public:
		inline static const void* RTTI = RTTI_hkpCdPointCollector;


		virtual ~hkpCdPointCollector();								// 00

		// add
		virtual void	AddCdPoint(const hkpCdPoint& a_point) = 0;	// 01
		virtual void	Reset();									// 02 - { earlyOutDistance = 0x7F7FFFEE; }


		// members
		float	earlyOutDistance;	// 08
		float	pad0C;				// 0C
	};
	STATIC_ASSERT(sizeof(hkpCdPointCollector) == 0x10);
}
