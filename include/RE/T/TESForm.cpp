#include "RE/T/TESForm.h"

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/F/FormTraits.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/V/VirtualMachine.h"

namespace RE
{
	std::int32_t TESForm::GetGoldValue() const
	{
		const auto obj = As<TESBoundObject>();
		if (obj) {
			const InventoryEntryData entry{ const_cast<TESBoundObject*>(obj), 1 };
			return entry.GetValue();
		} else {
			return -1;
		}
	}

	const char* TESForm::GetName() const
	{
		const auto fullName = As<TESFullName>();
		if (fullName) {
			const auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}

	float TESForm::GetWeight() const
	{
		const auto survival = []() {
			const auto dobj = BGSDefaultObjectManager::GetSingleton();
			const auto survival = dobj ? dobj->GetObject<TESGlobal>(DEFAULT_OBJECT::kSurvivalModeEnabled) : nullptr;
			return survival ? survival->value == 1.0F : false;
		};

		const auto ref = As<TESObjectREFR>();
		const auto baseObj = ref ? ref->GetBaseObject() : nullptr;
		const auto form = baseObj ? baseObj : this;
		if (!survival() && (form->IsAmmo() || form->IsLockpick())) {
			return 0.0F;
		} else if (const auto weightForm = form->As<TESWeightForm>(); weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			const auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0;
		}
	}

	bool TESForm::HasVMAD() const
	{
		const auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		const auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		const auto handle = policy->GetHandleForObject(GetFormType(), this);
		return handle != policy->EmptyHandle();
	}

	bool TESForm::HasWorldModel() const noexcept
	{
		return As<TESModel>() != nullptr;
	}
}
