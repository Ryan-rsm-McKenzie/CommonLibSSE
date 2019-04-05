#pragma once

#include "skse64/PapyrusDelayFunctors.h"  // SKSEDelayFunctorManager
#include "skse64/PapyrusEvents.h"  // SKSEModCallbackEvent, SKSECameraEvent, SKSECrosshairRefEvent, SKSEActionEvent, SKSENiNodeUpdateEvent
#include "skse64/PapyrusObjects.h"  // SKSEObjectRegistry, SKSEPersistentObjectStorage
#include "skse64/gamethreads.h"  // TaskDelegate
#include "skse64/PluginAPI.h"  // SKSEInterface, PluginHandle, SKSEScaleformInterface, SKSEPapyrusInterface, SKSESerializationInterface, SKSETaskInterface, SKSEMessagingInterface, SKSEObjectInterface

#include <functional>  // function

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/VirtualMachine.h"  // VirtualMachine


namespace SKSE
{
	using TaskFn = std::function<void()>;
	using PapyrusRegFunction = bool(RE::BSScript::Internal::VirtualMachine*);


	bool Init(const SKSEInterface* a_skse);

	PluginHandle	GetPluginHandle();
	UInt32			GetReleaseIndex();

	SKSEScaleformInterface* GetScaleformInterface();

	SKSEPapyrusInterface*	GetPapyrusInterface();
	bool					RegisterPapyrusCallback(PapyrusRegFunction* a_fn);
	bool					RegisterPapyrusCallback(SKSEPapyrusInterface::RegisterFunctions a_fn);

	SKSESerializationInterface* GetSerializationInterface();

	SKSETaskInterface*	GetTaskInterface();
	void				AddTask(TaskFn a_fn);
	void				AddTask(TaskDelegate* a_delegate);
	void				AddTask(UIDelegate_v1* a_delegate);

	SKSEMessagingInterface*						GetMessagingInterface();
	RE::BSTEventSource<SKSEModCallbackEvent>*	GetModCallbackEventSource();
	RE::BSTEventSource<SKSECameraEvent>*		GetCameraEventSource();
	RE::BSTEventSource<SKSECrosshairRefEvent>*	GetCrosshairRefEventSource();
	RE::BSTEventSource<SKSEActionEvent>*		GetActionEventSource();
	RE::BSTEventSource<SKSENiNodeUpdateEvent>*	GetNiNodeUpdateEventSource();

	SKSEObjectInterface*			GetObjectInterface();
	SKSEDelayFunctorManager*		GetDelayFunctorManager();
	SKSEObjectRegistry*				GetObjectRegistry();
	SKSEPersistentObjectStorage*	GetPersistentObjectStorage();


	namespace
	{
		class Task : public TaskDelegate
		{
		public:
			Task(TaskFn a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};


		inline PluginHandle	g_pluginHandle = static_cast<PluginHandle>(kPluginHandle_Invalid);
		inline UInt32		g_releaseIndex = 0;

		inline SKSEScaleformInterface*		g_scaleformInterface = 0;
		inline SKSEPapyrusInterface*		g_papyrusInterface = 0;
		inline SKSESerializationInterface*	g_serializationInterface = 0;
		inline SKSETaskInterface*			g_taskInterface = 0;

		inline SKSEMessagingInterface*						g_messagingInterface = 0;
		inline RE::BSTEventSource<SKSEModCallbackEvent>*	g_modCallbackEventSource = 0;
		inline RE::BSTEventSource<SKSECameraEvent>*			g_cameraEventSource = 0;
		inline RE::BSTEventSource<SKSECrosshairRefEvent>*	g_crosshairRefEventSource = 0;
		inline RE::BSTEventSource<SKSEActionEvent>*			g_actionEventSource = 0;
		inline RE::BSTEventSource<SKSENiNodeUpdateEvent>*	g_niNodeUpdateEventSource = 0;

		inline SKSEObjectInterface*			g_objectInterface = 0;
		inline SKSEDelayFunctorManager*		g_delayFunctorManager = 0;
		inline SKSEObjectRegistry*			g_objectRegistry = 0;
		inline SKSEPersistentObjectStorage*	g_persistentObjectStorage = 0;
	}
}
