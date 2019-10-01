#include "RE/BSLightingShaderMaterialBase.h"

#include "skse64/NiMaterial.h"  // CreateShaderMaterial

#include "RE/BSTextureSet.h"  // BSTextureSet


namespace RE
{
	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Type a_type)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialBase::CreateMaterial)>;
		func_t* func = unrestricted_cast<func_t*>(CreateShaderMaterial.GetUIntPtr());
		return func(a_type);
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
