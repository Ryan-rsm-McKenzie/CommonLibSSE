#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESActorBase

#include "RE/ActorValueOwner.h"  // ActorValueOwner
#include "RE/BGSAttackDataForm.h"  // BGSAttackDataForm
#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSPerkRankArray.h"  // BGSPerkRankArray
#include "RE/BGSSkinForm.h"  // BGSSkinForm
#include "RE/FormTypes.h"  // TESCombatStyle
#include "RE/TESActorBaseData.h"  // TESActorBaseData
#include "RE/TESAIForm.h"  // TESAIForm
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESContainer.h"  // TESContainer
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESSpellList.h"  // TESSpellList


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
		inline static const void* RTTI = RTTI_TESActorBase;


		virtual ~TESActorBase();												// 00

		// override (TESBoundAnimObject)
		virtual bool			MarkChanged(UInt32 a_changeFlags) override;		// 0A
		virtual void			UnMarkChanged(UInt32 a_changeFlags) override;	// 0B
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual bool			IsAutoCalc() const override;					// 3E - { return formType == FormType::NPC && (TESActorBaseData::flags >> 4) & 1; }
		virtual void			Unk_3F(void) override;							// 3F


		// add
		virtual void			Unk_53(void);									// 53 - { return 0; }
		virtual TESCombatStyle*	GetCombatStyle();								// 54 - { return 0; }
		virtual void			SetCombatStyle(TESCombatStyle* a_combatStyle);	// 55 - { return; }
		virtual void			Unk_56(void);									// 56 - { return this; }
	};
	STATIC_ASSERT(sizeof(TESActorBase) == 0x150);
}
