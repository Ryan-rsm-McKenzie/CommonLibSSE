#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSTList.h"


namespace RE
{
	class TESFaction;


	class TESReactionForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESReactionForm;


		struct Relation	// XNAM
		{
			enum class GroupCombatReaction : UInt32
			{
				kNeutral = 0,
				kEnemy = 1,
				kAlly = 2,
				kFriend = 3
			};


			TESFaction*				faction;				// 00
			UInt32					modifier;				// 08
			GroupCombatReaction		groupCombatReaction;	// 0C
		};
		STATIC_ASSERT(sizeof(Relation) == 0x10);


		virtual ~TESReactionForm();											// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01
		virtual void	ClearDataComponent() override;						// 02
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		BSSimpleList<Relation*>	relations;	// 08
		UInt8					unk18;		// 18
		UInt8					pad19;		// 19
		UInt16					pad1A;		// 1A
		UInt32					pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(TESReactionForm) == 0x20);
}
