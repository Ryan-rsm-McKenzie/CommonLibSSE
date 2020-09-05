#include "RE/Events/BGSFootstepManager.h"


namespace RE
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		REL::Relocation<BGSFootstepManager**> singleton{ Offset::BGSFootstepManager::Singleton };
		return *singleton;
	}
}
