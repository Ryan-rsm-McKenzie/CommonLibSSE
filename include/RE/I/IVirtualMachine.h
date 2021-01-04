#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ErrorLogger.h"
#include "RE/T/TypeInfo.h"

namespace RE
{
	namespace BSJobs
	{
		class JobList;
	}

	class TESForm;

	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IForEachScriptObjectFunctor;
		class IFunction;
		class IFunctionArguments;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class ITypeLinkedCallback;
		class Object;
		class ObjectBindPolicy;
		class ObjectTypeInfo;
		class Variable;
		struct IObjectHandlePolicy;
		struct LogEvent;
		struct StatsEvent;

		class IVirtualMachine : public BSIntrusiveRefCounted
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IVirtualMachine;

			using Severity = BSScript::ErrorLogger::Severity;

			virtual ~IVirtualMachine();	 // 00

			// add
			virtual void					   SetLinkedCallback(ITypeLinkedCallback* a_callback) = 0;																																	   // 01
			virtual void					   TraceStack(const char* a_str, VMStackID a_stackID, Severity a_severity = Severity::kInfo) = 0;																							   // 02
			virtual void					   Unk_03(void) = 0;																																										   // 03
			virtual void					   Update(float a_budget) = 0;																																								   // 04
			virtual void					   UpdateTasklets(float a_budget) = 0;																																						   // 05
			virtual void					   SetOverstressed(bool a_set) = 0;																																							   // 06
			virtual bool					   IsCompletelyFrozen() const = 0;																																							   // 07
			virtual bool					   RegisterObjectType(VMTypeID a_typeID, const char* a_className) = 0;																														   // 08
			virtual bool					   GetScriptObjectType1(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) = 0;																			   // 09
			virtual bool					   GetScriptObjectType2(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) = 0;																							   // 0A
			virtual bool					   GetScriptObjectTypeNoLoad1(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) const = 0;																	   // 0B
			virtual bool					   GetScriptObjectTypeNoLoad2(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) const = 0;																				   // 0C
			virtual bool					   GetTypeIDForScriptObject(const BSFixedString& a_className, VMTypeID& a_typeID) const = 0;																								   // 0D
			virtual void					   GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_classes) const = 0;																											   // 0E
			virtual bool					   GetParentNativeType(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) = 0;																				   // 0F
			virtual bool					   TypeIsValid(const BSFixedString& a_className) = 0;																																		   // 10
			virtual bool					   ReloadType(const char* a_className) = 0;																																					   // 11
			virtual void					   TasksToJobs(BSJobs::JobList& a_jobList) = 0;																																				   // 12
			virtual void					   CalculateFullReloadList(void) const = 0;																																					   // 13
			virtual bool					   CreateObject1(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr) = 0;																				   // 14
			virtual bool					   CreateObject2(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result) = 0;																									   // 15
			virtual bool					   CreateArray1(const TypeInfo& a_typeInfo, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;																					   // 16
			virtual bool					   CreateArray2(TypeInfo::RawType a_typeID, const BSFixedString& a_className, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;												   // 17
			virtual bool					   BindNativeMethod(IFunction* a_fn) = 0;																																					   // 18
			virtual void					   SetCallableFromTasklets1(const char* a_className, const char* a_stateName, const char* a_fnName, bool a_callable) = 0;																	   // 19
			virtual void					   SetCallableFromTasklets2(const char* a_className, const char* a_fnName, bool a_callable) = 0;																							   // 1A
			virtual void					   ForEachBoundObject(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) = 0;																										   // 1B
			virtual bool					   FindBoundObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<Object>& a_result) const = 0;																				   // 1C
			virtual void					   MoveBoundObjects(VMHandle a_from, VMHandle a_to) = 0;																																	   // 1D
			virtual void					   ResetAllBoundObjects(VMHandle a_handle) = 0;																																				   // 1E
			virtual bool					   CastObject(const BSTSmartPointer<Object>& a_fromObjPtr, const BSTSmartPointer<ObjectTypeInfo>& a_toTypeInfoPtr, BSTSmartPointer<Object>& a_toObjPtr) = 0;								   // 1F
			virtual bool					   SetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_setVal) = 0;																					   // 20
			virtual bool					   GetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_getVal) = 0;																					   // 21
			virtual bool					   GetVariableValue1(const BSTSmartPointer<Object>& a_objPtr, std::uint32_t a_index, Variable& a_out) const = 0;																			   // 22
			virtual bool					   GetVariableValue2(VMHandle a_handle, const BSFixedString& a_className, std::int32_t a_variableIndex, Variable& a_out) const = 0;															   // 23
			virtual void					   SendEvent(VMHandle a_handle, const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																							   // 24
			virtual void					   SendEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																											   // 25
			virtual bool					   DispatchStaticCall(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;					   // 26
			virtual bool					   DispatchMethodCall1(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;					   // 27
			virtual bool					   DispatchMethodCall2(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;  // 28
			virtual bool					   DispatchUnboundMethodCall(void) = 0;																																						   // 29
			virtual bool					   IsWaitingOnLatent(VMStackID a_stackID) const = 0;																																		   // 2A
			virtual void					   ReturnFromLatent(VMStackID a_stackID, const Variable& a_val) = 0;																														   // 2B
			virtual ErrorLogger*			   GetErrorLogger() = 0;																																									   // 2C
			virtual IObjectHandlePolicy*	   GetObjectHandlePolicy1() = 0;																																							   // 2D
			virtual const IObjectHandlePolicy* GetObjectHandlePolicy2() const = 0;																																						   // 2E
			virtual ObjectBindPolicy*		   GetObjectBindPolicy1() = 0;																																								   // 2F
			virtual const ObjectBindPolicy*	   GetObjectBindPolicy2() const = 0;																																						   // 30
			virtual ISavePatcherInterface*	   GetSavePatcherInterface() = 0;																																							   // 31
			virtual void					   RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;																																	   // 32
			virtual void					   UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;																																   // 33
			virtual void					   RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;																																   // 34
			virtual void					   UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;																															   // 35

			bool					   CreateArray(const TypeInfo& a_typeInfo, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr);
			bool					   CreateArray(TypeInfo::RawType a_typeID, const BSFixedString& a_className, std::uint32_t a_size, BSTSmartPointer<Array>& a_arrayPtr);
			bool					   CreateObject(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr);
			bool					   CreateObject(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result);
			bool					   DispatchMethodCall(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result);
			bool					   DispatchMethodCall(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result);
			ObjectBindPolicy*		   GetObjectBindPolicy();
			const ObjectBindPolicy*	   GetObjectBindPolicy() const;
			IObjectHandlePolicy*	   GetObjectHandlePolicy();
			const IObjectHandlePolicy* GetObjectHandlePolicy() const;
			bool					   GetScriptObjectType(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr);
			bool					   GetScriptObjectType(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr);
			bool					   GetScriptObjectTypeNoLoad(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) const;
			bool					   GetScriptObjectTypeNoLoad(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) const;
			bool					   GetVariableValue(const BSTSmartPointer<Object>& a_objPtr, std::uint32_t a_index, Variable& a_out) const;
			bool					   GetVariableValue(VMHandle a_handle, const BSFixedString& a_className, std::int32_t a_variableIndex, Variable& a_out) const;

			template <class F>
			void RegisterFunction(std::string_view a_fnName, std::string_view a_className, F a_callback, bool a_callableFromTasklets = false);

			void SetCallableFromTasklets(const char* a_className, const char* a_stateName, const char* a_fnName, bool a_callable);
			void SetCallableFromTasklets(const char* a_className, const char* a_fnName, bool a_callable);
			void TraceForm(TESForm* a_form, const char* a_str, VMStackID a_stackID, Severity a_severity);
			void VTraceStack(const char* a_fmt, VMStackID a_stackID, Severity a_severity = Severity::kInfo, ...);

			// members
			std::uint32_t pad0C;  // 0C
		};
		static_assert(sizeof(IVirtualMachine) == 0x10);
	}
}
