#pragma once

#include <type_traits>

#include "RE/BSPointerHandle.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSIdleCollection;
	class PackageLocation;
	class TESPackageData;


	enum class PACKAGE_OBJECT_TYPE : UInt32
	{
		kNone = 0,
		kACTI = 1,
		kARMO = 2,
		kBOOK = 3,
		kCONT = 4,
		kDOOR = 5,
		kINGR = 6,
		kLIGH = 7,
		kMISC = 8,
		kFLOR = 9,
		kFURN = 10,
		kWEAP = 11,
		kAMMO = 12,
		kKEYM = 13,
		kALCH = 14,
		kFOOD = 15
	};


	enum class PACKAGE_PROCEDURE_TYPE : UInt32
	{
		kNone = static_cast<std::underlying_type_t<PACKAGE_PROCEDURE_TYPE>>(-1),
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
		kGetUpFromChairBed = 26,
		kDoNothing = 27,
		kInGameDialogue = 28,
		kSurface = 29,
		kSearchForAttacker = 30,
		kAvoidPlayer = 31,
		kReactToDestroyedObject = 32,
		kReactToGrenadeOrMine = 33,
		kStealWarning = 34,
		kPickPocketWarning = 35,
		kMovementBlocked = 36,
		kVampireFeed = 37,
		kCannibal = 38
	};


	enum class PACKAGE_PROCEDURE_TYPE_8 : UInt8
	{
		kNone = static_cast<std::underlying_type_t<PACKAGE_PROCEDURE_TYPE_8>>(-1),
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
		kGetUpFromChairBed = 26,
		kDoNothing = 27,
		kInGameDialogue = 28,
		kSurface = 29,
		kSearchForAttacker = 30,
		kAvoidPlayer = 31,
		kReactToDestroyedObject = 32,
		kReactToGrenadeOrMine = 33,
		kStealWarning = 34,
		kPickPocketWarning = 35,
		kMovementBlocked = 36,
		kVampireFeed = 37,
		kCannibal = 38
	};


	enum class PACK_EVENT_ACTION_TYPE : UInt32
	{
		kBegin = 0,
		kEnd,
		kChange,
		kPatrol
	};


	enum class PACK_INTERRUPT_TARGET : UInt32
	{
		kNone = static_cast<std::underlying_type_t<PACK_INTERRUPT_TARGET>>(-1),
		kSpectator = 0,
		kObserveDead = 0x1,
		kGuardWarn = 0x2,
		kCombat = 0x3
	};


	enum class PACK_INTERRUPT_TARGET_8 : UInt8
	{
		kNone = static_cast<std::underlying_type_t<PACK_INTERRUPT_TARGET_8>>(-1),
		kSpectator = 0,
		kObserveDead = 0x1,
		kGuardWarn = 0x2,
		kCombat = 0x3
	};


	struct PACKAGE_DATA	 // PKDT
	{
		using InterruptOverride = PACK_INTERRUPT_TARGET_8;
		using Type = PACKAGE_PROCEDURE_TYPE_8;


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


		// members
		GeneralFlag		  packFlags;			  // 0
		Type			  packType;				  // 4
		InterruptOverride interruptOverrideType;  // 5
		PreferredSpeed	  maxSpeed;				  // 6
		UInt8			  pad7;					  // 7
		InterruptFlag	  foBehaviorFlags;		  // 8
		UInt16			  packageSpecificFlags;	  // A
	};
	STATIC_ASSERT(sizeof(PACKAGE_DATA) == 0xC);


	class PackageTarget
	{
	public:
		union Target
		{
			inline Target() :
				object(nullptr)
			{}

			~Target() {}


			// members
			ObjectRefHandle		  handle;
			TESForm*			  object;
			TESForm*			  refOrObj;
			PACKAGE_OBJECT_TYPE	  objType;
			UInt32				  aliasID;
			PACK_INTERRUPT_TARGET interruptTarg;
		};
		STATIC_ASSERT(sizeof(Target) == 0x8);


		// members
		SInt8  targType;  // 00
		UInt8  pad01;	  // 01
		UInt16 pad02;	  // 02
		Target target;	  // 08
		SInt32 value;	  // 10
		UInt32 pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(PackageTarget) == 0x18);


	struct PACK_SCHED_DATA
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


		// members
		SInt8	  month;	  // 0
		DayOfWeek dayOfWeek;  // 1
		SInt8	  date;		  // 2
		SInt8	  hour;		  // 3
		SInt8	  minute;	  // 4
		UInt8	  pad5;		  // 5
		UInt8	  pad6;		  // 6
		UInt8	  pad7;		  // 7
		SInt32	  duration;	  // 8 - minutes
	};
	STATIC_ASSERT(sizeof(PACK_SCHED_DATA) == 0xC);


	class PackageSchedule  // PSDT
	{
	public:
		// members
		PACK_SCHED_DATA psData;	 // 0
	};
	STATIC_ASSERT(sizeof(PackageSchedule) == 0xC);


	class PackageEventAction
	{
	public:
		struct TopicData  // PDTO
		{
			enum class Type : UInt32
			{
				kTopicRef = 0,
				kTopicSubtype = 1
			};


			// members
			Type	  type;	  // 00
			UInt32	  pad04;  // 04
			TESTopic* topic;  // 08
		};
		STATIC_ASSERT(sizeof(TopicData) == 0x10);


		// members
		TESIdleForm*		   idle;   // 00 - INAM
		PACK_EVENT_ACTION_TYPE type;   // 08
		UInt32				   pad0C;  // 0C
		TopicData			   topic;  // 10 - PDTO
	};
	STATIC_ASSERT(sizeof(PackageEventAction) == 0x20);


	class TESPackage : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESPackage;
		inline static constexpr auto FORMTYPE = FormType::Package;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kWaitingFlag = 1 << 26,
				kNeverRunFlag = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESPackage();	// 00

		// override (TESForm)
		virtual void		InitializeData() override;					  // 04
		virtual void		ClearData() override;						  // 05
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void		Revert(BGSLoadFormBuffer* a_buf) override;	  // 12
		virtual void		InitItemImpl() override;					  // 13
		virtual UInt32		GetRefCount() const override;				  // 2D - { return refCount; }
		virtual const char* GetObjectTypeName() const override;			  // 39 - { return g_packageTypeStrings[packData.packType]; }

		// add
		virtual bool IsActorAtLocation(Actor* a_actor, bool a_arg2, float a_arg3, bool a_arg4);						 // 3B
		virtual bool IsActorAtSecondLocation(Actor* a_arg1, Actor* a_arg2, bool a_arg3, float a_arg4, bool a_arg5);	 // 3C
		virtual bool IsActorAtRefTarget(Actor* a_actor, SInt32 a_arg2);												 // 3D
		virtual bool IsTargetAtLocation(Actor* a_actor, SInt32 a_arg2);												 // 3E
		virtual bool IsPackageOwner(Actor* a_actor);																 // 3F - { return true; }


		// members
		PACKAGE_DATA		   packData;		// 20 - PKDT
		UInt32				   pad2C;			// 2C
		TESPackageData*		   data;			// 30
		PackageLocation*	   packLoc;			// 38
		PackageTarget*		   packTarg;		// 40
		BGSIdleCollection*	   idleCollection;	// 48
		PackageSchedule		   packSched;		// 50 - PSDT
		UInt32				   pad5C;			// 5C
		TESCondition		   packConditions;	// 60
		TESCombatStyle*		   combatStyle;		// 68 - CNAM
		TESQuest*			   ownerQuest;		// 70 - QNAM
		PackageEventAction	   onBegin;			// 78
		PackageEventAction	   onEnd;			// 98
		PackageEventAction	   onChange;		// B8
		PACKAGE_PROCEDURE_TYPE procedureType;	// D8
		volatile UInt32		   refCount;		// DC
	};
	STATIC_ASSERT(sizeof(TESPackage) == 0xE0);
}
