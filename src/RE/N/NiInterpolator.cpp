#include "RE/N/NiInterpolator.h"

namespace RE
{
	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiQuatTransform& a_value)
	{
		return Update1(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiColorA& a_value)
	{
		return Update2(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiPoint3& a_value)
	{
		return Update3(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, NiQuaternion& a_value)
	{
		return Update4(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, float& a_value)
	{
		return Update5(a_time, a_interpTarget, a_value);
	}

	bool NiInterpolator::Update(float a_time, NiObjectNET* a_interpTarget, bool& a_value)
	{
		return Update6(a_time, a_interpTarget, a_value);
	}
}
