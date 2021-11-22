#include "RE/I/IHandlerFunctor.h"

namespace RE
{
	HandlerDictionary* HandlerDictionary::GetSingleton()
	{
		REL::Relocation<HandlerDictionary**> singleton{ REL::ID(404607) };
		return *singleton;
	}
}
