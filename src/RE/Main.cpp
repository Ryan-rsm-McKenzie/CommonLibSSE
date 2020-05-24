#include "RE/Main.h"


namespace RE
{
	Main* Main::GetSingleton()
	{
		REL::Offset<Main**> singleton(Offset::Main::Singleton);
		return *singleton;
	}
}
