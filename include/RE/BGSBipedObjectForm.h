#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class BGSBipedObjectForm : public BaseFormComponent
	{
	public:
		// applicable to DefaultRace
		enum PartFlag : UInt32
		{
			kPart_Head		= 1 << 0,
			kPart_Hair		= 1 << 1,
			kPart_Body		= 1 << 2,
			kPart_Hands		= 1 << 3,
			kPart_Forearms	= 1 << 4,
			kPart_Amulet	= 1 << 5,
			kPart_Ring		= 1 << 6,
			kPart_Feet		= 1 << 7,
			kPart_Calves	= 1 << 8,
			kPart_Shield	= 1 << 9,
			kPart_Tail		= 1 << 10,
			kPart_LongHair	= 1 << 11,
			kPart_Circlet	= 1 << 12,
			kPart_Ears		= 1 << 13,
			kPart_Unnamed14	= 1 << 14,
			kPart_Unnamed15 = 1 << 15,
			kPart_Unnamed16 = 1 << 16,
			kPart_Unnamed17 = 1 << 17,
			kPart_Unnamed18 = 1 << 18,
			kPart_Unnamed19 = 1 << 19,
			kPart_Unnamed20 = 1 << 20,
			kPart_Unnamed21 = 1 << 21,
			kPart_Unnamed22 = 1 << 22,
			kPart_Unnamed23 = 1 << 23,
			kPart_Unnamed24 = 1 << 24,
			kPart_Unnamed25 = 1 << 25,
			kPart_Unnamed26 = 1 << 26,
			kPart_Unnamed27 = 1 << 27,
			kPart_Unnamed28 = 1 << 28,
			kPart_Unnamed29 = 1 << 29,
			kPart_Unnamed30 = 1 << 30,
			kPart_FX01		= (UInt32)(1 << 31)
		};


		enum Weight : UInt32
		{
			kWeight_Light = 0,
			kWeight_Heavy,
			kWeight_None,
		};


		struct Data
		{
			UInt32	parts;			// 0 - init'd to 0
			Weight	weightClass;	// 4 - init'd to 2 (none)
		};


		UInt32	GetSlotMask() const;
		void	SetSlotMask(UInt32 mask);
		bool	HasPartOf(UInt32 flag) const;
		UInt32	GetWeightClass() const;
		bool	IsLightArmor() const;
		bool	IsHeavyArmor() const;
		UInt32	AddSlotToMask(UInt32 slot);
		UInt32	RemoveSlotFromMask(UInt32 slot);


		Data	bipedObjectData;	// 8
	};
}
