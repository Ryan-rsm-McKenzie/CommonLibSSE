#include "SKSE/RegistrationMap.h"


namespace SKSE
{
	namespace Impl
	{
		RegistrationMapBase::RegistrationMapBase() :
			_regs(),
			_lock()
		{}


		RegistrationMapBase::RegistrationMapBase(const RegistrationMapBase& a_rhs) :
			_regs(),
			_lock()
		{
			a_rhs._lock.lock();
			_regs = a_rhs._regs;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetObjectHandlePolicy();
			for (auto& reg : _regs) {
				policy->PersistHandle(reg.first);
			}
		}


		RegistrationMapBase::RegistrationMapBase(RegistrationMapBase&& a_rhs) :
			_regs(),
			_lock()
		{
			a_rhs._lock.lock();
			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();
			a_rhs._lock.unlock();
		}


		RegistrationMapBase::~RegistrationMapBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			if (vm) {
				auto policy = vm->GetObjectHandlePolicy();
				for (auto& reg : _regs) {
					policy->ReleaseHandle(reg.first);
				}
			}
		}


		RegistrationMapBase& RegistrationMapBase::operator=(const RegistrationMapBase& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Clear();

			a_rhs._lock.lock();
			_regs = a_rhs._regs;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetObjectHandlePolicy();
			for (auto& reg : _regs) {
				policy->PersistHandle(reg.first);
			}

			return *this;
		}


		RegistrationMapBase& RegistrationMapBase::operator=(RegistrationMapBase&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);
			Clear();

			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();

			return *this;
		}


		bool RegistrationMapBase::Register(const RE::TESForm* a_form, RE::BSFixedString a_callback)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetObjectHandlePolicy();
			auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(static_cast<RE::VMTypeID>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!\n");
				return false;
			}

			policy->PersistHandle(handle);

			_lock.lock();
			auto result = _regs.insert(std::make_pair(handle, a_callback));
			_lock.unlock();

			if (!result.second) {
				_WARNING("Handle already registered (%u)", handle);
			}
			return result.second;
		}


		bool RegistrationMapBase::Unregister(const RE::TESForm* a_form)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetObjectHandlePolicy();
			auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(static_cast<RE::VMTypeID>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!\n");
				return false;
			}

			Locker locker(_lock);
			auto it = _regs.find(handle);
			if (it == _regs.end()) {
				_WARNING("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle(it->first);
				return true;
			}
		}


		void RegistrationMapBase::Clear()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetObjectHandlePolicy();
			Locker locker(_lock);
			for (auto& reg : _regs) {
				policy->ReleaseHandle(reg.first);
			}
			_regs.clear();
		}


		bool RegistrationMapBase::Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version)
		{
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				_ERROR("Failed to open record!\n");
				return false;
			}

			return Save(a_intfc);
		}


		bool RegistrationMapBase::Save(SerializationInterface* a_intfc)
		{
			Locker locker(_lock);
			std::size_t numRegs = _regs.size();
			if (!a_intfc->WriteRecordData(numRegs)) {
				_ERROR("Failed to save number of regs (%zu)!\n", numRegs);
				return false;
			}

			std::size_t size;
			for (auto& reg : _regs) {
				if (!a_intfc->WriteRecordData(reg.first)) {
					_ERROR("Failed to save reg (%u: %s)!\n", reg.first, reg.second.c_str());
					return false;
				}

				size = reg.second.size() + 1;
				if (!a_intfc->WriteRecordData(size) ||
					!a_intfc->WriteRecordData(reg.second.data(), size)) {
					_ERROR("Failed to save reg (%u: %s)!\n", reg.first, reg.second.c_str());
					return false;
				}
			}

			return true;
		}


		bool RegistrationMapBase::Load(SerializationInterface* a_intfc)
		{
			std::size_t numRegs;
			a_intfc->ReadRecordData(numRegs);

			Locker locker(_lock);
			_regs.clear();
			RE::VMHandle handle;
			std::size_t size;
			EventName evnName;
			for (std::size_t i = 0; i < numRegs; ++i) {
				a_intfc->ReadRecordData(handle);
				a_intfc->ReadRecordData(size);
				evnName.reserve(size);
				a_intfc->ReadRecordData(evnName.data(), size);
				if (!a_intfc->ResolveHandle(handle, handle)) {
					_WARNING("Failed to resolve handle (%u: %s)", handle, evnName.c_str());
				} else {
					auto result = _regs.insert(std::make_pair(handle, evnName));
					if (!result.second) {
						_ERROR("Loaded duplicate handle (%u: %s)!\n", handle, evnName.c_str());
					}
				}
			}

			return true;
		}
	}
}
