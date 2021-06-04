#pragma once

class SKSEDelayFunctorManager;
class SKSEObjectRegistry;
class SKSEPersistentObjectStorage;
class TaskDelegate;
class UIDelegate_v1;

namespace SKSE
{
	using PluginHandle = std::uint32_t;
	enum : PluginHandle
	{
		kInvalidPluginHandle = static_cast<PluginHandle>(-1)
	};

	namespace detail
	{
		struct PluginInfo
		{
			std::uint32_t infoVersion;
			const char*   name;
			std::uint32_t version;
		};

		struct SKSEInterface
		{
			std::uint32_t skseVersion;
			std::uint32_t runtimeVersion;
			std::uint32_t editorVersion;
			std::uint32_t isEditor;
			void* (*QueryInterface)(std::uint32_t);
			PluginHandle (*GetPluginHandle)();
			std::uint32_t (*GetReleaseIndex)();
			const void* (*GetPluginInfo)(const char*);
		};

		struct SKSEMessagingInterface
		{
			std::uint32_t interfaceVersion;
			bool (*RegisterListener)(PluginHandle, const char*, void*);
			bool (*Dispatch)(PluginHandle, std::uint32_t, void*, std::uint32_t, const char*);
			void* (*GetEventDispatcher)(std::uint32_t);
		};

		struct SKSEObjectInterface
		{
			std::uint32_t interfaceVersion;
			SKSEDelayFunctorManager& (*GetDelayFunctorManager)();
			SKSEObjectRegistry& (*GetObjectRegistry)();
			SKSEPersistentObjectStorage& (*GetPersistentObjectStorage)();
		};

		struct SKSEPapyrusInterface
		{
			std::uint32_t interfaceVersion;
			bool (*Register)(void*);
		};

		struct SKSEScaleformInterface
		{
			std::uint32_t interfaceVersion;
			bool (*Register)(const char*, void*);
			void (*RegisterForInventory)(void*);
		};

		struct SKSESerializationInterface
		{
			std::uint32_t version;
			void (*SetUniqueID)(PluginHandle, std::uint32_t);
			void (*SetRevertCallback)(PluginHandle, void*);
			void (*SetSaveCallback)(PluginHandle, void*);
			void (*SetLoadCallback)(PluginHandle, void*);
			void (*SetFormDeleteCallback)(PluginHandle, void*);
			bool (*WriteRecord)(std::uint32_t, std::uint32_t, const void*, std::uint32_t);
			bool (*OpenRecord)(std::uint32_t, std::uint32_t);
			bool (*WriteRecordData)(const void*, std::uint32_t);
			bool (*GetNextRecordInfo)(std::uint32_t*, std::uint32_t*, std::uint32_t*);
			std::uint32_t (*ReadRecordData)(void*, std::uint32_t);
			bool (*ResolveHandle)(std::uint64_t, std::uint64_t*);
			bool (*ResolveFormId)(std::uint32_t, std::uint32_t*);
		};

		struct SKSETaskInterface
		{
			std::uint32_t interfaceVersion;
			void (*AddTask)(void*);
			void (*AddUITask)(void*);
		};

		struct SKSETrampolineInterface
		{
			std::uint32_t interfaceVersion;
			void* (*AllocateFromBranchPool)(PluginHandle, std::size_t);
			void* (*AllocateFromLocalPool)(PluginHandle, std::size_t);
		};

		class TaskDelegate
		{
		public:
			virtual void Run() = 0;
			virtual void Dispose() = 0;
		};

		class UIDelegate_v1
		{
		public:
			virtual void Run() = 0;
			virtual void Dispose() = 0;
		};
	}
}
