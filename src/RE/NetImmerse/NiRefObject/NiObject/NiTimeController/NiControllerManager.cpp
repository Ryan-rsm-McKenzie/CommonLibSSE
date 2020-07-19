#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiControllerManager.h"

#include "RE/NetImmerse/NiRefObject/NiObject/NiControllerSequence.h"


namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(std::string_view a_name)
	{
		auto it = stringMap.find(a_name);
		return it != stringMap.end() ? it->second : nullptr;
	}
}
