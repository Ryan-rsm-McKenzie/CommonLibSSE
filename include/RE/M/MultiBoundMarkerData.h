#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class MultiBoundMarkerData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_MultiBoundMarkerData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMultiBoundMarkerData;

		~MultiBoundMarkerData() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { reutrn kMultiBoundMarkerData; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02

		// members
		NiPoint3      halfExtents;  // 10
		std::uint32_t pad1C;        // 1C
	};
	static_assert(sizeof(MultiBoundMarkerData) == 0x20);
}
