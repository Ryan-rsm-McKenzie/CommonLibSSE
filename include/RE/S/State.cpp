#include "RE/S/State.h"

namespace RE
{
	namespace BSGraphics
	{
		State* State::GetSingleton()
		{
			REL::Relocation<State*> singleton{ REL::ID(524998) };
			return singleton.type();
		}
	}
}
