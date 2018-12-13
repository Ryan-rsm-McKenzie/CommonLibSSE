#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class BGSBipedObjectForm : public BaseFormComponent
	{
	public:
		struct BipedBodyTemplate	// BOD2
		{
			enum class FirstPersonFlag : UInt32
			{
				kNone = 0,
				kHead = 1 << 0,
				kHair = 1 << 1,
				kBody = 1 << 2,
				kHands = 1 << 3,
				kForearms = 1 << 4,
				kAmulet = 1 << 5,
				kRing = 1 << 6,
				kFeet = 1 << 7,
				kCalves = 1 << 8,
				kShield = 1 << 9,
				kTail = 1 << 10,
				kLongHair = 1 << 11,
				kCirclet = 1 << 12,
				kEars = 1 << 13,
				kDecapitateHead = 1 << 20,
				kDecapitate = 1 << 21,
				kFX01 = (UInt32)(1 << 31)
			};


			enum class ArmorType : UInt32
			{
				kLightArmor,
				kHeavyArmor,
				kClothing
			};


			FirstPersonFlag	firstPersonFlag;	// 0 - init'd to kNone
			ArmorType		armorType;			// 4 - init'd to kClothing
		};


		using FirstPersonFlag = BipedBodyTemplate::FirstPersonFlag;
		using ArmorType = BipedBodyTemplate::ArmorType;


		FirstPersonFlag	GetSlotMask() const;
		void			SetSlotMask(FirstPersonFlag a_mask);
		bool			HasPartOf(FirstPersonFlag a_flag) const;
		ArmorType		GetArmorType() const;
		bool			IsLightArmor() const;
		bool			IsHeavyArmor() const;
		bool			IsClothing() const;
		FirstPersonFlag	AddSlotToMask(FirstPersonFlag a_slot);
		FirstPersonFlag	RemoveSlotFromMask(FirstPersonFlag a_slot);


		BipedBodyTemplate bipedBodyTemplate;	// 8
	};
}
