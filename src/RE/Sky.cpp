#include "RE/Sky.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Sky* Sky::GetSingleton()
	{
		using func_t = decltype(&Sky::GetSingleton);
		REL::Offset<func_t> func(Offset::Sky::GetSingleton);
		return func();
	}
}
