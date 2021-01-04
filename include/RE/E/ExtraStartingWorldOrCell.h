#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESForm;

	class ExtraStartingWorldOrCell : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraStartingWorldOrCell;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kStartingWorldOrCell;

		virtual ~ExtraStartingWorldOrCell();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kStartingWorldOrCell; }

		// members
		TESForm* startingWorldOrCell;  // 10
	};
	static_assert(sizeof(ExtraStartingWorldOrCell) == 0x18);
}
