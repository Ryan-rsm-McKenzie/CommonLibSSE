#include "RE/InventoryEntryData.h"

#include "RE/BaseExtraList.h"
#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/TESBoundObject.h"
#include "RE/TESSoulGem.h"
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


	void InventoryEntryData::AddEntryList(BaseExtraList* a_extra)
	{
		if (!a_extra) {
			return;
		}

		if (!extraList) {
			extraList = new BSSimpleList<BaseExtraList*>;
		}

		extraList->push_front(a_extra);
	}


	const char* InventoryEntryData::GenerateName()
	{
		if (extraList && !extraList->empty()) {
			return extraList->front()->GenerateName(type);
		} else {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst->GetSetting("sMissingName");
			return sMissingName->GetString();
		}
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		if (extraList && !extraList->empty()) {
			return extraList->front()->GetOwner();
		} else {
			return 0;
		}
	}


	SoulLevel InventoryEntryData::GetSoulLevel() const
	{
		if (extraList && !extraList->empty()) {
			auto lvl = extraList->front()->GetSoulLevel();
			if (lvl > SoulLevel::kNone) {
				return lvl;
			}
		}

		if (type && type->Is(FormType::SoulGem)) {
			auto soulGem = static_cast<const TESSoulGem*>(type);
			return soulGem->GetContainedSoul();
		}

		return SoulLevel::kNone;
	}


	SInt32 InventoryEntryData::GetValue()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetValue)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::GetValue);
		return func(this);
	}


	float InventoryEntryData::GetWeight()
	{
		return type ? type->GetWeight() : -1.0;
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, bool a_defaultTo)
	{
		return IsOwnedBy(a_actor, GetOwner(), a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		return IsOwnedBy_Impl(a_actor, a_itemOwner, a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy_Impl(Actor* a_actor, TESForm* a_itemOwner, bool a_defaultTo)
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::IsOwnedBy_Impl)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::IsOwnedBy);
		return func(this, a_actor, a_itemOwner, a_defaultTo);
	}
}
