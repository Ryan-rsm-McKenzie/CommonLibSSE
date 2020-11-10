#include "RE/Menus/IMenu/BookMenu.h"

#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* BookMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::ID(519300) };
		return refptr->get();
	}
}
