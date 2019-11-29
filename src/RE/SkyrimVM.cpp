#include "RE/SkyrimVM.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	SkyrimVM* SkyrimVM::GetSingleton()
	{
		REL::Offset<SkyrimVM**> singleton(Offset::SkyrimVM::Singleton);
		return *singleton;
	}
}
