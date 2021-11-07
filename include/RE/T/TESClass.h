#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	struct CLASS_DATA  // DATA
	{
	public:
		enum class Skill
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
		public:
			// members
			std::uint8_t oneHanded;    // 00
			std::uint8_t twoHanded;    // 01
			std::uint8_t archery;      // 02
			std::uint8_t block;        // 03
			std::uint8_t smithing;     // 04
			std::uint8_t heavyArmor;   // 05
			std::uint8_t lightArmor;   // 06
			std::uint8_t pickpocket;   // 07
			std::uint8_t lockpicking;  // 08
			std::uint8_t sneak;        // 09
			std::uint8_t alchemy;      // 0A
			std::uint8_t speech;       // 0B
			std::uint8_t alteration;   // 0C
			std::uint8_t conjuration;  // 0D
			std::uint8_t destruction;  // 0E
			std::uint8_t illusion;     // 0F
			std::uint8_t restoration;  // 10
			std::uint8_t enchanting;   // 11
		};
		static_assert(sizeof(SkillWeights) == 0x12);

		struct AttributeWeights
		{
		public:
			// members
			std::uint8_t health;   // 0
			std::uint8_t magicka;  // 1
			std::uint8_t stamina;  // 2
		};
		static_assert(sizeof(AttributeWeights) == 0x3);

		// members
		std::uint32_t                         unk00;                 // 00
		stl::enumeration<Skill, std::uint8_t> teaches;               // 04
		std::uint8_t                          maximumTrainingLevel;  // 05
		SkillWeights                          skillWeights;          // 06
		float                                 bleedoutDefault;       // 18
		std::uint32_t                         voicePoints;           // 1C
		AttributeWeights                      attributeWeights;      // 20
		std::uint8_t                          pad23;                 // 23
	};
	static_assert(sizeof(CLASS_DATA) == 0x24);

	class TESClass :
		public TESForm,         // 00
		public TESFullName,     // 20
		public TESDescription,  // 30
		public TESTexture       // 40
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESClass;
		inline static constexpr auto VTABLE = VTABLE_TESClass;
		inline static constexpr auto FORMTYPE = FormType::Class;

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kTagSkills = 1 << 1
			};
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESClass() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06

		// members
		CLASS_DATA    data;   // 50 - DATA
		std::uint32_t pad74;  // 74
	};
	static_assert(sizeof(TESClass) == 0x78);
}
