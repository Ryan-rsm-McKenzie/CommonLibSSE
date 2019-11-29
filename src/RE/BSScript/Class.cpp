#include "RE/BSScript/Class.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		BSFixedString Class::ScriptFlag::GetFlag() const
		{
			auto sanitizedType = flag & ~kUnkFlag;
			return *reinterpret_cast<BSFixedString*>(&sanitizedType);
		}


		UInt32 Class::ScriptState::GetNumFuncs() const
		{
			return data & kFuncCountMask;
		}


		auto Class::ScriptState::GetFuncIter()
			-> Func*
		{
			return reinterpret_cast<Func*>((std::uintptr_t)this + (data >> kFuncOffsetShift));
		}


		auto Class::ScriptState::GetFuncIter() const
			-> const Func*
		{
			return reinterpret_cast<const Func*>((std::uintptr_t)this + (data >> kFuncOffsetShift));
		}


		Class::~Class()
		{
			ReleaseData();
		}


		const char* Class::GetName() const
		{
			return name.c_str();
		}


		VMTypeID Class::GetTypeID() const
		{
			return unrestricted_cast<VMTypeID>(this);
		}


		bool Class::IsInherited() const
		{
			return inherited;
		}


		bool Class::IsRemoved() const
		{
			return removed;
		}


		auto Class::GetFunctionIter()
			-> Function*
		{
			return reinterpret_cast<Function*>(data);
		}


		auto Class::GetFunctionIter() const
			-> const Function*
		{
			return reinterpret_cast<const Function*>(data);
		}


		UInt32 Class::GetNumFlags() const
		{
			return pun_bits(numFlags1, numFlags2, numFlags3, numFlags4, numFlags5, numFlags6);
		}


		auto Class::GetFlagIter()
			-> ScriptFlag*
		{
			return reinterpret_cast<ScriptFlag*>(data);
		}


		auto Class::GetFlagIter() const
			-> const ScriptFlag*
		{
			return reinterpret_cast<const ScriptFlag*>(data);
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


		auto Class::GetVariableIter()
			-> ScriptVariable*
		{
			return reinterpret_cast<ScriptVariable*>(GetFlagIter() + GetNumFlags());
		}


		auto Class::GetVariableIter() const
			-> const ScriptVariable*
		{
			return reinterpret_cast<const ScriptVariable*>(GetFlagIter() + GetNumFlags());
		}


		UInt32 Class::GetNumDefaultValues() const
		{
			return pun_bits(numDefaultValues1, numDefaultValues2, numDefaultValues3, numDefaultValues4, numDefaultValues5, numDefaultValues6, numDefaultValues7, numDefaultValues8, numDefaultValues9, numDefaultValues10);
		}


		auto Class::GetDefaultValueIter()
			-> DefaultScriptValue*
		{
			return reinterpret_cast<DefaultScriptValue*>(GetVariableIter() + GetNumVariables());
		}


		auto Class::GetDefaultValueIter() const
			-> const DefaultScriptValue*
		{
			return reinterpret_cast<const DefaultScriptValue*>(GetVariableIter() + GetNumVariables());
		}


		UInt32 Class::GetNumProperties() const
		{
			return pun_bits(numProperties1, numProperties2, numProperties3, numProperties4, numProperties5, numProperties6, numProperties7, numProperties8, numProperties9, numProperties10);
		}


		auto Class::GetPropertyIter()
			-> ScriptProperty*
		{
			return reinterpret_cast<ScriptProperty*>(GetDefaultValueIter() + GetNumDefaultValues());
		}


		auto Class::GetPropertyIter() const
			-> const ScriptProperty*
		{
			return reinterpret_cast<const ScriptProperty*>(GetDefaultValueIter() + GetNumDefaultValues());
		}


		UInt32 Class::GetNumGlobalFuncs() const
		{
			return pun_bits(numGlobalFuncs1, numGlobalFuncs2, numGlobalFuncs3, numGlobalFuncs4, numGlobalFuncs5, numGlobalFuncs6, numGlobalFuncs7, numGlobalFuncs8, numGlobalFuncs9);
		}


		auto Class::GetGlobalFuncIter()
			-> ScriptGlobalFunc*
		{
			return reinterpret_cast<ScriptGlobalFunc*>(GetPropertyIter() + GetNumProperties());
		}


		auto Class::GetGlobalFuncIter() const
			-> const ScriptGlobalFunc*
		{
			return reinterpret_cast<const ScriptGlobalFunc*>(GetPropertyIter() + GetNumProperties());
		}


		UInt32 Class::GetNumMemberFuncs() const
		{
			return pun_bits(numMemberFuncs1, numMemberFuncs2, numMemberFuncs3, numMemberFuncs4, numMemberFuncs5, numMemberFuncs6, numMemberFuncs7, numMemberFuncs8, numMemberFuncs9, numMemberFuncs10, numMemberFuncs11);
		}


		auto Class::GetMemberFuncIter()
			-> ScriptMemberFunc*
		{
			return reinterpret_cast<ScriptMemberFunc*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}


		auto Class::GetMemberFuncIter() const
			-> const ScriptMemberFunc*
		{
			return reinterpret_cast<const ScriptMemberFunc*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}


		UInt32 Class::GetNumStates() const
		{
			return pun_bits(numStates1, numStates2, numStates3, numStates4, numStates5, numStates6, numStates7);
		}


		auto Class::GetStateIter()
			-> ScriptState*
		{
			return reinterpret_cast<ScriptState*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}


		auto Class::GetStateIter() const
			-> const ScriptState*
		{
			return reinterpret_cast<const ScriptState*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}


		UInt32 Class::GetPropertyIndex(const BSFixedString& a_name) const
		{
			auto props = GetPropertyIter();
			for (UInt32 i = 0; i < GetNumVariables(); ++i) {
				auto& prop = props[i];
				if (prop.name == a_name) {
					return prop.idx;
				}
			}
			return static_cast<UInt32>(-1);
		}


		void Class::ReleaseData()
		{
			using func_t = function_type_t<decltype(&Class::ReleaseData)>;
			REL::Offset<func_t*> func(Offset::BSScript::Class::ReleaseData);
			return func(this);
		}
	}
}
