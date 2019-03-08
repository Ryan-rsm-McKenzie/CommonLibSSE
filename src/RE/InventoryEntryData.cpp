#include "RE/InventoryEntryData.h"

#include "skse64/GameExtraData.h"  // InventoryEntryData

#include <cstdint>  // uintptr_t

#include "RE/Offsets.h"


namespace RE
{
	InventoryEntryData::InventoryEntryData(TESForm* a_item, SInt32 a_count) :
		type(a_item),
		extraList(0),
		countDelta(a_count)
	{}


	InventoryEntryData::~InventoryEntryData()
	{
		delete extraList;
	}


	void InventoryEntryData::GetExtraWornBaseLists(BaseExtraList*& a_pWornBaseListOut, BaseExtraList*& a_pWornLeftBaseListOut)
	{
		typedef void _GetExtraWornBaseLists_t(InventoryEntryData* a_this, BaseExtraList*& a_pWornBaseListOut, BaseExtraList*& a_pWornLeftBaseListOut);
		_GetExtraWornBaseLists_t* _GetExtraWornBaseLists = reinterpret_cast<_GetExtraWornBaseLists_t*>(GetFnAddr(&::InventoryEntryData::GetExtraWornBaseLists));
		_GetExtraWornBaseLists(this, a_pWornBaseListOut, a_pWornLeftBaseListOut);
	}


	const char* InventoryEntryData::GenerateName()
	{
		typedef const char* _GenerateName_t(InventoryEntryData* a_this);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::InventoryEntryData*>(this)->_GenerateName_GetPtr());
		_GenerateName_t* _GenerateName = reinterpret_cast<_GenerateName_t*>(*ptr);
		return _GenerateName(this);
	}


	SInt32 InventoryEntryData::GetValue()
	{
		typedef SInt32 _GetValue_t(InventoryEntryData* a_this);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::InventoryEntryData*>(this)->_GetValue_GetPtr());
		_GetValue_t* _GetValue = reinterpret_cast<_GetValue_t*>(*ptr);
		return _GetValue(this);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, bool a_arg2)
	{
		typedef bool _IsOwnedBy_t(InventoryEntryData* a_this, Actor* a_actor, bool a_arg2);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::InventoryEntryData*>(this)->_IsOwnedBy_GetPtr());
		_IsOwnedBy_t* _IsOwnedBy = reinterpret_cast<_IsOwnedBy_t*>(*ptr);
		return _IsOwnedBy(this, a_actor, a_arg2);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_arg3)
	{
		typedef bool _IsOwnedBy_t(InventoryEntryData* a_this, Actor* a_actor, TESForm* a_itemOwner, bool a_arg3);
		RelocAddr<_IsOwnedBy_t*> _IsOwnedBy(INVENTORY_ENTRY_DATA_IS_OWNED_BY);
		return _IsOwnedBy(this, a_actor, a_itemOwner, a_arg3);
	}


	SoulLevel InventoryEntryData::GetSoulLevel()
	{
		typedef SoulLevel _GetSoulLevel_t(InventoryEntryData* a_this);
		std::uintptr_t* ptr = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<::InventoryEntryData*>(this)->_GetSoulLevel_GetPtr());
		_GetSoulLevel_t* _GetSoulLevel = reinterpret_cast<_GetSoulLevel_t*>(*ptr);
		return _GetSoulLevel(this);
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		typedef TESForm* _GetOwner_t(InventoryEntryData* a_this);
		RelocAddr<_GetOwner_t*> _GetOwner(INVENTORY_ENTRY_DATA_GET_OWNER);
		return _GetOwner(this);
	}


	float InventoryEntryData::GetWeight()
	{
		typedef float _GetWeight_t(InventoryEntryData* a_this);
		RelocAddr<_GetWeight_t*> _GetWeight(INVENTORY_ENTRY_DATA_GET_WEIGHT);
		return _GetWeight(this);
	}


	void InventoryEntryData::AddEntryList(BaseExtraList* a_extra)
	{
		if (!a_extra) {
			return;
		}

		if (!extraList) {
			extraList = new BSSimpleList<BaseExtraList*>;
		}
		if (extraList) {
			extraList->push_front(a_extra);
		}
	}
}
