#include "RE/S/Sky.h"

namespace RE
{
	Sky* Sky::GetSingleton()
	{
		using func_t = decltype(&Sky::GetSingleton);
		REL::Relocation<func_t> func{ Offset::Sky::GetSingleton };
		return func();
	}
}
