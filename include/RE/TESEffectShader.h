#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESEffectShader

#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType, BGSSoundDescriptorForm
#include "RE/TESForm.h"  // TESForm
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESEffectShader : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESEffectShader;


		enum { kTypeID = FormType::EffectShader };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class BlendMode : UInt32
			{
				kZero = 1,
				kOne = 2,
				kSourceColor = 3,
				kSourceInverseColor = 4,
				kSourceAlpha = 5,
				kSourceInvertedAlpha = 6,
				kDestAlpha = 7,
				kDestInvertedAlpha = 8,
				kDestColor = 9,
				kDestInverseColor = 10,
				kSourceAlphaSAT = 11
			};


			enum class BlendOperation : UInt32
			{
				kAdd = 1,
				kSubtract = 2,
				kReverseSubtract = 3,
				kMinimum = 4,
				kMaximum = 5
			};


			enum class ZTestFunction : UInt32
			{
				kEqualTo = 3,
				kNormal = 4,
				kGreaterThan = 5,
				kGreaterThanOrEqualTo = 7,
				kAlwaysShow = 8
			};


			enum class Flag : UInt32
			{
				kNone = 0,
				kNoMembraneShader = 1 << 0,
				kMembraneGreyscaleColor = 1 << 1,
				kMembraneGreyscaleAlpha = 1 << 2,
				kNoParticleShader = 1 << 3,
				kEdgeEffectInverse = 1 << 4,
				kAffectSkinOnly = 1 << 5,
				kIgnoreAlpha = 1 << 6,
				kProjectUVs = 1 << 7,
				kIgnoreBaseGeometryAlpha = 1 << 8,
				kLighting = 1 << 9,
				kNoWeapons = 1 << 10,
				kParticleAnimated = 1 << 15,
				kParticleGreyscaleColor = 1 << 16,
				kParticleGreyscaleAlpha = 1 << 17,
				kUseBloodGeometry = 1 << 24
			};


			UInt32					unk00;												// 000

			BlendMode				membraneShaderSourceBlendMode;						// 004
			BlendOperation			membraneShaderBlendOperation;						// 008
			ZTestFunction			membraneShaderZTestFunction;						// 00C

			Color					fillTextureEffectColorKey1;							// 010
			float					fillTextureEffectAlphaFadeInTime;					// 014
			float					fillTextureEffectFullAlphaTime;						// 018
			float					fillTextureEffectAlphaFadeOutTime;					// 01C
			float					fillTextureEffectPersistentAlphaRatio;				// 020
			float					fillTextureEffectAlphaPulseAmplitude;				// 024
			float					fillTextureEffectAlphaPulseFrequency;				// 028
			float					fillTextureEffectTextureAnimationSpeedU;			// 02C
			float					fillTextureEffectTextureAnimationSpeedV;			// 030

			float					edgeEffectFallOff;									// 034
			Color					edgeEffectColor;									// 038
			float					edgeEffectAlphaFadeInTime;							// 03C
			float					edgeEffectFullAlphaTime;							// 040
			float					edgeEffectAlphaFadeOutTime;							// 044
			float					edgeEffectPersistentAlphaRatio;						// 048
			float					edgeEffectAlphaPulseAmplitude;						// 04C
			float					edgeEffectAlphaPulseFrequency;						// 050

			float					fillTextureEffectFullAlphaRatio;					// 054

			float					edgeEffectFullAlphaRatio;							// 058

			BlendMode				membraneShaderDestBlendMode;						// 05C

			BlendMode				particleShaderSourceBlendMode;						// 060
			BlendOperation			particleShaderBlendOperation;						// 064
			ZTestFunction			particleShaderZTestOperation;						// 068
			BlendMode				particleShaderDestBlendMode;						// 06C
			float					particleShaderParticleBirthRampUpTime;				// 070
			float					particleShaderFullParticleBirthTime;				// 074
			float					particleShaderParticleBirthRampDownTime;			// 078
			float					particleShaderFullParticleBirthRatio;				// 07C
			float					particleShaderPersistantParticleCount;				// 080
			float					particleShaderParticleLifetime;						// 084
			float					particleShaderParticleLifetimeVariance;				// 088
			float					particleShaderInitialSpeedAlongNormal;				// 08C
			float					particleShaderAccelerationAlongNormal;				// 090
			float					particleShaderInitialVelocity1;						// 094
			float					particleShaderInitialVelocity2;						// 098
			float					particleShaderInitialVelocity3;						// 09C
			float					particleShaderAcceleration1;						// 0A0
			float					particleShaderAcceleration2;						// 0A4
			float					particleShaderAcceleration3;						// 0A8
			float					particleShaderScaleKey1;							// 0AC
			float					particleShaderScaleKey2;							// 0B0
			float					particleShaderScaleKey1Time;						// 0B4
			float					particleShaderScaleKey2Time;						// 0B8

			Color					colorKey1;											// 0BC
			Color					colorKey2;											// 0C0
			Color					colorKey3;											// 0C4
			float					colorKey1ColorAlpha;								// 0C8
			float					colorKey2ColorAlpha;								// 0CC
			float					colorKey3ColorAlpha;								// 0D0
			float					colorKey1ColorKeyTime;								// 0D4
			float					colorKey2ColorKeyTime;								// 0D8
			float					colorKey3ColorKeyTime;								// 0DC

			float					particleShaderInitialSpeedAlongNormalVariance;		// 0E0
			float					particleShaderInitialRotation;						// 0E4
			float					particleShaderInitialRotationVariance;				// 0E8
			float					particleShaderRotationSpeed;						// 0EC
			float					particleShaderRotationSpeedVariance;				// 0F0

			UInt32					pad0D4;												// 0F4

			BGSDebris*				addonModels;										// 0F8

			float					holesStartTime;										// 100
			float					holesEndTime;										// 104
			float					holesStartVal;										// 108
			float					holesEndVal;										// 10C

			float					edgeWidthAlphaUnits;								// 110
			Color					edgeColor;											// 114

			float					explosionWindSpeed;									// 118

			float					textureCountU;										// 11C
			float					textureCountV;										// 120

			float					addonModelsFadeInTime;								// 124
			float					addonModelsFadeOutTime;								// 128
			float					addonModelsScaleStart;								// 12C
			float					addonModelsScaleEnd;								// 130
			float					addonModelsScaleInTime;								// 134
			float					addonModelsScaleOutTime;							// 138

			UInt32					pad13C;												// 13C

			BGSSoundDescriptorForm*	ambientSound;										// 140

			Color					fillTextureEffectColorKey2;							// 148
			Color					fillTextureEffectColorKey3;							// 14C
			float					fillTextureEffectColorKeyScaleTimeColorKey1Scale;	// 150
			float					fillTextureEffectColorKeyScaleTimeColorKey2Scale;	// 154
			float					fillTextureEffectColorKeyScaleTimeColorKey3Scale;	// 158
			float					fillTextureEffectColorKeyScaleTimeColorKey1Time;	// 15C
			float					fillTextureEffectColorKeyScaleTimeColorKey2Time;	// 160
			float					fillTextureEffectColorKeyScaleTimeColorKey3Time;	// 164

			float					colorScale;											// 168

			float					birthPositionOffset;								// 16C
			float					birthPositionOffsetVariance;						// 170

			float					particleShaderAnimatedStartFrame;					// 174
			float					particleShaderAnimatedStartFrameVariance;			// 178
			float					particleShaderAnimatedEndFrame;						// 17C
			float					particleShaderAnimatedLoopStartFrame;				// 180
			float					particleShaderAnimatedLoopStartVariance;			// 184
			float					particleShaderAnimatedFrameCount;					// 188
			float					particleShaderAnimatedFrameCountVariance;			// 18C

			Flag					flags;												// 190

			float					fillTextureEffectTextureScaleU;						// 194
			float					fillTextureEffectTextureScaleV;						// 198

			UInt32					sceneGraphEmitDepthLimit;							// 19C - unused
		};
		STATIC_ASSERT(sizeof(Data) == 0x1A0);


		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data		data;					// 020 - DATA
		TESTexture	fillTexture;			// 1C0 - ICON
		TESTexture	particleShaderTexture;	// 1D0 - ICO2
		TESTexture	holesTexture;			// 1E0 - NAM7
		TESTexture	membranePaletteTexture; // 1F0 - NAM8
		TESTexture	particlePaletteTexture; // 200 - NAM9
		void*		unk210;					// 210
		void*		unk218;					// 218
	};
	STATIC_ASSERT(sizeof(TESEffectShader) == 0x220);
}
