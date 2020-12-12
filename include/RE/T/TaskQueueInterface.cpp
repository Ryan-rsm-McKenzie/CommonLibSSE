#include "RE/Misc/TaskQueueInterface.h"


namespace RE
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		REL::Relocation<TaskQueueInterface**> singleton{ REL::ID(517228) };
		return *singleton;
	}
}
