#include "RE/TESForm.h"

#include "skse64/GameForms.h"  // TESForm
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include "RE/MagicItem.h"  // MagicItem
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "RE/TESValueForm.h"  // TESValueForm


namespace RE
{
	TESForm* TESForm::LookupByID(UInt32 a_formID)
	{
		return LookupByID_internal(a_formID);
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
		func_t* func = function_cast<func_t*>(&::TESForm::CopyFromEx);
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


	bool TESForm::HasWorldModel() const
	{
		return DYNAMIC_CAST(this, TESForm, TESModel) != 0;
	}


	UInt32 TESForm::GetFormID() const
	{
		return formID;
	}


	float TESForm::GetWeight() const
	{
		using func_t = float(const TESForm*);
		func_t* func = function_cast<func_t*>(&::GetFormWeight);
		const TESObjectREFR* ref = const_cast<TESForm*>(this)->GetReference();
		return func(ref ? ref->baseForm : this);
	}


	SInt32 TESForm::GetValue() const
	{
		TESValueForm* valueForm = DYNAMIC_CAST(this, TESForm, TESValueForm);
		if (valueForm) {
			return valueForm->value;
		} else {
			MagicItem* magicItem = DYNAMIC_CAST(this, TESForm, MagicItem);
			return magicItem ? magicItem->GetValue() : -1;
		}
	}


	TESForm* TESForm::LookupByID_internal(UInt32 a_formID)
	{
		using func_t = function_type_t<decltype(&TESForm::LookupByID_internal)>;
		func_t* func = reinterpret_cast<func_t*>(::LookupFormByID.GetUIntPtr());
		return func(a_formID);
	}
}
