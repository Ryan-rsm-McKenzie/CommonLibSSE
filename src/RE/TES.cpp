#include "RE/TES.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Offset<TES**> singleton(Offset::TES::Singleton);
		return *singleton;
	}
}
