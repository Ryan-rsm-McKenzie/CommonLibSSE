#include "SKSE/Interfaces.h"

#include <cassert>

#include "RE/BSScript/Internal/VirtualMachine.h"

#include "SKSE/API.h"


namespace SKSE
{
	UInt32 QueryInterface::EditorVersion() const
	{
		return GetProxy()->editorVersion;
	}


	bool QueryInterface::IsEditor() const
	{
		return GetProxy()->isEditor;
	}


	Version QueryInterface::RuntimeVersion() const
	{
		const auto packed = GetProxy()->runtimeVersion;
		const auto major = static_cast<std::uint16_t>((packed & 0xFF000000) >> 24);
		const auto minor = static_cast<std::uint16_t>((packed & 0x00FF0000) >> 16);
		const auto revision = static_cast<std::uint16_t>((packed & 0x0000FFF0) >> 4);
		const auto build = static_cast<std::uint16_t>((packed & 0x0000000F) >> 0);
		return Version(major, minor, revision, build);
	}


	UInt32 QueryInterface::SKSEVersion() const
	{
		return GetProxy()->skseVersion;
	}


	const Impl::SKSEInterface* QueryInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSEInterface*>(this);
	}


	PluginHandle LoadInterface::GetPluginHandle() const
	{
		return GetProxy()->GetPluginHandle();
	}


	UInt32 LoadInterface::GetReleaseIndex() const
	{
		return GetProxy()->GetReleaseIndex();
	}


	void* LoadInterface::QueryInterface(InterfaceID a_id) const
	{
		return GetProxy()->QueryInterface(static_cast<UInt32>(a_id));
	}


	UInt32 ScaleformInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}


	bool ScaleformInterface::Register(RegCallback* a_callback, const char* a_name) const
	{
		auto result = GetProxy()->Register(a_name, a_callback);
		if (!result) {
			_ERROR("Failed to register %s for scaleform interface callback", a_name);
		}
		return result;
	}


	void ScaleformInterface::Register(RegInvCallback* a_callback) const
	{
		GetProxy()->RegisterForInventory(a_callback);
	}


	const Impl::SKSEScaleformInterface* ScaleformInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSEScaleformInterface*>(this);
	}


	UInt32 SerializationInterface::Version() const
	{
		return GetProxy()->version;
	}


	void SerializationInterface::SetUniqueID(UInt32 a_uid) const
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


	bool SerializationInterface::WriteRecord(UInt32 a_type, UInt32 a_version, const void* a_buf, UInt32 a_length) const
	{
		return GetProxy()->WriteRecord(a_type, a_version, a_buf, a_length);
	}


	bool SerializationInterface::OpenRecord(UInt32 a_type, UInt32 a_version) const
	{
		return GetProxy()->OpenRecord(a_type, a_version);
	}


	bool SerializationInterface::WriteRecordData(const void* a_buf, UInt32 a_length) const
	{
		return GetProxy()->WriteRecordData(a_buf, a_length);
	}


	bool SerializationInterface::GetNextRecordInfo(UInt32& a_type, UInt32& a_version, UInt32& a_length) const
	{
		return GetProxy()->GetNextRecordInfo(&a_type, &a_version, &a_length);
	}


	UInt32 SerializationInterface::ReadRecordData(void* a_buf, UInt32 a_length) const
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


	const Impl::SKSESerializationInterface* SerializationInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSESerializationInterface*>(this);
	}


	UInt32 TaskInterface::Version() const
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


	const Impl::SKSETaskInterface* TaskInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSETaskInterface*>(this);
	}


	UInt32 PapyrusInterface::Version() const
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
				_ERROR("Failed to register for papyrus interface");
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
				_ERROR("Failed to register for papyrus interface");
			}
			return result;
		}
	}


	const Impl::SKSEPapyrusInterface* PapyrusInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSEPapyrusInterface*>(this);
	}


	UInt32 MessagingInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}


	bool MessagingInterface::Dispatch(UInt32 a_messageType, void* a_data, UInt32 a_dataLen, const char* a_receiver) const
	{
		auto result = GetProxy()->Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
		if (!result) {
			_ERROR("Failed to dispatch message to %s", (a_receiver ? a_receiver : "all listeners"));
		}
		return result;
	}


	void* MessagingInterface::GetEventDispatcher(Dispatcher a_dispatcherID) const
	{
		return GetProxy()->GetEventDispatcher(static_cast<UInt32>(a_dispatcherID));
	}


	bool MessagingInterface::RegisterListener(EventCallback* a_callback) const
	{
		return RegisterListener("SKSE", a_callback);
	}


	bool MessagingInterface::RegisterListener(const char* a_sender, EventCallback* a_callback) const
	{
		auto result = GetProxy()->RegisterListener(GetPluginHandle(), a_sender, a_callback);
		if (!result) {
			_ERROR("Failed to register messaging listener for %s", a_sender);
		}
		return result;
	}


	const Impl::SKSEMessagingInterface* MessagingInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSEMessagingInterface*>(this);
	}


	UInt32 ObjectInterface::Version() const
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


	const Impl::SKSEObjectInterface* ObjectInterface::GetProxy() const
	{
		return reinterpret_cast<const Impl::SKSEObjectInterface*>(this);
	}
}
