#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TrespassPackage;

	class ExtraTresPassPackage : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTresPassPackage;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTresPassPackage;

		virtual ~ExtraTresPassPackage();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kTresPassPackage; }

		// members
		TrespassPackage* pack;	 // 10
		std::uint64_t	 unk18;	 // 18
	};
	static_assert(sizeof(ExtraTresPassPackage) == 0x20);
}
