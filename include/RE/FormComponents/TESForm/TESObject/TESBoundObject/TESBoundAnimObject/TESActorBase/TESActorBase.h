#pragma once

#include "RE/ActorValueOwner.h"
#include "RE/BGSAttackDataForm.h"
#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSPerkRankArray.h"
#include "RE/BGSSkinForm.h"
#include "RE/FormTypes.h"
#include "RE/TESAIForm.h"
#include "RE/TESActorBaseData.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESContainer.h"
#include "RE/TESFullName.h"
#include "RE/TESSpellList.h"


namespace RE
{
	class TESActorBase :
		public TESBoundAnimObject,		   // 000
		public TESActorBaseData,		   // 030
		public TESContainer,			   // 088
		public TESSpellList,			   // 0A0
		public TESAIForm,				   // 0B0
		public TESFullName,				   // 0D8
		public ActorValueOwner,			   // 0E8
		public BGSDestructibleObjectForm,  // 0F0
		public BGSSkinForm,				   // 100
		public BGSKeywordForm,			   // 110
		public BGSAttackDataForm,		   // 128
		public BGSPerkRankArray			   // 138
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESActorBase;


		virtual ~TESActorBase();  // 00

		// override (TESBoundAnimObject)
		virtual bool AddChange(UInt32 a_changeFlags) override;	   // 0A
		virtual void RemoveChange(UInt32 a_changeFlags) override;  // 0B
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual bool IsAutoCalc() const override;				   // 3E - { return formType == FormType::NPC && (TESActorBaseData::flags >> 4) & 1; }
		virtual void SetAutoCalc(bool a_autoCalc) override;		   // 3F

		// override (TESAIForm)
		virtual float GetActorValue(ActorValue a_akValue) override;														 // 01
		virtual float GetPermanentActorValue(ActorValue a_akValue) override;											 // 02
		virtual float GetBaseActorValue(ActorValue a_akValue) override;													 // 03
		virtual void  SetBaseActorValue(ActorValue a_akValue, float a_value) override;									 // 04
		virtual void  ModActorValue(ActorValue a_akValue, float a_value) override;										 // 05
		virtual void  RestoreActorValue(ACTOR_VALUE_MODIFIER a_modifier, ActorValue a_akValue, float a_value) override;	 // 06
		virtual void  SetActorValue(ActorValue a_akValue, float a_value) override;										 // 07
		virtual bool  GetIsPlayerOwner() const override;																 // 08

		// add
		virtual bool			GetHasPLSpecTex() const;						// 53 - { return false; }
		virtual TESCombatStyle* GetCombatStyle();								// 54 - { return 0; }
		virtual void			SetCombatStyle(TESCombatStyle* a_combatStyle);	// 55 - { return; }
		virtual TESForm*		GetAsForm();									// 56 - { return this; }
	};
	STATIC_ASSERT(sizeof(TESActorBase) == 0x150);
}
