#include "RE/InventoryEntryData.h"

#include <type_traits>

#include "RE/ExtraDataList.h"
#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/TESBoundObject.h"
#include "RE/TESSoulGem.h"
#include "REL/Relocation.h"


namespace RE
{
	InventoryEntryData::InventoryEntryData(TESBoundObject* a_object, SInt32 a_countDelta) :
		object(a_object),
		extraLists(0),
		countDelta(a_countDelta)
	{
		extraLists = new std::remove_pointer_t<decltype(extraLists)>;
	}


	InventoryEntryData::~InventoryEntryData()
	{
		delete extraLists;
	}


	void InventoryEntryData::AddExtraList(ExtraDataList* a_extra)
	{
		if (!a_extra) {
			return;
		}

		if (!extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>;
		}

		extraLists->push_front(a_extra);
	}


	const char* InventoryEntryData::GenerateName()
	{
		if (extraLists && !extraLists->empty()) {
			return extraLists->front()->GenerateName(object);
		} else {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst->GetSetting("sMissingName");
			return sMissingName->GetString();
		}
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		if (extraLists && !extraLists->empty()) {
			return extraLists->front()->GetOwner();
		} else {
			return 0;
		}
	}


	SOUL_LEVEL InventoryEntryData::GetSoulLevel() const
	{
		if (extraLists && !extraLists->empty()) {
			auto lvl = extraLists->front()->GetSoulLevel();
			if (lvl > SOUL_LEVEL::kNone) {
				return lvl;
			}
		}

		if (object && object->Is(FormType::SoulGem)) {
			auto soulGem = static_cast<const TESSoulGem*>(object);
			return soulGem->GetContainedSoul();
		}

		return SOUL_LEVEL::kNone;
	}


	SInt32 InventoryEntryData::GetValue()
	{
		using func_t = function_type_t<decltype(&InventoryEntryData::GetValue)>;
		REL::Offset<func_t*> func(Offset::InventoryEntryData::GetValue);
		return func(this);
	}


	float InventoryEntryData::GetWeight()
	{
		return object ? object->GetWeight() : -1.0;
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
