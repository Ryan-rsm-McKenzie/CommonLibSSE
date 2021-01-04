#include "RE/B/BSLightingShaderMaterialBase.h"

#include "RE/B/BSTextureSet.h"

namespace RE
{
	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Feature a_feature)
	{
		using func_t = decltype(&BSLightingShaderMaterialBase::CreateMaterial);
		REL::Relocation<func_t> func{ Offset::BSLightingShaderMaterialBase::CreateMaterial };
		return func(a_feature);
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
