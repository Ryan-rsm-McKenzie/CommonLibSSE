#include "RE/TESQuest.h"


namespace RE
{
	TESQuestStage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}
}
