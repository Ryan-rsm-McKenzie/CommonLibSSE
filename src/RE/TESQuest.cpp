#include "RE/TESQuest.h"

#include <cstdint>  // uintptr_t


namespace RE
{
	TESQuest::Stage::operator bool() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}
}
