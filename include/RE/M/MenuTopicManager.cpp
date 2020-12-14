#include "RE/M/MenuTopicManager.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	MenuTopicManager* MenuTopicManager::GetSingleton()
	{
		REL::Relocation<NiPointer<MenuTopicManager>*> singleton{ REL::ID(514959) };
		return singleton->get();
	}
}
