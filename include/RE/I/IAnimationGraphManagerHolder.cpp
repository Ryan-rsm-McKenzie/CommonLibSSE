#include "RE/I/IAnimationGraphManagerHolder.h"

namespace RE
{
	bool IAnimationGraphManagerHolder::GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) const
	{
		return GetAnimationGraphManagerImpl(a_out);
	}

	bool IAnimationGraphManagerHolder::GetGraphVariableFloat(const BSFixedString& a_variableName, float& a_out) const
	{
		return GetGraphVariableImpl1(a_variableName, a_out);
	}

	bool IAnimationGraphManagerHolder::GetGraphVariableInt(const BSFixedString& a_variableName, std::int32_t& a_out) const
	{
		return GetGraphVariableImpl2(a_variableName, a_out);
	}

	bool IAnimationGraphManagerHolder::GetGraphVariableBool(const BSFixedString& a_variableName, bool& a_out) const
	{
		return GetGraphVariableImpl3(a_variableName, a_out);
	}

	bool IAnimationGraphManagerHolder::SetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_in)
	{
		return SetAnimationGraphManagerImpl(a_in);
	}
}
