#pragma once

#include <functional>
#include <string>

#include "RE/BSScript/IVirtualMachine.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/GFxMovieView.h"
#include "RE/GFxValue.h"
#include "RE/InventoryEntryData.h"

#include "SKSE/Stubs.h"
#include "SKSE/Version.h"


namespace SKSE
{
	enum class InterfaceID : UInt32
	{
		kInvalid = 0,
		kScaleform,
		kPapyrus,
		kSerialization,
		kTask,
		kMessaging,
		kObject,

		kTotal
	};


	class QueryInterface
	{
	public:
		UInt32	EditorVersion() const;
		bool	IsEditor() const;
		Version RuntimeVersion() const;
		UInt32	SKSEVersion() const;

	protected:
		const Impl::SKSEInterface* GetProxy() const;
	};


	class LoadInterface : public QueryInterface
	{
	public:
		PluginHandle GetPluginHandle() const;
		UInt32		 GetReleaseIndex() const;
		void*		 QueryInterface(InterfaceID a_id) const;
	};


	class ScaleformInterface
	{
	public:
		using RegCallback = bool(RE::GFxMovieView* a_view, RE::GFxValue* a_root);
		using RegInvCallback = void(RE::GFxMovieView* a_view, RE::GFxValue* a_object, RE::InventoryEntryData* a_item);

		enum
		{
			kVersion = 2
		};

		UInt32 Version() const;

		bool Register(RegCallback* a_callback, const char* a_name) const;
		void Register(RegInvCallback* a_callback) const;

	protected:
		const Impl::SKSEScaleformInterface* GetProxy() const;
	};


	class SerializationInterface
	{
	public:
		using EventCallback = void(SerializationInterface* a_intfc);
		using FormDeleteCallback = void(RE::VMHandle a_handle);

		enum
		{
			kVersion = 4
		};

		UInt32 Version() const;

		void SetUniqueID(UInt32 a_uid) const;

		void SetFormDeleteCallback(FormDeleteCallback* a_callback) const;
		void SetLoadCallback(EventCallback* a_callback) const;
		void SetRevertCallback(EventCallback* a_callback) const;
		void SetSaveCallback(EventCallback* a_callback) const;

		bool WriteRecord(UInt32 a_type, UInt32 a_version, const void* a_buf, UInt32 a_length) const;
		template <class T, typename std::enable_if_t<std::negation<std::is_pointer<T>>::value, int> = 0>
		inline UInt32 WriteRecord(UInt32 a_type, UInt32 a_version, const T& a_buf) const
		{
			return WriteRecord(a_type, a_version, std::addressof(a_buf), sizeof(T));
		}
		template <class T, std::size_t N, typename std::enable_if_t<std::is_array<T>::value, int> = 0>
		inline UInt32 WriteRecord(UInt32 a_type, UInt32 a_version, const T (&a_buf)[N]) const
		{
			return WriteRecord(a_type, a_version, std::addressof(a_buf), sizeof(T) * N);
		}

		bool OpenRecord(UInt32 a_type, UInt32 a_version) const;

		bool WriteRecordData(const void* a_buf, UInt32 a_length) const;
		template <class T, typename std::enable_if_t<std::negation<std::is_pointer<T>>::value, int> = 0>
		inline UInt32 WriteRecordData(const T& a_buf) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T));
		}
		template <class T, std::size_t N, typename std::enable_if_t<std::is_array<T>::value, int> = 0>
		inline UInt32 WriteRecordData(const T (&a_buf)[N]) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		bool GetNextRecordInfo(UInt32& a_type, UInt32& a_version, UInt32& a_length) const;

		UInt32 ReadRecordData(void* a_buf, UInt32 a_length) const;
		template <class T, typename std::enable_if_t<std::negation<std::is_pointer<T>>::value, int> = 0>
		inline UInt32 ReadRecordData(T& a_buf) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T));
		}
		template <class T, std::size_t N, typename std::enable_if_t<std::is_array<T>::value, int> = 0>
		inline UInt32 ReadRecordData(T (&a_buf)[N]) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		bool ResolveFormID(RE::FormID a_oldFormID, RE::FormID& a_newFormID) const;
		bool ResolveHandle(RE::VMHandle a_oldHandle, RE::VMHandle& a_newHandle) const;

	protected:
		const Impl::SKSESerializationInterface* GetProxy() const;
	};


	class TaskInterface
	{
	public:
		using TaskFn = std::function<void()>;

		enum
		{
			kVersion = 2
		};

		UInt32 Version() const;

		void AddTask(TaskFn a_task) const;
		void AddTask(TaskDelegate* a_task) const;
		void AddUITask(TaskFn a_task) const;
		void AddUITask(UIDelegate_v1* a_task) const;

	protected:
		class Task : public Impl::TaskDelegate
		{
		public:
			Task(TaskFn&& a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};

		class UITask : public Impl::UIDelegate_v1
		{
		public:
			UITask(TaskFn&& a_fn);

			virtual void Run() override;
			virtual void Dispose() override;

		private:
			TaskFn _fn;
		};

		const Impl::SKSETaskInterface* GetProxy() const;
	};


	class PapyrusInterface
	{
	public:
		using RegFunction1 = bool(RE::BSScript::Internal::VirtualMachine* a_vm);
		using RegFunction2 = bool(RE::BSScript::IVirtualMachine* a_vm);

		enum
		{
			kVersion = 1
		};

		UInt32 Version() const;

		template <class Last>
		bool Register(Last a_last) const
		{
			return Register_Impl(a_last);
		}

		template <class First, class... Rest>
		bool Register(First a_first, Rest... a_rest) const
		{
			return Register_Impl(a_first) && Register(a_rest...);
		}

	protected:
		const Impl::SKSEPapyrusInterface* GetProxy() const;

	private:
		bool Register_Impl(RegFunction1* a_fn) const;
		bool Register_Impl(RegFunction2* a_fn) const;
	};


	class MessagingInterface
	{
	public:
		struct Message
		{
			const char* sender;
			UInt32		type;
			UInt32		dataLen;
			void*		data;
		};

		using EventCallback = void(Message* a_msg);

		enum
		{
			kVersion = 2
		};

		enum : UInt32
		{
			kPostLoad,
			kPostPostLoad,
			kPreLoadGame,
			kPostLoadGame,
			kSaveGame,
			kDeleteGame,
			kInputLoaded,
			kNewGame,
			kDataLoaded,

			kTotal
		};

		enum class Dispatcher : UInt32
		{
			kModEvent = 0,
			kCameraEvent,
			kCrosshairEvent,
			kActionEvent,
			kNiNodeUpdateEvent,

			kTotal
		};

		UInt32 Version() const;

		bool  Dispatch(UInt32 a_messageType, void* a_data, UInt32 a_dataLen, const char* a_receiver) const;
		void* GetEventDispatcher(Dispatcher a_dispatcherID) const;
		bool  RegisterListener(EventCallback* a_callback) const;
		bool  RegisterListener(const char* a_sender, EventCallback* a_callback) const;

	protected:
		const Impl::SKSEMessagingInterface* GetProxy() const;
	};


	class ObjectInterface
	{
	public:
		enum
		{
			kVersion = 1
		};

		UInt32 Version() const;

		SKSEDelayFunctorManager&	 GetDelayFunctorManager() const;
		SKSEObjectRegistry&			 GetObjectRegistry() const;
		SKSEPersistentObjectStorage& GetPersistentObjectStorage() const;

	private:
		const Impl::SKSEObjectInterface* GetProxy() const;
	};


	struct PluginInfo
	{
		enum
		{
			kVersion = 1
		};

		UInt32		infoVersion;
		const char* name;
		UInt32		version;
	};
}
