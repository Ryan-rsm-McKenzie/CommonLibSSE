#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSShaderProperty

#include "RE/NiShadeProperty.h"  // NiShadeProperty


namespace RE
{
	class BSLightingShaderMaterial;


	class BSShaderProperty : public NiShadeProperty
	{
	public:
		inline static const void* RTTI = RTTI_BSShaderProperty;


		enum class ShaderFlag1 : UInt32
		{
			kSpecular = 1 << 0,
			kSkinned = 1 << 1,
			kTempRefraction = 1 << 2,
			kVertexAlpha = 1 << 3,
			kGreyscaleToPaletteColor = 1 << 4,
			kGreyscaleToPaletteAlpha = 1 << 5,
			kUseFalloff = 1 << 6,
			kEnvironmentMapping = 1 << 7,
			kRecieveShadows = 1 << 8,
			kCastShadows = 1 << 9,
			kFacegenDetailMap = 1 << 10,
			kParallax = 1 << 11,
			kModelSpaceNormals = 1 << 12,
			kNonProjectiveShadows = 1 << 13,
			kLandscape = 1 << 14,
			kRefraction = 1 << 15,
			kFireRefraction = 1 << 16,
			kEyeEnvironmentMapping = 1 << 17,
			kHairSoftLighting = 1 << 18,
			kScreendoorAlphaFade = 1 << 19,
			kLocalmapHideSecret = 1 << 20,
			kFaceGenRGBTint = 1 << 21,
			kOwnEmit = 1 << 22,
			kProjectedUV = 1 << 23,
			kMultipleTextures = 1 << 24,
			kRemappableTextures = 1 << 25,
			kDecal = 1 << 26,
			kDynamicDecal = 1 << 27,
			kParallaxOcclusion = 1 << 28,
			kExternalEmittance = 1 << 29,
			kSoftEffect = 1 << 30,
			kZBufferTest = (UInt32)1 << 31
		};


		enum class ShaderFlag2 : UInt32
		{
			kZBufferWrite = 1 << 0,
			kLODLandscape = 1 << 1,
			kLODObjects = 1 << 2,
			kNoFade = 1 << 3,
			kDoubleSided = 1 << 4,
			kVertexColors = 1 << 5,
			kGlowMap = 1 << 6,
			kAssumeShadowmask = 1 << 7,
			kPackedTangent = 1 << 8,
			kMultiIndexSnow = 1 << 9,
			kVertexLighting = 1 << 10,
			kUniformScale = 1 << 11,
			kFitSlope = 1 << 12,
			kBillboard = 1 << 13,
			kNoLODLandBlend = 1 << 14,
			kEnvMapLightFade = 1 << 15,
			kWireframe = 1 << 16,
			kWeaponBlood = 1 << 17,
			kHideOnLocalMap = 1 << 18,
			kPremultAlpha = 1 << 19,
			kCloudLOD = 1 << 20,
			kAnisotropicLighting = 1 << 21,
			kNoTransparencyMultisampling = 1 << 22,
			kMultiLayerParallax = 1 << 24,
			kSoftLighting = 1 << 25,
			kRimLighting = 1 << 26,
			kBackLighting = 1 << 27,
			kTreeAnim = 1 << 29,
			kEffectLighting = 1 << 30,
			kHDLODObjects = (UInt32)1 << 31
		};


		virtual ~BSShaderProperty();	// 00

		// override (NiShadeProperty)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17 - { return 0; }
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { NiShadeProperty::LinkObject(a_stream); }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A - { return NiShadeProperty::RegisterStreamables(a_stream); }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C - { return false; }
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E - { NiObjectNET::PostLinkObject(a_stream); }
		virtual void			Unk_27(void) override;								// 27 - { return 1; }
		virtual void			Unk_29(void) override;								// 29

		// add
		virtual void			Unk_2A(void) = 0;									// 2A
		virtual void			Unk_2B(void);										// 2B - { return 0; }
		virtual void			Unk_2C(void);										// 2C - { return 0; }
		virtual void			Unk_2D(void);										// 2D - { return 0; }
		virtual void			Unk_2E(void);										// 2E - { return 1; }
		virtual void			Unk_2F(void);										// 2F - { return 0; }
		virtual void			Unk_30(void);										// 30
		virtual void			Unk_31(void);										// 31 - { return; }
		virtual void			Unk_32(void);										// 32 - { return 1.0; }
		virtual void			Unk_33(void);										// 33 - { return 1; }
		virtual void			Unk_34(void);										// 34
		virtual void			Unk_35(void);										// 35 - { return 0; }
		virtual void			Unk_36(void);										// 36 - { return 0; }
		virtual void			Unk_37(void);										// 37 - { return 0; }
		virtual void			Unk_38(void);										// 38 - { return 0; }
		virtual void			Unk_39(void);										// 39 - { return 0; }
		virtual void			Unk_3A(void);										// 3A - { return; }
		virtual void			Unk_3B(void);										// 3B - { return; }
		virtual void			Unk_3C(void);										// 3C - { return 0; }
		virtual void			Unk_3D(void);										// 3D - { return 0; }
		virtual void			Unk_3E(void);										// 3E - { return 0; }


		// members
		UInt32						unk30;			// 30
		UInt32						unk34;			// 34
		ShaderFlag1					shaderFlags1;	// 38
		ShaderFlag2					shaderFlags2;	// 3C
		void*						unk40;			// 40
		UInt64						unk48;			// 48
		void*						unk50;			// 50
		UInt64						unk58;			// 58
		UInt64						unk60;			// 60
		void*						unk68;			// 68 - smart ptr
		UInt64						unk70;			// 70
		BSLightingShaderMaterial*	material;		// 78
		UInt64						unk80;			// 80
	};
	STATIC_ASSERT(sizeof(BSShaderProperty) == 0x88);
}
