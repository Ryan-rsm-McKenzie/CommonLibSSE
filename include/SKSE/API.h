#pragma once

#include "skse64/PapyrusDelayFunctors.h"  // SKSEDelayFunctorManager
#include "skse64/PapyrusEvents.h"  // SKSEModCallbackEvent, SKSECameraEvent, SKSECrosshairRefEvent, SKSEActionEvent, SKSENiNodeUpdateEvent
#include "skse64/PapyrusObjects.h"  // SKSEObjectRegistry, SKSEPersistentObjectStorage
#include "skse64/gamethreads.h"  // TaskDelegate
#include "skse64/PluginAPI.h"  // PluginHandle

#include <functional>  // function

#include "SKSE/Events.h"  // ModCallbackEvent, CameraEvent, CrosshairRefEvent, ActionEvent, NiNodeUpdateEvent
#include "SKSE/Interfaces.h"  // LoadInterface, ScaleformInterface, PapyrusInterface, SerializationInterface, TaskInterface, MessagingInterface, ObjectInterface
#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/VirtualMachine.h"  // VirtualMachine


namespace SKSE
{
	using TaskFn = std::function<void()>;


	bool Init(const SKSE::LoadInterface* a_skse);

	const PluginHandle	GetPluginHandle();
	const UInt32		GetReleaseIndex();

	const SKSE::ScaleformInterface*		GetScaleformInterface();
	const SKSE::PapyrusInterface*		GetPapyrusInterface();
	const SKSE::SerializationInterface*	GetSerializationInterface();
	const SKSE::TaskInterface*			GetTaskInterface();

	const SKSE::MessagingInterface*					GetMessagingInterface();
	RE::BSTEventSource<SKSE::ModCallbackEvent>*		GetModCallbackEventSource();
	RE::BSTEventSource<SKSE::CameraEvent>*			GetCameraEventSource();
	RE::BSTEventSource<SKSE::CrosshairRefEvent>*	GetCrosshairRefEventSource();
	RE::BSTEventSource<SKSE::ActionEvent>*			GetActionEventSource();
	RE::BSTEventSource<SKSE::NiNodeUpdateEvent>*	GetNiNodeUpdateEventSource();

	const SKSE::ObjectInterface*		GetObjectInterface();
	const SKSEDelayFunctorManager*		GetDelayFunctorManager();
	const SKSEObjectRegistry*			GetObjectRegistry();
	const SKSEPersistentObjectStorage*	GetPersistentObjectStorage();


	namespace
	{
		inline PluginHandle	g_pluginHandle = static_cast<PluginHandle>(kPluginHandle_Invalid);
		inline UInt32		g_releaseIndex = 0;

		inline SKSE::ScaleformInterface*		g_scaleformInterface = 0;
		inline SKSE::PapyrusInterface*			g_papyrusInterface = 0;
		inline SKSE::SerializationInterface*	g_serializationInterface = 0;
		inline SKSE::TaskInterface*				g_taskInterface = 0;

		inline SKSE::MessagingInterface*					g_messagingInterface = 0;
		inline RE::BSTEventSource<SKSE::ModCallbackEvent>*	g_modCallbackEventSource = 0;
		inline RE::BSTEventSource<SKSE::CameraEvent>*		g_cameraEventSource = 0;
		inline RE::BSTEventSource<SKSE::CrosshairRefEvent>*	g_crosshairRefEventSource = 0;
		inline RE::BSTEventSource<SKSE::ActionEvent>*		g_actionEventSource = 0;
		inline RE::BSTEventSource<SKSE::NiNodeUpdateEvent>*	g_niNodeUpdateEventSource = 0;

		inline SKSE::ObjectInterface*		g_objectInterface = 0;
		inline SKSEDelayFunctorManager*		g_delayFunctorManager = 0;
		inline SKSEObjectRegistry*			g_objectRegistry = 0;
		inline SKSEPersistentObjectStorage*	g_persistentObjectStorage = 0;
	}
}
