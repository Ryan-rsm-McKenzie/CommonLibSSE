#include "RE/I/IVirtualMachine.h"

#include "RE/B/BSFixedString.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/T/TESForm.h"

namespace RE
{
	namespace BSScript
	{
		bool IVirtualMachine::CreateArray(const TypeInfo& a_typeInfo, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr)
		{
			return CreateArray1(a_typeInfo, a_size, a_arrayPtr);
		}

		bool IVirtualMachine::CreateArray(TypeInfo::RawType a_typeID, const BSFixedString& a_className, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr)
		{
			return CreateArray2(a_typeID, a_className, a_size, a_arrayPtr);
		}

		bool IVirtualMachine::CreateObject(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr)
		{
			return CreateObject1(a_className, a_property, a_objPtr);
		}

		bool IVirtualMachine::CreateObject(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result)
		{
			return CreateObject2(a_className, a_result);
		}

		bool IVirtualMachine::DispatchMethodCall(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result)
		{
			return DispatchMethodCall1(a_obj, a_fnName, a_args, a_result);
		}

		bool IVirtualMachine::DispatchMethodCall(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result)
		{
			return DispatchMethodCall2(a_handle, a_className, a_fnName, a_args, a_result);
		}

		ObjectBindPolicy* IVirtualMachine::GetObjectBindPolicy()
		{
			return GetObjectBindPolicy1();
		}

		const ObjectBindPolicy* IVirtualMachine::GetObjectBindPolicy() const
		{
			return GetObjectBindPolicy2();
		}

		IObjectHandlePolicy* IVirtualMachine::GetObjectHandlePolicy()
		{
			return GetObjectHandlePolicy1();
		}

		const IObjectHandlePolicy* IVirtualMachine::GetObjectHandlePolicy() const
		{
			return GetObjectHandlePolicy2();
		}

		bool IVirtualMachine::GetScriptObjectType(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr)
		{
			return GetScriptObjectType1(a_className, a_outTypeInfoPtr);
		}

		bool IVirtualMachine::GetScriptObjectType(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr)
		{
			return GetScriptObjectType2(a_typeID, a_outTypeInfoPtr);
		}

		bool IVirtualMachine::GetScriptObjectTypeNoLoad(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) const
		{
			return GetScriptObjectTypeNoLoad1(a_className, a_typeInfoPtr);
		}

		bool IVirtualMachine::GetScriptObjectTypeNoLoad(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) const
		{
			return GetScriptObjectTypeNoLoad2(a_typeID, a_outTypeInfoPtr);
		}

		bool IVirtualMachine::GetVariableValue(const BSTSmartPointer<Object>& a_objPtr, std::uint32_t a_index, Variable& a_out) const
		{
			return GetVariableValue1(a_objPtr, a_index, a_out);
		}

		bool IVirtualMachine::GetVariableValue(VMHandle a_handle, const BSFixedString& a_className, std::int32_t a_variableIndex, Variable& a_out) const
		{
			return GetVariableValue2(a_handle, a_className, a_variableIndex, a_out);
		}

		void IVirtualMachine::SetCallableFromTasklets(const char* a_className, const char* a_stateName, const char* a_fnName, bool a_callable)
		{
			return SetCallableFromTasklets1(a_className, a_stateName, a_fnName, a_callable);
		}

		void IVirtualMachine::SetCallableFromTasklets(const char* a_className, const char* a_fnName, bool a_callable)
		{
			return SetCallableFromTasklets2(a_className, a_fnName, a_callable);
		}

		void IVirtualMachine::TraceForm(TESForm* a_form, const char* a_str, VMStackID a_stackID, Severity a_severity)
		{
			assert(a_str);

			BSFixedString name;
			if (a_form) {
				auto policy = GetObjectHandlePolicy();
				if (policy) {
					auto handle = policy->GetHandleForObject(a_form->GetFormType(), a_form);
					policy->ConvertHandleToString(handle, name);
				}
			}

			if (name.empty()) {
				name = "None";
			}

			std::string_view str(a_str);
			std::string		 message;
			message.reserve(name.length() + 2 + str.length());
			message += name;
			message += ": ";
			message += str;

			TraceStack(message.c_str(), a_stackID, a_severity);
		}

		void IVirtualMachine::VTraceStack(const char* a_fmt, VMStackID a_stackID, Severity a_severity, ...)
		{
			assert(a_fmt);

			std::va_list args1;
			va_start(args1, a_fmt);
			std::va_list args2;
			va_copy(args2, args1);

			std::vector<char> buf(std::vsnprintf(nullptr, 0, a_fmt, args1) + 1);
			va_end(args1);

			std::vsnprintf(buf.data(), buf.size(), a_fmt, args2);
			va_end(args2);

			TraceStack(buf.data(), a_stackID, a_severity);
		}
	}
}
