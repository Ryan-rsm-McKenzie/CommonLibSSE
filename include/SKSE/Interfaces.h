#pragma once

#include "RE/G/GFxMovieView.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/V/VirtualMachine.h"

#include "SKSE/Impl/Stubs.h"
#include "SKSE/Version.h"

namespace SKSE
{
	struct PluginInfo;

	class QueryInterface
	{
	public:
		[[nodiscard]] std::uint32_t EditorVersion() const;
		[[nodiscard]] bool          IsEditor() const;
		[[nodiscard]] REL::Version  RuntimeVersion() const;
		[[nodiscard]] std::uint32_t SKSEVersion() const;

	protected:
		[[nodiscard]] const detail::SKSEInterface* GetProxy() const;
	};

	class LoadInterface : public QueryInterface
	{
	public:
		enum : std::uint32_t
		{
			kInvalid = 0,
			kScaleform,
			kPapyrus,
			kSerialization,
			kTask,
			kMessaging,
			kObject,
			kTrampoline,
			kTotal
		};

		[[nodiscard]] PluginHandle  GetPluginHandle() const;
		const PluginInfo*           GetPluginInfo(const char* a_name) const;
		[[nodiscard]] std::uint32_t GetReleaseIndex() const;
		[[nodiscard]] void*         QueryInterface(std::uint32_t a_id) const;
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

		[[nodiscard]] std::uint32_t Version() const;

		bool Register(RegCallback* a_callback, const char* a_name) const;
		void Register(RegInvCallback* a_callback) const;

	protected:
		[[nodiscard]] const detail::SKSEScaleformInterface* GetProxy() const;
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

		[[nodiscard]] std::uint32_t Version() const;

		void SetUniqueID(std::uint32_t a_uid) const;

		void SetFormDeleteCallback(FormDeleteCallback* a_callback) const;
		void SetLoadCallback(EventCallback* a_callback) const;
		void SetRevertCallback(EventCallback* a_callback) const;
		void SetSaveCallback(EventCallback* a_callback) const;

		bool WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const void* a_buf, std::uint32_t a_length) const;

		template <
			class T,
			std::enable_if_t<
				std::negation_v<
					std::is_pointer<T>>,
				int> = 0>
		inline std::uint32_t WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const T& a_buf) const
		{
			return WriteRecord(a_type, a_version, std::addressof(a_buf), sizeof(T));
		}

		template <
			class T,
			std::size_t N,
			std::enable_if_t<
				std::is_array_v<T>,
				int> = 0>
		inline std::uint32_t WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const T (&a_buf)[N]) const
		{
			return WriteRecord(a_type, a_version, std::addressof(a_buf), sizeof(T) * N);
		}

		[[nodiscard]] bool OpenRecord(std::uint32_t a_type, std::uint32_t a_version) const;

		bool WriteRecordData(const void* a_buf, std::uint32_t a_length) const;

		template <
			class T,
			std::enable_if_t<
				std::negation_v<
					std::is_pointer<T>>,
				int> = 0>
		inline std::uint32_t WriteRecordData(const T& a_buf) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T));
		}

		template <
			class T,
			std::size_t N,
			std::enable_if_t<
				std::is_array_v<T>,
				int> = 0>
		inline std::uint32_t WriteRecordData(const T (&a_buf)[N]) const
		{
			return WriteRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		bool GetNextRecordInfo(std::uint32_t& a_type, std::uint32_t& a_version, std::uint32_t& a_length) const;

		std::uint32_t ReadRecordData(void* a_buf, std::uint32_t a_length) const;

		template <
			class T,
			std::enable_if_t<
				std::negation_v<
					std::is_pointer<T>>,
				int> = 0>
		inline std::uint32_t ReadRecordData(T& a_buf) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T));
		}

		template <
			class T,
			std::size_t N,
			std::enable_if_t<
				std::is_array_v<T>,
				int> = 0>
		inline std::uint32_t ReadRecordData(T (&a_buf)[N]) const
		{
			return ReadRecordData(std::addressof(a_buf), sizeof(T) * N);
		}

		bool ResolveFormID(RE::FormID a_oldFormID, RE::FormID& a_newFormID) const;
		bool ResolveHandle(RE::VMHandle a_oldHandle, RE::VMHandle& a_newHandle) const;

	protected:
		[[nodiscard]] const detail::SKSESerializationInterface* GetProxy() const;
	};

	class TaskInterface
	{
	public:
		using TaskFn = std::function<void()>;

		enum
		{
			kVersion = 2
		};

		[[nodiscard]] std::uint32_t Version() const;

		void AddTask(TaskFn a_task) const;
		void AddTask(TaskDelegate* a_task) const;
		void AddUITask(TaskFn a_task) const;
		void AddUITask(UIDelegate_v1* a_task) const;

	protected:
		class Task : public detail::TaskDelegate
		{
		public:
			Task(TaskFn&& a_fn);

			void Run() override;
			void Dispose() override;

		private:
			TaskFn _fn;
		};

		class UITask : public detail::UIDelegate_v1
		{
		public:
			UITask(TaskFn&& a_fn);

			void Run() override;
			void Dispose() override;

		private:
			TaskFn _fn;
		};

		[[nodiscard]] const detail::SKSETaskInterface* GetProxy() const;
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

		[[nodiscard]] std::uint32_t Version() const;

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
		[[nodiscard]] const detail::SKSEPapyrusInterface* GetProxy() const;

	private:
		bool Register_Impl(RegFunction1* a_fn) const;
		bool Register_Impl(RegFunction2* a_fn) const;
	};

	class MessagingInterface
	{
	public:
		struct Message
		{
			const char*   sender;
			std::uint32_t type;
			std::uint32_t dataLen;
			void*         data;
		};

		using EventCallback = void(Message* a_msg);

		enum
		{
			kVersion = 2
		};

		enum : std::uint32_t
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

		enum class Dispatcher : std::uint32_t
		{
			kModEvent = 0,
			kCameraEvent,
			kCrosshairEvent,
			kActionEvent,
			kNiNodeUpdateEvent,

			kTotal
		};

		[[nodiscard]] std::uint32_t Version() const;

		bool                Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const;
		[[nodiscard]] void* GetEventDispatcher(Dispatcher a_dispatcherID) const;
		bool                RegisterListener(EventCallback* a_callback) const;
		bool                RegisterListener(const char* a_sender, EventCallback* a_callback) const;

	protected:
		[[nodiscard]] const detail::SKSEMessagingInterface* GetProxy() const;
	};

	class ObjectInterface
	{
	public:
		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const;

		[[nodiscard]] SKSEDelayFunctorManager&     GetDelayFunctorManager() const;
		[[nodiscard]] SKSEObjectRegistry&          GetObjectRegistry() const;
		[[nodiscard]] SKSEPersistentObjectStorage& GetPersistentObjectStorage() const;

	private:
		[[nodiscard]] const detail::SKSEObjectInterface* GetProxy() const;
	};

	class TrampolineInterface
	{
	public:
		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const;

		[[nodiscard]] void* AllocateFromBranchPool(std::size_t a_size) const;
		[[nodiscard]] void* AllocateFromLocalPool(std::size_t a_size) const;

	private:
		[[nodiscard]] const detail::SKSETrampolineInterface* GetProxy() const;
	};

	struct PluginInfo
	{
		enum
		{
			kVersion = 1
		};

		std::uint32_t infoVersion;
		const char*   name;
		std::uint32_t version;
	};

	struct PluginVersionData
	{
	public:
		enum
		{
			kVersion = 1,
		};

		constexpr void AuthorEmail(std::string_view a_email) noexcept { SetCharBuffer(a_email, std::span{ supportEmail }); }
		constexpr void AuthorName(std::string_view a_name) noexcept { SetCharBuffer(a_name, std::span{ author }); }

		constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
		{
			assert(a_versions.size() < std::size(compatibleVersions) - 1);
			std::transform(
				a_versions.begin(),
				a_versions.end(),
				std::begin(compatibleVersions),
				[](const REL::Version& a_version) noexcept { return a_version.pack(); });
		}

		constexpr void MinimumRequiredXSEVersion(REL::Version a_version) noexcept { xseMinimum = a_version.pack(); }
		constexpr void PluginName(std::string_view a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }
		constexpr void PluginVersion(REL::Version a_version) noexcept { pluginVersion = a_version.pack(); }
		constexpr void HasNoStructUse(bool a_value) noexcept { noStructUse = a_value; }
		constexpr void UsesAddressLibrary(bool a_value) noexcept { addressLibrary = a_value; }
		constexpr void UsesSigScanning(bool a_value) noexcept { sigScanning = a_value; }
		constexpr void UsesStructsPost629(bool a_value) noexcept { structsPost629 = a_value; }

		const std::uint32_t dataVersion{ kVersion };
		std::uint32_t       pluginVersion = 0;
		char                pluginName[256] = {};
		char                author[256] = {};
		char                supportEmail[252] = {};
		bool                noStructUse: 1 = false;
		std::uint8_t        padding1: 7 = 0;
		std::uint8_t        padding2 = 0;
		std::uint16_t       padding3 = 0;
		bool                addressLibrary: 1 = false;
		bool                sigScanning: 1 = false;
		bool                structsPost629: 1 = true;
		std::uint8_t        padding4: 5 = 0;
		std::uint8_t        padding5 = 0;
		std::uint16_t       padding6 = 0;
		std::uint32_t       compatibleVersions[16] = {};
		std::uint32_t       xseMinimum = 0;

	private:
		static constexpr void SetCharBuffer(
			std::string_view a_src,
			std::span<char>  a_dst) noexcept
		{
			assert(a_src.size() < a_dst.size());
			std::fill(a_dst.begin(), a_dst.end(), '\0');
			std::copy(a_src.begin(), a_src.end(), a_dst.begin());
		}
	};
	static_assert(offsetof(PluginVersionData, dataVersion) == 0x000);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x004);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x008);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, supportEmail) == 0x208);
	static_assert(offsetof(PluginVersionData, padding2) == 0x305);
	static_assert(offsetof(PluginVersionData, padding3) == 0x306);
	static_assert(offsetof(PluginVersionData, padding5) == 0x309);
	static_assert(offsetof(PluginVersionData, padding6) == 0x30A);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x30C);
	static_assert(offsetof(PluginVersionData, xseMinimum) == 0x34C);
	static_assert(sizeof(PluginVersionData) == 0x350);
}
