#include "RE/FileIO/ICellAttachDetachEventSource/TES.h"


namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Offset<TES**> singleton(Offset::TES::Singleton);
		return *singleton;
	}
}
