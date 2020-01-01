#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSTList.h"
#include "RE/FormTypes.h"


namespace RE
{
	enum FIGHT_REACTION : UInt32
	{
		kNeutral = 0,
		kEnemy = 1,
		kAlly = 2,
		kFriend = 3
	};


	struct GROUP_REACTION	// XNAM
	{
		TESForm*		form;			// 00
		SInt32			reaction;		// 08
		FIGHT_REACTION	fightReaction;	// 0C
	};
	STATIC_ASSERT(sizeof(GROUP_REACTION) == 0x10);


	class TESReactionForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESReactionForm;


		virtual ~TESReactionForm();											// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		BSSimpleList<GROUP_REACTION*>	reactions;		// 08 - XNAM
		FormType						groupFormType;	// 18
		UInt8							pad19;			// 19
		UInt16							pad1A;			// 1A
		UInt32							pad1C;			// 1C
	};
	STATIC_ASSERT(sizeof(TESReactionForm) == 0x20);
}
