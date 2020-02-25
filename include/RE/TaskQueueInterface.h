#pragma once


namespace RE
{
	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();
	};
	//STATIC_ASSERT(sizeof(TaskQueueInterface) == 0x);
}
