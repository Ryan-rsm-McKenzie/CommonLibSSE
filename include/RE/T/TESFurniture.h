#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESObjectACTI.h"

namespace RE
{
	class TESFurniture : public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFurniture;
		inline static constexpr auto VTABLE = VTABLE_TESFurniture;
		inline static constexpr auto FORMTYPE = FormType::Furniture;

		enum class ActiveMarker
		{
			kNone = 0,
			kSit0 = 1 << 0,
			kSit1 = 1 << 1,
			kSit2 = 1 << 2,
			kSit3 = 1 << 3,
			kSit4 = 1 << 4,
			kSit5 = 1 << 5,
			kSit6 = 1 << 6,
			kSit7 = 1 << 7,
			kSit8 = 1 << 8,
			kSit9 = 1 << 9,
			kSit10 = 1 << 10,
			kSit11 = 1 << 11,
			kSit12 = 1 << 12,
			kSit13 = 1 << 13,
			kSit14 = 1 << 14,
			kSit15 = 1 << 15,
			kSit16 = 1 << 16,
			kSit17 = 1 << 17,
			kSit18 = 1 << 18,
			kSit19 = 1 << 19,
			kSit20 = 1 << 20,
			kSit21 = 1 << 21,
			kSit22 = 1 << 22,
			kSit23 = 1 << 23,
			kDisablesActivation = 1 << 25,
			kIsPerch = 1 << 26,
			kMustExitToTalk = 1 << 27,
			kSit28 = 1 << 28,
			kCanLean = 1 << 29,
			kCanSit = 1 << 30,
			kCanSleep = 1 << 31
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIsPerch = 1 << 7,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kIsMarker = 1 << 23,
				kMustExitToTalk = 1 << 28,
				kChildCanUse = 1 << 29
			};
		};

		struct WorkBenchData  // WBDT
		{
		public:
			enum class BenchType
			{
				kNone = 0,
				kCreateObject = 1,
				kSmithingWeapon = 2,
				kEnchanting = 3,
				kEnchantingExperiment = 4,
				kAlchemy = 5,
				kAlchemyExperiment = 6,
				kSmithingArmor = 7,
			};

			// members
			stl::enumeration<BenchType, std::uint8_t>  benchType;  // 0
			stl::enumeration<ActorValue, std::uint8_t> usesSkill;  // 1
		};
		static_assert(sizeof(WorkBenchData) == 0x2);

		struct EntryPointData
		{
		public:
			struct DisabledEntryPoint  // NAM0
			{
			public:
				enum class DisabledPoint
				{
					kNone = 0,
					kFront = 1 << 0,
					kBehind = 1 << 1,
					kRight = 1 << 2,
					kLeft = 1 << 3,
					kUp = 1 << 4
				};

				// members
				std::uint16_t                                  unk0;            // 0
				stl::enumeration<DisabledPoint, std::uint16_t> disabledPoints;  // 2
			};
			static_assert(sizeof(DisabledEntryPoint) == 0x4);

			// members
			std::uint32_t      entryPoint;           // 00 - ENAM
			DisabledEntryPoint disabledEntryPoints;  // 04 - NAM0
			BGSKeyword*        keyword;              // 08 - FNMK
		};
		static_assert(sizeof(EntryPointData) == 0x10);

		~TESFurniture() override;  // 00

		// override (TESObjectACTI)
		void        InitializeData() override;                                                                                                                                // 04
		void        ClearData() override;                                                                                                                                     // 05
		bool        Load(TESFile* a_mod) override;                                                                                                                            // 06
		void        InitItemImpl() override;                                                                                                                                  // 13
		bool        Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		NiAVObject* Clone3D(TESObjectREFR* a_ref) override;                                                                                                                   // 4A
		bool        GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;                                                                                    // 4C
		bool        CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;                                                    // 4D

		// members
		BSTArray<EntryPointData>                      entryPointDataArray;  // C8
		WorkBenchData                                 workBenchData;        // E0 - WBDT
		std::uint16_t                                 padE2;                // E2
		stl::enumeration<ActiveMarker, std::uint32_t> furnFlags;            // E4
		SpellItem*                                    associatedForm;       // E8
	};
	static_assert(sizeof(TESFurniture) == 0xF0);
}
