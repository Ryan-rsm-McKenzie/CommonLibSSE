#include "RE/TESLevItem.h"

#include "skse64/GameForms.h" // FormType


namespace RE
{
	bool TESLevItem::IsValidInventoryItem() const
	{
		switch (formType) {
		case kFormType_ScrollItem:
		case kFormType_Armor:
		case kFormType_Book:
		case kFormType_Ingredient:
		case kFormType_Light:
		case kFormType_Misc:
		case kFormType_Apparatus:
		case kFormType_Weapon:
		case kFormType_Ammo:
		case kFormType_Key:
		case kFormType_Potion:
		case kFormType_Note:
		case kFormType_ConstructibleObject:
		case kFormType_SoulGem:
		case kFormType_LeveledItem:
			return true;
		default:
			return false;
		}
	}
}
