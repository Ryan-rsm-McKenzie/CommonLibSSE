#include "RE/Menus/MenuTopicManager.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	MenuTopicManager* MenuTopicManager::GetSingleton()
	{
		REL::Relocation<NiPointer<MenuTopicManager>*> singleton{ REL::ID(514959) };
		return singleton->get();
	}
}
