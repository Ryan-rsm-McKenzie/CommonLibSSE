#include "RE/L/LevelIncrease.h"

namespace RE
{
	BSTEventSource<LevelIncrease::Event>* LevelIncrease::GetEventSource()
	{
		using func_t = decltype(&LevelIncrease::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(39247) };
		return func();
	}
}
