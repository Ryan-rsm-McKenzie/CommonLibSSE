#include "RE/BSScript/BSScriptClass.h"

#include "skse64/PapyrusVM.h"  // VMClassInfo


namespace RE
{
	namespace BSScript
	{
		BSScriptClass::~BSScriptClass()
		{
			Dtor();
		}


		const char* BSScriptClass::GetName() const
		{
			return name;
		}


		UInt32 BSScriptClass::GetNumVariables() const
		{
			return numVariables;
		}

		UInt32 BSScriptClass::GetNumMemberFunctions() const
		{
			return numMemberFuncs;
		}

		UInt32 BSScriptClass::GetNumGlobalFunctions() const
		{
			return numGlobalFuncs;
		}


		VMTypeID BSScriptClass::GetTypeID() const
		{
			return unrestricted_cast<VMTypeID>(this);
		}


		SInt32 BSScriptClass::GetVariableIndex(const BSFixedString& a_name) const
		{
			using func_t = function_type_t<decltype(&BSScriptClass::GetVariableIndex)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, GetVariable, func_t*);
			return func(this, a_name);
		}


		IFunction* BSScriptClass::GetFunction(const char* a_name) const
		{
			using func_t = function_type_t<decltype(&BSScriptClass::GetFunction)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, GetFunction, func_t*);
			return func(this, a_name);
		}


		void BSScriptClass::Dtor()
		{
			using func_t = function_type_t<decltype(&BSScriptClass::Dtor)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMClassInfo, Destroy, func_t*);
			return func(this);
		}
	}
}
