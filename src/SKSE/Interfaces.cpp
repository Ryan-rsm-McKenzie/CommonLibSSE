#include "SKSE/Interfaces.h"

#include "skse64/PluginAPI.h"  // SKSEInterface, SKSEScaleformInterface, SKSESerializationInterface, SKSETaskInterface, SKSEPapyrusInterface, SKSEMessagingInterface, SKSEObjectInterface

#include "SKSE/API.h"  // GetPluginHandle


namespace SKSE
{
	void* LoadInterface::QueryInterface(InterfaceID a_id) const
	{
		return reinterpret_cast<const SKSEInterface*>(this)->QueryInterface(static_cast<UInt32>(a_id));
	}


	PluginHandle LoadInterface::GetPluginHandle() const
	{
		return reinterpret_cast<const SKSEInterface*>(this)->GetPluginHandle();
	}


	UInt32 LoadInterface::GetReleaseIndex() const
	{
		return reinterpret_cast<const SKSEInterface*>(this)->GetReleaseIndex();
	}


	bool ScaleformInterface::Register(RegCallback* a_callback, const char* a_name) const
	{
		return reinterpret_cast<const SKSEScaleformInterface*>(this)->Register(a_name, reinterpret_cast<SKSEScaleformInterface::RegisterCallback>(a_callback));
	}


	void ScaleformInterface::Register(RegInvCallback* a_callback) const
	{
		reinterpret_cast<const SKSEScaleformInterface*>(this)->RegisterForInventory(reinterpret_cast<SKSEScaleformInterface::RegisterInventoryCallback>(a_callback));
	}


	void SerializationInterface::SetUniqueID(UInt32 a_uid) const
	{
		reinterpret_cast<const SKSESerializationInterface*>(this)->SetUniqueID(GetPluginHandle(), a_uid);
	}


	void SerializationInterface::SetRevertCallback(EventCallback* a_callback) const
	{
		reinterpret_cast<const SKSESerializationInterface*>(this)->SetRevertCallback(GetPluginHandle(), reinterpret_cast<SKSESerializationInterface::EventCallback>(a_callback));
	}


	void SerializationInterface::SetSaveCallback(EventCallback* a_callback) const
	{
		reinterpret_cast<const SKSESerializationInterface*>(this)->SetSaveCallback(GetPluginHandle(), reinterpret_cast<SKSESerializationInterface::EventCallback>(a_callback));
	}


	void SerializationInterface::SetLoadCallback(EventCallback* a_callback) const
	{
		reinterpret_cast<const SKSESerializationInterface*>(this)->SetLoadCallback(GetPluginHandle(), reinterpret_cast<SKSESerializationInterface::EventCallback>(a_callback));
	}


	void SerializationInterface::SetFormDeleteCallback(FormDeleteCallback* a_callback) const
	{
		reinterpret_cast<const SKSESerializationInterface*>(this)->SetFormDeleteCallback(GetPluginHandle(), reinterpret_cast<SKSESerializationInterface::FormDeleteCallback>(a_callback));
	}


	bool SerializationInterface::WriteRecord(UInt32 a_type, UInt32 a_version, const void* a_buf, UInt32 a_length) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->WriteRecord(a_type, a_version, a_buf, a_length);
	}


	bool SerializationInterface::OpenRecord(UInt32 a_type, UInt32 a_version) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->OpenRecord(a_type, a_version);
	}


	bool SerializationInterface::WriteRecordData(const void* a_buf, UInt32 a_length) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->WriteRecordData(a_buf, a_length);
	}


	bool SerializationInterface::GetNextRecordInfo(UInt32& a_type, UInt32& a_version, UInt32& a_length) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->GetNextRecordInfo(&a_type, &a_version, &a_length);
	}


	UInt32 SerializationInterface::ReadRecordData(void* a_buf, UInt32 a_length) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->ReadRecordData(a_buf, a_length);
	}


	bool SerializationInterface::ResolveHandle(RE::VMHandle a_oldHandle, RE::VMHandle& a_newHandle) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->ResolveHandle(a_oldHandle, &a_newHandle);
	}


	bool SerializationInterface::ResolveFormID(UInt32 a_oldFormID, UInt32& a_newFormID) const
	{
		return reinterpret_cast<const SKSESerializationInterface*>(this)->ResolveFormId(a_oldFormID, &a_newFormID);
	}


	void TaskInterface::AddTask(TaskFn a_task) const
	{
		reinterpret_cast<const SKSETaskInterface*>(this)->AddTask(new Task(std::move(a_task)));
	}


	void TaskInterface::AddTask(TaskDelegate* a_task) const
	{
		reinterpret_cast<const SKSETaskInterface*>(this)->AddTask(a_task);
	}


	void TaskInterface::AddTask(UIDelegate_v1* a_task) const
	{
		reinterpret_cast<const SKSETaskInterface*>(this)->AddUITask(a_task);
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


	bool PapyrusInterface::Register(RegFunction* a_fn) const
	{
		return reinterpret_cast<const SKSEPapyrusInterface*>(this)->Register(reinterpret_cast<SKSEPapyrusInterface::RegisterFunctions>(a_fn));
	}


	bool MessagingInterface::RegisterListener(const char* a_sender, EventCallback* a_callback) const
	{
		return reinterpret_cast<const SKSEMessagingInterface*>(this)->RegisterListener(GetPluginHandle(), a_sender, reinterpret_cast<SKSEMessagingInterface::EventCallback>(a_callback));
	}


	bool MessagingInterface::Dispatch(UInt32 a_messageType, void* a_data, UInt32 a_dataLen, const char* a_receiver) const
	{
		return reinterpret_cast<const SKSEMessagingInterface*>(this)->Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
	}


	void* MessagingInterface::GetEventDispatcher(Dispatcher a_dispatcherID) const
	{
		return reinterpret_cast<const SKSEMessagingInterface*>(this)->GetEventDispatcher(static_cast<UInt32>(a_dispatcherID));
	}


	SKSEDelayFunctorManager& ObjectInterface::GetDelayFunctorManager() const
	{
		return reinterpret_cast<const SKSEObjectInterface*>(this)->GetDelayFunctorManager();
	}


	SKSEObjectRegistry& ObjectInterface::GetObjectRegistry() const
	{
		return reinterpret_cast<const SKSEObjectInterface*>(this)->GetObjectRegistry();
	}


	SKSEPersistentObjectStorage& ObjectInterface::GetPersistentObjectStorage() const
	{
		return reinterpret_cast<const SKSEObjectInterface*>(this)->GetPersistentObjectStorage();
	}
}
