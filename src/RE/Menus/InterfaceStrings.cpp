#include "RE/InterfaceStrings.h"


namespace RE
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		REL::Offset<InterfaceStrings**> singleton(Offset::InterfaceStrings::Singleton);
		return *singleton;
	}
}
