#include "RE/B/BookMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectBOOK* BookMenu::GetTargetForm()
	{
		REL::Relocation<TESObjectBOOK**> book{ REL::Offset(0x2FE6C10) };
		return *book;
	}

	TESObjectREFR* BookMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::ID(405840) };
		return refptr->get();
	}
}
