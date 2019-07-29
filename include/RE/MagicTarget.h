#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MagicTarget, RTTI_MagicTarget__ForEachActiveEffectVisitor

#include "RE/EffectSetting.h"  // EffectSetting::Data::Archetype
#include "RE/BSTList.h"  // BSSimpleList


namespace RE
{
	class Actor;
	class ActiveEffect;


	class MagicTarget
	{
	public:
		inline static const void* RTTI = RTTI_MagicTarget;


		using Archetype = EffectSetting::Data::Archetype;


		class ForEachActiveEffectVisitor
		{
		public:
			inline static const void* RTTI = RTTI_MagicTarget__ForEachActiveEffectVisitor;


			virtual ~ForEachActiveEffectVisitor();				// 00

			// add
			virtual bool Accept(ActiveEffect* a_effect) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(ForEachActiveEffectVisitor) == 0x8);


		virtual ~MagicTarget();													// 00

		// add
		virtual void							Unk_01(void);					// 01
		virtual Actor*							GetMagicTargetActor() const;	// 02 - { return 0; }
		virtual bool							IsActorMagicTarget() const;		// 03 - { return false; }
		virtual void							Unk_04(void);					// 04 - { return 0; }
		virtual void							Unk_05(void);					// 05 - { return; }
		virtual void							Unk_06(void) = 0;				// 06
		virtual BSSimpleList<ActiveEffect*>*	GetActiveEffects() = 0;			// 07
		virtual void							Unk_08(void);					// 08 - { return; }
		virtual void							Unk_09(void);					// 09 - { return; }
		virtual void							Unk_0A(void);					// 0A - { return 1.0; }
		virtual void							Unk_0B(void);					// 0B - { return 0; }

		bool									HasMagicEffect(EffectSetting* a_effect);
		bool									HasEffectWithArchetype(Archetype a_type);
		void									DispellEffectsWithArchetype(Archetype a_type, bool a_force);


		// members
		UInt64	unk04;	// 08
		UInt64	unk08;	// 10
	};
	STATIC_ASSERT(sizeof(MagicTarget) == 0x18);
}
