#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/EffectArchetypes.h"


namespace RE
{
	class Actor;
	class ActiveEffect;
	class EffectItem;
	class EffectSetting;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;


	class MagicTarget
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicTarget;


		using Archetype = EffectArchetypes::ArchetypeID;


		class ForEachActiveEffectVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_MagicTarget__ForEachActiveEffectVisitor;


			virtual ~ForEachActiveEffectVisitor();	// 00

			// add
			virtual bool Accept(ActiveEffect* a_effect) = 0;  // 01
		};
		STATIC_ASSERT(sizeof(ForEachActiveEffectVisitor) == 0x8);


		struct SpellDispelData
		{
			MagicItem*					  spell;		 // 00
			BSPointerHandle<Actor>		  caster;		 // 08
			UInt32						  pad0C;		 // 0C
			BSTSmartPointer<ActiveEffect> activeEffect;	 // 10
			SpellDispelData*			  next;			 // 18
		};
		STATIC_ASSERT(sizeof(SpellDispelData) == 0x20);


		virtual ~MagicTarget();	 // 00

		// add
		virtual void						 Unk_01(void);																			   // 01
		virtual TESObjectREFR*				 GetTargetStatsObject();																   // 02 - { return false; }
		virtual bool						 MagicTargetIsActor() const;															   // 03 - { return false; }
		virtual bool						 IsInvulnerable();																		   // 04 - { return false; }
		virtual void						 InvalidateCommandedActorEffect(ActiveEffect* a_effect);								   // 05 - { return; }
		virtual bool						 CanAddActiveEffect() = 0;																   // 06
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() = 0;																   // 07
		virtual void						 Unk_08(void);																			   // 08 - { return; }
		virtual void						 Unk_09(void);																			   // 09 - { return; }
		virtual void						 CheckResistance(MagicItem* a_magicItem, EffectItem* a_effect, TESBoundObject* a_object);  // 0A - { return 1.0; }
		virtual void						 CheckAbsorb(Actor* a_actor, MagicItem* a_magicItem, const EffectItem* a_effect);		   // 0B - { return false; }

		void DispellEffectsWithArchetype(Archetype a_type, bool a_force);
		bool HasEffectWithArchetype(Archetype a_type);
		bool HasMagicEffect(EffectSetting* a_effect);


		// members
		SpellDispelData* postUpdateDispelList;	// 08
		UInt8			 flags;					// 10
		UInt8			 pad11;					// 11
		UInt16			 pad12;					// 12
		UInt32			 pad14;					// 14
	};
	STATIC_ASSERT(sizeof(MagicTarget) == 0x18);
}
