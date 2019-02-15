#pragma once

#include "skse64/GameObjects.h"  // ActiveEffectReferenceEffectController

#include "RE/FormTypes.h"  // FormType


namespace RE
{
	struct Effect;


	class ActiveEffect
	{
	public:
		enum { kTypeID = FormType::ActiveMagicEffect };


		enum class Flag : UInt32
		{
			kInactive = 1 << 15,
			kDispelled = 1 << 18
		};


		// add
		virtual void	Unk_00(void);	// 00
		virtual void	Unk_01(void);	// 01
		virtual void	Unk_02(void);	// 02 - { return; }
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04 - { return; }
		virtual void	Unk_05(void);	// 05
		virtual void	Unk_06(void);	// 06 - { return 0; }
		virtual void	Unk_07(void);	// 07 - { return; }
		virtual void	Unk_08(void);	// 08
		virtual void	Unk_09(void);	// 09
		virtual void	Unk_0A(void);	// 0A
		virtual void	Unk_0B(void);	// 0B - { unk88 = 4; }
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D - { return; }
		virtual void	Unk_0E(void);	// 0E - { return; }
		virtual void	Unk_0F(void);	// 0F - { return; }
		virtual void	Unk_10(void);	// 10
		virtual void	Unk_11(void);	// 11 - { return 0; }
		virtual void	Unk_12(void);	// 12 - { return; }

		virtual ~ActiveEffect();		// 13

		virtual void	Unk_14(void);	// 14 - { return; }
		virtual void	Unk_15(void);	// 15 - { return; }
		virtual void	Unk_16(void);	// 16
		virtual void	Unk_17(void);	// 17 - { return 1; }
		virtual void	Unk_18(void);	// 18 - { return 1.0; }

		EffectSetting*	GetBaseObject() const;
		bool			Dispell(bool a_force);	// Returns success?


		ActiveEffectReferenceEffectController	controller;			// 08
		UInt32									unk18;				// 18
		float									unk1C;				// 1C
		float									unk20;				// 20
		float									unk24;				// 24
		UInt32									unk28;				// 28
		UInt8									unk2C;				// 2C
		UInt8									pad2D[3];			// 2D
		UInt32									unk30;				// 30
		UInt32									casterRefhandle;	// 34
		void*									niNode;				// 38
		MagicItem*								item;				// 40
		Effect*									effect;				// 48
		TESObjectREFR*							magicTarget;		// 50
		TESForm*								sourceItem;			// 58
		void*									unk60;				// 60
		void*									un68;				// 68
		float									elapsed;			// 70
		float									duration;			// 74
		float									magnitude;			// 78
		Flag									flags;				// 7C
		UInt32									unk80;				// 80
		UInt32									effectNum;			// 84 - Somekind of counter used to determine whether the ActiveMagicEffect handle is valid
		UInt32									unk88;				// 88
		UInt32									pad8C;				// 8C
	};
	STATIC_ASSERT(sizeof(ActiveEffect) == 0x90);
}
