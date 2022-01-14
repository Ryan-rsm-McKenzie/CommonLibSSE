#pragma once

#include "RE/C/Color.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESAttackDamageForm.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BSWaterShaderMaterial;
	class NiTexture;

	struct WaterShaderData  // DNAM
	{
		struct DepthProperties
		{
			float reflections;       // D0
			float refraction;        // D4
			float normals;           // D8
			float specularLighting;  // DC
		};
		static_assert(sizeof(DepthProperties) == 0x10);

		float           unk00;                   // 00
		float           unk04;                   // 04
		float           unk08;                   // 08
		float           unk0C;                   // 0C
		float           sunSpecularPower;        // 10
		float           reflectionAmount;        // 14
		float           fresnelAmount;           // 18
		std::uint32_t   unk1C;                   // 1C
		float           aboveWaterFogDistNear;   // 20
		float           aboveWaterFogDistFar;    // 24
		Color           shallowWaterColor;       // 28
		Color           deepWaterColor;          // 2C
		Color           reflectionWaterColor;    // 30
		std::uint32_t   unk34;                   // 34
		float           unk38;                   // 38
		float           unk3C;                   // 3C
		float           unk40;                   // 40
		float           unk44;                   // 44
		float           displacementSize;        // 48
		float           displacementForce;       // 4C
		float           displacementVelocity;    // 50
		float           displacementFalloff;     // 54
		float           displacementDampener;    // 58
		float           unk5C;                   // 5C
		float           noiseFalloff;            // 60
		float           noiseWindDirectionA[3];  // 64
		float           noiseWindSpeedA[3];      // 70
		float           unk7C;                   // 7C
		float           unk80;                   // 80
		float           aboveWaterFogAmount;     // 84
		float           unk88;                   // 88
		float           underwaterFogAmount;     // 8C
		float           underwaterFogDistNear;   // 90
		float           underwaterFogDistFar;    // 94
		float           refractionMagnitude;     // 98
		float           specularPower;           // 9C
		float           unkA0;                   // A0
		float           specularRadius;          // A4
		float           specularBrightness;      // A8
		float           uvScaleA[3];             // AC
		float           amplitudeA[3];           // B8
		float           reflectionMagnitude;     // C4
		float           sunSparkleMagnitude;     // C8
		float           sunSpecularMagnitude;    // CC
		DepthProperties depthProperties;         // D0
		float           sunSparklePower;         // E0
		float           flowmapScale;            // E4
	};
	static_assert(sizeof(WaterShaderData) == 0xE8);

	class TESWaterForm :
		public TESForm,             // 000
		public TESFullName,         // 020
		public TESAttackDamageForm  // 030
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWaterForm;
		inline static constexpr auto VTABLE = VTABLE_TESWaterForm;
		inline static constexpr auto FORMTYPE = FormType::Water;

		enum class Flag  // FNAM
		{
			kNone = 0,
			kCauseDamage = 1 << 0,
			kEnableFlowmap = 1 << 3,
			kBlendNormals = 1 << 4
		};

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESWaterForm() override;  // 00

		// override (TESForm)
		void InitializeData() override;                                                                                                                                // 04
		bool Load(TESFile* a_mod) override;                                                                                                                            // 06
		void InitItemImpl() override;                                                                                                                                  // 13
		bool GetDangerous() const override;                                                                                                                            // 1B - { return flags & 1; }
		bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37

		// members
		bool                                 needUpdate;               // 040
		std::uint8_t                         pad41;                    // 041
		std::uint16_t                        pad42;                    // 042
		NiColorA                             texScroll[3];             // 044
		std::uint32_t                        pad074;                   // 074
		TESTexture                           noiseTextures[4];         // 078 - NAM2 - NAM5
		std::int8_t                          alpha;                    // 0B8 - ANAM
		stl::enumeration<Flag, std::uint8_t> flags;                    // 0B9 - FNAM
		std::uint16_t                        pad0BA;                   // 0BA
		std::uint32_t                        pad0BC;                   // 0BC
		BGSMaterialType*                     materialType;             // 0C0 - TNAM
		BGSSoundDescriptorForm*              waterSound;               // 0C8 - SNAM
		WaterShaderData                      data;                     // 0D0 - DNAM
		TESWaterForm*                        waterWeatherControl[3];   // 1B8
		std::int32_t                         currentTextureSelect[2];  // 1D0
		std::uint32_t                        frequencyX;               // 1D8
		std::uint32_t                        frequencyY;               // 1DC
		std::int32_t                         octaves;                  // 1E0
		float                                amplitude;                // 1E4
		float                                lacunarity;               // 1E8
		float                                bias;                     // 1EC
		float                                gain;                     // 1F0
		std::uint32_t                        pad1F4;                   // 1F4
		SpellItem*                           contactSpell;             // 1F8 - XNAM
		NiPointer<NiTexture>                 noiseTextureData[4];      // 200
		TESObjectACTI*                       placeableAutoWater;       // 220
		TESObjectACTI*                       placeableLODWater;        // 228
		BSWaterShaderMaterial*               waterShaderMaterial;      // 230
		bool                                 resetNoiseTextures;       // 238
		std::uint8_t                         pad239;                   // 239
		std::uint16_t                        pad23A;                   // 23A
		std::uint32_t                        pad23C;                   // 23C
		TESImageSpace*                       imageSpace;               // 240 - INAM
		NiPoint3                             linearVelocity;           // 248 - NAM0
		NiPoint3                             angularVelocity;          // 254 - NAM1
	};
	static_assert(sizeof(TESWaterForm) == 0x260);
}
