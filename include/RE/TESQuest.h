#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESQuest

#include "RE/BGSStoryManagerTreeForm.h"  // BGSStoryManagerTreeForm
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSLock.h"  // BSReadWriteLock
#include "RE/BSString.h"  // BSString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Condition.h"  // Condition
#include "RE/FormTypes.h"  // FormType
#include "RE/QuestEvents.h"  // QuestEvent
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class BGSBaseAlias;


	class TESQuest :
		public BGSStoryManagerTreeForm,	// 000
		public TESFullName				// 028
	{
	public:
		inline static const void* RTTI = RTTI_TESQuest;


		enum { kTypeID = FormType::Quest };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct General	// DNAM
		{
			enum class Flag : UInt16
			{
				kNone = 0,
				kStartGameEnabled = 1 << 0,
				kAllowRepeatedStages = 1 << 3,
				kRunOnce = 1 << 8,
				kExcludesFromDialogueExport = 1 << 9,
				kWarnOnAliasFillFailure = 1 << 10
			};


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


			UInt32	unk0;		// 0
			Flag	flags;		// 4
			UInt8	priority;	// 6
			Type	type;		// 7
		};
		STATIC_ASSERT(sizeof(General) == 0x8);


		struct Stage
		{
			enum class Flag : UInt8
			{
				kNone = 0,
				kStartUpStage = 1 << 1,
				kShutDownStage = 1 << 2,
				kKeepInstanceDataFromHereOn = 1 << 3
			};


			bool IsValid() const;	// Call this to know if the node is valid while traversing executedStages


			UInt16	index;	// 0
			Flag	flags;	// 2
			UInt8	unk3;	// 3
			UInt32	pad4;	// 4
		};
		STATIC_ASSERT(sizeof(Stage) == 0x8);


		struct Objective
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kORWithPrevious = 1 << 0
			};


			struct Target	// QSTA
			{
				enum class Flag
				{
					kNone = 0,
					kCompassMarkerIgnoresLocks = 1 << 0
				};


				UInt64		unk00;		// 00
				Condition	conditions;	// 08
				UInt8		alias;		// 10
				UInt8		unk11;		// 11
				UInt16		unk12;		// 12
				UInt32		unk14;		// 14
			};
			STATIC_ASSERT(sizeof(Target) == 0x18);


			BSFixedString	displayText;	// 00 - NNAM
			TESQuest*		quest;			// 08
			Target**		targets;		// 10
			UInt32			numTargets;		// 18
			UInt16			index;			// 1C - QOBJ
			UInt16			unk1E;			// 1E
			Flag			flags;			// 20 - FNAM
			UInt32			unk24;			// 24
		};
		STATIC_ASSERT(sizeof(Objective) == 0x28);


		virtual ~TESQuest();												// 00

		// override (BGSStoryManagerTreeForm)
		virtual void		InitDefaults() override;						// 04
		virtual void		ReleaseManagedData() override;					// 05
		virtual bool		LoadForm(TESFile* a_mod) override;				// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void		Unk_11(void) override;							// 11
		virtual void		Unk_12(void) override;							// 12
		virtual void		InitItem() override;							// 13
		virtual const char*	GetEditorID() override;							// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;		// 33
		virtual Condition*	GetConditions() override;						// 3D - { return &dialogueConditions; }
		virtual void		Unk_3E(void) override;							// 3E


		// members
		BSTArray<void*>											unk038;					// 038
		UInt32													unk050;					// 050
		UInt32													pad054;					// 054
		BSTArray<BGSBaseAlias*>									aliases;				// 058
		BSTHashMap<UnkKey, UnkValue>							unk070;					// 070 - alias related
		BSTHashMap<UnkKey, UnkValue>							unk0A0;					// 0A0 - alias related
		mutable BSReadWriteLock									unk0D0;					// 0D0
		General													general;				// 0D8 - DNAM
		QuestEvent												event;					// 0E0 - ENAM
		UInt32													pad0E4;					// 0E4
		BSSimpleList<Stage>*									executedStages;			// 0E8 - I think its actually templated on a pointer, and they store the stage info in the pointer itself
		BSSimpleList<Stage*>*									waitingStages;			// 0F0
		BSSimpleList<Objective*>								objectives;				// 0F8
		Condition												dialogueConditions;		// 108
		Condition												conditions;				// 110
		BSTHashMap<BGSDialogueBranch*, BSTArray<TESTopic*>*>	topicTopics;			// 118 - Category::kTopic
		BSTHashMap<BGSDialogueBranch*, BSTArray<TESTopic*>*>	favorTopics;			// 148 - Category::kFavor
		BSTArray<TESTopic*>										sceneTopics;			// 178 - Category::kScene
		BSTArray<TESTopic*>										combatTopics;			// 190 - Category::kCombat
		BSTArray<TESTopic*>										favorsTopics;			// 1A8 - Category::kFavors
		BSTArray<TESTopic*>										detectionTopics;		// 1C0 - Category::kDetection
		BSTArray<TESTopic*>										serviceTopics;			// 1D8 - Category::kService
		BSTArray<TESTopic*>										miscellaneousTopics;	// 1F0 - Category::kMiscellaneous
		BSTArray<BGSScene*>										scenes;					// 208
		BSTArray<TESGlobal*>*									textDisplayGlobals;		// 220 - QTGL
		UInt32													unk228;					// 228
		UInt32													pad22C;					// 22C
		BSString												editorID;				// 230
		UInt64													unk240;					// 240
		UInt64													unk248;					// 248
		BSTArray<RefHandle>										unk250;					// 250 - dynamically assigned ref handles?
	};
	STATIC_ASSERT(sizeof(TESQuest) == 0x268);
}
