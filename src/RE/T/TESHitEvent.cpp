#include "RE/T/TESHitEvent.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESHitEvent::TESHitEvent() :
		TESHitEvent(nullptr, nullptr, static_cast<FormID>(0), static_cast<FormID>(0), Flag::kNone)
	{}

	TESHitEvent::TESHitEvent(TESObjectREFR* a_target, TESObjectREFR* a_aggressor, FormID a_weapon, FormID a_projectile, Flag a_flags) :
		target(a_target),
		cause(a_aggressor),
		source(a_weapon),
		projectile(a_projectile),
		flags(a_flags),
		pad19(0),
		pad1A(0),
		pad1C(0)
	{}
}
