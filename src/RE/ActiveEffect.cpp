#include "RE/ActiveEffect.h"

#include "RE/Actor.h"  // Actor
#include "RE/Effect.h"  // Effect
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "REL/Relocation.h"


namespace RE
{
	void ActiveEffect::Dispell(bool a_force)
	{
		using func_t = function_type_t<decltype(&ActiveEffect::Dispell)>;
		REL::Offset<func_t*> func(Offset::ActiveEffect::Dispell);
		return func(this, a_force);
	}


	EffectSetting* ActiveEffect::GetBaseObject()
	{
		return effect->baseEffect;
	}


	const EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect->baseEffect;
	}


	Actor* ActiveEffect::GetCasterActor()
	{
		RE::TESObjectREFRPtr ref;
		RE::TESObjectREFR::LookupByHandle(casterActor, ref);
		return static_cast<Actor*>(ref.get());
	}


	const Actor* ActiveEffect::GetCasterActor() const
	{
		RE::TESObjectREFRPtr ref;
		RE::TESObjectREFR::LookupByHandle(casterActor, ref);
		return static_cast<const Actor*>(ref.get());
	}


	Actor* ActiveEffect::GetTargetActor()
	{
		if (magicTarget && magicTarget->IsActorMagicTarget()) {
			return static_cast<Actor*>(magicTarget);
		} else {
			return 0;
		}
	}


	const Actor* ActiveEffect::GetTargetActor() const
	{
		if (magicTarget && magicTarget->IsActorMagicTarget()) {
			return static_cast<const Actor*>(magicTarget);
		} else {
			return 0;
		}
	}
}
