#include "RE/BSTCreateFactoryManager.h"


#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	MessageDataFactoryManager* MessageDataFactoryManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&MessageDataFactoryManager::GetSingleton)>;
		REL::Offset<func_t*> func(Offset::MessageDataFactoryManager::GetSingleton);
		return func();
	}
}
