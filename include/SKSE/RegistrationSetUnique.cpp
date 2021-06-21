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
			const auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Register(a_alias, std::move(handle), RE::BGSRefAlias::VMTYPEID);
			} else {
				return false;
			}
		}

		bool RegistrationSetUniqueBase::Register(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Register(a_activeEffect, std::move(handle), RE::ActiveEffect::VMTYPEID);
			} else {
				return false;
			}
		}

		bool RegistrationSetUniqueBase::Unregister(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Unregister(a_alias, std::move(handle), RE::BGSRefAlias::VMTYPEID);
			} else {
				return false;
			}
		}

		bool RegistrationSetUniqueBase::Unregister(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Unregister(a_activeEffect, std::move(handle), RE::ActiveEffect::VMTYPEID);
			} else {
				return false;
			}
		}

		void RegistrationSetUniqueBase::Clear()
		{
			auto   vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto   policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& [refHandle, vmHandle] : _handles) {
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

			for (auto& [refHandle, vmHandle] : _handles) {
				if (!a_intfc->WriteRecordData(refHandle)) {
					log::error("Failed to save reg ({})", refHandle);
					return false;
				}
				if (!a_intfc->WriteRecordData(vmHandle)) {
					log::error("Failed to save reg ({})", vmHandle);
					return false;
				}
			}

			return true;
		}

		bool RegistrationSetUniqueBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numHandles;
			if (!a_intfc->ReadRecordData(numHandles)) {
				log::warn("Error loading handle count");
				return false;
			}

			Locker locker(_lock);
			_handles.clear();

			RE::RefHandle refHandle;
			RE::VMHandle  vmHandle;
			for (std::size_t i = 0; i < numHandles; ++i) {
				if (!a_intfc->ReadRecordData(refHandle)) {
					log::warn("Error reading refHandle ({})", refHandle);
					return false;
				}
				a_intfc->ReadRecordData(vmHandle);
				if (!a_intfc->ResolveHandle(vmHandle, vmHandle)) {
					log::warn("Failed to resolve vmHandle ({})", vmHandle);
					return false;
				}
				auto result = _handles.insert({ refHandle, vmHandle });
				if (!result.second) {
					log::error("Loaded duplicate handle ({},{})", refHandle, vmHandle);
				}
			}

			return true;
		}

		bool RegistrationSetUniqueBase::Register(const void* a_object, RE::RefHandle a_refHandle, RE::VMTypeID a_typeID)
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
			auto result = _handles.insert({ a_refHandle, handle });
			_lock.unlock();

			if (!result.second) {
				//log::warn("Handle already registered ({})", handle);
			} else {
				policy->PersistHandle(handle);
			}
			return result.second;
		}

		bool RegistrationSetUniqueBase::Unregister(const void* a_object, RE::RefHandle a_refHandle, RE::VMTypeID a_typeID)
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
			auto   handlePair = std::pair{ a_refHandle, handle };
			auto   it = _handles.find(handlePair);
			if (it == _handles.end()) {
				//log::warn("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle((*it).second);
				_handles.erase(it);
				return true;
			}
		}
	}
}
