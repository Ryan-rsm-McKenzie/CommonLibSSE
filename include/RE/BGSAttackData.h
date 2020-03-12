#pragma once

#include "RE/BSFixedString.h"
#include "RE/FormTypes.h"
#include "RE/NiRefObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	struct AttackData  // ATKD
	{
		enum class AttackFlag : UInt32
		{
			kNone = 0,
			kIgnoreWeapon = 1 << 0,
			kBashAttack = 1 << 1,
			kPowerAttack = 1 << 2,
			kChargeAttack = 1 << 3,
			kRotatingAttack = 1 << 4,
			kContinuousAttack = 1 << 5,
			kOverrideData = (UInt32)1 << 31
		};


		float		damageMult;		// 00
		float		attackChance;	// 04
		SpellItem*	attackSpell;	// 08
		AttackFlag	flags;			// 10
		float		attackAngle;	// 14
		float		strikeAngle;	// 18
		float		staggerOffset;	// 1C
		BGSKeyword* attackType;		// 20
		float		knockDown;		// 28
		float		recoveryTime;	// 2C
		float		staminaMult;	// 30
		UInt32		pad34;			// 34
	};
	STATIC_ASSERT(sizeof(AttackData) == 0x38);


	NiSmartPointer(BGSAttackData);


	class BGSAttackData : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAttackData;


		virtual ~BGSAttackData();  // 00

		bool IsLeftAttack() const;


		// members
		BSFixedString event;  // 10 - ATKE
		AttackData	  data;	  // 18 - ATKD
	};
	STATIC_ASSERT(sizeof(BGSAttackData) == 0x50);
}
