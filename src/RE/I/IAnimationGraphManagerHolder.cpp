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

		bool IAnimationGraphManagerHolder::SetGraphVariableBool(const BSFixedString& a_variableName, bool a_in) const
	{
		using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableBool);
		REL::Relocation<func_t> func{ REL::ID(32141) };
		return func(this, a_variableName, a_in);
	}

	bool IAnimationGraphManagerHolder::SetGraphVariableInt(const BSFixedString& a_variableName, std::int32_t a_in) const
	{
		using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableInt);
		REL::Relocation<func_t> func{ REL::ID(32142) };
		return func(this, a_variableName, a_in);
	}

	bool IAnimationGraphManagerHolder::SetGraphVariableFloat(const BSFixedString& a_variableName, float a_in) const
	{
		using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableFloat);
		REL::Relocation<func_t> func{ REL::ID(32143) };
		return func(this, a_variableName, a_in);
	}

	bool IAnimationGraphManagerHolder::SetGraphVariableNiPoint3(const BSFixedString& a_variableName, NiPoint3& a_in) const
	{
		using func_t = decltype(&IAnimationGraphManagerHolder::SetGraphVariableNiPoint3);
		REL::Relocation<func_t> func{ REL::ID(32144) };
		return func(this, a_variableName, a_in);
	}


	bool IAnimationGraphManagerHolder::SetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_in)
	{
		return SetAnimationGraphManagerImpl(a_in);
	}
}
