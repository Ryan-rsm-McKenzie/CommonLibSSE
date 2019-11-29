#include "RE/BSLightingShaderMaterialBase.h"

#include "RE/BSTextureSet.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Type a_type)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialBase::CreateMaterial)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderMaterialBase::CreateMaterial);
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
