#include "RE/FormComponents/Components/IHandlerFunctor.h"


namespace RE
{
	HandlerDictionary* HandlerDictionary::GetSingleton()
	{
		REL::Relocation<HandlerDictionary**> singleton{ REL::ID(518086) };
		return *singleton;
	}
}
