#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSBipedObjectForm

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class BGSBipedObjectForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSBipedObjectForm;


		enum class BipedObject : UInt32
		{
			kNone = static_cast<std::underlying_type_t<BipedObject>>(-1),
			kHead = 0,
			kHair = 1,
			kBody = 2,
			kHands = 3,
			kForearms = 4,
			kAmulet = 5,
			kRing = 6,
			kFeet = 7,
			kCalves = 8,
			kShield = 9,
			kTail = 10,
			kLongHair = 11,
			kCirclet = 12,
			kEars = 13,
			kDecapitateHead = 20,
			kDecapitate = 21,
			kFX01 = 31
		};


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


			FirstPersonFlag	firstPersonFlag;	// 0
			ArmorType		armorType;			// 4
		};
		STATIC_ASSERT(sizeof(BipedBodyTemplate) == 0x8);
		using FirstPersonFlag = BipedBodyTemplate::FirstPersonFlag;
		using ArmorType = BipedBodyTemplate::ArmorType;


		virtual ~BGSBipedObjectForm();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		FirstPersonFlag	GetSlotMask() const;
		void			SetSlotMask(FirstPersonFlag a_mask);
		bool			HasPartOf(FirstPersonFlag a_flag) const;
		ArmorType		GetArmorType() const;
		bool			IsLightArmor() const;
		bool			IsHeavyArmor() const;
		bool			IsClothing() const;
		bool			IsShield() const;
		FirstPersonFlag	AddSlotToMask(FirstPersonFlag a_slot);
		FirstPersonFlag	RemoveSlotFromMask(FirstPersonFlag a_slot);


		// members
		BipedBodyTemplate bipedBodyTemplate;	// 08 - BOD2
	};
	STATIC_ASSERT(sizeof(BGSBipedObjectForm) == 0x10);
}
