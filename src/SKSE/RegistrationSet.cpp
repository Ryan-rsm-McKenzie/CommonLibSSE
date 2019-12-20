#include "SKSE/RegistrationSet.h"


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
			auto policy = vm->GetHandlePolicy();
			for (auto& handle : _handles) {
				policy->AddRef(handle);
			}
		}


		RegistrationSetBase::RegistrationSetBase(RegistrationSetBase&& a_rhs) :
			_handles(std::move(a_rhs._handles)),
			_eventName(a_rhs._eventName),
			_lock()
		{
			a_rhs._lock.lock();
			_handles = std::move(a_rhs._handles);
			a_rhs._handles.clear();
			a_rhs._lock.unlock();
		}


		RegistrationSetBase::~RegistrationSetBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			if (vm) {
				auto policy = vm->GetHandlePolicy();
				for (auto& handle : _handles) {
					policy->Release(handle);
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

			a_rhs._lock.lock();
			_handles = a_rhs._handles;
			_eventName = a_rhs._eventName;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetHandlePolicy();
			for (auto& handle : _handles) {
				policy->AddRef(handle);
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


		bool RegistrationSetBase::Register(RE::TESForm* a_form)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetHandlePolicy();
			auto invalidHandle = policy->GetInvalidHandle();
			auto handle = policy->GetHandle(static_cast<RE::FormType32>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!\n");
				return false;
			}

			policy->AddRef(handle);

			_lock.lock();
			auto result = _handles.insert(handle);
			_lock.unlock();

			if (!result.second) {
				_WARNING("Handle already registered (%u)", handle);
			}
			return result.second;
		}


		bool RegistrationSetBase::Unregister(RE::TESForm* a_form)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetHandlePolicy();
			auto invalidHandle = policy->GetInvalidHandle();
			auto handle = policy->GetHandle(static_cast<RE::FormType32>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!\n");
				return false;
			}

			Locker locker(_lock);
			auto it = _handles.find(handle);
			if (it == _handles.end()) {
				_WARNING("Could not find registration");
				return false;
			} else {
				policy->Release(*it);
				return true;
			}
		}


		void RegistrationSetBase::Clear()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetHandlePolicy();
			Locker locker(_lock);
			for (auto& handle : _handles) {
				policy->Release(handle);
			}
			_handles.clear();
		}


		bool RegistrationSetBase::Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version)
		{
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				_ERROR("Failed to open record!\n");
				return false;
			}

			return Save(a_intfc);
		}


		bool RegistrationSetBase::Save(SerializationInterface* a_intfc)
		{
			Locker locker(_lock);
			std::size_t numRegs = _handles.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				_ERROR("Failed to save number of regs (%zu)!\n", numRegs);
				return false;
			}

			for (auto& handle : _handles) {
				if (!a_intfc->WriteRecordData(handle)) {
					_ERROR("Failed to save reg (%u)!\n", handle);
					return false;
				}
			}

			return true;
		}


		bool RegistrationSetBase::Load(SerializationInterface* a_intfc)
		{
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
