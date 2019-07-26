#include "RE/BaseExtraList.h"

#include "skse64/GameReferences.h"  // g_invalidRefHandle

#include "RE/BGSKeyword.h"  // BGSKeyword
#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraAshPileRef.h"  // ExtraAshPileRef
#include "RE/ExtraLinkedRef.h"  // ExtraLinkedRef
#include "RE/ExtraMissingLinkedRefIDs.h"  // ExtraMissingLinkedRefIDs
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFR
#include "REL/Relocation.h"


namespace RE
{
	BaseExtraList::const_iterator::const_iterator(const BSExtraData* a_extra) :
		_cur(const_cast<BSExtraData*>(a_extra))
	{}


	BaseExtraList::const_iterator::operator pointer() const
	{
		return _cur;
	}


	BaseExtraList::const_iterator::operator bool() const
	{
		return !empty();
	}


	BaseExtraList::const_iterator::reference BaseExtraList::const_iterator::operator*() const
	{
		return *_cur;
	}


	BaseExtraList::const_iterator::pointer BaseExtraList::const_iterator::operator->() const
	{
		return _cur;
	}


	BaseExtraList::const_iterator::_iter& BaseExtraList::const_iterator::operator++()
	{
		_cur = _cur->next;
		return *this;
	}


	BaseExtraList::const_iterator::_iter BaseExtraList::const_iterator::operator++(int)
	{
		_iter tmp = *this;
		operator++();
		return tmp;
	}


	bool BaseExtraList::const_iterator::operator==(const _iter& a_rhs) const
	{
		return (_cur == a_rhs._cur);
	}


	bool BaseExtraList::const_iterator::operator!=(const _iter& a_rhs) const
	{
		return (!(*this == a_rhs));
	}


	bool BaseExtraList::const_iterator::empty() const
	{
		return _cur == nullptr;
	}


	BaseExtraList::iterator::iterator(BSExtraData* a_extra) :
		BaseExtraList::const_iterator(a_extra)
	{}


	BaseExtraList::iterator::operator pointer() const
	{
		return _cur;
	}


	BaseExtraList::iterator::pointer BaseExtraList::iterator::operator*() const
	{
		return _cur;
	}


	BaseExtraList::iterator::pointer BaseExtraList::iterator::operator->() const
	{
		return _cur;
	}

	BaseExtraList::iterator::_iter& BaseExtraList::iterator::operator++()
	{
		_cur = _cur->next;
		return *this;
	}


	BaseExtraList::iterator::_iter BaseExtraList::iterator::operator++(int)
	{
		_iter tmp = *this;
		operator++();
		return tmp;
	}


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
		UInt8& flag = bits[index];
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
		MarkType((UInt32)a_type, a_cleared);
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


	void BaseExtraList::SetInventoryChanges(InventoryChanges* a_changes)
	{
		using func_t = function_type_t<decltype(&BaseExtraList::SetInventoryChanges)>;
		REL::Offset<func_t*> func(Offset::BaseExtraList::SetInventoryChanges);
		return func(this, a_changes);
	}


	void BaseExtraList::SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable)
	{
		using func_t = function_type_t<decltype(&BaseExtraList::SetExtraFlags)>;
		REL::Offset<func_t*> func(Offset::BaseExtraList::SetExtraFlags);
		return func(this, a_flags, a_enable);
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
}
