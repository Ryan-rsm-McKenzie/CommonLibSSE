#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSFixedString.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiPoint3.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESModelPSA.h"

namespace RE
{
	struct PART_DATA  // BPND
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kSeverable = 1 << 0,
			kIKData = 1 << 1,
			kIKData_BipedData = 1 << 2,
			kExplodable = 1 << 3,
			kIKData_IsHead = 1 << 4,
			kIKData_HeadTracking = 1 << 5,
			kToHitChance_Absolute = 1 << 6
		};

		// members
		float                                                      damageMult;                   // 00
		stl::enumeration<Flag, std::uint8_t>                       flags;                        // 04
		stl::enumeration<BGSBodyPartDefs::LIMB_ENUM, std::uint8_t> type;                         // 05
		std::int8_t                                                healthPercent;                // 06
		stl::enumeration<ActorValue, std::uint8_t>                 actorValue;                   // 07
		std::int8_t                                                toHitChance;                  // 08
		std::int8_t                                                explosionChance;              // 09
		std::int8_t                                                explosionGenericDebrisCount;  // 0A
		std::uint8_t                                               pad0B;                        // 0B
		std::uint32_t                                              pad0C;                        // 0C
		BGSDebris*                                                 explosionGenericDebris;       // 10
		BGSExplosion*                                              explosion;                    // 18
		float                                                      trackingMaxAngle;             // 20
		float                                                      explosionGenericDebrisScale;  // 24
		std::int8_t                                                dismemberGenericDebrisCount;  // 28
		std::int8_t                                                unk29;                        // 29
		std::uint16_t                                              unk2A;                        // 2A
		std::uint32_t                                              unk2C;                        // 2C
		BGSDebris*                                                 dismemberGenericDebris;       // 30
		BGSExplosion*                                              dismemberExplosion;           // 38
		float                                                      dismemberGenericDebrisScale;  // 40
		NiPoint3                                                   goreTranslate;                // 44
		NiPoint3                                                   goreRotate;                   // 50
		std::uint32_t                                              pad5C;                        // 5C
		BGSImpactDataSet*                                          dismemberImpactDataSet;       // 60
		BGSImpactDataSet*                                          explosionImpactDataSet;       // 68
		std::int8_t                                                dismemberDecalCount;          // 70
		std::int8_t                                                explosionDecalCount;          // 71
		std::uint16_t                                              pad72;                        // 72
		float                                                      explosionSpecialDebrisScale;  // 74
	};
	static_assert(sizeof(PART_DATA) == 0x78);

	class BGSBodyPart
	{
	public:
		// members
		BSFixedString nodeName;                   // 00 - BPNN
		BSFixedString targetName;                 // 08 - BPNT
		BSFixedString hitReactionVariablePrefix;  // 10 - BPNI
		BSFixedString partName;                   // 18 - BPTN
		BSFixedString goreObjectName;             // 20 - NAM4
		TESModel      explosionSpecialDebris;     // 28 - NAM1
		TESModelPSA   poseMatching;               // 50 - PNAM
		PART_DATA     data;                       // 78 - BPND
	};
	static_assert(sizeof(BGSBodyPart) == 0xF0);

	class BGSBodyPartData :
		public TESForm,        // 00
		public TESModel,       // 20
		public BGSPreloadable  // 48
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSBodyPartData;
		inline static constexpr auto VTABLE = VTABLE_BGSBodyPartData;
		inline static constexpr auto FORMTYPE = FormType::BodyPartData;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSBodyPartData() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		void ClearData() override;           // 05
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BGSBodyPart* parts[BGSBodyPartDefs::LIMB_ENUM::kTotal];  // 50
		BGSRagdoll*  ragdoll;                                    // 80
	};
	static_assert(sizeof(BGSBodyPartData) == 0x88);
}
