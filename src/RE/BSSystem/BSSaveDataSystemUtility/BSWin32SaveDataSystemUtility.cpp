#include "RE/BSSystem/BSSaveDataSystemUtility/BSWin32SaveDataSystemUtility.h"


namespace RE
{
	BSWin32SaveDataSystemUtility* BSWin32SaveDataSystemUtility::GetSingleton()
	{
		using func_t = decltype(&BSWin32SaveDataSystemUtility::GetSingleton);
		REL::Offset<func_t> func(Offset::BSWin32SaveDataSystemUtility::GetSingleton);
		return func();
	}
}
