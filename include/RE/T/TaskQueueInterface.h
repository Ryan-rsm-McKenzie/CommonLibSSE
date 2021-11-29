#pragma once

namespace RE
{
	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();
	};
	//static_assert(sizeof(TaskQueueInterface) == 0x);
}
