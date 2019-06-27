#include "RE/InventoryEntryData.h"

#include "skse64/GameExtraData.h"  // InventoryEntryData

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	InventoryEntryData::InventoryEntryData(TESBoundObject* a_item, SInt32 a_count) :
		type(a_item),
		extraList(0),
		countDelta(a_count)
	{}


	InventoryEntryData::~InventoryEntryData()
	{
		delete extraList;
	}


	void InventoryEntryData::GetExtraWornBaseLists(BaseExtraList*& a_wornBaseListOut, BaseExtraList*& a_wornLeftBaseListOut)
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetExtraWornBaseLists)>;
		func_t* func = unrestricted_cast<func_t*>(&::InventoryEntryData::GetExtraWornBaseLists);
		return func(this, a_wornBaseListOut, a_wornLeftBaseListOut);
	}


	const char* InventoryEntryData::GenerateName()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GenerateName)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::InventoryEntryData, GenerateName, func_t*);
		return func(this);
	}


	SInt32 InventoryEntryData::GetValue()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetValue)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::InventoryEntryData, GetValue, func_t*);
		return func(this);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, bool a_defaultTo)
	{
		return IsOwnedBy_Internal1(a_actor, a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		return IsOwnedBy_Internal2(a_actor, a_itemOwner, a_defaultTo);
	}


	SoulLevel InventoryEntryData::GetSoulLevel()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetSoulLevel)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::InventoryEntryData, GetSoulLevel, func_t*);
		return func(this);
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetOwner)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::GetOwner);
		return func(this);
	}


	float InventoryEntryData::GetWeight()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetWeight)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::GetWeight);
		return func(this);
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


	bool InventoryEntryData::IsOwnedBy_Internal1(Actor* a_actor, bool a_defaultTo)
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::IsOwnedBy_Internal1)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::InventoryEntryData, IsOwnedBy, func_t*);
		return func(this, a_actor, a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy_Internal2(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::IsOwnedBy_Internal2)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::IsOwnedBy);
		return func(this, a_actor, a_itemOwner, a_defaultTo);
	}
}
