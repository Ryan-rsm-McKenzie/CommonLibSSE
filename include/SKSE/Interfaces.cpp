#include "SKSE/Interfaces.h"

#include "RE/V/VirtualMachine.h"

#include "SKSE/API.h"
#include "SKSE/Logger.h"

namespace SKSE
{
	std::uint32_t QueryInterface::EditorVersion() const
	{
		return GetProxy()->editorVersion;
	}

	bool QueryInterface::IsEditor() const
	{
		return GetProxy()->isEditor;
	}

	REL::Version QueryInterface::RuntimeVersion() const
	{
		const auto packed = GetProxy()->runtimeVersion;
		const auto major = static_cast<std::uint16_t>((packed & 0xFF000000) >> 24);
		const auto minor = static_cast<std::uint16_t>((packed & 0x00FF0000) >> 16);
		const auto revision = static_cast<std::uint16_t>((packed & 0x0000FFF0) >> 4);
		const auto build = static_cast<std::uint16_t>((packed & 0x0000000F) >> 0);
		return { major, minor, revision, build };
	}

	std::uint32_t QueryInterface::SKSEVersion() const
	{
		return GetProxy()->skseVersion;
	}

	const detail::SKSEInterface* QueryInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSEInterface*>(this);
	}

	PluginHandle LoadInterface::GetPluginHandle() const
	{
		return GetProxy()->GetPluginHandle();
	}

	const PluginInfo* LoadInterface::GetPluginInfo(const char* a_name) const
	{
		return static_cast<const PluginInfo*>(GetProxy()->GetPluginInfo(a_name));
	}

	std::uint32_t LoadInterface::GetReleaseIndex() const
	{
		return GetProxy()->GetReleaseIndex();
	}

	void* LoadInterface::QueryInterface(std::uint32_t a_id) const
	{
		return GetProxy()->QueryInterface(a_id);
	}

	std::uint32_t ScaleformInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	bool ScaleformInterface::Register(RegCallback* a_callback, const char* a_name) const
	{
		auto result = GetProxy()->Register(a_name, a_callback);
		if (!result) {
			log::error("Failed to register {} for scaleform interface callback", a_name);
		}
		return result;
	}

	void ScaleformInterface::Register(RegInvCallback* a_callback) const
	{
		GetProxy()->RegisterForInventory(a_callback);
	}

	const detail::SKSEScaleformInterface* ScaleformInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSEScaleformInterface*>(this);
	}

	std::uint32_t SerializationInterface::Version() const
	{
		return GetProxy()->version;
	}

	void SerializationInterface::SetUniqueID(std::uint32_t a_uid) const
	{
		GetProxy()->SetUniqueID(GetPluginHandle(), a_uid);
	}

	void SerializationInterface::SetFormDeleteCallback(FormDeleteCallback* a_callback) const
	{
		GetProxy()->SetFormDeleteCallback(GetPluginHandle(), a_callback);
	}

	void SerializationInterface::SetLoadCallback(EventCallback* a_callback) const
	{
		GetProxy()->SetLoadCallback(GetPluginHandle(), a_callback);
	}

	void SerializationInterface::SetRevertCallback(EventCallback* a_callback) const
	{
		GetProxy()->SetRevertCallback(GetPluginHandle(), a_callback);
	}

	void SerializationInterface::SetSaveCallback(EventCallback* a_callback) const
	{
		GetProxy()->SetSaveCallback(GetPluginHandle(), a_callback);
	}

	bool SerializationInterface::WriteRecord(std::uint32_t a_type, std::uint32_t a_version, const void* a_buf, std::uint32_t a_length) const
	{
		return GetProxy()->WriteRecord(a_type, a_version, a_buf, a_length);
	}

	bool SerializationInterface::OpenRecord(std::uint32_t a_type, std::uint32_t a_version) const
	{
		return GetProxy()->OpenRecord(a_type, a_version);
	}

	bool SerializationInterface::WriteRecordData(const void* a_buf, std::uint32_t a_length) const
	{
		return GetProxy()->WriteRecordData(a_buf, a_length);
	}

	bool SerializationInterface::GetNextRecordInfo(std::uint32_t& a_type, std::uint32_t& a_version, std::uint32_t& a_length) const
	{
		return GetProxy()->GetNextRecordInfo(&a_type, &a_version, &a_length);
	}

	std::uint32_t SerializationInterface::ReadRecordData(void* a_buf, std::uint32_t a_length) const
	{
		return GetProxy()->ReadRecordData(a_buf, a_length);
	}

	bool SerializationInterface::ResolveFormID(RE::FormID a_oldFormID, RE::FormID& a_newFormID) const
	{
		return GetProxy()->ResolveFormId(a_oldFormID, &a_newFormID);
	}

	bool SerializationInterface::ResolveHandle(RE::VMHandle a_oldHandle, RE::VMHandle& a_newHandle) const
	{
		return GetProxy()->ResolveHandle(a_oldHandle, &a_newHandle);
	}

	const detail::SKSESerializationInterface* SerializationInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSESerializationInterface*>(this);
	}

	std::uint32_t TaskInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	void TaskInterface::AddTask(TaskFn a_task) const
	{
		GetProxy()->AddTask(new Task(std::move(a_task)));
	}

	void TaskInterface::AddTask(TaskDelegate* a_task) const
	{
		GetProxy()->AddTask(a_task);
	}

	void TaskInterface::AddUITask(TaskFn a_task) const
	{
		GetProxy()->AddUITask(new UITask(std::move(a_task)));
	}

	void TaskInterface::AddUITask(UIDelegate_v1* a_task) const
	{
		GetProxy()->AddUITask(a_task);
	}

	TaskInterface::Task::Task(TaskFn&& a_fn) :
		_fn(std::move(a_fn))
	{}

	void TaskInterface::Task::Run()
	{
		_fn();
	}

	void TaskInterface::Task::Dispose()
	{
		delete this;
	}

	TaskInterface::UITask::UITask(TaskFn&& a_fn) :
		_fn(std::move(a_fn))
	{}

	void TaskInterface::UITask::Run()
	{
		_fn();
	}

	void TaskInterface::UITask::Dispose()
	{
		delete this;
	}

	const detail::SKSETaskInterface* TaskInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSETaskInterface*>(this);
	}

	std::uint32_t PapyrusInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	bool PapyrusInterface::Register_Impl(RegFunction1* a_fn) const
	{
		assert(a_fn);
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (vm) {
			a_fn(vm);
			return true;
		} else {
			auto result = GetProxy()->Register(a_fn);
			if (!result) {
				log::error("Failed to register for papyrus interface");
			}
			return result;
		}
	}

	bool PapyrusInterface::Register_Impl(RegFunction2* a_fn) const
	{
		assert(a_fn);
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (vm) {
			a_fn(vm);
			return true;
		} else {
			auto result = GetProxy()->Register(a_fn);
			if (!result) {
				log::error("Failed to register for papyrus interface");
			}
			return result;
		}
	}

	const detail::SKSEPapyrusInterface* PapyrusInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSEPapyrusInterface*>(this);
	}

	std::uint32_t MessagingInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	bool MessagingInterface::Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const
	{
		auto result = GetProxy()->Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
		if (!result) {
			log::error("Failed to dispatch message to {}", (a_receiver ? a_receiver : "all listeners"));
		}
		return result;
	}

	void* MessagingInterface::GetEventDispatcher(Dispatcher a_dispatcherID) const
	{
		return GetProxy()->GetEventDispatcher(static_cast<std::uint32_t>(a_dispatcherID));
	}

	bool MessagingInterface::RegisterListener(EventCallback* a_callback) const
	{
		return RegisterListener("SKSE", a_callback);
	}

	bool MessagingInterface::RegisterListener(const char* a_sender, EventCallback* a_callback) const
	{
		auto result = GetProxy()->RegisterListener(GetPluginHandle(), a_sender, a_callback);
		if (!result) {
			log::error("Failed to register messaging listener for {}", a_sender);
		}
		return result;
	}

	const detail::SKSEMessagingInterface* MessagingInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSEMessagingInterface*>(this);
	}

	std::uint32_t ObjectInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	SKSEDelayFunctorManager& ObjectInterface::GetDelayFunctorManager() const
	{
		return GetProxy()->GetDelayFunctorManager();
	}

	SKSEObjectRegistry& ObjectInterface::GetObjectRegistry() const
	{
		return GetProxy()->GetObjectRegistry();
	}

	SKSEPersistentObjectStorage& ObjectInterface::GetPersistentObjectStorage() const
	{
		return GetProxy()->GetPersistentObjectStorage();
	}

	const detail::SKSEObjectInterface* ObjectInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSEObjectInterface*>(this);
	}

	std::uint32_t TrampolineInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	void* TrampolineInterface::AllocateFromBranchPool(std::size_t a_size) const
	{
		return GetProxy()->AllocateFromBranchPool(GetPluginHandle(), a_size);
	}

	void* TrampolineInterface::AllocateFromLocalPool(std::size_t a_size) const
	{
		return GetProxy()->AllocateFromLocalPool(GetPluginHandle(), a_size);
	}

	const detail::SKSETrampolineInterface* TrampolineInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SKSETrampolineInterface*>(this);
	}
}
