#include "RE/E/ExtraDataList.h"

#include "RE/B/BGSKeyword.h"
#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraAshPileRef.h"
#include "RE/E/ExtraCount.h"
#include "RE/E/ExtraEncounterZone.h"
#include "RE/E/ExtraHealth.h"
#include "RE/E/ExtraLinkedRef.h"
#include "RE/E/ExtraMissingLinkedRefIDs.h"
#include "RE/E/ExtraOwnership.h"
#include "RE/E/ExtraReferenceHandle.h"
#include "RE/E/ExtraSoul.h"
#include "RE/E/ExtraTextDisplayData.h"
#include "RE/G/GameSettingCollection.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	bool BaseExtraList::PresenceBitfield::HasType(std::uint32_t a_type) const
	{
		const std::uint32_t index = (a_type >> 3);
		if (index >= 0x18) {
			return false;
		}
		const std::uint8_t bitMask = 1 << (a_type % 8);
		return (bits[index] & bitMask) != 0;
	}

	void BaseExtraList::PresenceBitfield::MarkType(std::uint32_t a_type, bool a_cleared)
	{
		const std::uint32_t index = (a_type >> 3);
		const std::uint8_t  bitMask = 1 << (a_type % 8);
		auto&               flag = bits[index];
		if (a_cleared) {
			flag &= ~bitMask;
		} else {
			flag |= bitMask;
		}
	}

	ExtraDataList::iterator ExtraDataList::begin()
	{
		return iterator(_extraData.data);
	}

	ExtraDataList::const_iterator ExtraDataList::cbegin() const
	{
		return const_iterator(_extraData.data);
	}

	ExtraDataList::const_iterator ExtraDataList::begin() const
	{
		return cbegin();
	}

	ExtraDataList::iterator ExtraDataList::end()
	{
		return iterator(nullptr);
	}

	ExtraDataList::const_iterator ExtraDataList::cend() const
	{
		return const_iterator(nullptr);
	}

	ExtraDataList::const_iterator ExtraDataList::end() const
	{
		return cend();
	}

	bool ExtraDataList::HasType(ExtraDataType a_type) const
	{
		BSReadLockGuard locker(_lock);
		return _extraData.presence != nullptr && _extraData.presence->HasType(static_cast<std::uint32_t>(a_type));
	}

	BSExtraData* ExtraDataList::GetByType(ExtraDataType a_type)
	{
		return GetByTypeImpl(a_type);
	}

	const BSExtraData* ExtraDataList::GetByType(ExtraDataType a_type) const
	{
		return GetByTypeImpl(a_type);
	}

	bool ExtraDataList::Remove(ExtraDataType a_type, BSExtraData* a_toRemove)
	{
		BSWriteLockGuard locker(_lock);

		if (!a_toRemove) {
			return false;
		}

		bool removed = false;

		if (_extraData.data == a_toRemove) {
			_extraData.data = _extraData.data->next;
			removed = true;
		} else {
			for (auto iter = _extraData.data; iter; iter = iter->next) {
				if (iter->next == a_toRemove) {
					iter->next = a_toRemove->next;
					removed = true;
					break;
				}
			}
		}

		if (removed) {
			MarkType(a_type, true);
		}

		return removed;
	}

	bool ExtraDataList::RemoveByType(ExtraDataType a_type)
	{
		BSWriteLockGuard locker(_lock);

		if (!_extraData.data) {
			return false;
		}

		bool removed = false;

		while (_extraData.data->GetType() == a_type) {
			auto tmp = _extraData.data;
			_extraData.data = _extraData.data->next;
			delete tmp;
			removed = true;
		}

		auto prev = _extraData.data;
		for (auto cur = _extraData.data->next; cur; cur = cur->next) {
			if (cur->GetType() == a_type) {
				prev->next = cur->next;
				delete cur;
				cur = prev;
				removed = true;
			}
			prev = cur;
		}

		MarkType(a_type, true);
		return removed;
	}

	BSExtraData* ExtraDataList::Add(BSExtraData* a_toAdd)
	{
		using func_t = decltype(&ExtraDataList::Add);
		REL::Relocation<func_t> func{ Offset::ExtraDataList::Add };
		return func(this, a_toAdd);
	}

	ObjectRefHandle ExtraDataList::GetAshPileRef()
	{
		auto xAshRef = GetByType<ExtraAshPileRef>();
		return xAshRef ? xAshRef->ashPileRef : ObjectRefHandle();
	}

	std::int32_t ExtraDataList::GetCount() const
	{
		auto xCount = GetByType<ExtraCount>();
		return xCount ? xCount->count : 1;
	}

	const char* ExtraDataList::GetDisplayName(TESBoundObject* a_baseObject)
	{
		const char* result = nullptr;
		float       health = 1.0F;

		auto xHealth = GetByType<ExtraHealth>();
		if (xHealth) {
			health = xHealth->health;
		}

		auto       xText = GetExtraTextDisplayData();
		const bool dfHealth = health <= 1.0F ? (1.0F - health) < 0.001F : (health - 1.0F) < 0.001F;  // check for health == 1.0
		if (!xText && !dfHealth) {
			xText = new ExtraTextDisplayData();
			Add(xText);
		}

		if (xText) {
			result = xText->GetDisplayName(a_baseObject, health);
		} else {
			result = a_baseObject->GetName();
		}

		if (!result || result[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst ? gmst->GetSetting("sMissingName") : nullptr;
			result = sMissingName ? sMissingName->GetString() : nullptr;
		}

		return result;
	}

	BGSEncounterZone* ExtraDataList::GetEncounterZone()
	{
		auto xZone = GetByType<ExtraEncounterZone>();
		return xZone ? xZone->zone : nullptr;
	}

	ExtraTextDisplayData* ExtraDataList::GetExtraTextDisplayData()
	{
		auto                  xRef = GetByType<ExtraReferenceHandle>();
		auto                  ref = xRef ? xRef->GetOriginalReference() : nullptr;
		ExtraTextDisplayData* xText = nullptr;
		if (ref && !ref->IsDeleted()) {
			xText = ref->extraList.GetByType<ExtraTextDisplayData>();
		}

		return xText ? xText : GetByType<ExtraTextDisplayData>();
	}

	TESObjectREFR* ExtraDataList::GetLinkedRef(BGSKeyword* a_keyword)
	{
		BSReadLockGuard locker(_lock);

		auto xLinkedRef = GetByType<ExtraLinkedRef>();
		if (!xLinkedRef) {
			return nullptr;
		}

		TESObjectREFR* linkedRef = nullptr;
		for (auto& entry : xLinkedRef->linkedRefs) {
			if (entry.keyword == a_keyword) {
				linkedRef = entry.refr;
				if (!linkedRef && HasType(ExtraDataType::kEditorID)) {
					auto xMissingLinkedRefIDs = GetByType<ExtraMissingLinkedRefIDs>();
					linkedRef = xMissingLinkedRefIDs ? xMissingLinkedRefIDs->GetLinkedRef(a_keyword) : nullptr;
				}
			}

			if (linkedRef) {
				break;
			}
		}

		return linkedRef;
	}

	TESForm* ExtraDataList::GetOwner()
	{
		auto xOwner = GetByType<ExtraOwnership>();
		return xOwner ? xOwner->owner : nullptr;
	}

	SOUL_LEVEL ExtraDataList::GetSoulLevel() const
	{
		auto xSoul = GetByType<ExtraSoul>();
		return xSoul ? *xSoul->soul : SOUL_LEVEL::kNone;
	}

	void ExtraDataList::SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable)
	{
		using func_t = decltype(&ExtraDataList::SetExtraFlags);
		REL::Relocation<func_t> func{ Offset::ExtraDataList::SetExtraFlags };
		return func(this, a_flags, a_enable);
	}

	void ExtraDataList::SetInventoryChanges(InventoryChanges* a_changes)
	{
		using func_t = decltype(&ExtraDataList::SetInventoryChanges);
		REL::Relocation<func_t> func{ Offset::ExtraDataList::SetInventoryChanges };
		return func(this, a_changes);
	}

	void ExtraDataList::SetOwner(TESForm* a_owner)
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

	BSExtraData* ExtraDataList::GetByTypeImpl(ExtraDataType a_type) const
	{
		BSReadLockGuard locker(_lock);

		if (!HasType(a_type)) {
			return nullptr;
		}

		for (auto iter = _extraData.data; iter; iter = iter->next) {
			if (iter->GetType() == a_type) {
				return iter;
			}
		}

		return nullptr;
	}

	void ExtraDataList::MarkType(std::uint32_t a_type, bool a_cleared)
	{
		_extraData.presence->MarkType(a_type, a_cleared);
	}

	void ExtraDataList::MarkType(ExtraDataType a_type, bool a_cleared)
	{
		MarkType(static_cast<std::uint32_t>(a_type), a_cleared);
	}
}
