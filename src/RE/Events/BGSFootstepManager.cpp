#include "RE/Events/BGSFootstepManager.h"


namespace RE
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		REL::Offset<BGSFootstepManager**> singleton(Offset::BGSFootstepManager::Singleton);
		return *singleton;
	}
}
