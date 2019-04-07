#include "SKSE/RegistrationSet.h"

#include "skse64/PapyrusVM.h"  // g_skyrimVM


namespace SKSE
{
	namespace Impl
	{
		RegistrationSetBase::RegistrationSetBase(const char* a_eventName) :
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

			auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			for (auto& handle : _handles) {
				policy->AddRef(handle);
			}
		}


		RegistrationSetBase::RegistrationSetBase(RegistrationSetBase&& a_rhs) :
			_handles(std::move(a_rhs._handles)),
			_eventName(std::move(a_rhs._eventName)),
			_lock()
		{
			a_rhs._handles.clear();
		}


		RegistrationSetBase::~RegistrationSetBase()
		{
			if (g_skyrimVM.GetPtr()) {
				auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
				for (auto& handle : _handles) {
					policy->Release(handle);
				}
			}
		}


		RegistrationSetBase& RegistrationSetBase::operator=(const RegistrationSetBase& a_rhs)
		{
			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);
			Clear();
			_eventName = a_rhs._eventName;

			auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			for (auto& handle : a_rhs._handles) {
				policy->AddRef(handle);
				_handles.insert(handle);
			}

			return *this;
		}


		RegistrationSetBase& RegistrationSetBase::operator=(RegistrationSetBase&& a_rhs)
		{
			Locker lhsLocker(_lock);
			Clear();
			_eventName = std::move(a_rhs._eventName);
			_handles = std::move(a_rhs._handles);
			a_rhs._handles.clear();

			return *this;
		}


		bool RegistrationSetBase::Register(RE::TESForm* a_form)
		{
			auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			auto invalidHandle = policy->GetInvalidHandle();
			auto handle = policy->Create(static_cast<UInt32>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("[ERROR] Failed to create handle!\n");
				return false;
			}

			_lock.lock();
			auto result = _handles.insert(handle);
			_lock.unlock();
			if (!result.second) {
				_ERROR("[ERROR] Handle already registered!\n");
			}
			return result.second;
		}


		bool RegistrationSetBase::Unregister(RE::TESForm* a_form)
		{
			auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			auto invalidHandle = policy->GetInvalidHandle();
			auto handle = policy->Create(static_cast<UInt32>(a_form->formType), a_form);
			if (handle == invalidHandle) {
				_ERROR("[ERROR] Failed to create handle!\n");
				return false;
			} else {
				policy->Release(handle);
			}

			Locker locker(_lock);
			auto result = _handles.find(handle);
			if (result == _handles.end()) {
				_ERROR("[ERROR] Could not find registration");
				return false;
			} else {
				policy->Release(handle);
				return true;
			}
		}


		void RegistrationSetBase::Clear()
		{
			auto policy = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			Locker locker(_lock);
			for (auto& handle : _handles) {
				policy->Release(handle);
			}
			_handles.clear();
		}


		bool RegistrationSetBase::Save(SKSESerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version)
		{
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				_ERROR("[ERROR] Failed to open record!\n");
				return false;
			}

			Locker locker(_lock);
			std::size_t numRegs = _handles.size();
			if (!a_intfc->WriteRecordData(&numRegs, sizeof(numRegs))) {
				_ERROR("[ERROR] Failed to save number of regs (%zu)!\n", numRegs);
				return false;
			}

			for (auto& handle : _handles) {
				if (!a_intfc->WriteRecordData(&handle, sizeof(handle))) {
					_ERROR("[ERROR] Failed to save reg (%u)!\n", handle);
					return false;
				}
			}

			return true;
		}


		bool RegistrationSetBase::Load(SKSESerializationInterface* a_intfc)
		{
			std::size_t numRegs;
			a_intfc->ReadRecordData(&numRegs, sizeof(numRegs));

			RE::VMHandle handle;
			for (std::size_t i = 0; i < numRegs; ++i) {
				a_intfc->ReadRecordData(&handle, sizeof(handle));
				if (!a_intfc->ResolveHandle(handle, &handle)) {
					_ERROR("[ERROR] Failed to resolve handle (%u)!\n", handle);
				} else {
					auto result = _handles.insert(handle);
					if (!result.second) {
						_ERROR("[ERROR] Loaded duplicate handle (%u)!\n", handle);
					}
				}
			}

			return true;
		}
	}
}
