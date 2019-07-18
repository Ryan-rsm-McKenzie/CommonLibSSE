#pragma once

#include "skse64/gamethreads.h"  // TaskDelegate
#include "skse64/Hooks_UI.h"  // UIDelegate_v1
#include "skse64/PapyrusDelayFunctors.h"  // SKSEDelayFunctorManager
#include "skse64/PapyrusObjects.h"  // SKSEObjectRegistry, SKSEPersistentObjectStorage
#include "skse64/PluginAPI.h"  // PluginHandle, SKSEInterface, SKSEScaleformInterface, SKSESerializationInterface, SKSETaskInterface, SKSEPapyrusInterface, SKSEMessagingInterface, SKSEObjectInterface

#include <functional>  // function

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/GFxMovieView.h"  // GFxMovieView
#include "RE/GFxValue.h"  // GFxValue
#include "RE/InventoryEntryData.h"  // InventoryEntryData


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


	class QueryInterface
	{
	public:
		UInt32 SKSEVersion() const;
		UInt32 RuntimeVersion() const;
		UInt32 EditorVersion() const;
		bool IsEditor() const;

	protected:
		const SKSEInterface* GetProxy() const;
	};


	class LoadInterface : public QueryInterface
	{
	public:
		void* QueryInterface(InterfaceID a_id) const;
		PluginHandle GetPluginHandle() const;
		UInt32 GetReleaseIndex() const;
	};


	class ScaleformInterface
	{
	public:
		using RegCallback = bool(RE::GFxMovieView* a_view, RE::GFxValue* a_root);
		using RegInvCallback = void(RE::GFxMovieView* a_view, RE::GFxValue* a_object, RE::InventoryEntryData* a_item);

		enum { kVersion = 2 };

		UInt32 Version() const;

		bool Register(RegCallback* a_callback, const char* a_name) const;
		void Register(RegInvCallback* a_callback) const;

	protected:
		const SKSEScaleformInterface* GetProxy() const;
	};
	STATIC_ASSERT(ScaleformInterface::kVersion == SKSEScaleformInterface::kInterfaceVersion);


	class SerializationInterface
	{
	public:
		using EventCallback = void(SerializationInterface* a_intfc);
		using FormDeleteCallback = void(RE::VMHandle a_handle);

		enum { kVersion = 4 };

		UInt32 Version() const;

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
		bool ResolveFormID(RE::FormID a_oldFormID, RE::FormID& a_newFormID) const;

	protected:
		const SKSESerializationInterface* GetProxy() const;
	};
	STATIC_ASSERT(SerializationInterface::kVersion == SKSESerializationInterface::kVersion);


	class TaskInterface
	{
	public:
		using TaskFn = std::function<void()>;

		enum { kVersion = 2 };

		UInt32 Version() const;

		void AddTask(TaskFn a_task) const;
		void AddTask(TaskDelegate* a_task) const;
		void AddUITask(TaskFn a_task) const;
		void AddUITask(UIDelegate_v1* a_task) const;

	protected:
		class Task : public TaskDelegate
		{
		public:
			Task(TaskFn&& a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};

		class UITask : public UIDelegate_v1
		{
		public:
			UITask(TaskFn&& a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};

		const SKSETaskInterface* GetProxy() const;
	};
	STATIC_ASSERT(TaskInterface::kVersion == SKSETaskInterface::kInterfaceVersion);


	class PapyrusInterface
	{
	public:
		using RegFunction = bool(RE::BSScript::Internal::VirtualMachine* a_vm);

		enum { kVersion = 1 };

		UInt32 Version() const;

		template <class Last>
		bool Register(Last a_last) const
		{
			return Register_Impl(a_last);
		}

		template <class First, class... Rest>
		bool Register(First a_first, Rest... a_rest) const
		{
			return Register_Impl(a_first) && Register(a_rest...);
		}

	protected:
		const SKSEPapyrusInterface* GetProxy() const;

	private:
		bool Register_Impl(RegFunction* a_fn) const;
	};
	STATIC_ASSERT(PapyrusInterface::kVersion == SKSEPapyrusInterface::kInterfaceVersion);


	class MessagingInterface
	{
	public:
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

		UInt32 Version() const;

		bool RegisterListener(const char* a_sender, EventCallback* a_callback) const;
		bool Dispatch(UInt32 a_messageType, void* a_data, UInt32 a_dataLen, const char* a_receiver) const;
		void* GetEventDispatcher(Dispatcher a_dispatcherID) const;

	protected:
		const SKSEMessagingInterface* GetProxy() const;
	};
	STATIC_ASSERT(MessagingInterface::kVersion == SKSEMessagingInterface::kInterfaceVersion);


	class ObjectInterface
	{
	public:
		enum { kVersion = 1 };

		UInt32 Version() const;

		SKSEDelayFunctorManager& GetDelayFunctorManager() const;
		SKSEObjectRegistry& GetObjectRegistry() const;
		SKSEPersistentObjectStorage& GetPersistentObjectStorage() const;

	private:
		const SKSEObjectInterface* GetProxy() const;
	};
	STATIC_ASSERT(ObjectInterface::kVersion == SKSEObjectInterface::kInterfaceVersion);


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
