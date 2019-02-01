#pragma once

#include "RE/BSSpinLock.h"  // BSSpinLock
#include "RE/BSTEvent.h"  // BSTEvent
#include "RE/BSTFreeList.h"  // BSTStaticFreeList
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/BSTMessageQueue.h"  // BSTCommonLLMessageQueue, BSTCommonStaticMessageQueue
#include "RE/FunctionMessage.h"  // BSScript::Internal::FunctionMessage
#include "RE/IVirtualMachine.h"  // BSScript::IVirtualMachine
#include "RE/IVMDebugInterface.h"  // BSScript::IVMDebugInterface
#include "RE/IVMObjectBindInterface.h"  // BSScript::IVMObjectBindInterface
#include "RE/IVMSaveLoadInterface.h"  // BSScript::IVMSaveLoadInterface
#include "RE/LinkerProcessor.h"  // BSScript::LinkerProcessor
#include "RE/StatsEvent.h"  // BSScript::StatsEvent
#include "RE/SuspendedStack.h"  // BSScript::Internal::SuspendedStack


namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class ISavePatcherInterface;
		class ObjectBindPolicy;
		class SimpleAllocMemoryPagePolicy;
		struct IObjectHandlePolicy;


		namespace Internal
		{
			class VirtualMachine :
				public IVirtualMachine,			// 0000
				public IVMObjectBindInterface,	// 0010
				public IVMSaveLoadInterface,	// 0018
				public IVMDebugInterface		// 0020
			{
			public:
				virtual ~VirtualMachine();

				// override (IVirtualMachine)
				virtual void							TraceStack(const char* a_str, UInt32 a_stackID, Severity a_severity = Severity::kInfo) override;																											// 02
				virtual void							OnUpdate(float a_arg1) override;																																											// 04
				virtual void							OnUpdateGameTime(float a_arg1) override;																																									// 05
				virtual bool							OnChangeVMState() override;																																													// 07
				virtual void							RegisterForm(UInt32 a_typeID, const char* a_papyrusClassName) override;																																		// 08
				virtual bool							GetScriptClassByName(const BSFixedString& a_className, BSTSmartPointer<BSScriptClass>& a_outClassPtr) override;																								// 09
				virtual bool							GetScriptClassByTypeID(UInt32 a_typeID, BSTSmartPointer<BSScriptClass>& a_outClass) override;																												// 0A
				virtual bool							RegisterScriptClass(const BSFixedString& a_className, BSTSmartPointer<BSScriptClass>& a_classPtr) override;																									// 0B
				virtual bool							GetFormTypeID(const BSFixedString& a_className, UInt32& a_typeID) override;																																	// 0D
				virtual bool							CreateScriptObjectWithProperty(const BSFixedString& a_className, void* a_property, BSTSmartPointer<BSScriptObject>& a_objPtr) override;																		// 14
				virtual bool							CreateScriptObject(const BSFixedString& a_className, BSTSmartPointer<BSScriptObject>& a_result) override;																									// 15
				virtual bool							CreateScriptArray(const BSScriptType& a_typeID, UInt32 a_size, BSTSmartPointer<BSScriptArray>& a_arrayPtr) override;																						// 16
				virtual bool							CreateScriptArray2(VMTypeID a_typeID, const BSFixedString& a_className, UInt32 a_size, BSTSmartPointer<BSScriptArray>& a_arrayPtr) override;																// 17
				virtual void							RegisterFunction(IFunction* a_fn) override;																																									// 18
				virtual void							SetFunctionFlagsEx(const char* a_className, UInt32 a_arg2, const char* a_fnName, FunctionFlag a_flags) override;																							// 19
				virtual void							SetFunctionFlags(const char* a_className, const char* a_fnName, FunctionFlag a_flags) override;																												// 1A - { SetFunctionFlagsEx(a_className, 0, a_fnName, a_flags); }
				virtual void							VisitScripts(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) override;																															// 1B
				virtual bool							ResolveScriptObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<BSScriptObject>& a_result) override;																						// 1C
				virtual bool							CastScriptObject(const BSTSmartPointer<BSScriptObject>& a_fromObjPtr, const BSTSmartPointer<BSScriptClass>& a_toClassPtr, BSTSmartPointer<BSScriptObject>& a_toObjPtr) override;							// 1F
				virtual bool							SetObjectProperty(BSTSmartPointer<BSScriptObject>& a_obj, const char* a_propertyName, BSScriptVariable& a_setVal) override;																					// 20
				virtual bool							GetObjectProperty(BSTSmartPointer<BSScriptObject>& a_obj, const char* a_propertyName, BSScriptVariable& a_getVal) override;																					// 21
				virtual bool							ExtractValue(const BSTSmartPointer<BSScriptObject>& a_objPtr, UInt32 a_index, BSScriptVariable& a_out) override;																							// 22
				virtual bool							ExtractValueFromHandle(VMHandle a_handle, const BSFixedString& a_className, SInt32 a_variableIndex, BSScriptVariable& a_out) override;																		// 23
				virtual void							QueueEvent(VMHandle a_handle, const BSFixedString & a_eventName, IFunctionArguments* a_args) override;																										// 24
				virtual bool							QueueEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) override;																														// 25
				virtual bool							CallStaticFunction(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;									// 26
				virtual bool							CallMemberFunction(BSTSmartPointer<BSScriptObject>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;							// 27
				virtual bool							CallMemberFunctionFromHandle(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;	// 28
				virtual bool							IsWaitingStack(UInt32 a_stackID) override;																																									// 2A
				virtual void							SetLatentReturn(UInt32 a_stackID, const BSScriptVariable& a_val) override;																																	// 2B
				virtual ErrorLogger*					GetLogger() override;																																														// 2C
				virtual SkyrimScript::HandlePolicy*		GetHandlePolicySK() override;																																												// 2D
				virtual IObjectHandlePolicy*			GetHandlePolicyBS() override;																																												// 2E
				virtual SkyrimScript::ObjectBindPolicy*	GetObjectBindPolicySK() override;																																											// 2F
				virtual ObjectBindPolicy*				GetObjectBindPolicyBS() override;																																											// 30
				virtual ISavePatcherInterface*			GetSavePatcher() override;																																													// 31
				virtual void							AddLogEventSink(BSTEventSink<LogEvent>* a_sink) override;																																					// 32
				virtual void							RemoveLogEventSink(BSTEventSink<LogEvent>* a_sink) override;																																				// 33
				virtual void							AddStatsEventSink(BSTEventSink<StatsEvent>* a_sink) override;																																				// 34
				virtual void							RemoveStatsEventSink(BSTEventSink<StatsEvent>* a_sink) override;																																			// 35

				// override (IVMObjectBindInterface)
				virtual VMHandle						GetHandle(const BSTSmartPointer<BSScriptObject>& a_objPtr) override;																																		// 01
				virtual void							BindObject(BSTSmartPointer<BSScriptObject>& a_objPtr, VMHandle a_handle, bool a_counditional) override;																										// 03
				virtual void							RegisterObject(BSTSmartPointer<BSScriptObject>& a_objPtr, VMHandle a_handle, bool a_counditional) override;																									// 04
				virtual bool							CreateObject(const BSFixedString& a_className, UInt32 a_numProperties, BSTSmartPointer<BSScriptObject>& a_objPtr) override;																					// 09
				virtual bool							SetProperty(BSTSmartPointer<BSScriptObject>& a_objPtr, void* a_property, bool a_arg3) override;																												// 0A


				// members
				BSTEventSource<StatsEvent>							statsEventSource;	// 0028
				ErrorLogger*										logger;				// 0080
				SimpleAllocMemoryPagePolicy*						memoryPagePolicy;	// 0088
				IObjectHandlePolicy*								objectHandlePolicy;	// 0090
				ObjectBindPolicy*									objectBindPolicy;	// 0098
				UInt64												unk00A0;			// 00A0
				UInt64												unk00A8;			// 00A8
				UInt64												unk00B0;			// 00B0
				ISavePatcherInterface*								savePatcher;		// 00B8
				UInt64												unk00C0;			// 00C0
				LinkerProcessor										linkerProcessor;	// 00C8
				BSTHashMap<UnkKey, UnkValue>						unk0158;			// 0158
				BSTHashMap<UnkKey, UnkValue>						unk0188;			// 0188
				BSTHashMap<UnkKey, UnkValue>						unk01B8;			// 01B8
				UInt64												unk01E8;			// 01E8
				UInt64												unk01F0;			// 01F0
				UInt64												unk01F8;			// 01F8
				UInt64												unk0200;			// 0200
				BSTStaticFreeList<FunctionMessage, 1024>			unk0208;			// 0208
				BSTCommonLLMessageQueue<FunctionMessage>			unk8220;			// 8220
				UInt64												unk8248;			// 8248
				UInt64												unk8250;			// 8250
				UInt64												unk8258;			// 8258
				UInt64												unk8260;			// 8260
				UInt64												unk8268;			// 8268
				UInt64												unk8270;			// 8270
				UInt64												unk8278;			// 8278
				BSTCommonStaticMessageQueue<SuspendedStack, 128>	unk8280;			// 8280
				BSTCommonStaticMessageQueue<SuspendedStack, 128>	unk8AA0;			// 8AA0
				UInt64												unk92C0;			// 92C0
				UInt64												unk92C8;			// 92C8
				UInt64												unk92D0;			// 92D0
				UInt64												unk92D8;			// 92D8
				UInt64												unk92E0;			// 92E0
				UInt64												unk92E8;			// 92E8
				UInt64												unk92F0;			// 92F0
				void*												unk92F8;			// 92F8
				void*												unk9300;			// 9300
				void*												unk9308;			// 9308
				void*												unk9310;			// 9310
				BSSpinLock											stackLock;			// 9318
				BSTHashMap<UInt32, UnkValue>						allStacks;			// 9320
				BSTHashMap<UInt32, UnkValue>						waitingStacks;		// 9350
				UInt64												unk9380;			// 9380
				UInt64												unk9388;			// 9388
				UInt64												unk9390;			// 9390
				UInt64												unk9398;			// 9398
				UInt64												unk93A0;			// 93A0
				BSTHashMap<UnkKey, UnkValue>						unk93A8;			// 93A8
				UInt64												unk93D8;			// 93D8
				UInt64												unk93E0;			// 93E0
				UInt64												unk93E8;			// 93E8
				UInt64												unk93F0;			// 93F0
				UInt64												unk93F8;			// 93F8
				UInt64												unk9400;			// 9400
				UInt64												unk9408;			// 9408
				UInt64												unk9410;			// 9410
				UInt64												unk9418;			// 9418
				UInt64												unk9420;			// 9420
				UInt64												unk9428;			// 9428
				UInt64												unk9430;			// 9430
				UInt64												unk9438;			// 9438
				UInt64												unk9440;			// 9440
				BSTHashMap<UnkKey, UnkValue>						unk9448;			// 9448
				BSTHashMap<UnkKey, UnkValue>						unk9478;			// 9478
				UInt64												unk94A8;			// 94A8
				UInt64												unk94B0;			// 94B0
				UInt64												unk94B8;			// 94B8
				UInt64												unk94C0;			// 94C0
				UInt64												unk94C8;			// 94C8
				UInt64												unk94D0;			// 94D0
				UInt64												unk94D8;			// 94D8
				UInt64												unk94E0;			// 94E0
				UInt64												unk94E8;			// 94E8
				UInt64												unk94F0;			// 94F0
				UInt64												unk94F8;			// 94F8
				UInt64												unk9500;			// 9500
				UInt64												unk9508;			// 9508
				UInt64												unk9518;			// 9510
			};
			STATIC_ASSERT(sizeof(VirtualMachine) == 0x9518);
		}
	}
}
