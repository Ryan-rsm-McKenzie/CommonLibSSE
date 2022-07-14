#include "SKSE/RegistrationSetUnique.h"

#include "SKSE/Logger.h"

namespace SKSE
{
	namespace Impl
	{
		RegistrationSetUniqueBase::RegistrationSetUniqueBase(const std::string_view& a_eventName) :
			_handles(),
			_eventName(a_eventName),
			_lock()
		{}

		RegistrationSetUniqueBase::RegistrationSetUniqueBase(const RegistrationSetUniqueBase& a_rhs) :
			_handles(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			a_rhs._lock.lock();
			_handles = a_rhs._handles;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [refHandle, vmHandle] : _handles) {
					policy->PersistHandle(vmHandle);
				}
			}
		}

		RegistrationSetUniqueBase::RegistrationSetUniqueBase(RegistrationSetUniqueBase&& a_rhs) :
			_handles(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_handles = std::move(a_rhs._handles);
			a_rhs._handles.clear();
		}

		RegistrationSetUniqueBase::~RegistrationSetUniqueBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [refHandle, vmHandle] : _handles) {
					policy->ReleaseHandle(vmHandle);
				}
			}
		}

		RegistrationSetUniqueBase& RegistrationSetUniqueBase::operator=(const RegistrationSetUniqueBase& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Clear();

			{
				Locker rhsLocker(a_rhs._lock);
				_handles = a_rhs._handles;
				_eventName = a_rhs._eventName;
			}

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [refHandle, vmHandle] : _handles) {
					policy->PersistHandle(vmHandle);
				}
			}

			return *this;
		}

		RegistrationSetUniqueBase& RegistrationSetUniqueBase::operator=(RegistrationSetUniqueBase&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);

			Clear();

			_eventName = a_rhs._eventName;

			_handles = std::move(a_rhs._handles);
			a_rhs._handles.clear();

			return *this;
		}

		bool RegistrationSetUniqueBase::Register(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_alias, std::move(formID), RE::BGSRefAlias::VMTYPEID);
			}

			return false;
		}

		bool RegistrationSetUniqueBase::Register(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_activeEffect, std::move(formID), RE::ActiveEffect::VMTYPEID);
			}

			return false;
		}

		bool RegistrationSetUniqueBase::Unregister(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_alias, std::move(formID), RE::BGSRefAlias::VMTYPEID);
			}

			return false;
		}

		bool RegistrationSetUniqueBase::Unregister(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_activeEffect, std::move(formID), RE::ActiveEffect::VMTYPEID);
			}

			return false;
		}

		void RegistrationSetUniqueBase::Clear()
		{
			auto   vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto   policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& [formID, vmHandle] : _handles) {
					policy->ReleaseHandle(vmHandle);
				}
			}
			_handles.clear();
		}

		bool RegistrationSetUniqueBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				log::error("Failed to open record");
				return false;
			}

			return Save(a_intfc);
		}

		bool RegistrationSetUniqueBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);

			Locker            locker(_lock);
			const std::size_t numHandles = _handles.size();
			if (!a_intfc->WriteRecordData(numHandles)) {
				log::error("Failed to save number of handles ({})", numHandles);
				return false;
			}

			for (auto& [formID, vmHandle] : _handles) {
				if (!a_intfc->WriteRecordData(formID)) {
					log::error("Failed to save reg formID ({:X})", formID);
					return false;
				}
				if (!a_intfc->WriteRecordData(vmHandle)) {
					log::error("Failed to save reg handle ({})", vmHandle);
					return false;
				}
			}

			return true;
		}

		bool RegistrationSetUniqueBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numHandles;
			a_intfc->ReadRecordData(numHandles);

			Locker locker(_lock);
			_handles.clear();

			RE::FormID   formID;
			RE::VMHandle vmHandle;
			for (std::size_t i = 0; i < numHandles; ++i) {
				a_intfc->ReadRecordData(formID);
				if (!a_intfc->ResolveFormID(formID, formID)) {
					log::warn("Error reading formID ({:X})", formID);
					continue;
				}
				a_intfc->ReadRecordData(vmHandle);
				if (!a_intfc->ResolveHandle(vmHandle, vmHandle)) {
					log::warn("Failed to resolve vmHandle ({})", vmHandle);
					continue;
				}
				_handles.insert({ formID, vmHandle });
			}

			return true;
		}

		void RegistrationSetUniqueBase::Revert(SerializationInterface*)
		{
			Clear();
		}

		bool RegistrationSetUniqueBase::Register(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle");
				return false;
			}

			_lock.lock();
			auto result = _handles.insert({ a_formID, handle });
			_lock.unlock();

			if (result.second) {
				policy->PersistHandle(handle);
			}

			return result.second;
		}

		bool RegistrationSetUniqueBase::Unregister(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return false;
			}

			auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle!");
				return false;
			}

			Locker locker(_lock);
			auto   handlePair = std::pair{ a_formID, handle };
			auto   it = _handles.find(handlePair);
			if (it == _handles.end()) {
				return false;
			} else {
				policy->ReleaseHandle((*it).second);
				_handles.erase(it);
				return true;
			}
		}

		bool RegistrationSetUniqueBase::Unregister(RE::VMHandle a_handle)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return false;
			}

			Locker locker(_lock);
			auto   it = std::ranges::find_if(_handles, [&](const auto& handlePair) { return handlePair.second == a_handle; });
			if (it == _handles.end()) {
				return false;
			} else {
				policy->ReleaseHandle((*it).second);
				_handles.erase(it);
				return true;
			}
		}
	}
}
