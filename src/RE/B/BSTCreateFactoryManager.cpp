#include "RE/B/BSTCreateFactoryManager.h"

namespace RE
{
	MessageDataFactoryManager* MessageDataFactoryManager::GetSingleton()
	{
		using func_t = decltype(&MessageDataFactoryManager::GetSingleton);
		REL::Relocation<func_t> func{ Offset::MessageDataFactoryManager::GetSingleton };
		return func();
	}
}
