#include "RE/BSWin32SaveDataSystemUtility.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSWin32SaveDataSystemUtility* BSWin32SaveDataSystemUtility::GetSingleton()
	{
		using func_t = decltype(&BSWin32SaveDataSystemUtility::GetSingleton);
		REL::Offset<func_t> func(Offset::BSWin32SaveDataSystemUtility::GetSingleton);
		return func();
	}
}
