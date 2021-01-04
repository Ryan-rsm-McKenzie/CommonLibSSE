#include "SKSE/RegistrationSet.h"

#include "SKSE/Logger.h"

namespace SKSE
{
	namespace Impl
	{
		RegistrationSetBase::RegistrationSetBase(const std::string_view& a_eventName) :
			_handles(),
			_eventName(a_eventName),
			_lock()
		{}

		RegistrationSetBase::RegistrationSetBase(const RegistrationSetBase& a_rhs) :
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
				for (auto& handle : _handles) {
					policy->PersistHandle(handle);
				}
			}
		}

		RegistrationSetBase::RegistrationSetBase(RegistrationSetBase&& a_rhs) :
			_handles(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_handles = std::move(a_rhs._handles);
			a_rhs._handles.clear();
		}

		RegistrationSetBase::~RegistrationSetBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& handle : _handles) {
					policy->ReleaseHandle(handle);
				}
			}
		}

		RegistrationSetBase& RegistrationSetBase::operator=(const RegistrationSetBase& a_rhs)
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
				for (auto& handle : _handles) {
					policy->PersistHandle(handle);
				}
			}

			return *this;
		}

		RegistrationSetBase& RegistrationSetBase::operator=(RegistrationSetBase&& a_rhs)
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

		bool RegistrationSetBase::Register(const RE::TESForm* a_form)
		{
			assert(a_form);
			return Register(a_form, static_cast<RE::VMTypeID>(a_form->GetFormType()));
		}

		bool RegistrationSetBase::Register(const RE::BGSBaseAlias* a_alias)
		{
			assert(a_alias);
			return Register(a_alias, a_alias->GetVMTypeID());
		}

		bool RegistrationSetBase::Register(const RE::ActiveEffect* a_effect)
		{
			assert(a_effect);
			return Register(a_effect, RE::ActiveEffect::VMTYPEID);
		}

		bool RegistrationSetBase::Unregister(const RE::TESForm* a_form)
		{
			assert(a_form);
			return Unregister(a_form, static_cast<RE::VMTypeID>(a_form->GetFormType()));
		}

		bool RegistrationSetBase::Unregister(const RE::BGSBaseAlias* a_alias)
		{
			assert(a_alias);
			return Unregister(a_alias, a_alias->GetVMTypeID());
		}

		bool RegistrationSetBase::Unregister(const RE::ActiveEffect* a_effect)
		{
			assert(a_effect);
			return Unregister(a_effect, RE::ActiveEffect::VMTYPEID);
		}

		void RegistrationSetBase::Clear()
		{
			auto   vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto   policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& handle : _handles) {
					policy->ReleaseHandle(handle);
				}
			}
			_handles.clear();
		}

		bool RegistrationSetBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				log::error("Failed to open record");
				return false;
			}

			return Save(a_intfc);
		}

		bool RegistrationSetBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker			  locker(_lock);
			const std::size_t numRegs = _handles.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				log::error("Failed to save number of regs ({})", numRegs);
				return false;
			}

			for (auto& handle : _handles) {
				if (!a_intfc->WriteRecordData(handle)) {
					log::error("Failed to save reg ({})", handle);
					return false;
				}
			}

			return true;
		}

		bool RegistrationSetBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numRegs;
			a_intfc->ReadRecordData(numRegs);

			Locker locker(_lock);
			_handles.clear();
			RE::VMHandle handle;
			for (std::size_t i = 0; i < numRegs; ++i) {
				a_intfc->ReadRecordData(handle);
				if (!a_intfc->ResolveHandle(handle, handle)) {
					log::warn("Failed to resolve handle ({})", handle);
				} else {
					auto result = _handles.insert(handle);
					if (!result.second) {
						log::error("Loaded duplicate handle ({})", handle);
					}
				}
			}

			return true;
		}

		bool RegistrationSetBase::Register(const void* a_object, RE::VMTypeID a_typeID)
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
			auto result = _handles.insert(handle);
			_lock.unlock();

			if (!result.second) {
				log::warn("Handle already registered ({})", handle);
			} else {
				policy->PersistHandle(handle);
			}
			return result.second;
		}

		bool RegistrationSetBase::Unregister(const void* a_object, RE::VMTypeID a_typeID)
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
			auto   it = _handles.find(handle);
			if (it == _handles.end()) {
				log::warn("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle(*it);
				_handles.erase(it);
				return true;
			}
		}
	}
}
