#include "RE/ActiveEffect.h"

#include "RE/Actor.h"
#include "RE/Effect.h"
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
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
		return effect ? effect->baseEffect : 0;
	}


	const EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect ? effect->baseEffect : 0;
	}


	Actor* ActiveEffect::GetCasterActor()
	{
		auto ref = TESObjectREFR::LookupByHandle(casterActor);
		return static_cast<Actor*>(ref.get());
	}


	const Actor* ActiveEffect::GetCasterActor() const
	{
		auto ref = TESObjectREFR::LookupByHandle(casterActor);
		return static_cast<const Actor*>(ref.get());
	}


	Actor* ActiveEffect::GetTargetActor()
	{
		if (magicTarget && magicTarget->MagicTargetIsActor()) {
			return static_cast<Actor*>(magicTarget);
		} else {
			return 0;
		}
	}


	const Actor* ActiveEffect::GetTargetActor() const
	{
		if (magicTarget && magicTarget->MagicTargetIsActor()) {
			return static_cast<const Actor*>(magicTarget);
		} else {
			return 0;
		}
	}
}
