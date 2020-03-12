#pragma once

class SKSEDelayFunctorManager;
class SKSEObjectRegistry;
class SKSEPersistentObjectStorage;
class TaskDelegate;
class UIDelegate_v1;


namespace SKSE
{
	using PluginHandle = UInt32;
	enum : PluginHandle
	{
		kInvalidPluginHandle = static_cast<PluginHandle>(-1)
	};


	namespace Impl
	{
		struct PluginInfo
		{
			UInt32		infoVersion;
			const char* name;
			UInt32		version;
		};


		struct SKSEInterface
		{
			UInt32 skseVersion;
			UInt32 runtimeVersion;
			UInt32 editorVersion;
			UInt32 isEditor;
			void* (*QueryInterface)(UInt32);
			PluginHandle (*GetPluginHandle)();
			UInt32 (*GetReleaseIndex)();
		};


		struct SKSEMessagingInterface
		{
			UInt32 interfaceVersion;
			bool (*RegisterListener)(PluginHandle, const char*, void*);
			bool (*Dispatch)(PluginHandle, UInt32, void*, UInt32, const char*);
			void* (*GetEventDispatcher)(UInt32);
		};


		struct SKSEObjectInterface
		{
			UInt32 interfaceVersion;
			SKSEDelayFunctorManager& (*GetDelayFunctorManager)();
			SKSEObjectRegistry& (*GetObjectRegistry)();
			SKSEPersistentObjectStorage& (*GetPersistentObjectStorage)();
		};


		struct SKSEPapyrusInterface
		{
			UInt32 interfaceVersion;
			bool (*Register)(void*);
		};


		struct SKSEScaleformInterface
		{
			UInt32 interfaceVersion;
			bool (*Register)(const char*, void*);
			void (*RegisterForInventory)(void*);
		};


		struct SKSESerializationInterface
		{
			UInt32 version;
			void (*SetUniqueID)(PluginHandle, UInt32);
			void (*SetRevertCallback)(PluginHandle, void*);
			void (*SetSaveCallback)(PluginHandle, void*);
			void (*SetLoadCallback)(PluginHandle, void*);
			void (*SetFormDeleteCallback)(PluginHandle, void*);
			bool (*WriteRecord)(UInt32, UInt32, const void*, UInt32);
			bool (*OpenRecord)(UInt32, UInt32);
			bool (*WriteRecordData)(const void*, UInt32);
			bool (*GetNextRecordInfo)(UInt32*, UInt32*, UInt32*);
			UInt32 (*ReadRecordData)(void*, UInt32);
			bool (*ResolveHandle)(UInt64, UInt64*);
			bool (*ResolveFormId)(UInt32, UInt32*);
		};


		struct SKSETaskInterface
		{
			UInt32 interfaceVersion;
			void (*AddTask)(void*);
			void (*AddUITask)(void*);
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
