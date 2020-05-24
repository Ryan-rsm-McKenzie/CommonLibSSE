#include "RE/BSShaderProperty.h"


namespace RE
{
	void BSShaderProperty::SetEffectShaderData(const BSTSmartPointer<BSEffectShaderData>& a_data)
	{
		lastRenderPassState = std::numeric_limits<SInt32>::max();
		effectData = a_data;
	}
}
