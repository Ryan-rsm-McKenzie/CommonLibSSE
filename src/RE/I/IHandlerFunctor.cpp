#include "RE/I/IHandlerFunctor.h"

namespace RE
{
	HandlerDictionary* HandlerDictionary::GetSingleton()
	{
		REL::Relocation<HandlerDictionary**> singleton{ REL::Offset(0x2FE3050) };
		return *singleton;
	}
}
