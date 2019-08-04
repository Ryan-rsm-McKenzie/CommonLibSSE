#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__IVirtualMachine

#include "RE/BSScript/LogEvent.h"  // BSScript::LogEvent::Severity
#include "RE/BSIntrusiveRefCounted.h"  // BSIntrusiveRefCounted
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/BSTEvent.h"  // BSTEventSink


namespace RE
{
	class BSFixedString;


	namespace SkyrimScript
	{
		class HandlePolicy;
		class ObjectBindPolicy;
	}


	namespace BSScript
	{
		class Array;
		class Class;
		class ErrorLogger;
		class IForEachScriptObjectFunctor;
		class IFunction;
		class IFunctionArguments;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class Object;
		class ObjectBindPolicy;
		class Type;
		class Variable;
		struct IObjectHandlePolicy;
		struct LogEvent;
		struct StatsEvent;


		class IVirtualMachine : public BSIntrusiveRefCounted
		{
		public:
			inline static const void* RTTI = RTTI_BSScript__IVirtualMachine;


			using Severity = BSScript::LogEvent::Severity;
			using StackID = UInt32;


			enum class FunctionFlag : UInt32
			{
				kNone = 0,
				kNoWait = 1 << 0
			};


			virtual ~IVirtualMachine();	// 00

			// add
			virtual void							Unk_01(void) = 0;																																													// 01
			virtual void							TraceStack(const char* a_str, StackID a_stackID, Severity a_severity = Severity::kInfo) = 0;																										// 02
			virtual void							Unk_03(void) = 0;																																													// 03
			virtual void							OnUpdate(float a_arg1) = 0;																																											// 04
			virtual void							OnUpdateGameTime(float a_arg1) = 0;																																									// 05
			virtual void							Unk_06(void) = 0;																																													// 06
			virtual bool							OnChangeVMState() = 0;																																												// 07
			virtual void							RegisterForm(FormType32 a_formType, const char* a_papyrusClassName) = 0;																															// 08
			virtual bool							GetScriptClassByName(const BSFixedString& a_className, BSTSmartPointer<Class>& a_outClassPtr) = 0;																									// 09
			virtual bool							GetScriptClassByTypeID(FormType32 a_formType, BSTSmartPointer<Class>& a_outClassPtr) = 0;																											// 0A
			virtual bool							RegisterScriptClass(const BSFixedString& a_className, BSTSmartPointer<Class>& a_classPtr) = 0;																										// 0B
			virtual void							Unk_0C(void) = 0;																																													// 0C
			virtual bool							GetFormTypeID(const BSFixedString& a_className, FormType32& a_formType) = 0;																														// 0D
			virtual void							Unk_0E(void) = 0;																																													// 0E
			virtual void							Unk_0F(void) = 0;																																													// 0F
			virtual void							Unk_10(void) = 0;																																													// 10
			virtual void							Unk_11(void) = 0;																																													// 11
			virtual void							Unk_12(void) = 0;																																													// 12
			virtual void							Unk_13(void) = 0;																																													// 13
			virtual bool							CreateScriptObjectWithProperty(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr) = 0;																			// 14
			virtual bool							CreateScriptObject(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result) = 0;																										// 15
			virtual bool							CreateScriptArray(const Type& a_typeID, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;																										// 16
			virtual bool							CreateScriptArray2(VMTypeID a_typeID, const BSFixedString& a_className, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) = 0;																		// 17
			virtual void							RegisterFunction(IFunction* a_fn) = 0;																																								// 18
			virtual void							SetFunctionFlagsEx(const char* a_className, UInt32 a_arg2, const char* a_fnName, FunctionFlag a_flags) = 0;																							// 19
			virtual void							SetFunctionFlags(const char* a_className, const char* a_fnName, FunctionFlag a_flags) = 0;																											// 1A
			virtual void							VisitScripts(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) = 0;																														// 1B
			virtual bool							ResolveScriptObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<Object>& a_result) = 0;																								// 1C
			virtual void							Unk_1D(void) = 0;																																													// 1D
			virtual void							Unk_1E(void) = 0;																																													// 1E
			virtual bool							CastScriptObject(const BSTSmartPointer<Object>& a_fromObjPtr, const BSTSmartPointer<Class>& a_toClassPtr, BSTSmartPointer<Object>& a_toObjPtr) = 0;													// 1F
			virtual bool							SetObjectProperty(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_setVal) = 0;																								// 20
			virtual bool							GetObjectProperty(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_getVal) = 0;																								// 21
			virtual bool							ExtractValue(const BSTSmartPointer<Object>& a_objPtr, UInt32 a_index, Variable& a_out) = 0;																											// 22
			virtual bool							ExtractValueFromHandle(VMHandle a_handle, const BSFixedString& a_className, SInt32 a_variableIndex, Variable& a_out) = 0;																			// 23
			virtual void							QueueEvent(VMHandle a_handle, const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																									// 24
			virtual bool							QueueEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) = 0;																													// 25
			virtual bool							CallStaticFunction(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;								// 26
			virtual bool							CallMemberFunction(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;								// 27
			virtual bool							CallMemberFunctionFromHandle(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) = 0;	// 28
			virtual void							Unk_29(void) = 0;																																													// 29
			virtual bool							IsWaitingStack(StackID a_stackID) = 0;																																								// 2A
			virtual void							SetLatentReturn(StackID a_stackID, const Variable& a_val) = 0;																																		// 2B
			virtual ErrorLogger*					GetLogger() = 0;																																													// 2C
			virtual IObjectHandlePolicy*			GetHandlePolicy() = 0;																																												// 2D
			virtual const IObjectHandlePolicy*		GetHandlePolicy() const = 0;																																										// 2E
			virtual ObjectBindPolicy*				GetObjectBindPolicy() = 0;																																											// 2F
			virtual const ObjectBindPolicy*			GetObjectBindPolicy() const = 0;																																									// 30
			virtual ISavePatcherInterface*			GetSavePatcher() = 0;																																												// 31
			virtual void							AddLogEventSink(BSTEventSink<LogEvent>* a_sink) = 0;																																				// 32
			virtual void							RemoveLogEventSink(BSTEventSink<LogEvent>* a_sink) = 0;																																				// 33
			virtual void							AddStatsEventSink(BSTEventSink<StatsEvent>* a_sink) = 0;																																			// 34
			virtual void							RemoveStatsEventSink(BSTEventSink<StatsEvent>* a_sink) = 0;																																			// 35


			// members
			UInt32 unk0C;	// 0C
		};
		STATIC_ASSERT(sizeof(IVirtualMachine) == 0x10);
	}
}
