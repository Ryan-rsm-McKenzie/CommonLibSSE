#include "RE/BGSBipedObjectForm.h"


namespace RE
{
	UInt32 BGSBipedObjectForm::GetSlotMask() const
	{
		return bipedObjectData.parts;
	}


	void BGSBipedObjectForm::SetSlotMask(UInt32 mask)
	{
		bipedObjectData.parts = mask;
	}


	bool BGSBipedObjectForm::HasPartOf(UInt32 flag) const
	{
		return (bipedObjectData.parts & flag) != 0;
	}


	UInt32 BGSBipedObjectForm::GetWeightClass() const
	{
		return bipedObjectData.weightClass;
	}


	bool BGSBipedObjectForm::IsLightArmor() const
	{
		return bipedObjectData.weightClass == kWeight_Light;
	}


	bool BGSBipedObjectForm::IsHeavyArmor() const
	{
		return bipedObjectData.weightClass == kWeight_Heavy;
	}


	UInt32 BGSBipedObjectForm::AddSlotToMask(UInt32 slot)
	{
		bipedObjectData.parts |= slot; return bipedObjectData.parts;
	}


	UInt32 BGSBipedObjectForm::RemoveSlotFromMask(UInt32 slot)
	{
		bipedObjectData.parts &= ~slot; return bipedObjectData.parts;
	}
}
