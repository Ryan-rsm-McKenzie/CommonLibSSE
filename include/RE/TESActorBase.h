#pragma once

#include "skse64/GameFormComponents.h"  // TESSpellList, TESAIForm, TESFullName, BGSDestructibleObjectForm, BGSSkinForm, BGSKeywordForm, BGSAttackDataForm, BGSPerkRankArray

#include "RE/TESActorBaseData.h"  // TESActorBaseData
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESContainer.h"  // TESContainer
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
		virtual bool				Unk_54(void);
		virtual TESCombatStyle*		GetCombatStyle();
		virtual void				SetCombatStyle(TESCombatStyle* a_arg);
		virtual TESActorBase*		Unk_57(void);
	};
	STATIC_ASSERT(sizeof(TESActorBase) == 0x150);
}
