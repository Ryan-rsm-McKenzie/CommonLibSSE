#include "RE/Menus/InterfaceStrings.h"


namespace RE
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		REL::Relocation<InterfaceStrings**> singleton{ Offset::InterfaceStrings::Singleton };
		return *singleton;
	}
}
