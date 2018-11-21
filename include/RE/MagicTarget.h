#pragma once

#include "skse64/GameTypes.h"  // tList

#include "Offsets.h"

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/EffectSetting.h"  // EffectSetting::Properties::Archetype


namespace RE
{
	class Character;


	class MagicTarget
	{
	public:
		class ActiveEffectVisitor
		{
			virtual bool Accept(ActiveEffect* a_effect) = 0;
		};


		virtual ~MagicTarget();

		virtual void					Unk_01(void);					// 1
		virtual Actor*					GetMagicTargetActor() const;	// 2
		virtual bool					IsActorMagicTarget() const;		// 3
		virtual void					Unk_04(void);					// 4
		virtual void					Unk_05(void);					// 5
		virtual void					Unk_06(void);					// 6
		virtual tList<ActiveEffect>*	GetActiveEffects();				// 7
		virtual void					Unk_08(void);					// 8
		virtual void					Unk_09(void);					// 9
		virtual void					Unk_0A(void);					// A
		virtual void					Unk_0B(void);					// B

		bool							HasEffectWithArchetype(EffectSetting::Properties::Archetype a_type);
		void							DispellEffectsWithArchetype(EffectSetting::Properties::Archetype a_type, bool a_force);


		void*	unk04;	// 08
		void*	unk08;	// 10
	};
	STATIC_ASSERT(sizeof(MagicTarget) == 0x18);
}
