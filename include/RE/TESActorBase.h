#pragma once

#include "RE/ActorValueOwner.h"
#include "RE/BGSAttackDataForm.h"
#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSPerkRankArray.h"
#include "RE/BGSSkinForm.h"
#include "RE/FormTypes.h"
#include "RE/TESActorBaseData.h"
#include "RE/TESAIForm.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESContainer.h"
#include "RE/TESFullName.h"
#include "RE/TESSpellList.h"


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
