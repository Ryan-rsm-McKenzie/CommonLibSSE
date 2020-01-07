#pragma once

#include "RE/BSScript/ErrorLogger.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTEvent.h"


namespace RE
{
	class BSFixedString;


	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IForEachScriptObjectFunctor;
		class IFunction;
		class IFunctionArguments;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class Object;
		class ObjectBindPolicy;
		class ObjectTypeInfo;
		class TypeInfo;
		class Variable;
		struct IObjectHandlePolicy;
		struct LogEvent;
		struct StatsEvent;


		class IVirtualMachine : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IVirtualMachine;


			using Severity = BSScript::ErrorLogger::Severity;


			virtual ~IVirtualMachine();																																																		// 00

			// add
			virtual void						Unk_01(void) = 0;																																											// 01
			virtual void						TraceStack(const char* a_str, VMStackID a_stackID, Severity a_severity = Severity::kInfo) = 0;																								// 02
			virtual void						Unk_03(void) = 0;																																											// 03
			virtual void						OnUpdate(float a_arg1) = 0;																																									// 04
			virtual void						OnUpdateGameTime(float a_arg1) = 0;																																							// 05
			virtual void						Unk_06(void) = 0;																																											// 06
			virtual bool						OnChangeVMState() = 0;																																										// 07
			virtual void						RegisterForm(VMTypeID a_typeID, const char* a_papyrusClassName) = 0;																														// 08
			virtual bool						GetScriptClassByName(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) = 0;																				// 09
			virtual bool						GetScriptClassByTypeID(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) = 0;																							// 0A
			virtual bool						RegisterScriptClass(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) = 0;																					// 0B
			virtual void						Unk_0C(void) = 0;																																											// 0C
			virtual bool						GetFormTypeID(const BSFixedString& a_className, VMTypeID& a_typeID) = 0;																													// 0D
			virtual void						Unk_0E(void) = 0;																																											// 0E
			virtual void						Unk_0F(void) = 0;																																											// 0F
			virtual void						Unk_10(void) = 0;																																											// 10
			virtual void						Unk_11(void) = 0;																																											// 11
			virtual void						Unk_12(void) = 0;																																											// 12
			virtual void						Unk_13(void) = 0;																																											// 13
			virtual bool						CreateObject(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr) = 0;																					// 14
			virtual bool						CreateObject(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result) = 0;																										// 15
			virtual bool						CreateArray(const TypeInfo& a_typeInfo, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;																								// 16
			virtual bool						CreateArray(TypeInfo::RawType a_typeID, const BSFixedString& a_className, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;															// 17
			virtual bool						BindNativeMethod(IFunction* a_fn) = 0;																																						// 18
			virtual void						SetCallableFromTasklets(const char* a_className, const char* a_stateName, const char* a_fnName, bool a_callable) = 0;																		// 19
			virtual void						SetCallableFromTasklets(const char* a_className, const char* a_fnName, bool a_callable) = 0;																								// 1A
			virtual void						ForEachBoundObject(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) = 0;																											// 1B
			virtual bool						FindBoundObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<Object>& a_result) = 0;																							// 1C
			virtual void						MoveBoundObjects(VMHandle a_from, VMHandle a_to) = 0;																																		// 1D
			virtual void						ResetAllBoundObjects(VMHandle a_handle) = 0;																																				// 1E
			virtual bool						CastObject(const BSTSmartPointer<Object>& a_fromObjPtr, const BSTSmartPointer<ObjectTypeInfo>& a_toTypeInfoPtr, BSTSmartPointer<Object>& a_toObjPtr) = 0;									// 1F
			virtual bool						SetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_setVal) = 0;																						// 20
			virtual bool						GetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_getVal) = 0;																						// 21
			virtual bool						GetVariableValue(const BSTSmartPointer<Object>& a_objPtr, UInt32 a_index, Variable& a_out) = 0;																								// 22
			virtual bool						GetVariableValue(VMHandle a_handle, const BSFixedString& a_className, SInt32 a_variableIndex, Variable& a_out) = 0;																			// 23
			virtual void						SendEvent(VMHandle a_handle, const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																								// 24
			virtual void						SendEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																												// 25
			virtual bool						DispatchStaticCall(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;						// 26
			virtual bool						DispatchMethodCall(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;						// 27
			virtual bool						DispatchMethodCall(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;	// 28
			virtual void						Unk_29(void) = 0;																																											// 29
			virtual bool						IsWaitingOnLatent(VMStackID a_stackID) = 0;																																					// 2A
			virtual void						ReturnFromLatent(VMStackID a_stackID, const Variable& a_val) = 0;																															// 2B
			virtual ErrorLogger*				GetErrorLogger() = 0;																																										// 2C
			virtual IObjectHandlePolicy*		GetObjectHandlePolicy() = 0;																																								// 2D
			virtual const IObjectHandlePolicy*	GetObjectHandlePolicy() const = 0;																																							// 2E
			virtual ObjectBindPolicy*			GetObjectBindPolicy() = 0;																																									// 2F
			virtual const ObjectBindPolicy*		GetObjectBindPolicy() const = 0;																																							// 30
			virtual ISavePatcherInterface*		GetSavePatcherInterface() = 0;																																								// 31
			virtual void						RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;																																	// 32
			virtual void						UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;																																	// 33
			virtual void						RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;																																// 34
			virtual void						UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;																																// 35


			// members
			UInt32 pad0C;	// 0C
		};
		STATIC_ASSERT(sizeof(IVirtualMachine) == 0x10);
	}
}
