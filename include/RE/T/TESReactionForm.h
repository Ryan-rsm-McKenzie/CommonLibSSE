#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/F/FightReactions.h"
#include "RE/F/FormTypes.h"

namespace RE
{
	struct GROUP_REACTION  // XNAM
	{
		TESForm*       form;           // 00
		std::int32_t   reaction;       // 08
		FIGHT_REACTION fightReaction;  // 0C
	};
	static_assert(sizeof(GROUP_REACTION) == 0x10);

	class TESReactionForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESReactionForm;

		~TESReactionForm() override;  // 00

		// override (BaseFormComponent)
		void InitializeDataComponent() override;                // 01
		void ClearDataComponent() override;                     // 02
		void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		BSSimpleList<GROUP_REACTION*>            reactions;      // 08 - XNAM
		stl::enumeration<FormType, std::uint8_t> groupFormType;  // 18
		std::uint8_t                             pad19;          // 19
		std::uint16_t                            pad1A;          // 1A
		std::uint32_t                            pad1C;          // 1C
	};
	static_assert(sizeof(TESReactionForm) == 0x20);
}
