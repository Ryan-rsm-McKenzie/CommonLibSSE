#include "RE/Main.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Main* Main::GetSingleton()
	{
		REL::Offset<Main**> singleton(Offset::Main::Singleton);
		return *singleton;
	}
}
