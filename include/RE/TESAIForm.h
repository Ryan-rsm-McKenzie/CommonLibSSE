#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESAIForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/BSTList.h"  // BSSimpleList


namespace RE
{
	class TESPackage;


	class TESAIForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESAIForm;


		enum class Aggression : UInt8
		{
			kUnaggressive = 0,
			kAggressive = 1,
			kVeryAggressive = 2,
			kFrenzied = 3
		};


		enum class Confidence : UInt8
		{
			kCowardly = 0,
			kCautious = 1,
			kAverage = 2,
			kBrave = 3,
			kFoolhardy = 4
		};


		enum class Responsibility : UInt8
		{
			kAnyCrime = 0,
			kViolenceAgainstEnemies = 1,
			kPropertyCrimeOnly = 2,
			kNoCrime = 3
		};


		enum class Mood : UInt8
		{
			kNeutral = 0,
			kAngry = 1,
			kFear = 2,
			kHappy = 3,
			kSad = 4,
			kSurprised = 5,
			kPuzzled = 6,
			kDisgusted = 7
		};


		enum class Assistance : UInt8
		{
			kHelpsNobody = 0,
			kHelpsAllies = 1,
			kHelpsFriendsAndAllies = 2
		};


		struct Data
		{
			bool	aggression1 : 1;			// 00
			bool	aggression2 : 1;			// 01
			bool	confidence1 : 1;			// 02
			bool	confidence2 : 1;			// 03
			bool	confidence3 : 1;			// 04
			bool	energyLevel1 : 1;			// 05
			bool	energyLevel2 : 1;			// 06
			bool	energyLevel3 : 1;			// 07
			bool	energyLevel4 : 1;			// 08
			bool	energyLevel5 : 1;			// 09
			bool	energyLevel6 : 1;			// 0A
			bool	energyLevel7 : 1;			// 0B
			bool	energyLevel8 : 1;			// 0C
			bool	responsibility1 : 1;		// 0D
			bool	responsibility2 : 1;		// 0E
			bool	mood1 : 1;					// 0F
			bool	mood2 : 1;					// 10
			bool	mood3 : 1;					// 11
			bool	assistance1 : 1;			// 12
			bool	assistance2 : 1;			// 13
			bool	aggroRadiusBehaviour : 1;	// 14
			bool	pad15 : 1;					// 15
			bool	pad16 : 1;					// 16
			bool	pad17 : 1;					// 17
			bool	pad18 : 1;					// 18
			bool	pad19 : 1;					// 19
			bool	pad1A : 1;					// 1A
			bool	pad1B : 1;					// 1B
			bool	pad1C : 1;					// 1C
			bool	pad1D : 1;					// 1D
			bool	pad1E : 1;					// 1E
			bool	pad1F : 1;					// 1F
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		Aggression		GetAggression() const;
		Confidence		GetConfidence() const;
		UInt8			GetEnergyLevel() const;
		Responsibility	GetResponsibility() const;
		Mood			GetMood() const;
		Assistance		GetAssistance() const;
		bool			AggroRadiusBehaviourIsEnabled() const;


		// members
		Data						data;		// 08
		UInt16						warn;		// 0C
		UInt16						warnAttack;	// 0E
		UInt16						attack;		// 10
		UInt16						pad12;		// 12
		UInt32						pad14;		// 14
		BSSimpleList<TESPackage*>	packages;	// 18 - PKID
	};
	STATIC_ASSERT(sizeof(TESAIForm) == 0x28);
}
