#pragma once

#include "skse64_common/skse_version.h"

#include <functional>

#include "RE/BSTEvent.h"

#include "SKSE/Events.h"
#include "SKSE/Interfaces.h"
#include "SKSE/Stubs.h"
#include "SKSE/Trampoline.h"


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

	Trampoline* GetTrampoline();
	bool		AllocTrampoline(std::size_t a_size);
}
