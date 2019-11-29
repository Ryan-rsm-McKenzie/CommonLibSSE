#include "RE/TESHitEvent.h"

#include "RE/TESObjectREFR.h"


namespace RE
{
	TESHitEvent::TESHitEvent() :
		target(),
		aggressor(),
		weapon(static_cast<FormID>(0)),
		projectile(static_cast<FormID>(0)),
		flags(Flag::kNone),
		pad19(0),
		pad1A(0),
		pad1C(0)
	{}


	TESHitEvent::TESHitEvent(TESObjectREFR* a_target, TESObjectREFR* a_aggressor, FormID a_weapon, FormID a_projectile, Flag a_flags) :
		target(a_target),
		aggressor(a_aggressor),
		weapon(a_weapon),
		projectile(a_projectile),
		flags(a_flags),
		pad19(0),
		pad1A(0),
		pad1C(0)
	{}
}
