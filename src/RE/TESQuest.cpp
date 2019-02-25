#include "RE/TESQuest.h"

#include <cstdint>  // uintptr_t


namespace RE
{
	bool TESQuest::Stage::IsValid() const
	{
		return *reinterpret_cast<const std::uintptr_t*>(this) != 0;
	}
}
