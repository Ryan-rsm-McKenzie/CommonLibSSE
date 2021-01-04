#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	class TESActorBase;

	class ExtraLeveledCreature : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLeveledCreature;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLeveledCreature;

		virtual ~ExtraLeveledCreature();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLeveledCreature; }

		// members
		TESActorBase* originalBase;	 // 10
		TESActorBase* templateBase;	 // 18
	};
	static_assert(sizeof(ExtraLeveledCreature) == 0x20);
}
