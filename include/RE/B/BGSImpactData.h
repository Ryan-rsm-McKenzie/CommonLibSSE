#pragma once

#include "RE/C/Color.h"
#include "RE/D/DecalData.h"
#include "RE/F/FormTypes.h"
#include "RE/I/ImpactResults.h"
#include "RE/S/SoundLevels.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSImpactData :
		public TESForm,  // 00
		public TESModel  // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSImpactData;
		inline static constexpr auto VTABLE = VTABLE_BGSImpactData;
		inline static constexpr auto FORMTYPE = FormType::Impact;

		enum class ORIENTATION
		{
			kSurfaceNormal = 0,
			kProjVector = 1,
			kProjReflect = 2
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		struct IMPACT_DATA_DATA  // DATA
		{
			enum class Flag
			{
				kNone = 0,
				kNoDecalData = 1 << 0
			};

			float                                        effectDuration;   // 00
			stl::enumeration<ORIENTATION, std::uint32_t> orient;           // 04
			float                                        angleThreshold;   // 08
			float                                        placementRadius;  // 0C
			SOUND_LEVEL                                  soundLevel;       // 10
			stl::enumeration<Flag, std::uint8_t>         flags;            // 14
			stl::enumeration<ImpactResult, std::uint8_t> resultOverride;   // 15
			std::uint16_t                                unk16;            // 16
		};
		static_assert(sizeof(IMPACT_DATA_DATA) == 0x18);

		~BGSImpactData() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		IMPACT_DATA_DATA        data;              // 48 - DATA
		BGSTextureSet*          decalTextureSet;   // 60 - DNAM
		BGSTextureSet*          decalTextureSet2;  // 68 - ENAM
		BGSSoundDescriptorForm* sound1;            // 70 - SNAM
		BGSSoundDescriptorForm* sound2;            // 78 - NAM1
		BGSHazard*              hazard;            // 80 - NAM2
		DecalData               dData;             // 88 - DODT
		std::uint32_t           padAC;             // AC
	};
	static_assert(sizeof(BGSImpactData) == 0xB0);
}
