#include "RE/SkyrimVM.h"  // SkyrimVM

#include "skse64/PapyrusVM.h"  // g_skyrimVM


namespace RE
{
	SkyrimVM* SkyrimVM::GetSingleton()
	{
		return *reinterpret_cast<SkyrimVM**>(g_skyrimVM.GetUIntPtr());
	}
}
