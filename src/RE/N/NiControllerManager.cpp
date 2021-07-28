#include "RE/N/NiControllerManager.h"

#include "RE/N/NiControllerSequence.h"

namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(std::string_view a_name)
	{
		auto it = stringMap.find(a_name);
		return it != stringMap.end() ? it->second : nullptr;
	}
}
