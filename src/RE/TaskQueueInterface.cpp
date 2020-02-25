#include "RE/TaskQueueInterface.h"

#include "REL/Relocation.h"


namespace RE
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		REL::Offset<TaskQueueInterface**> singleton(REL::ID(517228));
		return *singleton;
	}
}
