#include "RE/BSScript/Class.h"

#include "skse64/PapyrusVM.h"  // VMClassInfo


namespace RE
{
	namespace BSScript
	{
		Class::~Class()
		{
			Dtor();
		}


		const char* Class::GetName() const
		{
			return name.c_str();
		}


		UInt32 Class::GetFlags() const
		{
			return pun_bits(flag1, flag2);
		}


		UInt32 Class::GetNumScriptFlags() const
		{
			return pun_bits(numScriptFlags1, numScriptFlags2, numScriptFlags3, numScriptFlags4, numScriptFlags5, numScriptFlags6);
		}


		UInt32 Class::GetNumVariables() const
		{
			return pun_bits(numVariables1, numVariables2, numVariables3, numVariables4, numVariables5, numVariables6, numVariables7, numVariables8, numVariables9, numVariables10);
		}


		UInt32 Class::GetTotalNumVariables() const
		{
			auto numVars = GetNumVariables();
			for (auto iter = parent; iter; iter = iter->parent) {
				numVars += iter->GetNumVariables();
			}
			return numVars;
		}


		UInt32 Class::GetNumDefaultValues() const
		{
			return pun_bits(numDefaultValues1, numDefaultValues2, numDefaultValues3, numDefaultValues4, numDefaultValues5, numDefaultValues6, numDefaultValues7, numDefaultValues8, numDefaultValues9, numDefaultValues10);
		}


		UInt32 Class::GetNumProperties() const
		{
			return pun_bits(numProperties1, numProperties2, numProperties3, numProperties4, numProperties5, numProperties6, numProperties7, numProperties8, numProperties9, numProperties10);
		}


		UInt32 Class::GetNumGlobalFuncs() const
		{
			return pun_bits(numGlobalFuncs1, numGlobalFuncs2, numGlobalFuncs3, numGlobalFuncs4, numGlobalFuncs5, numGlobalFuncs6, numGlobalFuncs7, numGlobalFuncs8, numGlobalFuncs9);
		}


		UInt32 Class::GetNumMemberFuncs() const
		{
			return pun_bits(numMemberFuncs1, numMemberFuncs2, numMemberFuncs3, numMemberFuncs4, numMemberFuncs5, numMemberFuncs6, numMemberFuncs7, numMemberFuncs8, numMemberFuncs9);
		}


		UInt32 Class::GetNumStates() const
		{
			return pun_bits(numStates1, numStates2, numStates3, numStates4, numStates5);
		}


		VMTypeID Class::GetTypeID() const
		{
			return unrestricted_cast<VMTypeID>(this);
		}


		SInt32 Class::GetVariableIndex(const BSFixedString& a_name) const
		{
			using func_t = function_type_t<decltype(&Class::GetVariableIndex)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, GetVariable, func_t*);
			return func(this, a_name);
		}


		IFunction* Class::GetFunction(const char* a_name) const
		{
			using func_t = function_type_t<decltype(&Class::GetFunction)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, GetFunction, func_t*);
			return func(this, a_name);
		}


		void Class::Dtor()
		{
			using func_t = function_type_t<decltype(&Class::Dtor)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, Destroy, func_t*);
			return func(this);
		}
	}
}
