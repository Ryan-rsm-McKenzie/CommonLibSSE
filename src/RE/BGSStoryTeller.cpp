#include "RE/BGSStoryTeller.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSStoryTeller* BGSStoryTeller::GetSingleton()
	{
		REL::Offset<BGSStoryTeller**> singleton(Offset::BGSStoryTeller::Singleton);
		return *singleton;
	}


	void BGSStoryTeller::BeginShutDownQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginShutDownQuest);
		REL::Offset<func_t> func(Offset::BGSStoryTeller::BeginShutDownQuest);
		return func(this, a_quest);
	}


	void BGSStoryTeller::BeginStartUpQuest(TESQuest* a_quest)
	{
		using func_t = decltype(&BGSStoryTeller::BeginStartUpQuest);
		REL::Offset<func_t> func(Offset::BGSStoryTeller::BeginStartUpQuest);
		return func(this, a_quest);
	}
}
