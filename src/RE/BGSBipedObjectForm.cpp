#include "RE/BGSBipedObjectForm.h"


namespace RE
{
	auto BGSBipedObjectForm::GetSlotMask() const
		-> FirstPersonFlag
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


	auto BGSBipedObjectForm::GetArmorType() const
		-> ArmorType
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


	auto BGSBipedObjectForm::AddSlotToMask(FirstPersonFlag a_slot)
		-> FirstPersonFlag
	{
		bipedBodyTemplate.firstPersonFlag |= a_slot;
		return bipedBodyTemplate.firstPersonFlag;
	}


	auto BGSBipedObjectForm::RemoveSlotFromMask(FirstPersonFlag a_slot)
		-> FirstPersonFlag
	{
		if (a_slot != FirstPersonFlag::kNone) {
			bipedBodyTemplate.firstPersonFlag &= ~a_slot;
		}
		return bipedBodyTemplate.firstPersonFlag;
	}
}
