#pragma once

#include "RE/BSTList.h"
#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESPackage;


	enum class ACTOR_AGGRESSION : UInt32
	{
		kCalmed = static_cast<std::underlying_type_t<ACTOR_AGGRESSION>>(-1),
		kUnaggressive = 0,
		kAggressive = 1,
		kVeryAggressive = 2,
		kFrenzied = 3
	};


	struct ACTOR_AGGRO_RADIUS
	{
		enum
		{
			kWarn,
			kWarnAndAttack,
			kAttack,

			kTotal
		};
	};


	enum class ACTOR_ASSISTANCE : UInt32
	{
		kHelpsNobody = 0,
		kHelpsAllies = 1,
		kHelpsFriends = 2
	};


	enum class ACTOR_CONFIDENCE : UInt32
	{
		kCowardly = 0,
		kCautious = 1,
		kAverage = 2,
		kBrave = 3,
		kFoolhardy = 4
	};


	enum class ACTOR_MOOD : UInt32
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


	enum class ACTOR_MORALITY : UInt32
	{
		kAnyCrime = 0,
		kViolenceAgainstEnemy = 1,
		kPropertyCrimeOnly = 2,
		kNoCrime = 3
	};


	struct AIDATA_GAME
	{
		bool   aggression1 : 1;							 // 0 - 0
		bool   aggression2 : 1;							 // 0 - 1
		bool   confidence1 : 1;							 // 0 - 2
		bool   confidence2 : 1;							 // 0 - 3
		bool   confidence3 : 1;							 // 0 - 4
		bool   energyLevel1 : 1;						 // 0 - 5
		bool   energyLevel2 : 1;						 // 0 - 6
		bool   energyLevel3 : 1;						 // 0 - 7
		bool   energyLevel4 : 1;						 // 1 - 0
		bool   energyLevel5 : 1;						 // 1 - 1
		bool   energyLevel6 : 1;						 // 1 - 2
		bool   energyLevel7 : 1;						 // 1 - 3
		bool   energyLevel8 : 1;						 // 1 - 4
		bool   morality1 : 1;							 // 1 - 5
		bool   morality2 : 1;							 // 1 - 6
		bool   mood1 : 1;								 // 1 - 7
		bool   mood2 : 1;								 // 2 - 0
		bool   mood3 : 1;								 // 2 - 1
		bool   assistance1 : 1;							 // 2 - 2
		bool   assistance2 : 1;							 // 2 - 3
		bool   aggroRadiusBehaviour : 1;				 // 2 - 4
		bool   pad2_5 : 1;								 // 2 - 5
		bool   pad2_6 : 1;								 // 2 - 6
		bool   pad2_7 : 1;								 // 2 - 7
		UInt8  pad3;									 // 3
		UInt16 aggroRadius[ACTOR_AGGRO_RADIUS::kTotal];	 // 4
		bool   noSlowApproach : 1;						 // A - 0
		bool   padA_1 : 1;								 // A - 1
		bool   padA_2 : 1;								 // A - 2
		bool   padA_3 : 1;								 // A - 3
		bool   padA_4 : 1;								 // A - 4
		bool   padA_5 : 1;								 // A - 5
		bool   padA_6 : 1;								 // A - 6
		bool   padA_7 : 1;								 // A - 7
		UInt8  padB;									 // B
	};
	STATIC_ASSERT(sizeof(AIDATA_GAME) == 0xC);


	struct PackageList
	{
		BSSimpleList<TESPackage*> packages;	 // 00
	};
	STATIC_ASSERT(sizeof(PackageList) == 0x10);


	class TESAIForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESAIForm;


		virtual ~TESAIForm();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		bool			 AggroRadiusBehaviourIsEnabled() const;
		ACTOR_AGGRESSION GetAggressionLevel() const;
		ACTOR_ASSISTANCE GetAssistanceLevel() const;
		ACTOR_CONFIDENCE GetConfidenceLevel() const;
		UInt8			 GetEnergyLevel() const;
		ACTOR_MOOD		 GetMoodLevel() const;
		ACTOR_MORALITY	 GetMoralityLevel() const;
		bool			 NoSlowApproach() const;


		// members
		AIDATA_GAME aiData;		 // 08 - AIDT
		PackageList aiPackages;	 // 18 - PKID
	};
	STATIC_ASSERT(sizeof(TESAIForm) == 0x28);
}
