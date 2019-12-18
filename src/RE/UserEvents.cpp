#include "RE/UserEvents.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	UserEvents* UserEvents::GetSingleton()
	{
		REL::Offset<UserEvents**> singleton(Offset::UserEvents::Singleton);
		return *singleton;
	}
}
