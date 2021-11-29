#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSMusicType;

	class ExtraCellMusicType : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraCellMusicType;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kCellMusicType;

		~ExtraCellMusicType() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kCellMusicType; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return type != a_rhs->type; }

		// members
		BGSMusicType* type;  // 10
	};
	static_assert(sizeof(ExtraCellMusicType) == 0x18);
}
