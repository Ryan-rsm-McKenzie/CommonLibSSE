#include "RE/NiControllerManager.h"

#include "RE/NiControllerSequence.h"


namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(std::string_view a_name)
	{
		auto it = sequenceMap.find(a_name);
		return it != sequenceMap.end() ? it->second : nullptr;
	}
}
