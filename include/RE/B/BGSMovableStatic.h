#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESObjectSTAT.h"

namespace RE
{
	struct MOVABLE_STATIC_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kOnLocalMap = 1 << 0
		};

		// members
		stl::enumeration<Flag, std::uint8_t> flags;  // 0
	};
	static_assert(sizeof(MOVABLE_STATIC_DATA) == 0x1);

	class BGSMovableStatic :
		public TESFullName,                // 00
		public BGSDestructibleObjectForm,  // 10
		public TESObjectSTAT               // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMovableStatic;
		inline static constexpr auto VTABLE = VTABLE_BGSMovableStatic;
		inline static constexpr auto FORMTYPE = FormType::MovableStatic;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kMustUpdateAnims = 1 << 8,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kHasCurrents = 1 << 19,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};

		~BGSMovableStatic() override;  // 00

		// override (TESObjectSTAT)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		BGSSoundDescriptorForm* soundLoop;  // A0 - SNAM
		MOVABLE_STATIC_DATA     data;       // A8
		std::uint8_t            padA9;      // A9
		std::uint16_t           padAA;      // AA
		std::uint32_t           padAC;      // AC
	};
	static_assert(sizeof(BGSMovableStatic) == 0xB0);
}
