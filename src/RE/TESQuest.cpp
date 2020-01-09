#include "RE/TESQuest.h"

#include "RE/BGSStoryTeller.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESQuestStage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}


	bool TESQuest::IsEnabled() const
	{
		return (data.flags & QuestFlag::kEnabled) != QuestFlag::kNone;
	}


	void TESQuest::Reset()
	{
		using func_t = function_type_t<decltype(&TESQuest::Reset)>;
		REL::Offset<func_t*> func(Offset::TESQuest::Reset);
		return func(this);
	}


	void TESQuest::ResetAndUpdate()
	{
		Reset();

		auto enabled = IsEnabled();
		if (enabled != StartsEnabled()) {
			auto storyTeller = BGSStoryTeller::GetSingleton();
			if (enabled) {
				storyTeller->BeginStartUpQuest(this);
			} else {
				storyTeller->BeginShutDownQuest(this);
			}
		}
	}


	bool TESQuest::StartsEnabled() const
	{
		return (data.flags & QuestFlag::kStartsEnabled) != QuestFlag::kNone;
	}
}
