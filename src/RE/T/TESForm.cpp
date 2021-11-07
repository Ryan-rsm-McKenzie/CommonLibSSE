#include "RE/T/TESForm.h"

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BGSKeywordForm.h"
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
			return -1.0F;
		}
	}

	bool TESForm::HasKeywords(const std::vector<BGSKeyword*>& a_keywords, bool a_matchAll) const
	{
		if (!a_keywords.empty()) {
			const auto keywordForm = As<BGSKeywordForm>();
			if (keywordForm) {
				const auto has_keyword = [&]() {
					return [&](const BGSKeyword* a_keyword) {
						return a_keyword && keywordForm->HasKeyword(a_keyword);
					};
				};
				if (a_matchAll) {
					return std::ranges::all_of(a_keywords, has_keyword());
				} else {
					return std::ranges::any_of(a_keywords, has_keyword());
				}
			}
		}
		return true;
	}

	bool TESForm::HasKeywords(BGSListForm* a_keywords, bool a_matchAll) const
	{
		if (a_keywords) {
			const auto keywordForm = As<BGSKeywordForm>();
			if (keywordForm) {
				const auto form_has_keyword = [&]() {
					return [&](const TESForm* a_form) {
						const auto keyword = a_form ? a_form->As<BGSKeyword>() : nullptr;
						return keyword && keywordForm->HasKeyword(keyword);
					};
				};
				const auto id_has_keyword = [&]() {
					return [&](const std::uint32_t a_ID) {
						const auto keyword = LookupByID<BGSKeyword>(a_ID);
						return keyword && keywordForm->HasKeyword(keyword);
					};
				};
				if (a_matchAll) {
					if (std::ranges::none_of(a_keywords->forms, form_has_keyword())) {
						return false;
					}
					if (a_keywords->scriptAddedTempForms && std::ranges::none_of(*a_keywords->scriptAddedTempForms, id_has_keyword())) {
						return false;
					}
					return true;
				} else {
					if (std::ranges::any_of(a_keywords->forms, form_has_keyword())) {
						return true;
					}
					if (a_keywords->scriptAddedTempForms && std::ranges::any_of(*a_keywords->scriptAddedTempForms, id_has_keyword())) {
						return true;
					}
					return false;
				}
			}
		}
		return true;
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
