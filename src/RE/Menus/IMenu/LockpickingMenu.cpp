#include "RE/Menus/IMenu/LockpickingMenu.h"

#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* LockpickingMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::ID(519716) };
		return refptr->get();
	}
}
