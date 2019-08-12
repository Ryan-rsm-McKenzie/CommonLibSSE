#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESTopic

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class TESTopic :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static const void* RTTI = RTTI_TESTopic;


		enum { kTypeID = FormType::Dialogue };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class TopicFlag : UInt8
			{
				kNone = 0,
				kDoAllBeforeRepeating = 1 << 0
			};


			enum class Category : UInt8
			{
				kTopic = 0,
				kFavor = 1,
				kScene = 2,
				kCombat = 3,
				kFavors = 4,
				kDetection = 5,
				kService = 6,
				kMiscellaneous = 7
			};


			enum class Subtype : UInt8
			{
				kCustom = 0,
				kForceGreet = 1,
				kRumors = 2,
				kUnk3 = 3,	// custom?
				kIntimidate = 4,
				kFlatter = 5,
				kBribe = 6,
				kAskGift = 7,
				kGift = 8,
				kAskFavor = 9,
				kFavor = 10,
				kShowRelationships = 11,
				kFollow = 12,
				kReject = 13,
				kScene = 14,
				kShow = 15,
				kAgree = 16,
				kRefuse = 17,
				kExitFavorState = 18,
				kMoralRefusal = 19,
				kFlyingMountLand = 20,
				kFlyingMountCancelLand = 21,
				kFlyingMountAcceptTarget = 22,
				kFlyingMountRejectTarget = 23,
				kFlyingMountNoTarget = 24,
				kFlyingMountDestinationReached = 25,
				kAttack = 26,
				kPowerAttack = 27,
				kBash = 28,
				kHit = 29,
				kFlee = 30,
				kBleedout = 31,
				kAvoidThreat = 32,
				kDeath = 33,
				kGroupStrategy = 34,
				kBlock = 35,
				kTaunt = 36,
				kAllyKilled = 37,
				kSteal = 38,
				kYield = 39,
				kAcceptYield = 40,
				kPickpocketCombat = 41,
				kAssault = 42,
				kMurder = 43,
				kAssaultNPC = 44,
				kMurderNPC = 45,
				kPickpocketNPC = 46,
				kStealFromNPC = 47,
				kTrespassAgainstNPC = 48,
				kTrespass = 49,
				kWereTransformCrime = 50,
				kVoicePowerStartShort = 51,
				kVoicePowerStartLong = 52,
				kVoicePowerEndShort = 53,
				kVoicePowerEndLong = 54,
				kAlertIdle = 55,
				kLostIdle = 56,
				kNormalToAlert = 57,
				kAlertToCombat = 58,
				kNormalToCombat = 59,
				kAlertToNormal = 60,
				kCombatToNormal = 61,
				kCombatToLost = 62,
				kLostToNormal = 63,
				kLostToCombat = 64,
				kDetectFriendDie = 65,
				kServiceRefusal = 66,
				kRepair = 67,
				kTravel = 68,
				kTraining = 69,
				kBarterExit = 70,
				kRepairExit = 71,
				kRecharge = 72,
				kRechargeExit = 73,
				kTrainingExit = 74,
				kObserveCombat = 75,
				kNoticeCorpse = 76,
				kTimeToGo = 77,
				kGoodBye = 78,
				kHello = 79,
				kSwingMeleeWeapon = 80,
				kShootBow = 81,
				kZKeyObject = 82,
				kJump = 83,
				kKnockOverObject = 84,
				kDestroyObject = 85,
				kStandonFurniture = 86,
				kLockedObject = 87,
				kPickpocketTopic = 88,
				kPursueIdleTopic = 89,
				kSharedInfo = 90,
				kPlayerCastProjectileSpell = 91,
				kPlayerCastSelfSpell = 92,
				kPlayerShout = 93,
				kIdle = 94,
				kEnterSprintBreath = 95,
				kEnterBowZoomBreath = 96,
				kExitBowZoomBreath = 97,
				kActorCollidewithActor = 98,
				kPlayerinIronSights = 99,
				kOutofBreath = 100,
				kCombatGrunt = 101,
				kLeaveWaterBreath = 102
			};


			TopicFlag	topicFlags;	// 0
			Category	category;	// 1
			Subtype		subtype;	// 2
			UInt8		unk4;		// 3
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		virtual ~TESTopic();												// 00

		// override (TESForm)
		virtual bool			LoadForm(TESFile* a_mod) override;			// 06
		virtual void			InitItem() override;						// 13
		virtual const char*		GetEditorID() override;						// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool			SetEditorID(const char* a_str) override;	// 33 - { bool result = editorID == a_str; editorID = a_str; return result; }
		virtual void			Unk_36(void) override;						// 36 - { return a_arg1 == FormType::Info }

		float GetPriority() const;


		// members
		Data				data;		// 30 - DATA
		UInt8				unk34;		// 34
		UInt8				unk35;		// 35
		UInt8				unk36;		// 36
		UInt8				priority;	// 37 - PNAM - priority as a UInt8
		BGSDialogueBranch*	branch;		// 38 - BNAM
		TESQuest*			quest;		// 40 -	QNAM
		TESTopicInfo**		infoTopics;	// 48 - infoTopics[infoCount]
		UInt32				infoCount;	// 50 - TIFC
		UInt32				fileOffset;	// 54
		BSFixedString		editorID;	// 58
	};
	STATIC_ASSERT(sizeof(TESTopic) == 0x60);
}
