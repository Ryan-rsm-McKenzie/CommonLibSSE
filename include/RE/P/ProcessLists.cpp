#include "RE/P/ProcessLists.h"

#include "RE/M/ModelReferenceEffect.h"
#include "RE/S/ShaderReferenceEffect.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TempEffectTraits.h"

namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Relocation<ProcessLists**> singleton{ REL::ID(514167) };
		return *singleton;
	}

	void ProcessLists::ClearCachedFactionFightReactions() const
	{
		using func_t = decltype(&ProcessLists::ClearCachedFactionFightReactions);
		REL::Relocation<func_t> func{ REL::ID(40396) };
		return func(this);
	}

	void ProcessLists::GetMagicEffects(std::function<bool(BSTempEffect& a_tempEffect)> a_fn)
	{
		BSSpinLockGuard locker(magicEffectsLock);

		for (auto& tempEffectPtr : magicEffects) {
			const auto& tempEffect = tempEffectPtr.get();
			if (tempEffect && !a_fn(*tempEffect)) {
				break;
			}
		}
	}

	void ProcessLists::GetModelEffects(std::function<bool(ModelReferenceEffect& a_modelEffect)> a_fn)
	{
		GetMagicEffects([&](BSTempEffect& a_tempEffect) {
			const auto modelEffect = a_tempEffect.As<ModelReferenceEffect>();
			if (modelEffect && !a_fn(*modelEffect)) {
				return false;
			}
			return true;
		});
	}

	void ProcessLists::GetShaderEffects(std::function<bool(ShaderReferenceEffect& a_shaderEffect)> a_fn)
	{
		GetMagicEffects([&](BSTempEffect& a_tempEffect) {
			const auto shaderEffect = a_tempEffect.As<ShaderReferenceEffect>();
			if (shaderEffect && !a_fn(*shaderEffect)) {
				return false;
			}
			return true;
		});
	}

	void ProcessLists::StopAllMagicEffects(TESObjectREFR& a_ref)
	{
		auto handle = a_ref.CreateRefHandle();
		GetMagicEffects([&](BSTempEffect& a_tempEffect) {
			const auto referenceEffect = a_tempEffect.As<ReferenceEffect>();
			if (referenceEffect && referenceEffect->target == handle) {
				referenceEffect->finished = true;
			}
			return true;
		});
	}

	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Relocation<func_t> func{ REL::ID(40330) };
		return func(this, a_actor, a_notAlarm);
	}
}
