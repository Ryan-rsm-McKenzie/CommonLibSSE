#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();

		static bool ShouldUseTaskQueue();

		std::uint32_t QueueBulletWaterDisplacementTask(float a_scale, const NiPoint3& a_pos);  // 45
	};
	//static_assert(sizeof(TaskQueueInterface) == 0x);
}
