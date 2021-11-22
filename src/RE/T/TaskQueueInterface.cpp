#include "RE/T/TaskQueueInterface.h"

namespace RE
{
	TaskQueueInterface* TaskQueueInterface::GetSingleton()
	{
		REL::Relocation<TaskQueueInterface**> singleton{ REL::ID(403759) };
		return *singleton;
	}

	bool TaskQueueInterface::ShouldUseTaskQueue()
	{
		using func_t = decltype(&TaskQueueInterface::ShouldUseTaskQueue);
		REL::Relocation<func_t> func{ REL::ID(39033) };
		return func();
	}

	std::uint32_t TaskQueueInterface::QueueCreateRipple(float a_scale, const NiPoint3& a_pos)
	{
		using func_t = decltype(&TaskQueueInterface::QueueCreateRipple);
		REL::Relocation<func_t> func{ REL::ID(36953) };
		return func(this, a_scale, a_pos);
	}

	std::uint32_t TaskQueueInterface::QueueRemoveSpell(RE::ActorHandle& a_actorHandle, RE::SpellItem* a_spellItem)
	{
		using func_t = decltype(&TaskQueueInterface::QueueRemoveSpell);
		REL::Relocation<func_t> func{ REL::ID(36962) };
		return func(this, a_actorHandle, a_spellItem);
	}
}
