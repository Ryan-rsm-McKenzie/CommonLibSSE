#include "RE/C/ContainerMenu.h"

namespace RE
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		REL::Relocation<ContainerMode*> mode{ REL::ID(519396) };
		return *mode;
	}

	RefHandle ContainerMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ REL::ID(519421) };
		return *handle;
	}
}
