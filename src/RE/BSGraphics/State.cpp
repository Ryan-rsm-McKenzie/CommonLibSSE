#include "RE/BSGraphics/State.h"

#include "REL/Relocation.h"


namespace RE
{
	namespace BSGraphics
	{
		State* State::GetSingleton()
		{
			REL::Offset<State*> singleton = REL::ID(524998);
			return singleton.GetType();
		}
	}
}
