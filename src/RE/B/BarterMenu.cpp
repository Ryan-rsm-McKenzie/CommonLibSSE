#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ REL::ID(519283) };
		return *handle;
	}
}
