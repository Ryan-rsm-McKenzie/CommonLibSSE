#include "RE/L/LocationDiscovery.h"

namespace RE
{
	BSTEventSource<LocationDiscovery::Event>* LocationDiscovery::GetEventSource()
	{
		using func_t = decltype(&LocationDiscovery::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(40056) };
		return func();
	}
}
