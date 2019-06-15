#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharacterPointCollector

#include "RE/hkpAllCdPointCollector.h"  // hkpAllCdPointCollector


namespace RE
{
	class bhkCharacterPointCollector : public hkpAllCdPointCollector
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterPointCollector;


		virtual ~bhkCharacterPointCollector();							// 00

		// override (hkpAllCdPointCollector)
		virtual void	AddCdPoint(const hkpCdPoint& a_point) override;	// 01
		virtual void	Reset() override;								// 02


		// members
		UInt64	unk220;	// 220
		UInt64	unk228;	// 228
		UInt64	unk230;	// 230
		UInt64	unk238;	// 238
	};
	STATIC_ASSERT(sizeof(bhkCharacterPointCollector) == 0x240);
}
