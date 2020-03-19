#include "RE/BSScript/ObjectTypeInfo.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		BSFixedString ObjectTypeInfo::UserFlagInfo::GetUserFlag() const
		{
			auto sanitizedType = data & ~kUnkFlag;
			return *reinterpret_cast<BSFixedString*>(&sanitizedType);
		}


		UInt32 ObjectTypeInfo::NamedStateInfo::GetNumFuncs() const
		{
			return data & kFuncCountMask;
		}


		auto ObjectTypeInfo::NamedStateInfo::GetFuncIter()
			-> Func*
		{
			return reinterpret_cast<Func*>((std::uintptr_t)this + (data >> kFuncOffsetShift));
		}


		auto ObjectTypeInfo::NamedStateInfo::GetFuncIter() const
			-> const Func*
		{
			return reinterpret_cast<const Func*>((std::uintptr_t)this + (data >> kFuncOffsetShift));
		}


		ObjectTypeInfo::~ObjectTypeInfo()
		{
			ReleaseData();
		}


		const char* ObjectTypeInfo::GetName() const
		{
			return name.c_str();
		}


		ObjectTypeInfo* ObjectTypeInfo::GetParent()
		{
			return parentTypeInfo.get();
		}


		const ObjectTypeInfo* ObjectTypeInfo::GetParent() const
		{
			return parentTypeInfo.get();
		}


		TypeInfo::RawType ObjectTypeInfo::GetRawType() const
		{
			return unrestricted_cast<TypeInfo::RawType>(this);
		}


		bool ObjectTypeInfo::IsInherited() const
		{
			return inherited;
		}


		bool ObjectTypeInfo::IsRemoved() const
		{
			return removed;
		}


		auto ObjectTypeInfo::GetUnlinkedFunctionIter()
			-> UnlinkedNativeFunction*
		{
			return reinterpret_cast<UnlinkedNativeFunction*>(data);
		}


		auto ObjectTypeInfo::GetUnlinkedFunctionIter() const
			-> const UnlinkedNativeFunction*
		{
			return reinterpret_cast<const UnlinkedNativeFunction*>(data);
		}


		UInt32 ObjectTypeInfo::GetNumUserFlags() const
		{
			return pun_bits(userFlagCount1, userFlagCount2, userFlagCount3, userFlagCount4, userFlagCount5, userFlagCount6);
		}


		auto ObjectTypeInfo::GetUserFlagIter()
			-> UserFlagInfo*
		{
			return reinterpret_cast<UserFlagInfo*>(data);
		}


		auto ObjectTypeInfo::GetUserFlagIter() const
			-> const UserFlagInfo*
		{
			return reinterpret_cast<const UserFlagInfo*>(data);
		}


		UInt32 ObjectTypeInfo::GetNumVariables() const
		{
			return pun_bits(variableCount1, variableCount2, variableCount3, variableCount4, variableCount5, variableCount6, variableCount7, variableCount8, variableCount9, variableCount10);
		}


		UInt32 ObjectTypeInfo::GetTotalNumVariables() const
		{
			auto numVars = GetNumVariables();
			for (auto iter = GetParent(); iter; iter = iter->GetParent()) {
				numVars += iter->GetNumVariables();
			}
			return numVars;
		}


		auto ObjectTypeInfo::GetVariableIter()
			-> VariableInfo*
		{
			return reinterpret_cast<VariableInfo*>(GetUserFlagIter() + GetNumUserFlags());
		}


		auto ObjectTypeInfo::GetVariableIter() const
			-> const VariableInfo*
		{
			return reinterpret_cast<const VariableInfo*>(GetUserFlagIter() + GetNumUserFlags());
		}


		UInt32 ObjectTypeInfo::GetNumInitalValues() const
		{
			return pun_bits(initialValueCount1, initialValueCount2, initialValueCount3, initialValueCount4, initialValueCount5, initialValueCount6, initialValueCount7, initialValueCount8, initialValueCount9, initialValueCount10);
		}


		auto ObjectTypeInfo::GetInitialValueIter()
			-> InitialValueInfo*
		{
			return reinterpret_cast<InitialValueInfo*>(GetVariableIter() + GetNumVariables());
		}


		auto ObjectTypeInfo::GetInitialValueIter() const
			-> const InitialValueInfo*
		{
			return reinterpret_cast<const InitialValueInfo*>(GetVariableIter() + GetNumVariables());
		}


		UInt32 ObjectTypeInfo::GetNumProperties() const
		{
			return pun_bits(propertyCount1, propertyCount2, propertyCount3, propertyCount4, propertyCount5, propertyCount6, propertyCount7, propertyCount8, propertyCount9, propertyCount10);
		}


		auto ObjectTypeInfo::GetPropertyIter()
			-> PropertyInfo*
		{
			return reinterpret_cast<PropertyInfo*>(GetInitialValueIter() + GetNumInitalValues());
		}


		auto ObjectTypeInfo::GetPropertyIter() const
			-> const PropertyInfo*
		{
			return reinterpret_cast<const PropertyInfo*>(GetInitialValueIter() + GetNumInitalValues());
		}


		UInt32 ObjectTypeInfo::GetNumGlobalFuncs() const
		{
			return pun_bits(staticFunctionCount1, staticFunctionCount2, staticFunctionCount3, staticFunctionCount4, staticFunctionCount5, staticFunctionCount6, staticFunctionCount7, staticFunctionCount8, staticFunctionCount9);
		}


		auto ObjectTypeInfo::GetGlobalFuncIter()
			-> GlobalFuncInfo*
		{
			return reinterpret_cast<GlobalFuncInfo*>(GetPropertyIter() + GetNumProperties());
		}


		auto ObjectTypeInfo::GetGlobalFuncIter() const
			-> const GlobalFuncInfo*
		{
			return reinterpret_cast<const GlobalFuncInfo*>(GetPropertyIter() + GetNumProperties());
		}


		UInt32 ObjectTypeInfo::GetNumMemberFuncs() const
		{
			return pun_bits(emptyStateMemberFunctionCount1, emptyStateMemberFunctionCount2, emptyStateMemberFunctionCount3, emptyStateMemberFunctionCount4, emptyStateMemberFunctionCount5, emptyStateMemberFunctionCount6, emptyStateMemberFunctionCount7, emptyStateMemberFunctionCount8, emptyStateMemberFunctionCount9, emptyStateMemberFunctionCount10, emptyStateMemberFunctionCount11);
		}


		auto ObjectTypeInfo::GetMemberFuncIter()
			-> MemberFuncInfo*
		{
			return reinterpret_cast<MemberFuncInfo*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}


		auto ObjectTypeInfo::GetMemberFuncIter() const
			-> const MemberFuncInfo*
		{
			return reinterpret_cast<const MemberFuncInfo*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}


		UInt32 ObjectTypeInfo::GetNumNamedStates() const
		{
			return pun_bits(namedStateCount1, namedStateCount2, namedStateCount3, namedStateCount4, namedStateCount5, namedStateCount6, namedStateCount7);
		}


		auto ObjectTypeInfo::GetNamedStateIter()
			-> NamedStateInfo*
		{
			return reinterpret_cast<NamedStateInfo*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}


		auto ObjectTypeInfo::GetNamedStateIter() const
			-> const NamedStateInfo*
		{
			return reinterpret_cast<const NamedStateInfo*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}


		UInt32 ObjectTypeInfo::GetPropertyIndex(const BSFixedString& a_name) const
		{
			auto props = GetPropertyIter();
			if (props) {
				for (UInt32 i = 0; i < GetNumVariables(); ++i) {
					auto& prop = props[i];
					if (prop.name == a_name) {
						return prop.info.autoVarIndex;
					}
				}
			}
			return static_cast<UInt32>(-1);
		}


		void ObjectTypeInfo::ReleaseData()
		{
			using func_t = decltype(&ObjectTypeInfo::ReleaseData);
			REL::Offset<func_t> func(Offset::BSScript::ObjectTypeInfo::ReleaseData);
			return func(this);
		}
	}
}
