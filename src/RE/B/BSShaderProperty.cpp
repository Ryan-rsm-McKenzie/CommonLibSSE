#include "RE/B/BSShaderProperty.h"

namespace RE
{
	void BSShaderProperty::SetEffectShaderData(const BSTSmartPointer<BSEffectShaderData>& a_data)
	{
		lastRenderPassState = std::numeric_limits<std::int32_t>::max();
		effectData = a_data;
	}

	void BSShaderProperty::SetMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::SetMaterial);
		REL::Relocation<func_t> func{ REL::Offset(0x13B7B10) };
		return func(this, a_material, a_unk1);
	}

	void BSShaderProperty::SetFlags(EShaderPropertyFlag8 a_flag, bool a_toggle)
	{
		using func_t = decltype(&BSShaderProperty::SetFlags);
		REL::Relocation<func_t> func{ REL::Offset(0x13B7A00) };
		return func(this, a_flag, a_toggle);
	}
}
