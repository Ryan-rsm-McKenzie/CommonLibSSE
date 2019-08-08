#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAttackData

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // SpellItem, BGSKeyword
#include "RE/NiRefObject.h"  // NiRefObject
#include "RE/NiSmartPointer.h"  // NiSmartPointer


namespace RE
{
	NiSmartPointer(BGSAttackData);


	class BGSAttackData : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_BGSAttackData;


		struct AttackData	// ATKD
		{
			enum class AttackFlag : UInt32
			{
				kNone = 0,
				kIgnoreWeapon = 1 << 0,
				kBashAttack = 1 << 1,
				kPowerAttack = 1 << 2,
				kLeftAttack = 1 << 3,
				kRotatingAttack = 1 << 4,
				kOverrideData = (UInt32)1 << 31
			};


			float		damageMult;		// 00
			float		attackChance;	// 04
			SpellItem*	attackSpell;	// 08
			AttackFlag	attackFlags;	// 10
			float		attackAngle;	// 14
			float		strikeAngle;	// 18
			float		stagger;		// 1C
			BGSKeyword*	attackType;		// 20
			float		knockDown;		// 28
			float		recoveryTime;	// 2C
			float		staminaMult;	// 30
			UInt32		pad34;			// 34
		};
		STATIC_ASSERT(sizeof(AttackData) == 0x38);


		virtual ~BGSAttackData();	// 00

		bool IsLeftAttack() const;


		// members
		BSFixedString	attackEvent;	// 10 - ATKE
		AttackData		attackData;		// 18 - ATKD
	};
	STATIC_ASSERT(sizeof(BGSAttackData) == 0x50);
}
