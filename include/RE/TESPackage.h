#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESPackage

#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSIdleCollection;
	class TESCustomPackageData;


	class TESPackage : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESPackage;


		enum { kTypeID = FormType::Package };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct PackData	// PKDT
		{
			enum class GeneralFlag : UInt32
			{
				kNone = 0,
				kOffersServices = 1 << 0,
				kMustComplete = 1 << 2,
				kMaintainSpeedAtGoal = 1 << 3,
				kUnlocksDoorsAtPackageStart = 1 << 6,
				kUnlocksDoorsAtPackageEnd = 1 << 7,
				kContinueIfPCNear = 1 << 9,
				kOncePerDay = 1 << 10,
				kPreferredSpeed = 1 << 13,
				kAlwaysSneak = 1 << 17,
				kAllowSwimming = 1 << 18,
				kIgnoreCombat = 1 << 20,
				kWeaponsUnequipped = 1 << 21,
				kWeaponDrawn = 1 << 23,
				kNoCombatAlert = 1 << 27,
				kWearSleepOutfit = 1 << 29
			};


			enum class Type : UInt8
			{
				kFind = 0,
				kFollow = 1,
				kEscort = 2,
				kEat = 3,
				kSleep = 4,
				kWander = 5,
				kTravel = 6,
				kAccompany = 7,
				kUseItemAt = 8,
				kAmbush = 9,
				kFleeNotCombat = 10,
				kCastMagic = 11,
				kSandbox = 12,
				kPatrol = 13,
				kGuard = 14,
				kDialogue = 15,
				kUseWeapon = 16,
				kFind2 = 17,
				kPackage = 18,
				kPackageTemplate = 19,
				kActivate = 20,
				kAlarm = 21,
				kFlee = 22,
				kTrespass = 23,
				kSpectator = 24,
				kReactToDead = 25,
				kGetUpFromChair = 26,
				kDoNothing = 27,
				kInGameDialogue = 28,
				kSurface = 29,
				kSearchForAttacker = 30,
				kAvoidPlayer = 31,
				kReactToDestroyedObject = 32,
				kReactToGrenadeOrMine = 33,
				kStealWarning = 34,
				kPickPocketWarning = 35,
				kMovementBlocked = 36
			};


			enum class InterruptOverride : UInt8
			{
				kNone = 0,
				kSpectator = 1,
				kObserveDead = 2,
				kGuardWarn = 3,
				kCombat = 4
			};


			enum class PreferredSpeed : UInt8
			{
				kWalk = 0,
				kJog = 1,
				kRun = 2,
				kFastWalk = 3
			};


			enum class InterruptFlag : UInt16
			{
				kNone = 0,
				kHellosToPlayer = 1 << 0,
				kRandomConversations = 1 << 1,
				kObserveCombatBehaviour = 1 << 2,
				kGreetCorpseBehaviour = 1 << 3,
				kReactionToPlayerActions = 1 << 4,
				kFriendlyFireComments = 1 << 5,
				kAggroRadiusBehavior = 1 << 6,
				kAllowIdleChatter = 1 << 7,
				kWorldInteractions = 1 << 9
			};


			GeneralFlag			generalFlags;		// 00
			Type				type;				// 04
			InterruptOverride	interruptOverride;	// 05
			PreferredSpeed		preferredSpeed;		// 06
			UInt8				unk07;				// 07
			InterruptFlag		interruptFlags;		// 08
			UInt16				unk0A;				// 0A
			UInt32				unk0C;				// 0C
		};
		STATIC_ASSERT(sizeof(PackData) == 0x10);


		struct Schedule	// PSDT
		{
			enum class DayOfWeek : SInt8
			{
				kAny = -1,
				kSunday = 0,
				kMonday = 1,
				kTuesday = 2,
				kWednesday = 3,
				kThursday = 4,
				kFriday = 5,
				kSaturday = 6,
				kWeekdays = 7,
				kWeekends = 8,
				kMondayWednesdayFriday = 9,
				kTuesdayThursday = 10
			};


			SInt8		month;		// 00
			DayOfWeek	dayOfWeek;	// 01
			SInt8		date;		// 02
			SInt8		hour;		// 03
			SInt8		minute;		// 04
			UInt8		unk05;		// 05
			UInt8		unk06;		// 06
			UInt8		unk07;		// 07
			UInt32		duration;	// 08 - minutes
			UInt32		unk0C;		// 0C
		};
		STATIC_ASSERT(sizeof(Schedule) == 0x10);


		struct OnEvent
		{
			enum Index : UInt32
			{
				kOnBegin = 0,
				kOnEnd,
				kOnChange,

				kTotal
			};


			struct TopicData	// PDTO
			{
				enum class Type : UInt32
				{
					kTopicRef = 0,
					kTopicSubtype = 1
				};


				Type		type;	// 00
				UInt32		pad04;	// 04
				TESTopic*	topic;	// 08
			};
			STATIC_ASSERT(sizeof(TopicData) == 0x10);


			TESIdleForm*	idle;	// 00 - INAM
			Index			index;	// 08
			UInt32			pad0C;	// 0C
			TopicData		topic;	// 10 - PDTO
		};
		STATIC_ASSERT(sizeof(OnEvent) == 0x20);


		virtual ~TESPackage();												// 00

		// override (TESForm)
		virtual void		InitDefaults() override;						// 04
		virtual void		ReleaseManagedData() override;					// 05
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		Unk_12(void) override;							// 12
		virtual void		InitItem() override;							// 13
		virtual void		Unk_2D(void) override;							// 2D - { return unkDC; }
		virtual const char*	GetTypeString() const override;					// 39 - { return g_packageTypeStrings[unk24]; }

		// add
		virtual void		Unk_3B(void);									// 3B
		virtual void		Unk_3C(void);									// 3C
		virtual void		Unk_3D(void);									// 3D
		virtual void		Unk_3E(void);									// 3E
		virtual void		Unk_3F(void);									// 3F - { return 1; }


		// members
		PackData				packData;					// 20 - PKDT
		TESCustomPackageData*	package;					// 30
		UInt64					unk38;						// 38
		UInt64					unk40;						// 40
		BGSIdleCollection*		idleAnimations;				// 48
		Schedule				schedule;					// 50 - PSDT
		Condition				conditions;					// 60
		TESCombatStyle*			combatStyle;				// 68 - CNAM
		TESQuest*				ownerQuest;					// 70 - QNAM
		OnEvent					onEvents[OnEvent::kTotal];	// 78
		UInt32					unkD8;						// D8
		UInt32					unkDC;						// DC
	};
	STATIC_ASSERT(sizeof(TESPackage) == 0xE0);
}
