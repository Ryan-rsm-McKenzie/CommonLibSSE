#include "RE/Sky.h"

#include "RE/Offsets.h"


namespace RE
{
	Sky* Sky::GetSingleton()
	{
		using func_t = function_type_t<decltype(&Sky::GetSingleton)>;
		RelocUnrestricted<func_t*> func(Offset::Sky::GetSingleton);
		return func();
	}
}
