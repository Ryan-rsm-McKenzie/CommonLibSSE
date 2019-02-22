#include "RE/TESForm.h"

#include "skse64/GameForms.h"  // TESForm
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	void TESForm::CopyFromEx(TESForm* a_rhs)
	{
		typedef void _CopyFromEx_t(TESForm* a_this, TESForm* a_rhs);
		_CopyFromEx_t* _CopyFromEx = reinterpret_cast<_CopyFromEx_t*>(GetFnAddr(&::TESForm::CopyFromEx));
		_CopyFromEx(this, a_rhs);
	}


	TESForm* TESForm::LookupByID(UInt32 a_formID)
	{
		typedef TESForm* _LookupByID_t(UInt32 a_formID);
		static _LookupByID_t* _LookupByID = reinterpret_cast<_LookupByID_t*>(::LookupFormByID.GetUIntPtr());
		return _LookupByID(a_formID);
	}


	UInt32 TESForm::GetFormID() const
	{
		return formID;
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
		return Is(FormType::Key);
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


	bool TESForm::HasWorldModel(void) const
	{
		return DYNAMIC_CAST(this, TESForm, TESModel) != 0;
	}


	float TESForm::GetWeight()
	{
		typedef float _GetWeight_t(TESForm* a_this);
		_GetWeight_t* _GetWeight = reinterpret_cast<_GetWeight_t*>(GetFnAddr(&::GetFormWeight));

		TESObjectREFR* ref = const_cast<TESForm*>(this)->GetReference();
		return _GetWeight(ref ? ref->baseForm : this);
	}
}
