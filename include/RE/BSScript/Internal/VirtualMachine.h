#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSScript/IVMDebugInterface.h"
#include "RE/BSScript/IVMObjectBindInterface.h"
#include "RE/BSScript/IVMSaveLoadInterface.h"
#include "RE/BSScript/IVirtualMachine.h"
#include "RE/BSScript/Internal/AttachedScript.h"
#include "RE/BSScript/Internal/FunctionMessage.h"
#include "RE/BSScript/Internal/SuspendedStack.h"
#include "RE/BSScript/LinkerProcessor.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTFreeList.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTMessageQueue.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IFreezeQuery;
		class IProfilePolicy;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class IStackCallbackSaveInterface;
		class ObjectBindPolicy;
		class Stack;
		struct IMemoryPagePolicy;
		struct IObjectHandlePolicy;
		struct StatsEvent;


		namespace Internal
		{
			class CodeTasklet;


			class VirtualMachine :
				public IVirtualMachine,			   // 0000
				public IVMObjectBindInterface,	   // 0010
				public IVMSaveLoadInterface,	   // 0018
				public IVMDebugInterface,		   // 0020
				public BSTEventSource<StatsEvent>  // 0028
			{
			public:
				inline static constexpr auto RTTI = RTTI_BSScript__Internal__VirtualMachine;


				struct QueuedUnbindRefs
				{
				public:
					// members
					BSTSmartPointer<Object> obj;	   // 00
					UInt32					refCount;  // 08
					UInt32					pad0C;	   // 0C
				};
				STATIC_ASSERT(sizeof(QueuedUnbindRefs) == 0x10);


				virtual ~VirtualMachine();	// 00

				// override (IVirtualMachine)
				virtual void					   SetLinkedCallback(ITypeLinkedCallback* a_callback) override;																																		// 01
				virtual void					   TraceStack(const char* a_str, VMStackID a_stackID, Severity a_severity = Severity::kInfo) override;																								// 02
				virtual void					   Unk_03(void) override;																																											// 03
				virtual void					   Update(float a_budget) override;																																									// 04
				virtual void					   UpdateTasklets(float a_budget) override;																																							// 05
				virtual void					   SetOverstressed(bool a_set) override;																																							// 06 - { overstressed = a_set; }
				virtual bool					   IsCompletelyFrozen() const override;																																								// 07
				virtual bool					   RegisterObjectType(VMTypeID a_typeID, const char* a_className) override;																															// 08
				virtual bool					   GetScriptObjectType1(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) override;																				// 09
				virtual bool					   GetScriptObjectType2(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) override;																								// 0A
				virtual bool					   GetScriptObjectTypeNoLoad1(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) const override;																		// 0B
				virtual bool					   GetScriptObjectTypeNoLoad2(VMTypeID a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_outTypeInfoPtr) const override;																					// 0C
				virtual bool					   GetTypeIDForScriptObject(const BSFixedString& a_className, VMTypeID& a_typeID) const override;																									// 0D
				virtual void					   GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_results) const override;																												// 0E
				virtual bool					   GetParentNativeType(const BSFixedString& a_className, BSTSmartPointer<ObjectTypeInfo>& a_typeInfoPtr) override;																					// 0F
				virtual bool					   TypeIsValid(const BSFixedString& a_className) override;																																			// 10
				virtual bool					   ReloadType(const char* a_className) override;																																					// 11
				virtual void					   TasksToJobs(BSJobs::JobList& a_jobList) override;																																				// 12
				virtual void					   CalculateFullReloadList(void) const override;																																					// 13
				virtual bool					   CreateObject1(const BSFixedString& a_className, void* a_property, BSTSmartPointer<Object>& a_objPtr) override;																					// 14
				virtual bool					   CreateObject2(const BSFixedString& a_className, BSTSmartPointer<Object>& a_result) override;																										// 15
				virtual bool					   CreateArray1(const TypeInfo& a_typeInfo, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) override;																							// 16
				virtual bool					   CreateArray2(TypeInfo::RawType a_typeID, const BSFixedString& a_className, UInt32 a_size, BSTSmartPointer<Array>& a_arrayPtr) override;															// 17
				virtual bool					   BindNativeMethod(IFunction* a_fn) override;																																						// 18
				virtual void					   SetCallableFromTasklets1(const char* a_className, const char* a_stateName, const char* a_fnName, bool a_callable) override;																		// 19
				virtual void					   SetCallableFromTasklets2(const char* a_className, const char* a_fnName, bool a_callable) override;																								// 1A - { SetCallableFromTasklets1(a_className, 0, a_fnName, a_callable); }
				virtual void					   ForEachBoundObject(VMHandle a_handle, IForEachScriptObjectFunctor* a_functor) override;																											// 1B
				virtual bool					   FindBoundObject(VMHandle a_handle, const char* a_className, BSTSmartPointer<Object>& a_result) const override;																					// 1C
				virtual void					   MoveBoundObjects(VMHandle a_from, VMHandle a_to) override;																																		// 1D
				virtual void					   ResetAllBoundObjects(VMHandle a_handle) override;																																				// 1E
				virtual bool					   CastObject(const BSTSmartPointer<Object>& a_fromObjPtr, const BSTSmartPointer<ObjectTypeInfo>& a_toTypeInfoPtr, BSTSmartPointer<Object>& a_toObjPtr) override;									// 1F
				virtual bool					   SetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_setVal) override;																						// 20
				virtual bool					   GetPropertyValue(BSTSmartPointer<Object>& a_obj, const char* a_propertyName, Variable& a_getVal) override;																						// 21
				virtual bool					   GetVariableValue1(const BSTSmartPointer<Object>& a_objPtr, UInt32 a_index, Variable& a_out) const override;																						// 22
				virtual bool					   GetVariableValue2(VMHandle a_handle, const BSFixedString& a_className, SInt32 a_variableIndex, Variable& a_out) const override;																	// 23
				virtual void					   SendEvent(VMHandle a_handle, const BSFixedString& a_eventName, IFunctionArguments* a_args) override;																								// 24
				virtual void					   SendEventAll(const BSFixedString& a_eventName, IFunctionArguments* a_args) override;																												// 25
				virtual bool					   DispatchStaticCall(const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;						// 26
				virtual bool					   DispatchMethodCall1(BSTSmartPointer<Object>& a_obj, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;						// 27
				virtual bool					   DispatchMethodCall2(VMHandle a_handle, const BSFixedString& a_className, const BSFixedString& a_fnName, IFunctionArguments* a_args, BSTSmartPointer<IStackCallbackFunctor>& a_result) override;	// 28
				virtual bool					   DispatchUnboundMethodCall(void) override;																																						// 29
				virtual bool					   IsWaitingOnLatent(VMStackID a_stackID) const override;																																			// 2A
				virtual void					   ReturnFromLatent(VMStackID a_stackID, const Variable& a_val) override;																															// 2B
				virtual ErrorLogger*			   GetErrorLogger() override;																																										// 2C - { return errorLogger; }
				virtual IObjectHandlePolicy*	   GetObjectHandlePolicy1() override;																																								// 2D - { return handlePolicy; }
				virtual const IObjectHandlePolicy* GetObjectHandlePolicy2() const override;																																							// 2E - { return handlePolicy; }
				virtual ObjectBindPolicy*		   GetObjectBindPolicy1() override;																																									// 2F - { return objectBindPolicy; }
				virtual const ObjectBindPolicy*	   GetObjectBindPolicy2() const override;																																							// 30 - { return objectBindPolicy; }
				virtual ISavePatcherInterface*	   GetSavePatcherInterface() override;																																								// 31 - { return savePatcherInterface; }
				virtual void					   RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;																																	// 32
				virtual void					   UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;																																	// 33
				virtual void					   RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;																																// 34
				virtual void					   UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;																																// 35

				// override (IVMObjectBindInterface)
				virtual VMHandle GetBoundHandle(const BSTSmartPointer<Object>& a_objPtr) const override;															// 01
				virtual bool	 TypeCanBeBound(const BSFixedString& a_className, VMHandle a_handle) override;														// 02
				virtual void	 BindObject(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) override;										// 03
				virtual void	 HandleLoadedBinding(BSTSmartPointer<Object>& a_objPtr, VMHandle a_handle, bool a_conditional) override;							// 04
				virtual void	 RemoveAllBoundObjects(VMHandle a_handle) override;																					// 05
				virtual void	 RemoveAllDiskLoadedBoundObjects(VMHandle a_handle) override;																		// 06
				virtual void	 HandleCObjectDeletion(VMHandle a_handle) override;																					// 07
				virtual void	 UnbindObject(const BSTSmartPointer<Object>& a_objPtr) override;																	// 08
				virtual bool	 CreateObjectWithProperties(const BSFixedString& a_className, UInt32 a_numProperties, BSTSmartPointer<Object>& a_objPtr) override;	// 09
				virtual bool	 InitObjectProperties(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) override;									// 0A

				static VirtualMachine* GetSingleton();


				// members
				ErrorLogger*											   errorLogger;					// 0080
				IMemoryPagePolicy*										   memoryPagePolicy;			// 0088
				IObjectHandlePolicy*									   handlePolicy;				// 0090
				ObjectBindPolicy*										   objectBindPolicy;			// 0098
				IFreezeQuery*											   freezeQuery;					// 00A0
				IStackCallbackSaveInterface*							   stackCallbackSaveInterface;	// 00A8
				IProfilePolicy*											   profilePolicy;				// 00B0
				ISavePatcherInterface*									   savePatcherInterface;		// 00B8
				mutable BSSpinLock										   typeInfoLock;				// 00C0
				LinkerProcessor											   linker;						// 00C8
				BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>> objectTypeMap;				// 0158
				BSTHashMap<VMTypeID, BSFixedString>						   typeIDToObjectType;			// 0188
				BSTHashMap<BSFixedString, VMTypeID>						   objectTypeToTypeID;			// 01B8
				BSTArray<BSTSmartPointer<ObjectTypeInfo>>				   typesToUnload;				// 01E8
				mutable BSSpinLock										   funcQueueLock;				// 0200
				BSTStaticFreeList<FunctionMessage, 1024>				   funcMsgPool;					// 0208
				BSTCommonLLMessageQueue<FunctionMessage>				   funcMsgQueue;				// 8220
				BSTArray<FunctionMessage>								   overflowFuncMsgs;			// 8248
				BSTArray<CodeTasklet*>									   vmTasks;						// 8260
				UInt32													   uiWaitingFunctionMessages;	// 8278
				bool													   overstressed;				// 827C
				bool													   initialized;					// 827D
				UInt16													   pad827E;						// 827E
				BSTCommonStaticMessageQueue<SuspendedStack, 128>		   suspendQueue1;				// 8280
				BSTCommonStaticMessageQueue<SuspendedStack, 128>		   suspendQueue2;				// 8AA0
				BSTArray<SuspendedStack>								   overflowSuspendArray1;		// 92C0
				BSTArray<SuspendedStack>								   overflowSuspendArray2;		// 92D8
				mutable BSSpinLock										   suspendQueueLock;			// 92F0
				BSTCommonStaticMessageQueue<SuspendedStack, 128>*		   stacksToResume;				// 92F8 - ref to suspendQueue2
				BSTArray<SuspendedStack>*								   stacksToResumeOverflow;		// 9300 - ref to overflowSuspendArray2
				BSTCommonStaticMessageQueue<SuspendedStack, 128>*		   stacksToSuspend;				// 9308 - ref to suspendQueue1
				BSTArray<SuspendedStack>*								   stacksToSuspendOverflow;		// 9310 - ref to overflowSuspendArray1
				mutable BSSpinLock										   runningStacksLock;			// 9318
				BSTHashMap<VMStackID, BSTSmartPointer<Stack>>			   allRunningStacks;			// 9320
				BSTHashMap<VMStackID, BSTSmartPointer<Stack>>			   waitingLatentReturns;		// 9350
				VMStackID												   nextStackID;					// 9380
				mutable BSSpinLock										   frozenStacksLock;			// 9384
				UInt32													   unk938C;						// 938C
				UInt64													   unk9390;						// 9390
				UInt64													   unk9398;						// 9398
				mutable BSSpinLock										   attachedScriptsLock;			// 93A0
				BSTHashMap<VMHandle, BSTSmallSharedArray<AttachedScript>>  attachedScripts;				// 93A8
				UInt64													   unk93D8;						// 93D8
				BSTArray<void*>											   unk93E0;						// 93E0
				mutable BSSpinLock										   arraysLock;					// 93F8
				UInt32													   nextArrayToClean;			// 9400
				UInt32													   pad9404;						// 9404
				BSTArray<BSTSmartPointer<Array>>						   arrays;						// 9408
				mutable BSSpinLock										   objectResetLock;				// 9420
				BSTArray<BSTSmartPointer<Object>>						   objectsAwaitingReset;		// 9428
				UInt64													   unk9440;						// 9440
				BSTHashMap<UnkKey, UnkValue>							   unk9448;						// 9448
				BSTHashMap<UnkKey, UnkValue>							   unk9478;						// 9478
				mutable BSSpinLock										   queuedUnbindLock;			// 94A8
				BSTArray<QueuedUnbindRefs>								   queuedUnbinds;				// 94B0
				UInt64													   unk94C8;						// 94C8
				UInt64													   unk94D0;						// 94D0
				UInt64													   unk94D8;						// 94D8
				UInt64													   unk94E0;						// 94E0
				UInt64													   unk94E8;						// 94E8
				UInt64													   unk94F0;						// 94F0
				UInt64													   unk94F8;						// 94F8
				UInt64													   unk9500;						// 9500
				UInt64													   unk9508;						// 9508
				UInt64													   unk9518;						// 9510
			};
			STATIC_ASSERT(sizeof(VirtualMachine) == 0x9518);
		}
	}
}
