#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/TESCondition.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSSceneAction;


	class BGSScene : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSScene;


		enum { kTypeID = FormType::Scene };


		enum class Flag : UInt32
		{
			kNone = 0,
			kBeginOnQuestStart = 1 << 0,
			kStopOnQuestEnd = 1 << 1,
			kRepeatConditionsWhileTrue = 1 << 3,
			kInterruptible = 1 << 4
		};


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kActive = (UInt32)1 << 31
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


		struct Phase
		{
			TESCondition				startConditions;		// 00
			TESCondition				completionConditions;	// 08
			BGSStoryManagerQuestNode*	questNode;				// 10
		};
		STATIC_ASSERT(sizeof(Phase) == 0x18);


		struct Actor
		{
			enum class Flag : UInt32	// LNAM
			{
				kNone = 0,
				kNoPlayerActivation = 1 << 0,
				kOptional = 1 << 1
			};


			enum class BehaviourFlag : UInt32	// DNAM
			{
				kNone = 0,
				kDeathPause = 1 << 0,	// unused
				kDeathEnd = 1 << 1,
				kCombatPause = 1 << 2,
				kCombatEnd = 1 << 3,
				kDialoguePause = 1 << 4,
				kDialogueEnd = 1 << 5,
				kOBS_COMPause = 1 << 6,
				kOBS_COMEnd = 1 << 7
			};


			BSTArray<UInt32>		actorIDs;		// 00 - ALID
			BSTArray<Flag>			flags;			// 18 - LNAM
			BSTArray<BehaviourFlag>	behaviourFlags;	// 30 - DNAM
		};
		STATIC_ASSERT(sizeof(Actor) == 0x48);


		virtual ~BGSScene();											// 00

		// override (TESForm)
		virtual void	InitializeData() override;						// 05
		virtual bool	Load(TESFile* a_mod) override;					// 06
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	InitLoadGame(void* a_arg1) override;			// 10
		virtual void	Revert(void* a_arg1) override;					// 12
		virtual void	InitItemImpl() override;						// 13


		// members
		BSTArray<Phase*>			phases;		// 20
		Actor						actors;		// 38
		BSTArray<BGSSceneAction*>	actions;	// 80
		TESQuest*					quest;		// 98 - PNAM
		Flag						flags;		// A0 - FNAM
		UInt32						padA4;		// A4
		TESCondition				conditions;	// A8 - CTDA
		UInt64						unkB0;		// B0
		UInt64						unkB8;		// B8
		UInt32						unkC0;		// C0
		UInt32						padC4;		// C4
	};
	STATIC_ASSERT(sizeof(BGSScene) == 0xC8);
}
