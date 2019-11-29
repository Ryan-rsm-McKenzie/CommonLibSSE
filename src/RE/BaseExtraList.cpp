#include "RE/BaseExtraList.h"

#include "skse64/GameReferences.h"

#include "RE/BGSKeyword.h"
#include "RE/BSExtraData.h"
#include "RE/ExtraAshPileRef.h"
#include "RE/ExtraEncounterZone.h"
#include "RE/ExtraHealth.h"
#include "RE/ExtraLinkedRef.h"
#include "RE/ExtraMissingLinkedRefIDs.h"
#include "RE/ExtraOwnership.h"
#include "RE/ExtraReferenceHandle.h"
#include "RE/ExtraSoul.h"
#include "RE/ExtraTextDisplayData.h"
#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESForm.h"
#include "REL/Relocation.h"


namespace RE
{
	BaseExtraList::BaseExtraList() :
		_data(0),
		_presence(0),
		_lock()
	{}


	BaseExtraList::~BaseExtraList()
	{
		while (_data) {
			auto xData = _data;
			_data = xData->next;
			delete xData;
		}
		_data = 0;

		free(_presence);
		_presence = 0;
	}


	BaseExtraList::iterator BaseExtraList::begin()
	{
		return iterator(_data);
	}


	BaseExtraList::const_iterator BaseExtraList::cbegin() const
	{
		return const_iterator(_data);
	}


	BaseExtraList::const_iterator BaseExtraList::begin() const
	{
		return cbegin();
	}


	BaseExtraList::iterator BaseExtraList::end()
	{
		return iterator(0);
	}


	BaseExtraList::const_iterator BaseExtraList::cend() const
	{
		return const_iterator(0);
	}


	BaseExtraList::const_iterator BaseExtraList::end() const
	{
		return cend();
	}


	bool BaseExtraList::HasType(UInt32 a_type) const
	{
		BSReadLockGuard locker(_lock);
		return _presence ? _presence->HasType(a_type) : false;
	}


	bool BaseExtraList::HasType(ExtraDataType a_type) const
	{
		return HasType(static_cast<UInt32>(a_type));
	}


	BSExtraData* BaseExtraList::GetByType(UInt32 a_type) const
	{
		BSReadLockGuard locker(_lock);
		if (!HasType(a_type)) {
			return 0;
		}

		BSExtraData* result = 0;

		for (auto cur = _data; cur; cur = cur->next) {
			if (to_underlying(cur->GetType()) == a_type) {
				result = cur;
				break;
			}
		}

		return result;
	}


	BSExtraData* BaseExtraList::GetByType(ExtraDataType a_type) const
	{
		return GetByType(static_cast<UInt32>(a_type));
	}


	bool BaseExtraList::Remove(UInt8 a_type, BSExtraData* a_toRemove)
	{
		if (!a_toRemove) {
			return false;
		}

		bool removed = false;

		if (_data == a_toRemove) {
			_data = _data->next;
			removed = true;
		} else {
			for (auto traverse = _data; traverse; traverse = traverse->next) {
				if (traverse->next == a_toRemove) {
					traverse->next = a_toRemove->next;
					removed = true;
					break;
				}
			}
		}

		if (removed) {
			MarkType(a_type, true);
		}

		return true;
	}


	bool BaseExtraList::Remove(ExtraDataType a_type, BSExtraData* a_toRemove)
	{
		return Remove(static_cast<UInt8>(a_type), a_toRemove);
	}


	BSExtraData* BaseExtraList::Add(BSExtraData* a_toAdd)
	{
		using func_t = function_type_t<decltype(&BaseExtraList::Add)>;
		REL::Offset<func_t*> func(Offset::BaseExtraList::Add);
		return func(this, a_toAdd);
	}


	const char* BaseExtraList::GenerateName(TESForm* a_form)
	{
		const char* result = 0;
		float health = 1.0;

		auto xHealth = GetByType<ExtraHealth>();
		if (xHealth) {
			health = xHealth->health;
		}

		auto xText = GetExtraTextDisplayData();
		bool dfHealth = health <= 1.0 ? (1.0 - health) < 0.001 : (health - 1.0) < 0.001;	// check for health == 1.0
		if (!xText && !dfHealth) {
			xText = new ExtraTextDisplayData();
			Add(xText);
		}

		if (xText) {
			result = xText->GenerateName(a_form, health);
		} else {
			result = a_form->GetName();
		}

		if (!result || result[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst->GetSetting("sMissingName");
			result = sMissingName->GetString();
		}

		return result;
	}


	bool BaseExtraList::GetAshPileRefHandle(RefHandle& a_refHandle)
	{
		auto xAshRef = GetByType<ExtraAshPileRef>();
		if (xAshRef) {
			a_refHandle = xAshRef->refHandle;
		} else {
			a_refHandle = *g_invalidRefHandle;
		}
		return a_refHandle != *g_invalidRefHandle;
	}


	BGSEncounterZone* BaseExtraList::GetEncounterZone()
	{
		auto xZone = GetByType<ExtraEncounterZone>();
		return xZone ? xZone->encounterZone : 0;
	}



	ExtraTextDisplayData* BaseExtraList::GetExtraTextDisplayData()
	{
		auto xRef = GetByType<ExtraReferenceHandle>();
		if (!xRef) {
			return 0;
		}

		auto ref = xRef->GetReference();
		if (!ref || !ref->IsDeleted()) {
			return GetByType<ExtraTextDisplayData>();
		} else {
			return 0;
		}
	}


	TESObjectREFR* BaseExtraList::GetLinkedRef(BGSKeyword* a_keyword)
	{
		BSReadLockGuard locker(_lock);

		auto xLinkedRef = GetByType<ExtraLinkedRef>();
		if (!xLinkedRef) {
			return 0;
		}

		TESObjectREFR* linkedRef = 0;
		for (auto& entry : xLinkedRef->entries) {
			if (entry.keyword == a_keyword) {
				linkedRef = entry.linkedRef;
				if (!linkedRef && HasType(ExtraDataType::kEditorID)) {
					auto xMissingLinkedRefIDs = GetByType<ExtraMissingLinkedRefIDs>();
					linkedRef = xMissingLinkedRefIDs->GetLinkedRef(a_keyword);
				}
			}

			if (linkedRef) {
				break;
			}
		}

		return linkedRef;
	}


	TESForm* BaseExtraList::GetOwner()
	{
		auto xOwner = GetByType<ExtraOwnership>();
		return xOwner ? xOwner->owner : 0;
	}


	SoulLevel BaseExtraList::GetSoulLevel() const
	{
		auto xSoul = GetByType<ExtraSoul>();
		return xSoul ? xSoul->level : SoulLevel::kNone;
	}


	void BaseExtraList::SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable)
	{
		using func_t = function_type_t<decltype(&BaseExtraList::SetExtraFlags)>;
		REL::Offset<func_t*> func(Offset::BaseExtraList::SetExtraFlags);
		return func(this, a_flags, a_enable);
	}


	void BaseExtraList::SetInventoryChanges(InventoryChanges* a_changes)
	{
		using func_t = function_type_t<decltype(&BaseExtraList::SetInventoryChanges)>;
		REL::Offset<func_t*> func(Offset::BaseExtraList::SetInventoryChanges);
		return func(this, a_changes);
	}


	void BaseExtraList::SetOwner(TESForm* a_owner)
	{
		if (a_owner && a_owner->IsDynamicForm()) {
			return;
		}

		auto xOwner = GetByType<ExtraOwnership>();
		if (xOwner) {
			if (a_owner) {
				xOwner->owner = a_owner;
			} else {
				Remove(xOwner);
			}
		} else if (a_owner) {
			xOwner = new ExtraOwnership(a_owner);
			Add(xOwner);
		}
	}


	bool BaseExtraList::PresenceBitfield::HasType(UInt32 a_type) const
	{
		UInt32 index = (a_type >> 3);
		if (index >= 0x18) {
			return false;
		}
		UInt8 bitMask = 1 << (a_type % 8);
		return (bits[index] & bitMask) != 0;
	}


	void BaseExtraList::PresenceBitfield::MarkType(UInt32 a_type, bool a_cleared)
	{
		UInt32 index = (a_type >> 3);
		UInt8 bitMask = 1 << (a_type % 8);
		auto& flag = bits[index];
		if (a_cleared) {
			flag &= ~bitMask;
		} else {
			flag |= bitMask;
		}
	}


	void BaseExtraList::MarkType(UInt32 a_type, bool a_cleared)
	{
		_presence->MarkType(a_type, a_cleared);
	}


	void BaseExtraList::MarkType(ExtraDataType a_type, bool a_cleared)
	{
		MarkType(static_cast<UInt32>(a_type), a_cleared);
	}
}
