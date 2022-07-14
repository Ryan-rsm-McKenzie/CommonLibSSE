#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/C/Color.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiColor.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModelTextureSwap.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	enum class TES_LIGHT_FLAGS
	{
		kNone = 0,
		kDynamic = 1 << 0,
		kCanCarry = 1 << 1,
		kNegative = 1 << 2,
		kFlicker = 1 << 3,
		kDeepCopy = 1 << 4,
		kOffByDefault = 1 << 5,
		kFlickerSlow = 1 << 6,
		kPulse = 1 << 7,
		kPulseSlow = 1 << 8,
		kSpotlight = 1 << 9,
		kSpotShadow = 1 << 10,
		kHemiShadow = 1 << 11,
		kOmniShadow = 1 << 12,
		kPortalStrict = 1 << 13,

		kType = kSpotlight | kSpotShadow | kHemiShadow | kOmniShadow
	};

	struct OBJ_LIGH  // DATA
	{
	public:
		// members
		std::int32_t                                     time;                       // 00
		std::uint32_t                                    radius;                     // 04
		Color                                            color;                      // 08
		stl::enumeration<TES_LIGHT_FLAGS, std::uint32_t> flags;                      // 0C
		float                                            fallofExponent;             // 10
		float                                            fov;                        // 14
		float                                            nearDistance;               // 18
		float                                            flickerPeriodRecip;         // 1C - CK value * 100
		float                                            flickerIntensityAmplitude;  // 20
		float                                            flickerMovementAmplitude;   // 24
	};
	static_assert(sizeof(OBJ_LIGH) == 0x28);

	class TESObjectLIGH :
		public TESBoundAnimObject,         // 000
		public TESFullName,                // 030
		public TESModelTextureSwap,        // 040
		public TESIcon,                    // 078
		public BGSMessageIcon,             // 088
		public TESWeightForm,              // 0A0
		public TESValueForm,               // 0B0
		public BGSDestructibleObjectForm,  // 0C0
		public BGSEquipType                // 0D0
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectLIGH;
		inline static constexpr auto VTABLE = VTABLE_TESObjectLIGH;
		inline static constexpr auto FORMTYPE = FormType::Light;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kRandomAnimStart = 1 << 16,
				kPortalStrict = 1 << 17,
				kObstacle = 1 << 25
			};
		};

		~TESObjectLIGH() override;  // 00

		// override (TESBoundAnimObject)
		void        InitializeData() override;                                                                                                                                // 04
		bool        Load(TESFile* a_mod) override;                                                                                                                            // 06
		void        SaveGame(BGSSaveFormBuffer* a_buf) override;                                                                                                              // 0E
		void        LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                              // 0F
		void        InitItemImpl() override;                                                                                                                                  // 13
		bool        Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
		void        UnClone3D(TESObjectREFR* a_ref) override;                                                                                                                 // 41
		NiAVObject* LoadGraphics(TESObjectREFR* a_ref) override;                                                                                                              // 47
		NiAVObject* Clone3D(TESObjectREFR* a_ref) override;                                                                                                                   // 4A

		// override (BGSEquipType)
		BGSEquipSlot* GetEquipSlot() const override;                // 04
		void          SetEquipSlot(BGSEquipSlot* a_slot) override;  // 05 - { return; }

		[[nodiscard]] constexpr bool CanBeCarried() const noexcept { return data.flags.all(TES_LIGHT_FLAGS::kCanCarry); }

		// members
		OBJ_LIGH                data;            // 0E0 - DATA
		float                   fade;            // 108 - FNAM
		std::uint32_t           pad10C;          // 10C
		BGSSoundDescriptorForm* sound;           // 110 - SNAM
		NiColor                 emittanceColor;  // 118
		std::uint32_t           pad124;          // 124
		BGSLensFlare*           lensFlare;       // 128
	};
	static_assert(sizeof(TESObjectLIGH) == 0x130);
}
