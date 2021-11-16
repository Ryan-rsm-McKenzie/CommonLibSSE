#include "RE/C/ContainerMenu.h"

namespace RE
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		REL::Relocation<ContainerMode*> mode{ REL::Offset(0x2FE6FF0) };
		return *mode;
	}

	RefHandle ContainerMenu::GetTargetRefHandle()
	{
		REL::Relocation<RefHandle*> handle{ REL::Offset(0x2FE70B8) };
		return *handle;
	}
}
