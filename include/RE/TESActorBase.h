#pragma once

#include "skse64/GameFormComponents.h"  // TESSpellList, BGSDestructibleObjectForm, BGSSkinForm, BGSAttackDataForm, BGSPerkRankArray

#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/TESActorBaseData.h"  // TESActorBaseData
#include "RE/TESAIForm.h"  // TESAIForm
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESContainer.h"  // TESContainer
#include "RE/TESFullName.h"  // TESFullName
#include "RE/ActorValueOwner.h"  // ActorValueOwner

class TESCombatStyle;


namespace RE
{
	class TESActorBase :
		public TESBoundAnimObject,			// 000
		public TESActorBaseData,			// 030
		public TESContainer,				// 088
		public TESSpellList,				// 0A0
		public TESAIForm,					// 0B0
		public TESFullName,					// 0D8
		public ActorValueOwner,				// 0E8
		public BGSDestructibleObjectForm,	// 0F0
		public BGSSkinForm,					// 100
		public BGSKeywordForm,				// 110
		public BGSAttackDataForm,			// 128
		public BGSPerkRankArray				// 138
	{
	public:
		// add
		virtual void			Unk_54(void);							// 54
		virtual TESCombatStyle*	GetCombatStyle();						// 55
		virtual void			SetCombatStyle(TESCombatStyle* a_arg);	// 56
		virtual void			Unk_57(void);							// 57
	};
	STATIC_ASSERT(sizeof(TESActorBase) == 0x150);
}
