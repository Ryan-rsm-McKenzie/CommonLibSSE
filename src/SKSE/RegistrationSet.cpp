#include "SKSE/RegistrationSet.h"

#include <cassert>


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
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				_ERROR("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_form->GetFormType(), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!");
				return false;
			}

			_lock.lock();
			auto result = _handles.insert(handle);
			_lock.unlock();

			if (!result.second) {
				_WARNING("Handle already registered (%u)", handle);
			} else {
				policy->PersistHandle(handle);
			}
			return result.second;
		}


		bool RegistrationSetBase::Unregister(const RE::TESForm* a_form)
		{
			assert(a_form);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				_ERROR("Failed to get handle policy!");
				return false;
			}

			auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(a_form->GetFormType(), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!");
				return false;
			}

			Locker locker(_lock);
			auto it = _handles.find(handle);
			if (it == _handles.end()) {
				_WARNING("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle(*it);
				_handles.erase(it);
				return true;
			}
		}


		void RegistrationSetBase::Clear()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& handle : _handles) {
					policy->ReleaseHandle(handle);
				}
			}
			_handles.clear();
		}


		bool RegistrationSetBase::Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				_ERROR("Failed to open record!");
				return false;
			}

			return Save(a_intfc);
		}


		bool RegistrationSetBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker locker(_lock);
			const std::size_t numRegs = _handles.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				_ERROR("Failed to save number of regs (%zu)!", numRegs);
				return false;
			}

			for (auto& handle : _handles) {
				if (!a_intfc->WriteRecordData(handle)) {
					_ERROR("Failed to save reg (%u)!", handle);
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
					_WARNING("Failed to resolve handle (%u)", handle);
				} else {
					auto result = _handles.insert(handle);
					if (!result.second) {
						_ERROR("Loaded duplicate handle (%u)!\n", handle);
					}
				}
			}

			return true;
		}
	}
}
