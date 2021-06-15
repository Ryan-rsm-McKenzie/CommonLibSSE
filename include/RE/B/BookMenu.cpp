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
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::ID(519300) };
		return refptr->get();
	}
}
