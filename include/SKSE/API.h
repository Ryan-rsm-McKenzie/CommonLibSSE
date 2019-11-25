#pragma once

#include "skse64/PapyrusDelayFunctors.h"
#include "skse64/PapyrusObjects.h"
#include "skse64/PluginAPI.h"

#include <functional>

#include "RE/BSTEvent.h"
#include "SKSE/Events.h"
#include "SKSE/Interfaces.h"


namespace SKSE
{
	bool	Init(const LoadInterface* a_skse);
	void	RegisterForAPIInitEvent(std::function<void()> a_fn);

	const PluginHandle	GetPluginHandle();
	const UInt32		GetReleaseIndex();

	const ScaleformInterface*		GetScaleformInterface();
	const PapyrusInterface*			GetPapyrusInterface();
	const SerializationInterface*	GetSerializationInterface();
	const TaskInterface*			GetTaskInterface();

	const MessagingInterface*				GetMessagingInterface();
	RE::BSTEventSource<ModCallbackEvent>*	GetModCallbackEventSource();
	RE::BSTEventSource<CameraEvent>*		GetCameraEventSource();
	RE::BSTEventSource<CrosshairRefEvent>*	GetCrosshairRefEventSource();
	RE::BSTEventSource<ActionEvent>*		GetActionEventSource();
	RE::BSTEventSource<NiNodeUpdateEvent>*	GetNiNodeUpdateEventSource();

	const ObjectInterface*				GetObjectInterface();
	const SKSEDelayFunctorManager*		GetDelayFunctorManager();
	const SKSEObjectRegistry*			GetObjectRegistry();
	const SKSEPersistentObjectStorage*	GetPersistentObjectStorage();

	bool	AllocLocalTrampoline(std::size_t a_size);
	bool	AllocBranchTrampoline(std::size_t a_size);
}
