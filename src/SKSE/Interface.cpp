#include "SKSE/Interface.h"


namespace SKSE
{
	bool Init(const SKSEInterface* a_skse)
	{
		g_pluginHandle = a_skse->GetPluginHandle();
		g_releaseIndex = a_skse->GetReleaseIndex();

		g_scaleformInterface = static_cast<decltype(g_scaleformInterface)>(a_skse->QueryInterface(kInterface_Scaleform));
		if (!g_scaleformInterface) {
			_ERROR("[ERROR] Failed to query scaleform interface!\n");
			return false;
		}

		g_papyrusInterface = static_cast<decltype(g_papyrusInterface)>(a_skse->QueryInterface(kInterface_Papyrus));
		if (!g_papyrusInterface) {
			_ERROR("[ERROR] Failed to query papyrus interface!\n");
			return false;
		}

		g_serializationInterface = static_cast<decltype(g_serializationInterface)>(a_skse->QueryInterface(kInterface_Serialization));
		if (!g_serializationInterface) {
			_ERROR("[ERROR] Failed to query serialization interface!\n");
			return false;
		}

		g_taskInterface = static_cast<decltype(g_taskInterface)>(a_skse->QueryInterface(kInterface_Task));
		if (!g_taskInterface) {
			_ERROR("[ERROR] Failed to query task interface!\n");
			return false;
		}

		g_messagingInterface = static_cast<decltype(g_messagingInterface)>(a_skse->QueryInterface(kInterface_Messaging));
		if (!g_messagingInterface) {
			_ERROR("[ERROR] Failed to query messaging interface!\n");
			return false;
		} else {
			g_modCallbackEventSource = static_cast<decltype(g_modCallbackEventSource)>(g_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_ModEvent));
			if (!g_modCallbackEventSource) {
				_ERROR("[ERROR] Failed to get mod callback event source!\n");
				return false;
			}

			g_cameraEventSource = static_cast<decltype(g_cameraEventSource)>(g_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_CameraEvent));
			if (!g_cameraEventSource) {
				_ERROR("[ERROR] Failed to get camera event source!\n");
				return false;
			}

			g_crosshairRefEventSource = static_cast<decltype(g_crosshairRefEventSource)>(g_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_CrosshairEvent));
			if (!g_crosshairRefEventSource) {
				_ERROR("[ERROR] Failed to get crosshair ref event source!\n");
				return false;
			}

			g_actionEventSource = static_cast<decltype(g_actionEventSource)>(g_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_ActionEvent));
			if (!g_actionEventSource) {
				_ERROR("[ERROR] Failed to get action event source!\n");
				return false;
			}

			g_niNodeUpdateEventSource = static_cast<decltype(g_niNodeUpdateEventSource)>(g_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_NiNodeUpdateEvent));
			if (!g_niNodeUpdateEventSource) {
				_ERROR("[ERROR] Failed to get ni node update event source!\n");
				return false;
			}
		}

		g_objectInterface = static_cast<decltype(g_objectInterface)>(a_skse->QueryInterface(kInterface_Object));
		if (!g_objectInterface) {
			_ERROR("[ERROR] Failed to query object interface!\n");
			return false;
		} else {
			g_delayFunctorManager = &g_objectInterface->GetDelayFunctorManager();
			g_objectRegistry = &g_objectInterface->GetObjectRegistry();
			g_persistentObjectStorage = &g_objectInterface->GetPersistentObjectStorage();
		}

		return true;
	}


	auto GetPluginHandle()
		-> decltype(g_pluginHandle)
	{
		return g_pluginHandle;
	}


	auto GetReleaseIndex()
		-> decltype(g_releaseIndex)
	{
		return g_releaseIndex;
	}


	auto GetScaleformInterface()
		-> decltype(g_scaleformInterface)
	{
		return g_scaleformInterface;
	}


	auto GetPapyrusInterface()
		-> decltype(g_papyrusInterface)
	{
		return g_papyrusInterface;
	}


	bool RegisterPapyrusCallback(PapyrusRegFunction* a_fn)
	{
		return g_papyrusInterface->Register(reinterpret_cast<SKSEPapyrusInterface::RegisterFunctions>(a_fn));
	}


	bool RegisterPapyrusCallback(SKSEPapyrusInterface::RegisterFunctions a_fn)
	{
		return g_papyrusInterface->Register(a_fn);
	}


	auto GetSerializationInterface()
		-> decltype(g_serializationInterface)
	{
		return g_serializationInterface;
	}


	auto GetTaskInterface()
		-> decltype(g_taskInterface)
	{
		return g_taskInterface;
	}


	void AddTask(TaskFn a_fn)
	{
		g_taskInterface->AddTask(new Task(a_fn));
	}


	void AddTask(TaskDelegate* a_delegate)
	{
		g_taskInterface->AddTask(a_delegate);
	}


	void AddTask(UIDelegate_v1* a_delegate)
	{
		g_taskInterface->AddUITask(a_delegate);
	}


	auto GetMessagingInterface()
		-> decltype(g_messagingInterface)
	{
		return g_messagingInterface;
	}


	auto GetModCallbackEventSource()
		-> decltype(g_modCallbackEventSource)
	{
		return g_modCallbackEventSource;
	}


	auto GetCameraEventSource()
		-> decltype(g_cameraEventSource)
	{
		return g_cameraEventSource;
	}


	auto GetCrosshairRefEventSource()
		-> decltype(g_crosshairRefEventSource)
	{
		return g_crosshairRefEventSource;
	}


	auto GetActionEventSource()
		-> decltype(g_actionEventSource)
	{
		return g_actionEventSource;
	}


	auto GetNiNodeUpdateEventSource()
		-> decltype(g_niNodeUpdateEventSource)
	{
		return g_niNodeUpdateEventSource;
	}


	auto GetObjectInterface()
		-> decltype(g_objectInterface)
	{
		return g_objectInterface;
	}


	auto GetDelayFunctorManager()
		-> decltype(g_delayFunctorManager)
	{
		return g_delayFunctorManager;
	}


	auto GetObjectRegistry()
		-> decltype(g_objectRegistry)
	{
		return g_objectRegistry;
	}


	auto GetPersistentObjectStorage()
		-> decltype(g_persistentObjectStorage)
	{
		return g_persistentObjectStorage;
	}


	Task::Task(TaskFn a_fn) :
		_fn(a_fn)
	{}


	void Task::Run()
	{
		_fn();
	}


	void Task::Dispose()
	{
		delete this;
	}
}
