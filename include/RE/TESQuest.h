#pragma once

#include <type_traits>

#include "RE/BGSStoryManagerTreeForm.h"
#include "RE/BSAtomic.h"
#include "RE/BSFixedString.h"
#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/DialogueTypes.h"
#include "RE/FormTypes.h"
#include "RE/QuestEvents.h"
#include "RE/QuestObjectiveStates.h"
#include "RE/TESCondition.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSBaseAlias;
	class QueuedPromoteQuestTask;


	enum class QuestFlag : UInt16
	{
		kStopStart = static_cast<std::underlying_type_t<QuestFlag>>(-1),
		kNone = 0,
		kEnabled = 1 << 0,
		kCompleted = 1 << 1,
		kAddIdleToHello = 1 << 2,
		kAllowRepeatStages = 1 << 3,
		kStartsEnabled = 1 << 4,
		kDisplayedInHUD = 1 << 5,
		kFailed = 1 << 6,
		kStageWait = 1 << 7,
		kRunOnce = 1 << 8,
		kExcludeFromExport = 1 << 9,
		kWarnOnAliasFillFailure = 1 << 10,
		kActive = 1 << 11,
		kRepeatsConditions = 1 << 12,
		kKeepInstance = 1 << 13,
		kWantDormant = 1 << 14,
		kHasDialogueData = 1 << 15
	};


	enum class QUEST_OBJECTIVE_FLAGS : UInt32
	{
		kNone = 0,
		kORWithPrevious = 1 << 0,
		kNoStatsTracking = 1 << 1
	};


	struct BGSQuestInstanceText
	{
		struct StringData
		{
			UInt32 aliasID;			// 0
			UInt32 fullNameFormID;	// 4
		};
		STATIC_ASSERT(sizeof(StringData) == 0x8);


		struct GlobalValueData
		{
			const TESGlobal* global;  // 00
			float			 value;	  // 08
			UInt32			 pad0C;	  // 0C
		};
		STATIC_ASSERT(sizeof(GlobalValueData) == 0x10);


		UInt32					  id;				 // 00
		UInt32					  pad04;			 // 04
		BSTArray<StringData>	  stringData;		 // 08
		BSTArray<GlobalValueData> valueData;		 // 20
		UInt16					  journalStage;		 // 38
		SInt8					  journalStageItem;	 // 3A
		UInt8					  pad3B;			 // 3B
		UInt32					  pad3C;			 // 3C
	};
	STATIC_ASSERT(sizeof(BGSQuestInstanceText) == 0x40);


	struct QUEST_DATA  // DNAM
	{
		enum class Type : UInt8
		{
			kNone = 0,
			kMainQuest = 1,
			kMagesGuild = 2,
			kThievesGuild = 3,
			kDarkBrotherhood = 4,
			kCompanionsQuest = 5,
			kMiscellaneous = 6,
			kDaedric = 7,
			kSideQuest = 8,
			kCivilWar = 9,
			kDLC01_Vampire = 10,
			kDLC02_Dragonborn = 11
		};


		float	  questDelayTime;  // 0
		QuestFlag flags;		   // 4
		SInt8	  priority;		   // 6
		Type	  questType;	   // 7
	};
	STATIC_ASSERT(sizeof(QUEST_DATA) == 0x8);


	struct QUEST_STAGE_DATA
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kStartUpStage = 1 << 1,
			kShutDownStage = 1 << 2,
			kKeepInstanceDataFromHereOn = 1 << 3
		};


		UInt16 index;  // 0
		Flag   flags;  // 2
		UInt8  pad3;   // 3
		UInt32 pad4;   // 4
	};
	STATIC_ASSERT(sizeof(QUEST_STAGE_DATA) == 0x8);


	class TESQuestStage
	{
	public:
		explicit operator bool() const;


		// members
		QUEST_STAGE_DATA data;	// 0
	};
	STATIC_ASSERT(sizeof(TESQuestStage) == 0x8);


	class TESQuestTarget  // QSTA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kCompassMarkerIgnoresLocks = 1 << 0
		};


		UInt64		 unk00;		  // 00
		TESCondition conditions;  // 08
		UInt8		 alias;		  // 10
		UInt8		 unk11;		  // 11
		UInt16		 unk12;		  // 12
		UInt32		 unk14;		  // 14
	};
	STATIC_ASSERT(sizeof(TESQuestTarget) == 0x18);


	class BGSQuestObjective
	{
	public:
		BSFixedString			displayText;  // 00 - NNAM
		TESQuest*				ownerQuest;	  // 08
		TESQuestTarget**		targets;	  // 10 - QSTA
		UInt32					numTargets;	  // 18
		UInt16					index;		  // 1C - QOBJ
		bool					initialized;  // 1E
		QUEST_OBJECTIVE_STATE_8 state;		  // 1E
		QUEST_OBJECTIVE_FLAGS	flags;		  // 20 - FNAM
		UInt32					pad24;		  // 24
	};
	STATIC_ASSERT(sizeof(BGSQuestObjective) == 0x28);


	class BGSStoryEvent
	{
	public:
		UInt32 id;			// 00
		UInt32 index;		// 04
		UInt64 members[6];	// 08
	};
	STATIC_ASSERT(sizeof(BGSStoryEvent) == 0x38);


	class TESQuest :
		public BGSStoryManagerTreeForm,	 // 000
		public TESFullName				 // 028
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESQuest;


		using DT = DIALOGUE_TYPE;
		inline static constexpr auto FORMTYPE = FormType::Quest;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kQuestFlags = 1 << 1,
				kQuestScriptDelay = 1 << 2,
				kQuestAlreadyRun = 1 << 26,
				kQuestInstanceData = 1 << 27,
				kQuestRuntimeData = 1 << 28,
				kQuestObjectives = 1 << 29,
				kQuestScript = 1 << 30,
				kQuestStages = (UInt32)1 << 31
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


		virtual ~TESQuest();  // 00

		// override (BGSStoryManagerTreeForm)
		virtual void									 InitializeData() override;										 // 04
		virtual void									 ClearData() override;											 // 05
		virtual bool									 Load(TESFile* a_mod) override;									 // 06
		virtual void									 SaveGame(BGSSaveFormBuffer* a_buf) override;					 // 0E
		virtual void									 LoadGame(BGSLoadFormBuffer* a_buf) override;					 // 0F
		virtual void									 FinishLoadGame(BGSLoadFormBuffer* a_buf) override;				 // 11
		virtual void									 Revert(BGSLoadFormBuffer* a_buf) override;						 // 12
		virtual void									 InitItemImpl() override;										 // 13
		virtual const char*								 GetFormEditorID() const override;								 // 32 - { return formEditorID.c_str(); }
		virtual bool									 SetFormEditorID(const char* a_str) override;					 // 33
		virtual TESCondition*							 QConditions() override;										 // 3D - { return &objConditions; }
		virtual BGSStoryManagerTreeVisitor::VisitControl AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor) override;	 // 3E

		bool   EnsureQuestStarted(bool& a_result, bool a_startNow);
		UInt16 GetCurrentStageID() const;
		bool   IsActive() const;
		bool   IsCompleted() const;
		bool   IsEnabled() const;
		bool   IsRunning() const;
		bool   IsStarting() const;
		bool   IsStopped() const;
		bool   IsStopping() const;
		void   Reset();
		void   ResetAndUpdate();
		void   SetEnabled(bool a_set);
		bool   Start();
		bool   StartsEnabled() const;
		void   Stop();


		// members
		BSTArray<BGSQuestInstanceText*>						 instanceData;							   // 038
		UInt32												 currentInstanceID;						   // 050
		UInt32												 pad054;								   // 054
		BSTArray<BGSBaseAlias*>								 aliases;								   // 058
		BSTHashMap<UnkKey, UnkValue>						 unk070;								   // 070 - alias related
		BSTHashMap<UnkKey, UnkValue>						 unk0A0;								   // 0A0 - alias related
		mutable BSReadWriteLock								 aliasAccessLock;						   // 0D0
		QUEST_DATA											 data;									   // 0D8 - DNAM
		QuestEvent											 eventID;								   // 0E0 - ENAM
		UInt32												 pad0E4;								   // 0E4
		BSSimpleList<TESQuestStage>*						 executedStages;						   // 0E8
		BSSimpleList<TESQuestStage*>*						 waitingStages;							   // 0F0
		BSSimpleList<BGSQuestObjective*>					 objectives;							   // 0F8
		TESCondition										 objConditions;							   // 108
		TESCondition										 storyManagerConditions;				   // 110
		BSTHashMap<BGSDialogueBranch*, BSTArray<TESTopic*>*> branchedDialogue[DT::kBranchedTotal];	   // 118
		BSTArray<TESTopic*>									 topics[DT::kTotal - DT::kBranchedTotal];  // 178
		BSTArray<BGSScene*>									 scenes;								   // 208
		BSTArray<TESGlobal*>*								 textGlobals;							   // 220 - QTGL
		UInt16												 currentStage;							   // 228
		bool												 alreadyRun;							   // 22A
		UInt8												 pad22B;								   // 22B
		UInt32												 pad22C;								   // 22C
		BSString											 formEditorID;							   // 230
		const BGSStoryEvent*								 startEventData;						   // 240
		NiPointer<QueuedPromoteQuestTask>					 promoteTask;							   // 248
		BSTArray<ObjectRefHandle>							 promotedRefs;							   // 250
	};
	STATIC_ASSERT(sizeof(TESQuest) == 0x268);
}
