#include "RE/TESObjectMISC.h"


namespace RE
{
	TESObjectMISC* TESObjectMISC::GetGoldForm()
	{
		return RE::TESForm::LookupByID<TESObjectMISC>(0x0000000F);
	}
}
