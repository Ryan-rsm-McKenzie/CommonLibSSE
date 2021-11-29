#pragma once

#include "RE/B/BSTEvent.h"

#include "SKSE/Events.h"
#include "SKSE/Impl/Stubs.h"
#include "SKSE/Interfaces.h"
#include "SKSE/Trampoline.h"
#include "SKSE/Version.h"

#define SKSEAPI __cdecl

namespace SKSE
{
	void Init(const LoadInterface* a_intfc) noexcept;
	void RegisterForAPIInitEvent(std::function<void()> a_fn);

	PluginHandle  GetPluginHandle() noexcept;
	std::uint32_t GetReleaseIndex() noexcept;

	const ScaleformInterface*     GetScaleformInterface() noexcept;
	const PapyrusInterface*       GetPapyrusInterface() noexcept;
	const SerializationInterface* GetSerializationInterface() noexcept;
	const TaskInterface*          GetTaskInterface() noexcept;
	const TrampolineInterface*    GetTrampolineInterface() noexcept;

	const MessagingInterface*              GetMessagingInterface() noexcept;
	RE::BSTEventSource<ModCallbackEvent>*  GetModCallbackEventSource() noexcept;
	RE::BSTEventSource<CameraEvent>*       GetCameraEventSource() noexcept;
	RE::BSTEventSource<CrosshairRefEvent>* GetCrosshairRefEventSource() noexcept;
	RE::BSTEventSource<ActionEvent>*       GetActionEventSource() noexcept;
	RE::BSTEventSource<NiNodeUpdateEvent>* GetNiNodeUpdateEventSource() noexcept;

	const ObjectInterface*             GetObjectInterface() noexcept;
	const SKSEDelayFunctorManager*     GetDelayFunctorManager() noexcept;
	const SKSEObjectRegistry*          GetObjectRegistry() noexcept;
	const SKSEPersistentObjectStorage* GetPersistentObjectStorage() noexcept;

	Trampoline& GetTrampoline();
	void        AllocTrampoline(std::size_t a_size, bool a_trySKSEReserve = true);
}
