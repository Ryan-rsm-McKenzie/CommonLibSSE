#include "SKSEInterface.h"


bool SKSE::Init(const SKSEInterface* a_skse)
{
	_pluginHandle = a_skse->GetPluginHandle();
	_releaseIndex = a_skse->GetReleaseIndex();

	_scaleformInterface = static_cast<decltype(_scaleformInterface)>(a_skse->QueryInterface(kInterface_Scaleform));
	if (!_scaleformInterface) {
		_ERROR("[ERROR] Failed to query scaleform interface!\n");
		return false;
	}

	_papyrusInterface = static_cast<decltype(_papyrusInterface)>(a_skse->QueryInterface(kInterface_Papyrus));
	if (!_papyrusInterface) {
		_ERROR("[ERROR] Failed to query papyrus interface!\n");
		return false;
	}

	_serializationInterface = static_cast<decltype(_serializationInterface)>(a_skse->QueryInterface(kInterface_Serialization));
	if (!_serializationInterface) {
		_ERROR("[ERROR] Failed to query serialization interface!\n");
		return false;
	}

	_taskInterface = static_cast<decltype(_taskInterface)>(a_skse->QueryInterface(kInterface_Task));
	if (!_taskInterface) {
		_ERROR("[ERROR] Failed to query task interface!\n");
		return false;
	}

	_messagingInterface = static_cast<decltype(_messagingInterface)>(a_skse->QueryInterface(kInterface_Messaging));
	if (!_messagingInterface) {
		_ERROR("[ERROR] Failed to query messaging interface!\n");
		return false;
	} else {
		_modCallbackEventSource = static_cast<decltype(_modCallbackEventSource)>(_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_ModEvent));
		if (!_modCallbackEventSource) {
			_ERROR("[ERROR] Failed to get mod callback event source!\n");
			return false;
		}

		_cameraEventSource = static_cast<decltype(_cameraEventSource)>(_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_CameraEvent));
		if (!_cameraEventSource) {
			_ERROR("[ERROR] Failed to get camera event source!\n");
			return false;
		}

		_crosshairRefEventSource = static_cast<decltype(_crosshairRefEventSource)>(_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_CrosshairEvent));
		if (!_crosshairRefEventSource) {
			_ERROR("[ERROR] Failed to get crosshair ref event source!\n");
			return false;
		}

		_actionEventSource = static_cast<decltype(_actionEventSource)>(_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_ActionEvent));
		if (!_actionEventSource) {
			_ERROR("[ERROR] Failed to get action event source!\n");
			return false;
		}

		_niNodeUpdateEventSource = static_cast<decltype(_niNodeUpdateEventSource)>(_messagingInterface->GetEventDispatcher(SKSEMessagingInterface::kDispatcher_NiNodeUpdateEvent));
		if (!_niNodeUpdateEventSource) {
			_ERROR("[ERROR] Failed to get ni node update event source!\n");
			return false;
		}
	}

	_objectInterface = static_cast<decltype(_objectInterface)>(a_skse->QueryInterface(kInterface_Object));
	if (!_objectInterface) {
		_ERROR("[ERROR] Failed to query object interface!\n");
		return false;
	} else {
		_delayFunctorManager = &_objectInterface->GetDelayFunctorManager();
		_objectRegistry = &_objectInterface->GetObjectRegistry();
		_persistentObjectStorage = &_objectInterface->GetPersistentObjectStorage();
	}

	return true;
}


auto SKSE::GetPluginHandle()
-> decltype(_pluginHandle)
{
	return _pluginHandle;
}


auto SKSE::GetReleaseIndex()
-> decltype(_releaseIndex)
{
	return _releaseIndex;
}


auto SKSE::GetScaleformInterface()
-> decltype(_scaleformInterface)
{
	return _scaleformInterface;
}


auto SKSE::GetPapyrusInterface()
-> decltype(_papyrusInterface)
{
	return _papyrusInterface;
}


auto SKSE::GetSerializationInterface()
-> decltype(_serializationInterface)
{
	return _serializationInterface;
}


auto SKSE::GetTaskInterface()
-> decltype(_taskInterface)
{
	return _taskInterface;
}


void SKSE::AddTask(TaskFn a_fn)
{
	_taskInterface->AddTask(new Task(a_fn));
}


void SKSE::AddTask(TaskDelegate* a_delegate)
{
	_taskInterface->AddTask(a_delegate);
}


void SKSE::AddTask(UIDelegate_v1* a_delegate)
{
	_taskInterface->AddUITask(a_delegate);
}


auto SKSE::GetMessagingInterface()
-> decltype(_messagingInterface)
{
	return _messagingInterface;
}


auto SKSE::GetModCallbackEventSource()
-> decltype(_modCallbackEventSource)
{
	return _modCallbackEventSource;
}


auto SKSE::GetCameraEventSource()
-> decltype(_cameraEventSource)
{
	return _cameraEventSource;
}


auto SKSE::GetCrosshairRefEventSource()
-> decltype(_crosshairRefEventSource)
{
	return _crosshairRefEventSource;
}


auto SKSE::GetActionEventSource()
-> decltype(_actionEventSource)
{
	return _actionEventSource;
}


auto SKSE::GetNiNodeUpdateEventSource()
-> decltype(_niNodeUpdateEventSource)
{
	return _niNodeUpdateEventSource;
}


auto SKSE::GetObjectInterface()
-> decltype(_objectInterface)
{
	return _objectInterface;
}


auto SKSE::GetDelayFunctorManager()
-> decltype(_delayFunctorManager)
{
	return _delayFunctorManager;
}


auto SKSE::GetObjectRegistry()
-> decltype(_objectRegistry)
{
	return _objectRegistry;
}


auto SKSE::GetPersistentObjectStorage()
-> decltype(_persistentObjectStorage)
{
	return _persistentObjectStorage;
}


SKSE::Task::Task(TaskFn a_fn) :
	_fn(a_fn)
{}


void SKSE::Task::Run()
{
	_fn();
}


void SKSE::Task::Dispose()
{
	delete this;
}
