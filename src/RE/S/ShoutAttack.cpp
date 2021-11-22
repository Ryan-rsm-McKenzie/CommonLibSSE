#include "RE/S/ShoutAttack.h"

namespace RE
{
	BSTEventSource<ShoutAttack::Event>* ShoutAttack::GetEventSource()
	{
		using func_t = decltype(&ShoutAttack::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(41071) };
		return func();
	}
}
