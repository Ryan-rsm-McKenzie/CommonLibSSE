#pragma once

#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSceneAction;

	enum class SCENE_ACTOR_FLAG	 // LNAM
	{
		kNone = 0,
		kNoPlayerActivation = 1 << 0,
		kOptional = 1 << 1,
		kRunOnlyScenePackages = 1 << 2,
		kNoCommandState = 1 << 3
	};

	class BGSScenePhase
	{
	public:
		// members
		TESCondition			  startConditions;		 // 00
		TESCondition			  completionConditions;	 // 08
		BGSStoryManagerQuestNode* questNode;			 // 10
	};
	static_assert(sizeof(BGSScenePhase) == 0x18);

	class BGSScene : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSScene;
		inline static constexpr auto FORMTYPE = FormType::Scene;

		enum class Flag
		{
			kNone = 0,
			kBeginOnQuestStart = 1 << 0,
			kStopOnQuestEnd = 1 << 1,
			kRepeatConditionsWhileTrue = 1 << 3,
			kInterruptible = 1 << 4
		};

		enum class BehaviourFlag  // DNAM
		{
			kNone = 0,
			kDeathPause = 1 << 0,  // unused
			kDeathEnd = 1 << 1,
			kCombatPause = 1 << 2,
			kCombatEnd = 1 << 3,
			kDialoguePause = 1 << 4,
			kDialogueEnd = 1 << 5,
			kOBS_COMPause = 1 << 6,
			kOBS_COMEnd = 1 << 7
		};

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kActive = (std::uint32_t)1 << 31
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

		virtual ~BGSScene();  // 00

		// override (TESForm)
		virtual void InitializeData() override;						   // 05
		virtual bool Load(TESFile* a_mod) override;					   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;	   // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;	   // 0F
		virtual void InitLoadGame(BGSLoadFormBuffer* a_buf) override;  // 10
		virtual void Revert(BGSLoadFormBuffer* a_buf) override;		   // 12
		virtual void InitItemImpl() override;						   // 13

		// members
		BSTArray<BGSScenePhase*>									phases;					// 20
		BSTArray<FormID>											actors;					// 00 - ALID
		BSTArray<stl::enumeration<SCENE_ACTOR_FLAG, std::uint32_t>> actorFlags;				// 18 - LNAM
		BSTArray<stl::enumeration<BehaviourFlag, std::uint32_t>>	actorProgressionFlags;	// 30 - DNAM
		BSTArray<BGSSceneAction*>									actions;				// 80
		TESQuest*													parentQuest;			// 98 - PNAM
		stl::enumeration<Flag, std::uint32_t>						flags;					// A0 - FNAM
		std::uint32_t												padA4;					// A4
		TESCondition												conditions;				// A8 - CTDA
		std::uint32_t												unkB0;					// B0
		std::uint32_t												unkB4;					// B4
		std::uint32_t												unkB8;					// B8
		std::uint32_t												unkBC;					// BC
		std::uint32_t												unkC0;					// C0
		std::uint32_t												padC4;					// C4
	};
	static_assert(sizeof(BGSScene) == 0xC8);
}
