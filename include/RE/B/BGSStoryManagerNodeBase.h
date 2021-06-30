#pragma once

#include "RE/B/BGSStoryManagerTreeForm.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class BGSStoryManagerNodeBase : public BGSStoryManagerTreeForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSStoryManagerNodeBase;

		struct Flags  // DNAM
		{
		public:
			enum class NodeFlag
			{
				kNone = 0,
				kRandom = 1 << 0,
				kWarnIfNoChildQuestStarted = 1 << 1
			};

			enum class QuestFlag
			{
				kNone = 0,
				kDoAllBeforeRepeating = 1 << 0,
				kSharesEvent = 1 << 1,
				kNumQuestsToRun = 1 << 2
			};

			// members
			stl::enumeration<NodeFlag, std::uint16_t>  nodeFlags;  // 0
			stl::enumeration<QuestFlag, std::uint16_t> questFags;  // 2
		};
		static_assert(sizeof(Flags) == 0x4);

		~BGSStoryManagerNodeBase() override;  // 00

		// override (BGSStoryManagerTreeForm)
		void          InitializeData() override;      // 04
		void          ClearData() override;           // 05
		bool          Load(TESFile* a_mod) override;  // 06
		void          InitItemImpl() override;        // 13
		TESCondition* QConditions() override;         // 3D - { return &conditions; }

		// members
		BGSStoryManagerBranchNode* parent;           // 28 - PNAM
		BGSStoryManagerNodeBase*   previousSibling;  // 30 - SNAM
		std::uint32_t              maxQuests;        // 38 - XNAM
		Flags                      flags;            // 3C - DNAM
		TESCondition               conditions;       // 40 - CITC
	};
	static_assert(sizeof(BGSStoryManagerNodeBase) == 0x48);
}
