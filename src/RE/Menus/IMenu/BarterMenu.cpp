#include "RE/Menus/IMenu/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ REL::ID(519283) };
		return *handle;
	}
}
