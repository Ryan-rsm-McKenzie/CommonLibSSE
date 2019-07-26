#include "RE/TESForm.h"

#include "skse64/GameForms.h"  // TESForm

#include "RE/ExtraEnchantment.h"  // ExtraEnchantment
#include "RE/FormTraits.h"  // As
#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESModel.h"  // TESModel
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "RE/TESValueForm.h"  // TESValueForm


namespace RE
{
	TESForm* TESForm::LookupByID(UInt32 a_formID)
	{
		return LookupByID_Internal(a_formID);
	}


	bool TESForm::Is(FormType a_type) const
	{
		return formType == a_type;
	}


	bool TESForm::IsNot(FormType a_type) const
	{
		return formType != a_type;
	}


	void TESForm::CopyFromEx(TESForm* a_rhs)
	{
		using func_t = function_type_t<decltype(&TESForm::CopyFromEx)>;
		func_t* func = unrestricted_cast<func_t*>(&::TESForm::CopyFromEx);
		return func(this, a_rhs);
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


	UInt32 TESForm::GetFormID() const
	{
		return formID;
	}


	float TESForm::GetWeight() const
	{
		using func_t = function_type_t<decltype(&TESForm::GetWeight)>;
		func_t* func = unrestricted_cast<func_t*>(&::GetFormWeight);
		auto ref = As<TESObjectREFR*>();
		auto form = ref ? ref->baseForm : this;
		return func(form);
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


	TESForm* TESForm::LookupByID_Internal(UInt32 a_formID)
	{
		using func_t = function_type_t<decltype(&TESForm::LookupByID_Internal)>;
		func_t* func = reinterpret_cast<func_t*>(::LookupFormByID.GetUIntPtr());
		return func(a_formID);
	}
}
