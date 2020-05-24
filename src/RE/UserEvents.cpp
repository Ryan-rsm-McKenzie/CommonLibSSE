#include "RE/UserEvents.h"


namespace RE
{
	UserEvents* UserEvents::GetSingleton()
	{
		REL::Offset<UserEvents**> singleton(Offset::UserEvents::Singleton);
		return *singleton;
	}
}
