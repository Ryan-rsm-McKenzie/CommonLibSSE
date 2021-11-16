#include "RE/B/BSLightingShaderMaterialBase.h"

#include "RE/B/BSLightingShaderMaterial.h"
#include "RE/B/BSLightingShaderMaterialEnvmap.h"
#include "RE/B/BSLightingShaderMaterialEye.h"
#include "RE/B/BSLightingShaderMaterialFacegen.h"
#include "RE/B/BSLightingShaderMaterialFacegenTint.h"
#include "RE/B/BSLightingShaderMaterialGlowmap.h"
#include "RE/B/BSLightingShaderMaterialHairTint.h"
#include "RE/B/BSLightingShaderMaterialLODLandscape.h"
#include "RE/B/BSLightingShaderMaterialLandscape.h"
#include "RE/B/BSLightingShaderMaterialMultiLayerParallax.h"
#include "RE/B/BSLightingShaderMaterialParallax.h"
#include "RE/B/BSLightingShaderMaterialParallaxOcc.h"
#include "RE/B/BSLightingShaderMaterialSnow.h"
#include "RE/B/BSTextureSet.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	void BSLightingShaderMaterialBase::CopyBaseMembers(BSLightingShaderMaterialBase* a_other)
	{
		texCoordOffset[0] = a_other->texCoordOffset[0];
		texCoordOffset[1] = a_other->texCoordOffset[1];
		texCoordScale[0] = a_other->texCoordScale[0];
		texCoordScale[1] = a_other->texCoordScale[1];

		diffuseTexture = a_other->diffuseTexture;
		normalTexture = a_other->normalTexture;
		rimSoftLightingTexture = a_other->rimSoftLightingTexture;
		specularBackLightingTexture = a_other->specularBackLightingTexture;
		textureClampMode = a_other->textureClampMode;
		textureSet = a_other->textureSet;

		materialAlpha = a_other->materialAlpha;
		specularPower = a_other->specularPower;
		specularColor = a_other->specularColor;
		specularColorScale = a_other->specularColorScale;
		refractionPower = a_other->refractionPower;
		subSurfaceLightRolloff = a_other->subSurfaceLightRolloff;
		rimLightPower = a_other->rimLightPower;
	}

	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Feature a_feature)
	{
		switch (a_feature) {
		case Feature::kDefault:
			{
				REL::Relocation<std::uintptr_t> vtbl{ BSLightingShaderMaterial::VTABLE[0] };
				auto                            material = malloc<BSLightingShaderMaterial>();
				std::memset(material, 0, sizeof(BSLightingShaderMaterial));
				material->Ctor();
				((std::uintptr_t*)material)[0] = vtbl.address();
				return material;
			}
		case Feature::kEnvironmentMap:
			{
				auto material = malloc<BSLightingShaderMaterialEnvmap>();
				return material->Ctor();
			}
		case Feature::kGlowMap:
			{
				auto material = malloc<BSLightingShaderMaterialGlowmap>();
				return material->Ctor();
			}
		case Feature::kParallax:
			{
				auto material = malloc<BSLightingShaderMaterialParallax>();
				return material->Ctor();
			}
		case Feature::kFaceGen:
			{
				auto material = malloc<BSLightingShaderMaterialFacegen>();
				return material->Ctor();
			}
		case Feature::kFaceGenRGBTint:
			{
				auto material = malloc<BSLightingShaderMaterialFacegenTint>();
				return material->Ctor();
			}
		case Feature::kHairTint:
			{
				auto material = malloc<BSLightingShaderMaterialHairTint>();
				return material->Ctor();
			}
		case Feature::kParallaxOcc:
			{
				auto material = malloc<BSLightingShaderMaterialParallaxOcc>();
				return material->Ctor();
			}
		case Feature::kMultiTexLand:
		case Feature::kMultiTexLandLODBlend:
			{
				auto material = malloc<BSLightingShaderMaterialLandscape>();
				return material->Ctor();
			}
		case Feature::kLODLand:
		case Feature::kLODLandNoise:
			{
				auto material = malloc<BSLightingShaderMaterialLODLandscape>();
				return material->Ctor();
			}
		case Feature::kUnknown:
		case Feature::kMultiIndexTriShapeSnow:
			{
				auto material = malloc<BSLightingShaderMaterialSnow>();
				return material->Ctor();
			}
		case Feature::kMultilayerParallax:
			{
				auto material = malloc<BSLightingShaderMaterialMultiLayerParallax>();
				return material->Ctor();
			}
		case Feature::kEye:
			{
				auto material = malloc<BSLightingShaderMaterialEye>();
				return material->Ctor();
			}
		default:
			return nullptr;
		}
	}

	NiPointer<BSTextureSet> BSLightingShaderMaterialBase::GetTextureSet() const
	{
		return textureSet;
	}

	void BSLightingShaderMaterialBase::SetTextureSet(NiPointer<BSTextureSet> a_textureSet)
	{
		textureSet = a_textureSet;
	}
}
