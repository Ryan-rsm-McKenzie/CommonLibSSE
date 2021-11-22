#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ REL::ID(403520) };
		return *handle;
	}
}
