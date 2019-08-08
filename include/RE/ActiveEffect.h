#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActiveEffect

#include "RE/ActiveEffectReferenceEffectController.h"  // ActiveEffectReferenceEffectController
#include "RE/FormTypes.h"  // MagicItem
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class MagicItem;
	class MagicTarget;
	class NiRefObject;
	struct Effect;


	class ActiveEffect
	{
	public:
		inline static const void* RTTI = RTTI_ActiveEffect;


		enum class Flag : UInt32
		{
			kHasConditions = 1 << 7,
			kRecovers = 1 << 9,
			kInactive = 1 << 15,
			kDispelled = 1 << 18
		};


		// add
		virtual void	Unk_00(void);			// 00
		virtual void	Unk_01(void);			// 01
		virtual void	Unk_02(void);			// 02 - { return; }
		virtual Actor*	GetMagicTargetActor();	// 03 - { return magicTarget ? magicTarget->GetMagicTargetActor() : 0; }
		virtual void	Unk_04(void);			// 04 - { return; }
		virtual void	Unk_05(void);			// 05
		virtual void	Unk_06(void);			// 06 - { return 0; }
		virtual void	Unk_07(void);			// 07 - { return; }
		virtual void	Unk_08(void);			// 08
		virtual void	Unk_09(void);			// 09
		virtual void	Unk_0A(void);			// 0A
		virtual void	Unk_0B(void);			// 0B - { unk88 = 4; }
		virtual void	Unk_0C(void);			// 0C
		virtual void	Unk_0D(void);			// 0D - { return; }
		virtual void	Unk_0E(void);			// 0E - { return; }
		virtual void	Unk_0F(void);			// 0F - { return; }
		virtual void	Unk_10(void);			// 10
		virtual void	Unk_11(void);			// 11 - { return 0; }
		virtual void	Unk_12(void);			// 12 - { return; }

		virtual ~ActiveEffect();				// 13

		virtual void	Unk_14(void);			// 14 - { return; }
		virtual void	Unk_15(void);			// 15 - { return; }
		virtual void	Unk_16(void);			// 16
		virtual void	Unk_17(void);			// 17 - { return 1; }
		virtual void	Unk_18(void);			// 18 - { return 1.0; }

		void					Dispell(bool a_force);
		EffectSetting*			GetBaseObject();
		const EffectSetting*	GetBaseObject() const;
		Actor*					GetCasterActor();
		const Actor*			GetCasterActor() const;
		Actor*					GetTargetActor();
		const Actor*			GetTargetActor() const;


		ActiveEffectReferenceEffectController	controller;		// 08
		UInt32									unk28;			// 28
		UInt8									unk2C;			// 2C
		UInt8									pad2D;			// 2D
		UInt16									pad2E;			// 2E
		UInt32									unk30;			// 30
		RefHandle								casterActor;	// 34
		NiPointer<NiRefObject>					node;			// 38
		MagicItem*								item;			// 40
		Effect*									effect;			// 48
		MagicTarget*							magicTarget;	// 50
		TESForm*								sourceItem;		// 58
		void*									unk60;			// 60
		void*									unk68;			// 68
		float									elapsed;		// 70
		float									duration;		// 74
		float									magnitude;		// 78
		Flag									flags;			// 7C
		UInt32									unk80;			// 80
		UInt16									handle;			// 84
		UInt16									unk86;			// 86
		UInt32									unk88;			// 88
		UInt32									pad8C;			// 8C
	};
	STATIC_ASSERT(sizeof(ActiveEffect) == 0x90);
}
