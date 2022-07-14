#include "RE/T/TESBoundObject.h"

namespace RE
{
	void TESBoundObject::NotifyPickup(std::uint32_t a_count, std::uint8_t a_arg2, bool a_playSound, void* a_arg4)
	{
		using func_t = decltype(&TESBoundObject::NotifyPickup);
		REL::Relocation<func_t> func{ REL::ID(51636) };
		return func(this, a_count, a_arg2, a_playSound, a_arg4);
	}
}
