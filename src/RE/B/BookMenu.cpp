#include "RE/B/BookMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* BookMenu::GetTargetReference()
	{
		REL::Relocation<TESObjectREFRPtr*> refptr{ REL::ID(519300) };
		return refptr->get();
	}
}
