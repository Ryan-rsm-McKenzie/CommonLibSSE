#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class ExtraForcedLandingMarker : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraForcedLandingMarker;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kForcedLandingMarker;

		virtual ~ExtraForcedLandingMarker();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kForcedLandingMarker; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return landingMarker != a_rhs->landingMarker; }

		// members
		ObjectRefHandle landingMarker;	// 10
		std::uint32_t	pad14;			// 14
	};
	static_assert(sizeof(ExtraForcedLandingMarker) == 0x18);
}
