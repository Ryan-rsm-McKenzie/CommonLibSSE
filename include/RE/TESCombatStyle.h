#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESCombatStyle

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESCombatStyle : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESCombatStyle;


		enum { kTypeID = FormType::CombatStyle };


		enum class Flag : UInt32	// DATA
		{
			kNone = 0,
			kDueling = 1 << 0,
			kFlanking = 1 << 1,
			kAllowDualWielding = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kAllowDualWielding = 1 << 19
			};
		};


		struct General	// CSGD
		{
			struct EquipmentScoreMult
			{
				float	melee;		// 00
				float	magic;		// 04
				float	ranged;		// 08
				float	shout;		// 0C
				float	unarmed;	// 10
				float	staff;		// 14
			};
			STATIC_ASSERT(sizeof(EquipmentScoreMult) == 0x18);


			float				offensiveMult;		// 00
			float				defensiveMult;		// 04
			float				groupOffensiveMult;	// 08
			EquipmentScoreMult	equipmentScoreMult;	// 0C
			float				avoidThreatChance;	// 24
		};
		STATIC_ASSERT(sizeof(General) == 0x28);


		struct Melee	// CSME
		{
			float	attackStaggeredMult;		// 00
			float	powerAttackStaggeredMult;	// 04
			float	powerAttackBlockingMult;	// 08
			float	bashMult;					// 0C
			float	bashRecoilMult;				// 10
			float	bashAttackMult;				// 14
			float	bashPowerAttackMult;		// 18
			float	specialAttackMult;			// 1C
		};
		STATIC_ASSERT(sizeof(Melee) == 0x20);


		struct CloseRange	// CSCR
		{
			float	circleMult;		// 00
			float	fallbackMult;	// 04
			float	flankDistance;	// 08
			float	stalkTime;		// 0C
		};
		STATIC_ASSERT(sizeof(CloseRange) == 0x10);


		struct LongRange	// CSLR
		{
			float strafeMult;	// 0
		};
		STATIC_ASSERT(sizeof(LongRange) == 0x4);


		struct Flight	// CSFL
		{
			float	hoverChance;		// 00
			float	diveBombChance;		// 04
			float	groundAttackChance;	// 08
			float	hoverTime;			// 0C
			float	groundAttackTime;	// 10
			float	perchAttackChance;	// 14
			float	perchAttackTime;	// 18
			float	flyingAttackChance;	// 1C
		};
		STATIC_ASSERT(sizeof(Flight) == 0x20);


		virtual ~TESCombatStyle();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		General		general;	// 20 - CSGD
		Melee		melee;		// 48 - CSME
		CloseRange	closeRange;	// 68 - CSCR
		LongRange	longRange;	// 78 - CSLR
		Flight		flight;		// 7C - CSFL
		Flag		flags;		// 9C - DATA
	};
	STATIC_ASSERT(sizeof(TESCombatStyle) == 0xA0);
}
