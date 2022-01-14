#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/F/FormTypes.h"
#include "RE/S/SoundLevels.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	struct BGSExplosionData  // DATA
	{
		enum class Flag
		{
			kNone = 0,
			kAlwaysUsesWorldOrientation = 1 << 1,
			kKnockDown_Always = 1 << 2,
			kKnockDown_ByFormula = 1 << 3,
			kIgnoreLOSCheck = 1 << 4,
			kPushExplosionSourceRefOnly = 1 << 5,
			kIgnoreImageSpaceSwap = 1 << 6,
			kChain = 1 << 7,
			kNoControllerVibration = 1 << 8
		};

		TESObjectLIGH*                               light;               // 00
		BGSSoundDescriptorForm*                      sound1;              // 08
		BGSSoundDescriptorForm*                      sound2;              // 10
		BGSImpactDataSet*                            impactDataSet;       // 18
		TESObjectREFR*                               impactPlacedObject;  // 20
		BGSProjectile*                               spawnProjectile;     // 28
		float                                        force;               // 30
		float                                        damage;              // 34
		float                                        radius;              // 38
		float                                        imageSpaceRadius;    // 3C
		float                                        verticalOffsetMult;  // 40
		stl::enumeration<Flag, std::uint32_t>        flags;               // 44
		stl::enumeration<SOUND_LEVEL, std::uint32_t> eSoundLevel;         // 48
		std::uint32_t                                pad4C;               // 4C
	};
	static_assert(sizeof(BGSExplosionData) == 0x50);

	class BGSExplosion :
		public TESBoundObject,              // 00
		public TESFullName,                 // 30
		public TESModel,                    // 40
		public TESEnchantableForm,          // 68
		public BGSPreloadable,              // 80
		public TESImageSpaceModifiableForm  // 88
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSExplosion;
		inline static constexpr auto VTABLE = VTABLE_BGSExplosion;
		inline static constexpr auto FORMTYPE = FormType::Explosion;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSExplosion() override;  // 00

		// override (TESBoundObject)
		void        InitializeData() override;                            // 04
		bool        Load(TESFile* a_mod) override;                        // 06
		void        InitItemImpl() override;                              // 13
		NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
		void        UnClone3D(TESObjectREFR* a_ref) override;             // 41

		// members
		BGSExplosionData data;  // 98 - DATA
	};
	static_assert(sizeof(BGSExplosion) == 0xE8);
}
