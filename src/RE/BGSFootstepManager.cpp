#include "RE/BGSFootstepManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		REL::Offset<BGSFootstepManager**> singleton(Offset::BGSFootstepManager::Singleton);
		return *singleton;
	}
}
