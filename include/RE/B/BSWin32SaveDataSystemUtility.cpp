#include "RE/B/BSWin32SaveDataSystemUtility.h"

namespace RE
{
	BSWin32SaveDataSystemUtility* BSWin32SaveDataSystemUtility::GetSingleton()
	{
		using func_t = decltype(&BSWin32SaveDataSystemUtility::GetSingleton);
		REL::Relocation<func_t> func{ Offset::BSWin32SaveDataSystemUtility::GetSingleton };
		return func();
	}
}
