#include "SKSE/API.h"

#include "skse64_common/BranchTrampoline.h"  // g_localTrampoline, g_branchTrampoline

#include <mutex>  // mutex
#include <vector>  // vector


namespace SKSE
{
	namespace
	{
		namespace
		{
			template <class T> struct _make_const { using type = typename const T; };
			template <class T> struct _make_const<T*> { using type = typename const T*; };
		}
		template <class T> struct make_const : _make_const<T> {};
		template <class T> using make_const_t = typename make_const<T>::type;


		PluginHandle	g_pluginHandle = static_cast<PluginHandle>(kPluginHandle_Invalid);
		UInt32			g_releaseIndex = 0;

		ScaleformInterface*		g_scaleformInterface = 0;
		PapyrusInterface*		g_papyrusInterface = 0;
		SerializationInterface*	g_serializationInterface = 0;
		TaskInterface*			g_taskInterface = 0;

		MessagingInterface*						g_messagingInterface = 0;
		RE::BSTEventSource<ModCallbackEvent>*	g_modCallbackEventSource = 0;
		RE::BSTEventSource<CameraEvent>*		g_cameraEventSource = 0;
		RE::BSTEventSource<CrosshairRefEvent>*	g_crosshairRefEventSource = 0;
		RE::BSTEventSource<ActionEvent>*		g_actionEventSource = 0;
		RE::BSTEventSource<NiNodeUpdateEvent>*	g_niNodeUpdateEventSource = 0;

		ObjectInterface*				g_objectInterface = 0;
		SKSEDelayFunctorManager*		g_delayFunctorManager = 0;
		SKSEObjectRegistry*				g_objectRegistry = 0;
		SKSEPersistentObjectStorage*	g_persistentObjectStorage = 0;

		std::mutex g_apiLock;
		std::vector<std::function<void()>> g_apiInitRegs;
		bool g_apiInit = false;
	}


	bool Init(const LoadInterface* a_skse)
	{
		std::lock_guard<decltype(g_apiLock)> locker(g_apiLock);

		if (!g_apiInit) {
			g_pluginHandle = a_skse->GetPluginHandle();
			if (g_pluginHandle == kPluginHandle_Invalid) {
				_ERROR("Failed to get valid plugin handle!\n");
				return false;
			}

			g_releaseIndex = a_skse->GetReleaseIndex();

			g_scaleformInterface = static_cast<decltype(g_scaleformInterface)>(a_skse->QueryInterface(InterfaceID::kScaleform));
			if (!g_scaleformInterface) {
				_ERROR("Failed to query scaleform interface!\n");
				return false;
			}

			g_papyrusInterface = static_cast<decltype(g_papyrusInterface)>(a_skse->QueryInterface(InterfaceID::kPapyrus));
			if (!g_papyrusInterface) {
				_ERROR("Failed to query papyrus interface!\n");
				return false;
			}

			g_serializationInterface = static_cast<decltype(g_serializationInterface)>(a_skse->QueryInterface(InterfaceID::kSerialization));
			if (!g_serializationInterface) {
				_ERROR("Failed to query serialization interface!\n");
				return false;
			}

			g_taskInterface = static_cast<decltype(g_taskInterface)>(a_skse->QueryInterface(InterfaceID::kTask));
			if (!g_taskInterface) {
				_ERROR("Failed to query task interface!\n");
				return false;
			}

			g_messagingInterface = static_cast<decltype(g_messagingInterface)>(a_skse->QueryInterface(InterfaceID::kMessaging));
			if (!g_messagingInterface) {
				_ERROR("Failed to query messaging interface!\n");
				return false;
			} else {
				g_modCallbackEventSource = static_cast<decltype(g_modCallbackEventSource)>(g_messagingInterface->GetEventDispatcher(MessagingInterface::Dispatcher::kModEvent));
				if (!g_modCallbackEventSource) {
					_ERROR("Failed to get mod callback event source!\n");
					return false;
				}

				g_cameraEventSource = static_cast<decltype(g_cameraEventSource)>(g_messagingInterface->GetEventDispatcher(MessagingInterface::Dispatcher::kCameraEvent));
				if (!g_cameraEventSource) {
					_ERROR("Failed to get camera event source!\n");
					return false;
				}

				g_crosshairRefEventSource = static_cast<decltype(g_crosshairRefEventSource)>(g_messagingInterface->GetEventDispatcher(MessagingInterface::Dispatcher::kCrosshairEvent));
				if (!g_crosshairRefEventSource) {
					_ERROR("Failed to get crosshair ref event source!\n");
					return false;
				}

				g_actionEventSource = static_cast<decltype(g_actionEventSource)>(g_messagingInterface->GetEventDispatcher(MessagingInterface::Dispatcher::kActionEvent));
				if (!g_actionEventSource) {
					_ERROR("Failed to get action event source!\n");
					return false;
				}

				g_niNodeUpdateEventSource = static_cast<decltype(g_niNodeUpdateEventSource)>(g_messagingInterface->GetEventDispatcher(MessagingInterface::Dispatcher::kNiNodeUpdateEvent));
				if (!g_niNodeUpdateEventSource) {
					_ERROR("Failed to get ni node update event source!\n");
					return false;
				}
			}

			g_objectInterface = static_cast<decltype(g_objectInterface)>(a_skse->QueryInterface(InterfaceID::kObject));
			if (!g_objectInterface) {
				_ERROR("Failed to query object interface!\n");
				return false;
			} else {
				g_delayFunctorManager = &g_objectInterface->GetDelayFunctorManager();
				if (!g_delayFunctorManager) {
					_ERROR("Failed to get delay functor manager!\n");
					return false;
				}

				g_objectRegistry = &g_objectInterface->GetObjectRegistry();
				if (!g_objectRegistry) {
					_ERROR("Failed to get object registry!\n");
					return false;
				}

				g_persistentObjectStorage = &g_objectInterface->GetPersistentObjectStorage();
				if (!g_persistentObjectStorage) {
					_ERROR("Failed to get persistent object storage!\n");
					return false;
				}
			}

			g_apiInit = true;
			for (auto& reg : g_apiInitRegs) {
				reg();
			}
			g_apiInitRegs.clear();
			g_apiInitRegs.shrink_to_fit();
		}

		return true;
	}


	void RegisterForAPIInitEvent(std::function<void()> a_fn)
	{
		g_apiLock.lock();

		if (!g_apiInit) {
			g_apiInitRegs.push_back(a_fn);
			g_apiLock.unlock();
		} else {
			g_apiLock.unlock();
			a_fn();
		}
	}


	auto GetPluginHandle()
		-> make_const_t<decltype(g_pluginHandle)>
	{
		return g_pluginHandle;
	}


	auto GetReleaseIndex()
		-> make_const_t<decltype(g_releaseIndex)>
	{
		return g_releaseIndex;
	}


	auto GetScaleformInterface()
		-> make_const_t<decltype(g_scaleformInterface)>
	{
		return g_scaleformInterface;
	}


	auto GetPapyrusInterface()
		-> make_const_t<decltype(g_papyrusInterface)>
	{
		return g_papyrusInterface;
	}


	auto GetSerializationInterface()
		-> make_const_t<decltype(g_serializationInterface)>
	{
		return g_serializationInterface;
	}


	auto GetTaskInterface()
		-> make_const_t<decltype(g_taskInterface)>
	{
		return g_taskInterface;
	}


	auto GetMessagingInterface()
		-> make_const_t<decltype(g_messagingInterface)>
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
		-> make_const_t<decltype(g_objectInterface)>
	{
		return g_objectInterface;
	}


	auto GetDelayFunctorManager()
		-> make_const_t<decltype(g_delayFunctorManager)>
	{
		return g_delayFunctorManager;
	}


	auto GetObjectRegistry()
		-> make_const_t<decltype(g_objectRegistry)>
	{
		return g_objectRegistry;
	}


	auto GetPersistentObjectStorage()
		-> make_const_t<decltype(g_persistentObjectStorage)>
	{
		return g_persistentObjectStorage;
	}


	bool AllocLocalTrampoline(std::size_t a_size)
	{
		if (!g_localTrampoline.Create(a_size)) {
			_ERROR("Local trmapoline creation failed!\n");
			return false;
		}

		return true;
	}


	bool AllocBranchTrampoline(std::size_t a_size)
	{
		if (!g_branchTrampoline.Create(a_size)) {
			_ERROR("Branch trmapoline creation failed!\n");
			return false;
		}

		return true;
	}
}
