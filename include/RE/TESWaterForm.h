#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESWaterForm

#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESAttackDamageForm.h"  // TESAttackDamageForm
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESTexture.h"  // TESTexture


namespace RE
{
	class TESWaterForm :
		public TESForm,				// 000
		public TESFullName,			// 020
		public TESAttackDamageForm	// 030
	{
	public:
		inline static const void* RTTI = RTTI_TESWaterForm;


		enum { kTypeID = FormType::Water };


		enum class Flag : UInt8	// FNAM
		{
			kNone = 0,
			kCauseDamage = 1 << 0,
			kEnableFlowmap = 1 << 3,
			kBlendNormals = 1 << 4
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Layers
		{
			enum
			{
				kLayerOne = 0,
				kLayerTwo,
				kLayerThree,

				kTotal
			};
		};


		struct FlowNormals
		{
			TESTexture noiseTexture;	// 00
		};
		STATIC_ASSERT(sizeof(FlowNormals) == 0x10);


		struct VisualData	// DNAM
		{
			struct DisplacementSimulator
			{
				float	startingSize;	// 00
				float	force;			// 04
				float	velocity;		// 08
				float	falloff;		// 0C
				float	dampener;		// 10
			};
			STATIC_ASSERT(sizeof(DisplacementSimulator) == 0x14);


			struct DepthProperties
			{
				float	reflections;		// D0
				float	refraction;			// D4
				float	normals;			// D8
				float	specularLighting;	// DC
			};
			STATIC_ASSERT(sizeof(DepthProperties) == 0x10);


			float					unk00;											// 00
			float					unk04;											// 04
			float					unk08;											// 08
			float					unk0C;											// 0C

			float					specularPropertiesSunSpecularPower;				// 10

			float					waterPropertiesReflectivityAmount;				// 14
			float					waterPropertiesFresnelAmount;					// 18

			UInt32					unk1C;											// 1C

			float					fogPropertiesAboveWaterFogDistanceNearPlane;	// 20
			float					fogPropertiesAboveWaterFogDistanceFarPlane;		// 24

			Color					shallowColor;									// 28
			Color					deepColor;										// 2C
			Color					reflectionColor;								// 30

			UInt32					unk34;											// 34
			float					unk38;											// 38
			float					unk3C;											// 3C
			float					unk40;											// 40
			float					unk44;											// 44

			DisplacementSimulator	displacementSimulator;							// 48

			float					unk5C;											// 5C

			float					noisePropertiesNoiseFalloff;					// 60
			float					noisePropertiesWindDirection[Layers::kTotal];	// 64
			float					noisePropertiesWindSpeed[Layers::kTotal];		// 70

			float					unk7C;											// 7C
			float					unk80;											// 80

			float					fogPropertiesAboveWaterFogAmount;				// 84
			float					unk88;											// 88
			float					fogPropertiesUnderWaterFogAmount;				// 8C
			float					fogPropertiesUnderWaterFogDistanceNearPlane;	// 90
			float					fogPropertiesUnderWaterFogDistanceFarPlane;		// 94

			float					waterPropertiesRefractionMagnitude;				// 98

			float					specularPropertiesSpecularPower;				// 9C

			float					unkA0;											// A0

			float					specularPropertiesSpecularRadius;				// A4
			float					specularPropertiesSpecularBrightness;			// A8

			float					noisePropertiesUVScale[Layers::kTotal];			// AC
			float					noisePropertiesAmplitudeScale[Layers::kTotal];	// B8

			float					waterPropertiesReflectionMagnitude;				// C4

			float					specularPropertiesSunSparkleMagnitude;			// C8
			float					specularPropertiesSunSpecularMagnitude;			// CC

			DepthProperties			depthProperties;								// D0

			float					specularPropertiesSunSparklePower;				// E0

			float					noisePropertiesFlowmapScale;					// E4
		};
		STATIC_ASSERT(sizeof(VisualData) == 0xE8);


		struct Velocity
		{
			float	x;	// 0
			float	y;	// 4
			float	z;	// 8
		};
		STATIC_ASSERT(sizeof(Velocity) == 0xC);


		virtual ~TESWaterForm();																																	// 00

		// override (TESForm)
		virtual void	InitDefaults() override;																													// 04
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	InitItem() override;																														// 13
		virtual bool	GetFlag00020000() override;																													// 1B - { return flags & 1; }
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37


		// members
		UInt32					unk040;							// 040
		UInt32					unk044;							// 044
		UInt64					unk048;							// 048
		UInt64					unk050;							// 050
		UInt64					unk058;							// 058
		UInt64					unk060;							// 060
		UInt64					unk068;							// 068
		UInt32					unk070;							// 070
		UInt32					pad074;							// 074
		TESTexture				noiseLayers[Layers::kTotal];	// 078 - NAM2 - NAM4
		FlowNormals				flowNormals;					// 0A8 - NAM5
		UInt8					opacity;						// 0B8 - ANAM
		Flag					flags;							// 0B9 - FNAM
		UInt16					pad0BA;							// 0BA
		UInt32					pad0BC;							// 0BC
		BGSMaterialType*		material;						// 0C0 - TNAM
		BGSSoundDescriptorForm*	openSound;						// 0C8 - SNAM
		VisualData				visualData;						// 0D0 - DNAM
		UInt64					unk1B8;							// 1B8
		UInt64					unk1C0;							// 1C0
		UInt64					unk1C8;							// 1C8
		UInt64					unk1D0;							// 1D0
		UInt32					unk1D8;							// 1D8
		UInt32					unk1DC;							// 1DC
		UInt32					unk1E0;							// 1E0
		float					unk1E4;							// 1E4
		float					unk1E8;							// 1E8
		float					unk1EC;							// 1EC
		float					unk1F0;							// 1F0
		UInt32					unk1F4;							// 1F4
		SpellItem*				spell;							// 1F8 - XNAM
		UInt64					unk200;							// 200
		UInt64					unk208;							// 208
		UInt64					unk210;							// 210
		UInt64					unk218;							// 218
		UInt64					unk220;							// 220
		UInt64					unk228;							// 228
		UInt64					unk230;							// 230
		UInt32					unk238;							// 238
		UInt32					unk23C;							// 23C
		TESImageSpace*			imageSpace;						// 240 - INAM
		Velocity				linearVelocity;					// 248 - NAM0
		Velocity				angularVelocity;				// 248 - NAM1
	};
	STATIC_ASSERT(sizeof(TESWaterForm) == 0x260);
}
