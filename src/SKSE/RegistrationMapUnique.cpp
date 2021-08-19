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

			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_activeEffect, std::move(formID), std::move(a_key), RE::ActiveEffect::VMTYPEID);
			}

			return false;
		}

		bool RegistrationMapUniqueBase::Register(RE::BGSRefAlias* a_alias, Key a_key)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Register(a_alias, std::move(formID), std::move(a_key), RE::BGSRefAlias::VMTYPEID);
			}

			return false;
		}

		bool RegistrationMapUniqueBase::Unregister(RE::ActiveEffect* a_activeEffect, Key a_key)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_activeEffect, std::move(formID), std::move(a_key), RE::ActiveEffect::VMTYPEID);
			}

			return false;
		}

		bool RegistrationMapUniqueBase::Unregister(RE::BGSRefAlias* a_alias, Key a_key)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				return Unregister(a_alias, std::move(formID), std::move(a_key), RE::BGSRefAlias::VMTYPEID);
			}

			return false;
		}

		void RegistrationMapUniqueBase::UnregisterAll(RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);

			const auto target = a_activeEffect->GetTargetActor();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				UnregisterAll(a_activeEffect, std::move(formID), RE::ActiveEffect::VMTYPEID);
			}
		}

		void RegistrationMapUniqueBase::UnregisterAll(RE::BGSRefAlias* a_alias)
		{
			assert(a_alias);

			const auto target = a_alias->GetActorReference();
			const auto formID = target ? target->GetFormID() : 0;

			if (formID != 0) {
				UnregisterAll(a_alias, std::move(formID), RE::BGSRefAlias::VMTYPEID);
			}
		}

		void RegistrationMapUniqueBase::Clear()
		{
			auto   vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto   policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
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
				for (auto& [formID, vmHandle] : reg.second) {
					if (!a_intfc->WriteRecordData(formID)) {
						log::error("Failed to save reg ({:X})", formID);
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
			a_intfc->ReadRecordData(numKeys);

			Locker locker(_lock);
			_regs.clear();

			// Key
			Key        curKey;
			RE::FormID keyFormID;
			bool       match;
			// Reg count
			std::size_t numRegs;
			// Regs
			RE::FormID   targetFormID;
			RE::VMHandle vmHandle;

			for (std::size_t i = 0; i < numKeys; ++i) {
				a_intfc->ReadRecordData(keyFormID);
				if (!a_intfc->ResolveFormID(keyFormID, keyFormID)) {
					log::warn("Failed to resolve formID ({:X})", keyFormID);
					continue;
				}
				a_intfc->ReadRecordData(match);
				curKey = std::pair{ keyFormID, match };

				a_intfc->ReadRecordData(numRegs);
				for (std::size_t k = 0; k < numRegs; ++k) {
					a_intfc->ReadRecordData(targetFormID);
					if (!a_intfc->ResolveFormID(targetFormID, targetFormID)) {
						log::warn("Error reading target formID ({:X})", targetFormID);
						continue;
					}
					a_intfc->ReadRecordData(vmHandle);
					if (!a_intfc->ResolveHandle(vmHandle, vmHandle)) {
						log::warn("Failed to resolve handle ({})", vmHandle);
						continue;
					}
					_regs[curKey].insert({ targetFormID, vmHandle });
				}
			}

			return true;
		}

		void RegistrationMapUniqueBase::Revert(SerializationInterface*)
		{
			Clear();
		}

		bool RegistrationMapUniqueBase::Register(const void* a_object, RE::FormID a_formID, Key a_key, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			auto       handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				log::error("Failed to create handle!");
				return false;
			}

			_lock.lock();
			auto result = _regs[a_key].insert({ a_formID, handle });
			_lock.unlock();

			if (result.second) {
				policy->PersistHandle(handle);
			}

			return result.second;
		}

		bool RegistrationMapUniqueBase::Unregister(const void* a_object, RE::FormID a_formID, Key a_key, RE::VMTypeID a_typeID)
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
			auto   handlePair = std::pair{ a_formID, handle };
			auto   it = _regs[a_key].find(handlePair);
			if (it == _regs[a_key].end()) {
				return false;
			} else {
				policy->ReleaseHandle((*it).second);
				_regs[a_key].erase(it);
				return true;
			}
		}

		void RegistrationMapUniqueBase::UnregisterAll(const void* a_object, RE::FormID a_formID, RE::VMTypeID a_typeID)
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
			auto   handlePair = std::pair{ a_formID, handle };
			for (auto i = _regs.begin(); i != _regs.end(); i++) {
				auto result = i->second.erase(handlePair);
				if (result != 0) {
					policy->ReleaseHandle(handle);
				}
			}
		}

		void RegistrationMapUniqueBase::UnregisterAll(RE::VMHandle a_handle)
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				log::error("Failed to get handle policy!");
				return;
			}

			Locker locker(_lock);
			for (auto i = _regs.begin(); i != _regs.end(); i++) {
				auto result = std::erase_if(i->second, [&](const auto& handlePair) { return handlePair.second == a_handle; });
				if (result != 0) {
					policy->ReleaseHandle(a_handle);
				}
			}
		}
	}
}
