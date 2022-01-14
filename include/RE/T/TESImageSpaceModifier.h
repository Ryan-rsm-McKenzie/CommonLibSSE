#pragma once

#include "RE/B/BSString.h"
#include "RE/F/FormTypes.h"
#include "RE/I/ImageSpaceModifierInstanceDOF.h"
#include "RE/N/NiPoint2.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NiColorInterpolator;
	class NiFloatInterpolator;

	struct ImageSpaceModifierData  // DNAM
	{
	public:
		template <typename T>
		struct MultAdd
		{
		public:
			// members
			T mult;
			T add;
		};

		template <typename T>
		struct MinMax
		{
		public:
			// members
			MultAdd<T> min;
			MultAdd<T> max;
		};

		struct HDR
		{
		public:
			// members
			MultAdd<float> eyeAdaptSpeed;    // 00
			MultAdd<float> bloomBlurRadius;  // 08
			MultAdd<float> bloomThreshold;   // 10
			MultAdd<float> bloomScale;       // 18
			MinMax<float>  targetLum;        // 20
			MultAdd<float> sunlightScale;    // 30
			MultAdd<float> skyScale;         // 38
			MultAdd<float> empty[6];         // 40
		};
		static_assert(sizeof(HDR) == 0x70);

		struct Bloom
		{
		public:
			// members
			MultAdd<float> empty[3];  // 00
		};
		static_assert(sizeof(Bloom) == 0x18);

		struct Cinematic
		{
		public:
			// members
			MultAdd<float> saturation;  // 00
			MultAdd<float> brightness;  // 08
			MultAdd<float> contrast;    // 10
			MultAdd<float> empty;       // 18
		};
		static_assert(sizeof(Cinematic) == 0x20);

		struct DOF
		{
		public:
			using Mode = ImageSpaceModifierInstanceDOF::DepthOfFieldMode;

			// members
			std::uint32_t                        strength;   // 00
			std::uint32_t                        distance;   // 04
			std::uint32_t                        range;      // 08
			bool                                 useTarget;  // 0C
			stl::enumeration<Mode, std::uint8_t> flags;      // 0D
			std::uint16_t                        pad0E;      // 0E
		};
		static_assert(sizeof(DOF) == 0x10);

		// members
		bool          animatable;              // 00
		std::uint8_t  pad01;                   // 01
		std::uint16_t pad02;                   // 01
		float         duration;                // 04
		HDR           hdr;                     // 08
		Bloom         bloom;                   // 78
		Cinematic     cinematic;               // 90
		std::uint32_t tintColor;               // B0
		std::uint32_t blurRadius;              // B4
		std::uint32_t doubleVisionStrength;    // B8
		std::uint32_t radialBlurStrength;      // BC
		std::uint32_t radialBlurRampUp;        // C0
		std::uint32_t radialBlurStart;         // C4
		bool          useTargetForRadialBlur;  // C8
		std::uint8_t  padC9;                   // C9
		std::uint16_t padCA;                   // CA
		NiPoint2      radialBlurCenter;        // CC
		DOF           dof;                     // D4
		std::uint32_t radialBlurRampDown;      // E4
		std::uint32_t radialBlurDownStart;     // E8
		std::uint32_t fadeColor;               // EC
		std::uint32_t motionBlurStrength;      // F0
	};
	static_assert(sizeof(ImageSpaceModifierData) == 0xF4);

	class TESImageSpaceModifier : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESImageSpaceModifier;
		inline static constexpr auto VTABLE = VTABLE_TESImageSpaceModifier;
		inline static constexpr auto FORMTYPE = FormType::ImageAdapter;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		template <typename T>
		struct MultAdd
		{
			T mult;
			T add;
		};

		template <typename T>
		struct MinMax
		{
			MultAdd<T> min;
			MultAdd<T> max;
		};

		struct HDR
		{
			MultAdd<NiPointer<NiFloatInterpolator>> eyeAdaptSpeed;    // 00 - aIAD - @IAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomBlurRadius;  // 10 - bIAD - AIAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomThreshold;   // 20 - cIAD - BIAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomScale;       // 30 - dIAD - CIAD
			MinMax<NiPointer<NiFloatInterpolator>>  targetLum;        // 40 - eIAD - EIAD
			MultAdd<NiPointer<NiFloatInterpolator>> sunlightScale;    // 60 - gIAD - FIAD
			MultAdd<NiPointer<NiFloatInterpolator>> skyScale;         // 70 - hIAD - GIAD
			MultAdd<NiPointer<NiFloatInterpolator>> empty[6];         // 80 - iIAD - MIAD
		};
		static_assert(sizeof(HDR) == 0xE0);

		struct Bloom
		{
			MultAdd<NiPointer<NiFloatInterpolator>> empty[3];  // 00 - oIAD - PIAD
		};
		static_assert(sizeof(Bloom) == 0x30);

		struct Cinematic
		{
			MultAdd<NiPointer<NiFloatInterpolator>> saturation;  // 00 - rIAD - QIAD
			MultAdd<NiPointer<NiFloatInterpolator>> brightness;  // 10 - sIAD - RIAD
			MultAdd<NiPointer<NiFloatInterpolator>> contrast;    // 20 - tIAD - SIAD
			MultAdd<NiPointer<NiFloatInterpolator>> empty;       // 30 - uIAD - TIAD
		};
		static_assert(sizeof(Cinematic) == 0x40);

		struct RadialBlur
		{
			NiPointer<NiFloatInterpolator> strength;   // 00 - RNAM
			NiPointer<NiFloatInterpolator> rampUp;     // 08 - SNAM
			NiPointer<NiFloatInterpolator> start;      // 10 - UNAM
			NiPointer<NiFloatInterpolator> rampDown;   // 18 - NAM1
			NiPointer<NiFloatInterpolator> downStart;  // 20 - NAM2
		};
		static_assert(sizeof(RadialBlur) == 0x28);

		struct DOF
		{
			NiPointer<NiFloatInterpolator> strength;  // 00 - WNAM
			NiPointer<NiFloatInterpolator> distance;  // 08 - XNAM
			NiPointer<NiFloatInterpolator> range;     // 10 - YNAM
		};
		static_assert(sizeof(DOF) == 0x18);

		~TESImageSpaceModifier() override;  // 00

		// override (TESForm)
		void        InitializeData() override;                    // 04
		void        ClearData() override;                         // 05
		bool        Load(TESFile* a_mod) override;                // 06
		const char* GetFormEditorID() const override;             // 32 - { return formEditorID.c_str(); }
		bool        SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; }

		// members
		ImageSpaceModifierData         data;                  // 020 - DNAM
		std::uint32_t                  pad114;                // 114
		HDR                            hdr;                   // 118
		Bloom                          bloom;                 // 1F8
		Cinematic                      cinematic;             // 228
		NiPointer<NiFloatInterpolator> blurRadius;            // 268 - BNAM
		NiPointer<NiFloatInterpolator> doubleVisionStrength;  // 270 - VNAM
		NiPointer<NiColorInterpolator> tintColor;             // 278 - TNAM
		NiPointer<NiColorInterpolator> fadeColor;             // 280 - NAM3
		RadialBlur                     radialBlur;            // 288
		DOF                            dof;                   // 2B0
		NiPointer<NiColorInterpolator> motionBlurStrength;    // 2C8 - NAM4
		BSString                       formEditorID;          // 2D0 - EDID
	};
	static_assert(sizeof(TESImageSpaceModifier) == 0x2E0);
}
