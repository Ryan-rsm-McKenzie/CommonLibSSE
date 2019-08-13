#include "RE/TESForm.h"

#include "RE/ExtraEnchantment.h"  // ExtraEnchantment
#include "RE/FormTraits.h"  // As
#include "RE/GlobalLookupInfo.h"  // GlobalLookupInfo
#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESModel.h"  // TESModel
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "RE/TESValueForm.h"  // TESValueForm


namespace RE
{
	TESForm* TESForm::LookupByID(FormID a_formID)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		RE::BSReadLockGuard locker(lookup->formIDsLock);
		if (!lookup->formIDs) {
			return 0;
		}

		auto& formIDs = *lookup->formIDs;
		auto it = formIDs.find(a_formID);
		return it != formIDs.end() ? it->second : 0;
	}


	TESForm* TESForm::LookupByEditorID(const std::string_view& a_editorID)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		RE::BSReadLockGuard locker(lookup->editorIDsLock);
		if (!lookup->editorIDs) {
			return 0;
		}

		auto& editorIDs = *lookup->editorIDs;
		auto it = editorIDs.find(a_editorID);
		return it != editorIDs.end() ? it->second : 0;
	}


	bool TESForm::Is(FormType a_type) const
	{
		return formType == a_type;
	}


	bool TESForm::IsNot(FormType a_type) const
	{
		return formType != a_type;
	}


	bool TESForm::IsKey() const
	{
		return Is(FormType::KeyMaster);
	}


	bool TESForm::IsWeapon() const
	{
		return Is(FormType::Weapon);
	}


	bool TESForm::IsAmmo() const
	{
		return Is(FormType::Ammo);
	}


	bool TESForm::IsArmor() const
	{
		return Is(FormType::Armor);
	}


	bool TESForm::IsSoulGem() const
	{
		return Is(FormType::SoulGem);
	}


	bool TESForm::IsLockpick() const
	{
		return formID == 0x0000000A;
	}


	bool TESForm::IsGold() const
	{
		return formID == 0x0000000F;
	}


	bool TESForm::IsPlayer() const
	{
		return formID == 0x00000007;
	}


	bool TESForm::IsPlayerRef() const
	{
		return formID == 0x00000014;
	}


	bool TESForm::IsDynamicForm() const
	{
		return formID >= 0xFF000000;
	}


	bool TESForm::HasWorldModel() const
	{
		return As<TESModel*>() != 0;
	}


	FormID TESForm::GetFormID() const
	{
		return formID;
	}


	float TESForm::GetWeight() const
	{
		auto ref = As<TESObjectREFR*>();
		auto form = ref ? ref->baseForm : this;
		auto weightForm = form->As<TESWeightForm*>();
		if (weightForm) {
			return weightForm->weight;
		} else {
			return -1.0;
		}
	}


	SInt32 TESForm::GetGoldValue() const
	{
		SInt32 value = 0;
		auto form = this;
		auto objRef = As<TESObjectREFR*>();
		if (objRef) {
			form = objRef->baseForm;
			auto xEnch = objRef->extraData.GetByType<ExtraEnchantment>();
			if (xEnch && xEnch->objectEffect) {
				value += xEnch->objectEffect->CalculateTotalGoldValue();
			}
		}

		auto valueForm = form->As<TESValueForm*>();
		if (valueForm) {
			value += valueForm->value;
		} else {
			auto magicItem = form->As<MagicItem*>();
			if (magicItem) {
				value += magicItem->CalculateTotalGoldValue();
			} else {
				value = -1;
			}
		}

		return value;
	}
}
