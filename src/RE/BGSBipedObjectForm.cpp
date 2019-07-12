#include "RE/BGSBipedObjectForm.h"


namespace RE
{
	BGSBipedObjectForm::FirstPersonFlag BGSBipedObjectForm::GetSlotMask() const
	{
		return bipedBodyTemplate.firstPersonFlag;
	}


	void BGSBipedObjectForm::SetSlotMask(FirstPersonFlag a_mask)
	{
		bipedBodyTemplate.firstPersonFlag = a_mask;
	}


	bool BGSBipedObjectForm::HasPartOf(FirstPersonFlag a_flag) const
	{
		return (bipedBodyTemplate.firstPersonFlag & a_flag) != FirstPersonFlag::kNone;
	}


	BGSBipedObjectForm::ArmorType BGSBipedObjectForm::GetArmorType() const
	{
		return bipedBodyTemplate.armorType;
	}


	bool BGSBipedObjectForm::IsLightArmor() const
	{
		return bipedBodyTemplate.armorType == ArmorType::kLightArmor;
	}


	bool BGSBipedObjectForm::IsHeavyArmor() const
	{
		return bipedBodyTemplate.armorType == ArmorType::kHeavyArmor;
	}


	bool BGSBipedObjectForm::IsClothing() const
	{
		return bipedBodyTemplate.armorType == ArmorType::kClothing;
	}


	bool BGSBipedObjectForm::IsShield() const
	{
		return (bipedBodyTemplate.firstPersonFlag & FirstPersonFlag::kShield) != FirstPersonFlag::kNone;
	}


	BGSBipedObjectForm::FirstPersonFlag BGSBipedObjectForm::AddSlotToMask(FirstPersonFlag a_slot)
	{
		bipedBodyTemplate.firstPersonFlag |= a_slot;
		return bipedBodyTemplate.firstPersonFlag;
	}


	BGSBipedObjectForm::FirstPersonFlag BGSBipedObjectForm::RemoveSlotFromMask(FirstPersonFlag a_slot)
	{
		if (a_slot != FirstPersonFlag::kNone) {
			bipedBodyTemplate.firstPersonFlag &= ~a_slot;
		}
		return bipedBodyTemplate.firstPersonFlag;
	}
}
