#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESClass

#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESClass :
		public TESForm,			// 00
		public TESFullName,		// 20
		public TESDescription,	// 30
		public TESTexture		// 40
	{
	public:
		inline static const void* RTTI = RTTI_TESClass;


		enum { kTypeID = FormType::Class };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESClass();							// 00

		// override (TESForm)
		virtual bool LoadForm(TESFile* a_mod) override;	// 06


		struct Data	// DATA
		{
			enum class Skill : UInt8
			{
				kOneHanded = 0,
				kTwoHanded = 1,
				kArchery = 2,
				kBlock = 3,
				kSmithing = 4,
				kHeavyArmor = 5,
				kLightArmor = 6,
				kPickpocket = 7,
				kLockpicking = 8,
				kSneak = 9,
				kAlchemy = 10,
				kSpeech = 11,
				kAlteration = 12,
				kConjuration = 13,
				kDestruction = 14,
				kIllusion = 15,
				kRestoration = 16,
				kEnchanting = 17,
			};


			struct SkillWeights
			{
				UInt8	oneHanded;		// 00
				UInt8	twoHanded;		// 01
				UInt8	archery;		// 02
				UInt8	block;			// 03
				UInt8	smithing;		// 04
				UInt8	heavyArmor;		// 05
				UInt8	lightArmor;		// 06
				UInt8	pickpocket;		// 07
				UInt8	lockpicking;	// 08
				UInt8	sneak;			// 09
				UInt8	alchemy;		// 0A
				UInt8	speech;			// 0B
				UInt8	alteration;		// 0C
				UInt8	conjuration;	// 0D
				UInt8	destruction;	// 0E
				UInt8	illusion;		// 0F
				UInt8	restoration;	// 10
				UInt8	enchanting;		// 11
			};
			STATIC_ASSERT(sizeof(SkillWeights) == 0x12);


			struct AttributeWeights
			{
				UInt8	health;		// 0
				UInt8	magicka;	// 1
				UInt8	stamina;	// 2
				UInt8	pad3;		// 3
			};
			STATIC_ASSERT(sizeof(AttributeWeights) == 0x4);


			UInt32				unk00;					// 00
			Skill				teaches;				// 04
			UInt8				maximumTrainingLevel;	// 05
			SkillWeights		skillWeights;			// 06
			float				bleedoutDefault;		// 18
			UInt32				voicePoints;			// 1C
			AttributeWeights	attributeWeights;		// 20
		};
		STATIC_ASSERT(sizeof(Data) == 0x24);


		// members
		Data	data;	// 50 - DATA
		UInt32	pad74;	// 74
	};
	STATIC_ASSERT(sizeof(TESClass) == 0x78);
}
