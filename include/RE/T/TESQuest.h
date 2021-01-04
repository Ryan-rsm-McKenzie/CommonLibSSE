#pragma once

#include "RE/B/BGSStoryManagerTreeForm.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTList.h"
#include "RE/D/DialogueTypes.h"
#include "RE/F/FormTypes.h"
#include "RE/Q/QuestEvents.h"
#include "RE/Q/QuestObjectiveStates.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSBaseAlias;
	class QueuedPromoteQuestTask;

	enum class QuestFlag
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

	enum class QUEST_OBJECTIVE_FLAGS
	{
		kNone = 0,
		kORWithPrevious = 1 << 0,
		kNoStatsTracking = 1 << 1
	};

	struct BGSQuestInstanceText
	{
	public:
		struct StringData
		{
		public:
			// members
			std::uint32_t aliasID;		   // 0
			std::uint32_t fullNameFormID;  // 4
		};
		static_assert(sizeof(StringData) == 0x8);

		struct GlobalValueData
		{
		public:
			// members
			const TESGlobal* global;  // 00
			float			 value;	  // 08
			std::uint32_t	 pad0C;	  // 0C
		};
		static_assert(sizeof(GlobalValueData) == 0x10);

		// members
		std::uint32_t			  id;				 // 00
		std::uint32_t			  pad04;			 // 04
		BSTArray<StringData>	  stringData;		 // 08
		BSTArray<GlobalValueData> valueData;		 // 20
		std::uint16_t			  journalStage;		 // 38
		std::int8_t				  journalStageItem;	 // 3A
		std::uint8_t			  pad3B;			 // 3B
		std::uint32_t			  pad3C;			 // 3C
	};
	static_assert(sizeof(BGSQuestInstanceText) == 0x40);

	struct QUEST_DATA  // DNAM
	{
	public:
		enum class Type
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

		// members
		float									   questDelayTime;	// 0
		stl::enumeration<QuestFlag, std::uint16_t> flags;			// 4
		std::int8_t								   priority;		// 6
		stl::enumeration<Type, std::uint8_t>	   questType;		// 7
	};
	static_assert(sizeof(QUEST_DATA) == 0x8);

	struct QUEST_STAGE_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kStartUpStage = 1 << 1,
			kShutDownStage = 1 << 2,
			kKeepInstanceDataFromHereOn = 1 << 3
		};

		// members
		std::uint16_t						 index;	 // 0
		stl::enumeration<Flag, std::uint8_t> flags;	 // 2
		std::uint8_t						 pad3;	 // 3
		std::uint32_t						 pad4;	 // 4
	};
	static_assert(sizeof(QUEST_STAGE_DATA) == 0x8);

	class TESQuestStage
	{
	public:
		explicit operator bool() const;

		// members
		QUEST_STAGE_DATA data;	// 0
	};
	static_assert(sizeof(TESQuestStage) == 0x8);

	class TESQuestTarget  // QSTA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kCompassMarkerIgnoresLocks = 1 << 0
		};

		// members
		std::uint64_t unk00;	   // 00
		TESCondition  conditions;  // 08
		std::uint8_t  alias;	   // 10
		std::uint8_t  unk11;	   // 11
		std::uint16_t unk12;	   // 12
		std::uint32_t unk14;	   // 14
	};
	static_assert(sizeof(TESQuestTarget) == 0x18);

	class BGSQuestObjective
	{
	public:
		// members
		BSFixedString										   displayText;	 // 00 - NNAM
		TESQuest*											   ownerQuest;	 // 08
		TESQuestTarget**									   targets;		 // 10 - QSTA
		std::uint32_t										   numTargets;	 // 18
		std::uint16_t										   index;		 // 1C - QOBJ
		bool												   initialized;	 // 1E
		stl::enumeration<QUEST_OBJECTIVE_STATE, std::uint8_t>  state;		 // 1E
		stl::enumeration<QUEST_OBJECTIVE_FLAGS, std::uint32_t> flags;		 // 20 - FNAM
		std::uint32_t										   pad24;		 // 24
	};
	static_assert(sizeof(BGSQuestObjective) == 0x28);

	class BGSStoryEvent
	{
	public:
		// members
		std::uint32_t id;		   // 00
		std::uint32_t index;	   // 04
		std::uint64_t members[6];  // 08
	};
	static_assert(sizeof(BGSStoryEvent) == 0x38);

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
			enum ChangeFlag : std::uint32_t
			{
				kQuestFlags = 1 << 1,
				kQuestScriptDelay = 1 << 2,
				kQuestAlreadyRun = 1 << 26,
				kQuestInstanceData = 1 << 27,
				kQuestRuntimeData = 1 << 28,
				kQuestObjectives = 1 << 29,
				kQuestScript = 1 << 30,
				kQuestStages = (std::uint32_t)1 << 31
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
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

		bool		  EnsureQuestStarted(bool& a_result, bool a_startNow);
		std::uint16_t GetCurrentStageID() const;
		bool		  IsActive() const;
		bool		  IsCompleted() const;
		bool		  IsEnabled() const;
		bool		  IsRunning() const;
		bool		  IsStarting() const;
		bool		  IsStopped() const;
		bool		  IsStopping() const;
		void		  Reset();
		void		  ResetAndUpdate();
		void		  SetEnabled(bool a_set);
		bool		  Start();
		bool		  StartsEnabled() const;
		void		  Stop();

		// members
		BSTArray<BGSQuestInstanceText*>						 instanceData;							   // 038
		std::uint32_t										 currentInstanceID;						   // 050
		std::uint32_t										 pad054;								   // 054
		BSTArray<BGSBaseAlias*>								 aliases;								   // 058
		BSTHashMap<UnkKey, UnkValue>						 unk070;								   // 070 - alias related
		BSTHashMap<UnkKey, UnkValue>						 unk0A0;								   // 0A0 - alias related
		mutable BSReadWriteLock								 aliasAccessLock;						   // 0D0
		QUEST_DATA											 data;									   // 0D8 - DNAM
		QuestEvent											 eventID;								   // 0E0 - ENAM
		std::uint32_t										 pad0E4;								   // 0E4
		BSSimpleList<TESQuestStage>*						 executedStages;						   // 0E8
		BSSimpleList<TESQuestStage*>*						 waitingStages;							   // 0F0
		BSSimpleList<BGSQuestObjective*>					 objectives;							   // 0F8
		TESCondition										 objConditions;							   // 108
		TESCondition										 storyManagerConditions;				   // 110
		BSTHashMap<BGSDialogueBranch*, BSTArray<TESTopic*>*> branchedDialogue[DT::kBranchedTotal];	   // 118
		BSTArray<TESTopic*>									 topics[DT::kTotal - DT::kBranchedTotal];  // 178
		BSTArray<BGSScene*>									 scenes;								   // 208
		BSTArray<TESGlobal*>*								 textGlobals;							   // 220 - QTGL
		std::uint16_t										 currentStage;							   // 228
		bool												 alreadyRun;							   // 22A
		std::uint8_t										 pad22B;								   // 22B
		std::uint32_t										 pad22C;								   // 22C
		BSString											 formEditorID;							   // 230
		const BGSStoryEvent*								 startEventData;						   // 240
		NiPointer<QueuedPromoteQuestTask>					 promoteTask;							   // 248
		BSTArray<ObjectRefHandle>							 promotedRefs;							   // 250
	};
	static_assert(sizeof(TESQuest) == 0x268);
}
