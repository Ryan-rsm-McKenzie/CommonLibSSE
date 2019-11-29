#include "RE/TESQuest.h"


namespace RE
{
	TESQuest::Stage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}
}
