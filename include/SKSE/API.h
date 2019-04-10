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
	bool Init(const LoadInterface* a_skse);

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


	namespace
	{
		inline PluginHandle	g_pluginHandle = static_cast<PluginHandle>(kPluginHandle_Invalid);
		inline UInt32		g_releaseIndex = 0;

		inline ScaleformInterface*		g_scaleformInterface = 0;
		inline PapyrusInterface*		g_papyrusInterface = 0;
		inline SerializationInterface*	g_serializationInterface = 0;
		inline TaskInterface*			g_taskInterface = 0;

		inline MessagingInterface*						g_messagingInterface = 0;
		inline RE::BSTEventSource<ModCallbackEvent>*	g_modCallbackEventSource = 0;
		inline RE::BSTEventSource<CameraEvent>*			g_cameraEventSource = 0;
		inline RE::BSTEventSource<CrosshairRefEvent>*	g_crosshairRefEventSource = 0;
		inline RE::BSTEventSource<ActionEvent>*			g_actionEventSource = 0;
		inline RE::BSTEventSource<NiNodeUpdateEvent>*	g_niNodeUpdateEventSource = 0;

		inline ObjectInterface*				g_objectInterface = 0;
		inline SKSEDelayFunctorManager*		g_delayFunctorManager = 0;
		inline SKSEObjectRegistry*			g_objectRegistry = 0;
		inline SKSEPersistentObjectStorage*	g_persistentObjectStorage = 0;
	}
}
