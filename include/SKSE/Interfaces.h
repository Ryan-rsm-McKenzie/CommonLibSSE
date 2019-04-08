#pragma once

#include "skse64/gamethreads.h"  // TaskDelegate
#include "skse64/Hooks_UI.h"  // UIDelegate_v1
#include "skse64/PapyrusDelayFunctors.h"  // SKSEDelayFunctorManager
#include "skse64/PapyrusObjects.h"  // SKSEObjectRegistry, SKSEPersistentObjectStorage
#include "skse64/PluginAPI.h"  // PluginHandle, SKSEInterface, SKSEScaleformInterface, SKSESerializationInterface, SKSETaskInterface, SKSEPapyrusInterface, SKSEMessagingInterface, SKSEObjectInterface

#include <functional>  // function

#include "RE/GFxMovieView.h"  // GFxMovieView
#include "RE/GFxValue.h"  // GFxValue
#include "RE/InventoryEntryData.h"  // InventoryEntryData
#include "RE/VirtualMachine.h"  // VirtualMachine


namespace SKSE
{
	enum class InterfaceID : UInt32
	{
		kInvalid = 0,
		kScaleform,
		kPapyrus,
		kSerialization,
		kTask,
		kMessaging,
		kObject,

		kTotal
	};


	struct QueryInterface
	{
		UInt32	skseVersion;
		UInt32	runtimeVersion;
		UInt32	editorVersion;
		BOOL	isEditor;
	};
	STATIC_ASSERT(offsetof(QueryInterface, skseVersion) == offsetof(SKSEInterface, skseVersion));
	STATIC_ASSERT(offsetof(QueryInterface, runtimeVersion) == offsetof(SKSEInterface, runtimeVersion));
	STATIC_ASSERT(offsetof(QueryInterface, editorVersion) == offsetof(SKSEInterface, editorVersion));
	STATIC_ASSERT(offsetof(QueryInterface, isEditor) == offsetof(SKSEInterface, isEditor));


	struct LoadInterface : QueryInterface
	{
	public:
		void* QueryInterface(InterfaceID a_id) const;
		PluginHandle GetPluginHandle() const;
		UInt32 GetReleaseIndex() const;

	private:
		void* _queryInterface;
		void* _getPluginHandle;
		void* _getReleaseIndex;
	};
	STATIC_ASSERT(offsetof(LoadInterface, skseVersion) == offsetof(SKSEInterface, skseVersion));
	STATIC_ASSERT(offsetof(LoadInterface, runtimeVersion) == offsetof(SKSEInterface, runtimeVersion));
	STATIC_ASSERT(offsetof(LoadInterface, editorVersion) == offsetof(SKSEInterface, editorVersion));
	STATIC_ASSERT(offsetof(LoadInterface, isEditor) == offsetof(SKSEInterface, isEditor));
	STATIC_ASSERT(sizeof(LoadInterface) == sizeof(SKSEInterface));


	struct ScaleformInterface
	{
	public:
		using RegCallback = bool(RE::GFxMovieView* a_view, RE::GFxValue* a_root);
		using RegInvCallback = void(RE::GFxMovieView* a_view, GFxValue* a_object, RE::InventoryEntryData* a_item);

		enum { kVersion = 2 };

		bool Register(RegCallback* a_callback, const char* a_name) const;
		void Register(RegInvCallback* a_callback) const;

		UInt32 version;

	private:
		void* _register;
		void* _registerForInventory;
	};
	STATIC_ASSERT(ScaleformInterface::kVersion == SKSEScaleformInterface::kInterfaceVersion);
	STATIC_ASSERT(offsetof(ScaleformInterface, version) == offsetof(SKSEScaleformInterface, interfaceVersion));
	STATIC_ASSERT(sizeof(ScaleformInterface) == sizeof(SKSEScaleformInterface));


	struct SerializationInterface
	{
	public:
		using EventCallback = void(SerializationInterface* a_intfc);
		using FormDeleteCallback = void(UInt64 a_handle);

		enum { kVersion = 4 };

		void SetUniqueID(UInt32 a_uid) const;

		void SetRevertCallback(EventCallback* a_callback) const;
		void SetSaveCallback(EventCallback* a_callback) const;
		void SetLoadCallback(EventCallback* a_callback) const;
		void SetFormDeleteCallback(FormDeleteCallback* a_callback) const;

		bool WriteRecord(UInt32 a_type, UInt32 a_version, const void* a_buf, UInt32 a_length) const;
		bool OpenRecord(UInt32 a_type, UInt32 a_version) const;
		bool WriteRecordData(const void* a_buf, UInt32 a_length) const;

		bool GetNextRecordInfo(UInt32& a_type, UInt32& a_version, UInt32& a_length) const;
		UInt32 ReadRecordData(void* a_buf, UInt32 a_length) const;
		bool ResolveHandle(RE::VMHandle a_oldHandle, RE::VMHandle& a_newHandle) const;
		bool ResolveFormID(UInt32 a_oldFormID, UInt32& a_newFormID) const;

		UInt32 version;

	private:
		void* _setUniqueID;
		void* _setRevertCallback;
		void* _setSaveCallback;
		void* _setLoadCallback;
		void* _setFormDeleteCallback;
		void* _writeRecord;
		void* _openRecord;
		void* _writeRecordData;
		void* _getNextRecordInfo;
		void* _readRecordData;
		void* _resolveHandle;
		void* _resolveFormID;
	};
	STATIC_ASSERT(SerializationInterface::kVersion == SKSESerializationInterface::kVersion);
	STATIC_ASSERT(offsetof(SerializationInterface, version) == offsetof(SKSESerializationInterface, version));
	STATIC_ASSERT(sizeof(SerializationInterface) == sizeof(SKSESerializationInterface));


	struct TaskInterface
	{
	public:
		using TaskFn = std::function<void()>;

		enum { kVersion = 2 };

		void AddTask(TaskFn a_task) const;
		void AddTask(TaskDelegate* a_task) const;
		void AddTask(UIDelegate_v1* a_task) const;

		UInt32 version;

	private:
		class Task : public TaskDelegate
		{
		public:
			Task(TaskFn&& a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};

		void* _addTask;
		void* _addUITask;
	};
	STATIC_ASSERT(TaskInterface::kVersion == SKSETaskInterface::kInterfaceVersion);
	STATIC_ASSERT(offsetof(TaskInterface, version) == offsetof(SKSETaskInterface, interfaceVersion));
	STATIC_ASSERT(sizeof(TaskInterface) == sizeof(SKSETaskInterface));


	struct PapyrusInterface
	{
	public:
		using RegFunction = bool(RE::BSScript::Internal::VirtualMachine* a_vm);

		enum { kVersion = 1 };

		bool Register(RegFunction* a_fn) const;

		UInt32 version;

	private:
		void* _register;
	};
	STATIC_ASSERT(PapyrusInterface::kVersion == SKSEPapyrusInterface::kInterfaceVersion);
	STATIC_ASSERT(offsetof(PapyrusInterface, version) == offsetof(SKSEPapyrusInterface, interfaceVersion));
	STATIC_ASSERT(sizeof(PapyrusInterface) == sizeof(SKSEPapyrusInterface));


	struct MessagingInterface
	{
		struct Message
		{
			const char*	sender;
			UInt32		type;
			UInt32		dataLen;
			void*		data;
		};

		using EventCallback = void(Message* a_msg);

		enum { kVersion = 2 };

		enum : UInt32
		{
			kPostLoad,
			kPostPostLoad,
			kPreLoadGame,
			kPostLoadGame,
			kSaveGame,
			kDeleteGame,
			kInputLoaded,
			kNewGame,
			kDataLoaded,

			kTotal
		};

		enum class Dispatcher : UInt32
		{
			kModEvent = 0,
			kCameraEvent,
			kCrosshairEvent,
			kActionEvent,
			kNiNodeUpdateEvent,

			kTotal
		};

		bool RegisterListener(const char* a_sender, EventCallback* a_callback) const;
		bool Dispatch(UInt32 a_messageType, void* a_data, UInt32 a_dataLen, const char* a_receiver) const;
		void* GetEventDispatcher(Dispatcher a_dispatcherID) const;

		UInt32 version;

	private:
		void* _registerListener;
		void* _dispatch;
		void* _getEventDispatcher;
	};
	STATIC_ASSERT(MessagingInterface::kVersion == SKSEMessagingInterface::kInterfaceVersion);
	STATIC_ASSERT(offsetof(MessagingInterface, version) == offsetof(SKSEMessagingInterface, interfaceVersion));
	STATIC_ASSERT(sizeof(MessagingInterface) == sizeof(SKSEMessagingInterface));


	struct ObjectInterface
	{
	public:
		enum { kVersion = 1 };

		SKSEDelayFunctorManager& GetDelayFunctorManager() const;
		SKSEObjectRegistry& GetObjectRegistry() const;
		SKSEPersistentObjectStorage& GetPersistentObjectStorage() const;

		UInt32 version;

	private:
		void* _getDelayFunctorManager;
		void* _getObjectRegistry;
		void* _getPersistentObjectStorage;
	};
	STATIC_ASSERT(ObjectInterface::kVersion == SKSEObjectInterface::kInterfaceVersion);
	STATIC_ASSERT(offsetof(ObjectInterface, version) == offsetof(SKSEObjectInterface, interfaceVersion));
	STATIC_ASSERT(sizeof(ObjectInterface) == sizeof(SKSEObjectInterface));


	struct PluginInfo
	{
		enum { kVersion = 1 };

		UInt32		infoVersion;
		const char*	name;
		UInt32		version;
	};
	STATIC_ASSERT(PluginInfo::kVersion == ::PluginInfo::kInfoVersion);
	STATIC_ASSERT(offsetof(PluginInfo, infoVersion) == offsetof(::PluginInfo, infoVersion));
	STATIC_ASSERT(offsetof(PluginInfo, name) == offsetof(::PluginInfo, name));
	STATIC_ASSERT(offsetof(PluginInfo, version) == offsetof(::PluginInfo, version));
	STATIC_ASSERT(sizeof(PluginInfo) == sizeof(::PluginInfo));
}
