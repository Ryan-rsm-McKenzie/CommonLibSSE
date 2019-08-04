#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSScript__Internal__VirtualMachine

#include "RE/BSScript/Internal/FunctionMessage.h"  // BSScript::Internal::FunctionMessage
#include "RE/BSScript/Internal/SuspendedStack.h"  // BSScript::Internal::SuspendedStack
#include "RE/BSScript/IVirtualMachine.h"  // BSScript::IVirtualMachine
#include "RE/BSScript/IVMDebugInterface.h"  // BSScript::IVMDebugInterface
#include "RE/BSScript/IVMObjectBindInterface.h"  // BSScript::IVMObjectBindInterface
#include "RE/BSScript/IVMSaveLoadInterface.h"  // BSScript::IVMSaveLoadInterface
#include "RE/BSScript/LinkerProcessor.h"  // BSScript::LinkerProcessor
#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEvent
#include "RE/BSTFreeList.h"  // BSTStaticFreeList
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTMessageQueue.h"  // BSTCommonLLMessageQueue, BSTCommonStaticMessageQueue
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IFreezeQuery;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class IStackCallbackSaveInterface;
		class ObjectBindPolicy;
		class SimpleAllocMemoryPagePolicy;
		class Stack;
		struct IObjectHandlePolicy;
		struct StatsEvent;


		namespace Internal
		{
			class CodeTasklet;


			class VirtualMachine :
				public IVirtualMachine,				// 0000
				public IVMObjectBindInterface,		// 0010
				public IVMSaveLoadInterface,		// 0018
				public IVMDebugInterface,			// 0020
				public BSTEventSource<StatsEvent>	// 0028
			{
			public:
				inline static const void* RTTI = RTTI_BSScript__Internal__VirtualMachine;


				virtual ~VirtualMachine();

				// override (IVirtualMachine)
				virtual void							Unk_01(void) override;																																														// 01
				virtual void							TraceStack(const char* a_str, StackID a_stackID, Severity a_severity = Severity::kInfo) override;																											// 02
				virtual void							Unk_03(void) override;																																														// 03
				virtual void							OnUpdate(float a_arg1) override;																																											// 04
				virtual void							OnUpdateGameTime(float a_arg1) override;																																									// 05
				virtual void							Unk_06(void) override;																																														// 06
				virtual bool							OnChangeVMState() override;																																													// 07
				virtual void							RegisterForm(FormType32 a_formType, const char* a_papyrusClassName) override;																																// 08
				virtual bool							GetScriptClassByName(const BSFixedString& a_className, BSTSmartPointer<Class>& a_outClassPtr) override;																										// 09
				virtual bool							GetScriptClassByTypeID(FormType32 a_formType, BSTSmartPointer<Class>& a_outClassPtr) override;																												// 0A
				virtual bool							RegisterScriptClass(const BSFixedString& a_className, BSTSmartPointer<Class>& a_classPtr) override;																											// 0B
				virtual void							Unk_0C(void) override;																																														// 0C
				virtual bool							GetFormTypeID(const BSFixedString& a_className, FormType32& a_formType) override;																															// 0D
				virtual void							Unk_0E(void) override;																																														// 0E
				virtual void							Unk_0F(void) override;																																														// 0F
				virtual void							Unk_10(void) override;																																														// 10
				virtual void							Unk_11(void) override;																																														// 11
				virtual void							Unk_12(void) override;																																														// 12
				virtual void							Unk_13(void) override;																																														// 13
				virtual bool							CreateScriptObjectWithProperty(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr) override;																				// 14
				virtual bool							CreateScriptObject(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result) override;																											// 15
				virtual bool							CreateScriptArray(const Type& a_typeID, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) override;																										// 16
				virtual bool							CreateScriptArray2(VMTypeID a_typeID, const BSFixedString& a_className, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) override;																		// 17
				virtual void							RegisterFunction(IFunction* a_fn) override;																																									// 18
				virtual void							SetFunctionFlagsEx(const char* a_className, UInt32 a_arg2, const char* a_fnName, FunctionFlag a_flags) override;																							// 19
				virtual void							SetFunctionFlags(const char* a_className, const char* a_fnName, FunctionFlag a_flags) override;																												// 1A - { SetFunctionFlagsEx(a_className, 0, a_fnName, a_flags); }
				virtual void							VisitScripts(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) override;																															// 1B
				virtual bool							ResolveScriptObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<Object>& a_result) override;																								// 1C
				virtual void							Unk_1D(void) override;																																														// 1D
				virtual void							Unk_1E(void) override;																																														// 1E
				virtual bool							CastScriptObject(const BSTSmartPointer<Object>& a_fromObjPtr, const BSTSmartPointer<Class>& a_toClassPtr, BSTSmartPointer<Object>& a_toObjPtr) override;													// 1F
				virtual bool							SetObjectProperty(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_setVal) override;																									// 20
				virtual bool							GetObjectProperty(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_getVal) override;																									// 21
				virtual bool							ExtractValue(const BSTSmartPointer<Object>& a_objPtr, UInt32 a_index, Variable& a_out) override;																											// 22
				virtual bool							ExtractValueFromHandle(VMHandle a_handle, const BSFixedString& a_className, SInt32 a_variableIndex, Variable& a_out) override;																				// 23
				virtual void							QueueEvent(VMHandle a_handle, const BSFixedString& a_eventName, IFunctionArguments* a_args) override;																										// 24
				virtual bool							QueueEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) override;																														// 25
				virtual bool							CallStaticFunction(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;									// 26
				virtual bool							CallMemberFunction(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;									// 27
				virtual bool							CallMemberFunctionFromHandle(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;	// 28
				virtual void							Unk_29(void) override;																																														// 29
				virtual bool							IsWaitingStack(StackID a_stackID) override;																																									// 2A
				virtual void							SetLatentReturn(StackID a_stackID, const Variable& a_val) override;																																			// 2B
				virtual ErrorLogger*					GetLogger() override;																																														// 2C - { return logger; }
				virtual IObjectHandlePolicy*			GetHandlePolicy() override;																																													// 2D - { return objectHandlePolicy; }
				virtual const IObjectHandlePolicy*		GetHandlePolicy() const override;																																											// 2E - { return objectHandlePolicy; }
				virtual ObjectBindPolicy*				GetObjectBindPolicy() override;																																												// 2F - { return objectBindPolicy; }
				virtual const ObjectBindPolicy*			GetObjectBindPolicy() const override;																																										// 30 - { return objectBindPolicy; }
				virtual ISavePatcherInterface*			GetSavePatcher() override;																																													// 31 - { return savePatcher; }
				virtual void							AddLogEventSink(BSTEventSink<LogEvent>* a_sink) override;																																					// 32
				virtual void							RemoveLogEventSink(BSTEventSink<LogEvent>* a_sink) override;																																				// 33
				virtual void							AddStatsEventSink(BSTEventSink<StatsEvent>* a_sink) override;																																				// 34
				virtual void							RemoveStatsEventSink(BSTEventSink<StatsEvent>* a_sink) override;																																			// 35

				// override (IVMObjectBindInterface)
				virtual VMHandle						GetHandle(const BSTSmartPointer<Object>& a_objPtr) override;																																				// 01
				virtual void							BindObject(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) override;																												// 03
				virtual void							RegisterObject(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) override;																											// 04
				virtual bool							CreateObject(const BSFixedString& a_className, UInt32 a_numProperties, BSTSmartPointer<Object>& a_objPtr) override;																							// 09
				virtual bool							SetProperty(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) override;																														// 0A

				static VirtualMachine* GetSingleton();

				bool					AllocateArray(const VMTypeID& a_typeID, std::size_t a_size, BSTSmartPointer<Array>& a_array);
				template <class F> void	RegisterFunction(const char* a_fnName, const char* a_className, F* a_callback, FunctionFlag a_flags = FunctionFlag::kNone);


				// members
				ErrorLogger*										logger;						// 0080
				SimpleAllocMemoryPagePolicy*						memoryPagePolicy;			// 0088
				IObjectHandlePolicy*								objectHandlePolicy;			// 0090
				ObjectBindPolicy*									objectBindPolicy;			// 0098
				IFreezeQuery*										freezeQuery;				// 00A0
				IStackCallbackSaveInterface*						stackCallbackSaveInterface;	// 00A8
				UInt64												unk00B0;					// 00B0
				ISavePatcherInterface*								savePatcher;				// 00B8
				mutable BSUniqueLock								classLock;					// 00C0
				LinkerProcessor										linkerProcessor;			// 00C8
				BSTHashMap<BSFixedString, BSTSmartPointer<Class>>	linkedClassMap;				// 0158
				BSTHashMap<FormType32, BSFixedString>				typeToClassNameMap;			// 0188
				BSTHashMap<BSFixedString, FormType32>				classNameToTypeMap;			// 01B8
				BSTArray<void*>										unk01E8;					// 01E8
				mutable BSUniqueLock								unk0200;					// 0200
				BSTStaticFreeList<FunctionMessage, 1024>			unk0208;					// 0208
				BSTCommonLLMessageQueue<FunctionMessage>			unk8220;					// 8220
				BSTArray<void*>										unk8248;					// 8248
				BSTArray<CodeTasklet*>								codeTasklets;				// 8260
				UInt32												unk8278;					// 8278
				UInt32												unk827C;					// 827C
				BSTCommonStaticMessageQueue<SuspendedStack, 128>	unk8280;					// 8280
				BSTCommonStaticMessageQueue<SuspendedStack, 128>	unk8AA0;					// 8AA0
				BSTArray<void*>										unk92C0;					// 92C0
				BSTArray<void*>										unk92D8;					// 92D8
				UInt64												unk92F0;					// 92F0
				BSTCommonStaticMessageQueue<SuspendedStack, 128>*	unk92F8;					// 92F8 - ref to unk8AA0
				BSTArray<void*>*									unk9300;					// 9300 - ref to unk92D8
				BSTCommonStaticMessageQueue<SuspendedStack, 128>*	unk9308;					// 9308 - ref to unk8280
				BSTArray<void*>*									unk9310;					// 9310 - ref to unk92C0
				mutable BSUniqueLock								stackLock;					// 9318
				BSTHashMap<StackID, BSTSmartPointer<Stack>>			allStacks;					// 9320
				BSTHashMap<UInt32, UnkValue>						waitingStacks;				// 9350
				StackID												nextFreeStackID;			// 9380
				UInt32												unk9384;					// 9384
				UInt64												unk9388;					// 9388
				UInt64												unk9390;					// 9390
				UInt64												unk9398;					// 9398
				UInt64												unk93A0;					// 93A0
				BSTHashMap<UnkKey, UnkValue>						unk93A8;					// 93A8
				UInt64												unk93D8;					// 93D8
				BSTArray<void*>										unk93E0;					// 93E0
				mutable BSUniqueLock								unk93F8;					// 93F8
				UInt64												unk9400;					// 9400
				BSTArray<void*>										unk9408;					// 9408
				UInt64												unk9420;					// 9420
				BSTArray<void*>										unk9428;					// 9428
				UInt64												unk9440;					// 9440
				BSTHashMap<UnkKey, UnkValue>						unk9448;					// 9448
				BSTHashMap<UnkKey, UnkValue>						unk9478;					// 9478
				UInt64												unk94A8;					// 94A8
				BSTArray<void*>										unk94B0;					// 94B0
				UInt64												unk94C8;					// 94C8
				UInt64												unk94D0;					// 94D0
				UInt64												unk94D8;					// 94D8
				UInt64												unk94E0;					// 94E0
				UInt64												unk94E8;					// 94E8
				UInt64												unk94F0;					// 94F0
				UInt64												unk94F8;					// 94F8
				UInt64												unk9500;					// 9500
				UInt64												unk9508;					// 9508
				UInt64												unk9518;					// 9510
			};
			STATIC_ASSERT(sizeof(VirtualMachine) == 0x9518);
		}
	}
}
