#include "RE/B/BookMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectBOOK* BookMenu::GetTargetForm()
	{
		REL::Relocation<TESObjectBOOK**> book{ REL::ID(519295) };
		return *book;
	}

	TESObjectREFR* BookMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::Offset(0x2FE6C38) };
		return refptr->get();
	}
}
