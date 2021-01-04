#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESObjectREFR;

	class ExtraRandomTeleportMarker : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRandomTeleportMarker;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRandomTeleportMarker;

		virtual ~ExtraRandomTeleportMarker();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRandomTeleportMarker; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return marker != a_rhs->marker; }

		// members
		TESObjectREFR* marker;	// 10
	};
	static_assert(sizeof(ExtraRandomTeleportMarker) == 0x18);
}
