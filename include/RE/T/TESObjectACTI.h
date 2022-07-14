#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESModelTextureSwap.h"

namespace RE
{
	class TESObjectACTI :
		public TESBoundAnimObject,         // 00
		public TESFullName,                // 30
		public TESModelTextureSwap,        // 40
		public TESMagicTargetForm,         // A8
		public BGSDestructibleObjectForm,  // 78
		public BGSOpenCloseForm,           // 88
		public BGSKeywordForm              // 90
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectACTI;
		inline static constexpr auto VTABLE = VTABLE_TESObjectACTI;
		inline static constexpr auto FORMTYPE = FormType::Activator;

		enum class ActiFlags
		{
			kNone = 0,
			kNoDisplacement = 1 << 0,
			kIgnoredBySandbox = 1 << 1,
			kIsProceduralWater = 1 << 2,
			kIsLODWater = 1 << 3
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kHasTreeLOD = 1 << 6,
				kMustUpdateAnims = 1 << 8,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15,
				kRandomAnimStart = 1 << 16,
				kDangerous = 1 << 17,
				kIgnoresObjectInteraction = 1 << 20,
				kIsMarker = 1 << 23,
				kObstacle = 1 << 25,
				kNavMeshGeneration_Filter = 1 << 26,
				kNavMeshGeneration_BoundingBox = 1 << 27,
				kChildCanUse = 1 << 29,
				kNavMeshGeneration_Ground = 1 << 30
			};
		};

		~TESObjectACTI() override;  // 00

		// override (TESBoundAnimObject)
		void          InitializeData() override;                                                                                                                                // 04
		void          ClearData() override;                                                                                                                                     // 05
		bool          Load(TESFile* a_mod) override;                                                                                                                            // 06
		void          SaveGame(BGSSaveFormBuffer* a_buf) override;                                                                                                              // 0E
		void          LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                              // 0F
		void          InitItemImpl() override;                                                                                                                                  // 13
		bool          GetIgnoredBySandbox() const override;                                                                                                                     // 22 - { return (flags >> 1) & 1; }
		bool          IsWater() const override;                                                                                                                                 // 2A - { return waterType != 0; }
		bool          Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		TESWaterForm* GetWaterType() const override;                                                                                                                            // 3D - { return waterType; }
		bool          GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;                                                                                    // 4C
		bool          CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;                                                    // 4D

		// members
		BGSSoundDescriptorForm*                    soundLoop;      // A8 - SNAM
		BGSSoundDescriptorForm*                    soundActivate;  // B0 - VNAM
		TESWaterForm*                              waterForm;      // B8 - WNAM
		stl::enumeration<ActiFlags, std::uint16_t> flags;          // C0 - FNAM
		std::uint16_t                              padC2;          // C2
		std::uint32_t                              padC4;          // C4
	};
	static_assert(sizeof(TESObjectACTI) == 0xC8);
}
