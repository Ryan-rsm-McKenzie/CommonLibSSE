#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class SpellItem;

	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();

		static bool ShouldUseTaskQueue();

		std::uint32_t QueueBulletWaterDisplacementTask(float a_scale, const NiPoint3& a_pos);            // 45
		std::uint32_t QueueRemoveSpellTask(RE::ActorHandle& a_actorHandle, RE::SpellItem* a_spellItem);  // 93
	};
	//static_assert(sizeof(TaskQueueInterface) == 0x);
}
