#include "RE/InputStringHolder.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InputStringHolder* InputStringHolder::GetSingleton()
	{
		REL::Offset<InputStringHolder**> singleton(Offset::InputStringHolder::Singleton);
		return *singleton;
	}
}
