#include "SKSE/RegistrationMapUnique.h"


namespace SKSE
{
	namespace Impl
	{
		RegistrationMapUniqueBase::RegistrationMapUniqueBase(const std::string_view& a_eventName) :
			_regs(),
			_eventName(a_eventName),
			_lock()
		{}


		RegistrationMapUniqueBase::RegistrationMapUniqueBase(const RegistrationMapUniqueBase& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			a_rhs._lock.lock();
			_regs = a_rhs._regs;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->PersistHandle(handle.second);
					}
				}
			}
		}


		RegistrationMapUniqueBase::RegistrationMapUniqueBase(RegistrationMapUniqueBase&& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();
		}


		RegistrationMapUniqueBase::~RegistrationMapUniqueBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->ReleaseHandle(handle.second);
					}
				}
			}
		}


		RegistrationMapUniqueBase& RegistrationMapUniqueBase::operator=(const RegistrationMapUniqueBase& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Clear();

			{
				Locker rhsLocker(a_rhs._lock);
				_regs = a_rhs._regs;
				_eventName = a_rhs._eventName;
			}

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->PersistHandle(handle.second);
					}
				}
			}

			return *this;
		}


		RegistrationMapUniqueBase& RegistrationMapUniqueBase::operator=(RegistrationMapUniqueBase&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);

			Clear();

			_eventName = a_rhs._eventName;

			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();

			return *this;
		}


		bool RegistrationMapUniqueBase::Register(RE::ActiveEffect* a_activeEffect, Key a_key)
		{
			assert(a_activeEffect);
			
			auto target = a_activeEffect->GetTargetActor();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Register(a_activeEffect, std::move(handle), std::move(a_key), RE::ActiveEffect::VMTYPEID);
			} else {
				return false;
			}
		}


		bool RegistrationMapUniqueBase::Register(RE::BGSRefAlias* a_alias, Key a_key)
		{
			assert(a_alias);
	
			auto target = a_alias->GetActorReference();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Register(a_alias, std::move(handle), std::move(a_key), RE::BGSRefAlias::VMTYPEID);
			} else {
				return false;
			}
		}


		bool RegistrationMapUniqueBase::Unregister(RE::ActiveEffect* a_activeEffect, Key a_key)
		{
			assert(a_activeEffect);
			
			auto target = a_activeEffect->GetTargetActor();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Unregister(a_activeEffect, std::move(handle), std::move(a_key), RE::ActiveEffect::VMTYPEID);
			} else {
				return false;
			}
		}


		bool RegistrationMapUniqueBase::Unregister(RE::BGSRefAlias* a_alias, Key a_key)
		{
			assert(a_alias);

			auto target = a_alias->GetActorReference();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				return Unregister(a_alias, std::move(handle), std::move(a_key), RE::BGSRefAlias::VMTYPEID);
			} else {
				return false;
			}
		}


		void RegistrationMapUniqueBase::UnregisterAll(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);
			
			auto target = a_activeEffect->GetTargetActor();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				UnregisterAll(a_activeEffect, std::move(handle), RE::ActiveEffect::VMTYPEID);
			}
		}


		void RegistrationMapUniqueBase::UnregisterAll(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);

			auto target = a_alias->GetActorReference();
			auto handle = target ? target->CreateRefHandle().native_handle() : 0;

			if (handle != 0) {
				UnregisterAll(a_alias, std::move(handle), RE::BGSRefAlias::VMTYPEID);
			}
		}


		void RegistrationMapUniqueBase::Clear()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->ReleaseHandle(handle.second);
					}
				}
			}
			_regs.clear();
		}


		bool RegistrationMapUniqueBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				log::error("Failed to open record!");
				return false;
			}

			return Save(a_intfc);
		}


		bool RegistrationMapUniqueBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker locker(_lock);

			// Key count
			const std::size_t numKeys = _regs.size();
			if (!a_intfc->WriteRecordData(numKeys)) {
				log::error("Failed to save key count ({})!", numKeys);
				return false;
			}
			for (auto& reg : _regs) {
				// Key
				auto key = reg.first;
				auto& [formID, match] = key;
				if (!a_intfc->WriteRecordData(formID)) {
					log::error("Failed to save reg key as formID ({})!", formID);
					return false;
				}
				if (!a_intfc->WriteRecordData(match)) {
					log::error("Failed to save reg key as bool ({})!", match);
					return false;
				}
				// Reg count
				std::size_t numRegs = reg.second.size();
				if (!a_intfc->WriteRecordData(numRegs)) {
					log::error("Failed to save number of regs ({})!", numRegs);
					return false;
				}
				// Regs
				for (auto& [refHandle, vmHandle] : reg.second) {
					if (!a_intfc->WriteRecordData(refHandle)) {
						log::error("Failed to save reg ({})", refHandle);
						return false;
					}
					if (!a_intfc->WriteRecordData(vmHandle)) {
						log::error("Failed to save reg ({})", vmHandle);
						return false;
					}
				}
			}

			return true;
		}


		bool RegistrationMapUniqueBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numKeys;
			if (!a_intfc->ReadRecordData(numKeys)) {
				log::warn("Error loading key count");
				return false;
			}

			Locker locker(_lock);
			_regs.clear();

			for (std::size_t i = 0; i < numKeys; ++i) {
				// Key
				Key curKey;
				RE::FormID formID;
				bool match;

				a_intfc->ReadRecordData(formID);
				if (!a_intfc->ResolveFormID(formID, formID)) {
					log::warn("Failed to resolve formID ({})", formID);
					return false;
				}
				a_intfc->ReadRecordData(match);

				curKey = std::pair{ formID, match };
				// Reg count
				std::size_t numRegs;
				if (!a_intfc->ReadRecordData(numRegs)) {
					log::warn("Error loading reg count or reg count is zero");
					return false;
				}
				// Regs
				RE::RefHandle refHandle;
				RE::VMHandle vmHandle;
				for (std::size_t k = 0; k < numRegs; ++k) {
					if (!a_intfc->ReadRecordData(refHandle)) {
						log::warn("Error reading refHandle ({})", refHandle);
						return false;
					}										
					a_intfc->ReadRecordData(vmHandle);
					if (!a_intfc->ResolveHandle(vmHandle, vmHandle)) {
						log::warn("Failed to resolve handle ({})", vmHandle);
						return false;
					}
					
					auto result = _regs[curKey].insert({ refHandle, vmHandle });
					if (!result.second) {
						log::error("Loaded duplicate handle ({},{})", refHandle, vmHandle);
					}
				}
			}

			return true;
		}


		bool RegistrationMapUniqueBase::Register(const void* a_object, RE::RefHandle a_refHandle, Key a_key, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle!");
				return false;
			}

			_lock.lock();
			auto result = _regs[a_key].insert({ a_refHandle, handle });
			_lock.unlock();

			if (!result.second) {
				//log::warn("Handle already registered in key : ({})", handle);
			} else {
				policy->PersistHandle(handle);
			}
			return result.second;
		}


		bool RegistrationMapUniqueBase::Unregister(const void* a_object, std::uint32_t a_refHandle, Key a_key, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle!");
				return false;
			}

			Locker locker(_lock);
			auto handlePair = std::pair{ a_refHandle, handle };
			auto it = _regs[a_key].find(handlePair);
			if (it == _regs[a_key].end()) {
				log::warn("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle((*it).second);
				_regs[a_key].erase(it);
				return true;
			}
		}


		void RegistrationMapUniqueBase::UnregisterAll(const void* a_object, std::uint32_t a_refHandle, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle!");
				return;
			}

			Locker locker(_lock);
			auto handlePair = std::pair{ a_refHandle, handle };
			for (auto i = _regs.begin(); i != _regs.end(); i++) {
				auto result = i->second.erase(handlePair);
				if (result != 0) {
					policy->ReleaseHandle(handle);
				}
			}
		}
	}
}
