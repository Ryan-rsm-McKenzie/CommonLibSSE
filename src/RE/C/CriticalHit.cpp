#include "RE/C/CriticalHit.h"

namespace RE
{
	BSTEventSource<CriticalHit::Event>* CriticalHit::GetEventSource()
	{
		using func_t = decltype(&CriticalHit::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(38671) };
		return func();
	}
}
