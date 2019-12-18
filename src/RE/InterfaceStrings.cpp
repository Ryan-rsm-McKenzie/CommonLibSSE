#include "RE/InterfaceStrings.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		REL::Offset<InterfaceStrings**> singleton(Offset::InterfaceStrings::Singleton);
		return *singleton;
	}
}
