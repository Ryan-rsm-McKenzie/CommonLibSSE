#pragma once

#include "RE/C/Color.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	enum class D3DBLEND;
	enum class D3DBLENDOP;

	enum class D3DCMPFUNC
	{
		kNever = 1,
		kLess,
		kEqual,
		kLessEqual,
		kGreater,
		kNotEqual,
		kGreaterEqual,
		kAlways
	};

	struct EffectShaderData  // DATA
	{
	public:
		enum class Flags
		{
			kNone = 0,
			kDisableTextureShader = 1 << 0,
			kGreyscaleToColor = 1 << 1,
			kGreyscaleToAlpha = 1 << 2,
			kDisableParticleShader = 1 << 3,
			kEdgeColorSubtractive = 1 << 4,
			kSkinOnly = 1 << 5,
			kIgnoreTexAlpha = 1 << 6,
			kFillTexProjectedUV = 1 << 7,
			kIgnoreBaseGeomTexAlpha = 1 << 8,
			kLighting = 1 << 9,
			kIgnoreWeapons = 1 << 10,
			kAlpha = 1 << 11,
			kPreferDismemberedLimb = 1 << 12,
			kParticleAnimated = 1 << 15,
			kParticleGreyscaleColor = 1 << 16,
			kParticleGreyscaleAlpha = 1 << 17,
			kUseBloodGeometry = 1 << 24
		};

		// members
		std::uint32_t unk00;  // 000

		D3DBLEND   membraneShaderSourceBlendMode;  // 004
		D3DBLENDOP membraneShaderBlendOperation;   // 008
		D3DCMPFUNC membraneShaderZTestFunction;    // 00C

		Color fillTextureEffectColorKey1;               // 010
		float fillTextureEffectAlphaFadeInTime;         // 014
		float fillTextureEffectFullAlphaTime;           // 018
		float fillTextureEffectAlphaFadeOutTime;        // 01C
		float fillTextureEffectPersistentAlphaRatio;    // 020
		float fillTextureEffectAlphaPulseAmplitude;     // 024
		float fillTextureEffectAlphaPulseFrequency;     // 028
		float fillTextureEffectTextureAnimationSpeedU;  // 02C
		float fillTextureEffectTextureAnimationSpeedV;  // 030

		float edgeEffectFallOff;               // 034
		Color edgeEffectColor;                 // 038
		float edgeEffectAlphaFadeInTime;       // 03C
		float edgeEffectFullAlphaTime;         // 040
		float edgeEffectAlphaFadeOutTime;      // 044
		float edgeEffectPersistentAlphaRatio;  // 048
		float edgeEffectAlphaPulseAmplitude;   // 04C
		float edgeEffectAlphaPulseFrequency;   // 050

		float fillTextureEffectFullAlphaRatio;  // 054

		float edgeEffectFullAlphaRatio;  // 058

		D3DBLEND membraneShaderDestBlendMode;  // 05C

		D3DBLEND   particleShaderSourceBlendMode;            // 060
		D3DBLENDOP particleShaderBlendOperation;             // 064
		D3DCMPFUNC particleShaderZTestOperation;             // 068
		D3DBLEND   particleShaderDestBlendMode;              // 06C
		float      particleShaderParticleBirthRampUpTime;    // 070
		float      particleShaderFullParticleBirthTime;      // 074
		float      particleShaderParticleBirthRampDownTime;  // 078
		float      particleShaderFullParticleBirthRatio;     // 07C
		float      particleShaderPersistantParticleCount;    // 080
		float      particleShaderParticleLifetime;           // 084
		float      particleShaderParticleLifetimeVariance;   // 088
		float      particleShaderInitialSpeedAlongNormal;    // 08C
		float      particleShaderAccelerationAlongNormal;    // 090
		float      particleShaderInitialVelocity1;           // 094
		float      particleShaderInitialVelocity2;           // 098
		float      particleShaderInitialVelocity3;           // 09C
		float      particleShaderAcceleration1;              // 0A0
		float      particleShaderAcceleration2;              // 0A4
		float      particleShaderAcceleration3;              // 0A8
		float      particleShaderScaleKey1;                  // 0AC
		float      particleShaderScaleKey2;                  // 0B0
		float      particleShaderScaleKey1Time;              // 0B4
		float      particleShaderScaleKey2Time;              // 0B8

		Color colorKey1;              // 0BC
		Color colorKey2;              // 0C0
		Color colorKey3;              // 0C4
		float colorKey1ColorAlpha;    // 0C8
		float colorKey2ColorAlpha;    // 0CC
		float colorKey3ColorAlpha;    // 0D0
		float colorKey1ColorKeyTime;  // 0D4
		float colorKey2ColorKeyTime;  // 0D8
		float colorKey3ColorKeyTime;  // 0DC

		float particleShaderInitialSpeedAlongNormalVariance;  // 0E0
		float particleShaderInitialRotation;                  // 0E4
		float particleShaderInitialRotationVariance;          // 0E8
		float particleShaderRotationSpeed;                    // 0EC
		float particleShaderRotationSpeedVariance;            // 0F0

		std::uint32_t pad0D4;  // 0F4

		BGSDebris* addonModels;  // 0F8

		float holesStartTime;  // 100
		float holesEndTime;    // 104
		float holesStartVal;   // 108
		float holesEndVal;     // 10C

		float edgeWidthAlphaUnits;  // 110
		Color edgeColor;            // 114

		float explosionWindSpeed;  // 118

		float textureCountU;  // 11C
		float textureCountV;  // 120

		float addonModelsFadeInTime;    // 124
		float addonModelsFadeOutTime;   // 128
		float addonModelsScaleStart;    // 12C
		float addonModelsScaleEnd;      // 130
		float addonModelsScaleInTime;   // 134
		float addonModelsScaleOutTime;  // 138

		std::uint32_t pad13C;  // 13C

		BGSSoundDescriptorForm* ambientSound;  // 140

		Color fillTextureEffectColorKey2;                        // 148
		Color fillTextureEffectColorKey3;                        // 14C
		float fillTextureEffectColorKeyScaleTimeColorKey1Scale;  // 150
		float fillTextureEffectColorKeyScaleTimeColorKey2Scale;  // 154
		float fillTextureEffectColorKeyScaleTimeColorKey3Scale;  // 158
		float fillTextureEffectColorKeyScaleTimeColorKey1Time;   // 15C
		float fillTextureEffectColorKeyScaleTimeColorKey2Time;   // 160
		float fillTextureEffectColorKeyScaleTimeColorKey3Time;   // 164

		float colorScale;  // 168

		float birthPositionOffset;          // 16C
		float birthPositionOffsetVariance;  // 170

		float particleShaderAnimatedStartFrame;          // 174
		float particleShaderAnimatedStartFrameVariance;  // 178
		float particleShaderAnimatedEndFrame;            // 17C
		float particleShaderAnimatedLoopStartFrame;      // 180
		float particleShaderAnimatedLoopStartVariance;   // 184
		float particleShaderAnimatedFrameCount;          // 188
		float particleShaderAnimatedFrameCountVariance;  // 18C

		stl::enumeration<Flags, std::uint32_t> flags;  // 190

		float fillTextureEffectTextureScaleU;  // 194
		float fillTextureEffectTextureScaleV;  // 198

		std::uint32_t sceneGraphEmitDepthLimit;  // 19C - unused
	};
	static_assert(sizeof(EffectShaderData) == 0x1A0);

	class TESEffectShader : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESEffectShader;
		inline static constexpr auto VTABLE = VTABLE_TESEffectShader;
		inline static constexpr auto FORMTYPE = FormType::EffectShader;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~TESEffectShader() override;  // 00

		// override (TESForm)
		void InitializeData() override;      // 04
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		// members
		EffectShaderData data;                    // 020 - DATA
		TESTexture       fillTexture;             // 1C0 - ICON
		TESTexture       particleShaderTexture;   // 1D0 - ICO2
		TESTexture       holesTexture;            // 1E0 - NAM7
		TESTexture       membranePaletteTexture;  // 1F0 - NAM8
		TESTexture       particlePaletteTexture;  // 200 - NAM9
		void*            unk210;                  // 210 - smart ptr
		void*            unk218;                  // 218 - smart ptr
	};
	static_assert(sizeof(TESEffectShader) == 0x220);
}
