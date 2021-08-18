#include "RE/B/BGSStoryTeller.h"

namespace RE
{
	BGSStoryTeller* BGSStoryTeller::GetSingleton()
	{
		REL::Relocation<BGSStoryTeller**> singleton{ Offset::BGSStoryTeller::Singleton };
		return *singleton;
	}

	void BGSStoryTeller::BeginShutDownQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginShutDownQuest);
		REL::Relocation<func_t> func{ Offset::BGSStoryTeller::BeginShutDownQuest };
		return func(this, a_quest);
	}

	void BGSStoryTeller::BeginStartUpQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginStartUpQuest);
		REL::Relocation<func_t> func{ Offset::BGSStoryTeller::BeginStartUpQuest };
		return func(this, a_quest);
	}
}
