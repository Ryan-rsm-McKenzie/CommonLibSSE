#include "RE/Inventory/InventoryEntryData.h"

#include "RE/BSExtraData/ExtraCharge.h"
#include "RE/BSExtraData/ExtraEnchantment.h"
#include "RE/BSExtraData/ExtraTextDisplayData.h"
#include "RE/BSMain/SettingCollection/GameSettingCollection.h"
#include "RE/FormComponents/Components/FormTraits.h"
#include "RE/FormComponents/TESEnchantableForm.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundObject.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESSoulGem.h"
#include "RE/Inventory/ExtraDataList.h"


namespace RE
{
	InventoryEntryData::InventoryEntryData() :
		object(nullptr),
		extraLists(nullptr),
		countDelta(0),
		pad14(0)
	{}


	InventoryEntryData::InventoryEntryData(const InventoryEntryData& a_rhs) :
		object(a_rhs.object),
		extraLists(nullptr),
		countDelta(a_rhs.countDelta),
		pad14(0)
	{
		if (a_rhs.extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists);
		}
	}


	InventoryEntryData::InventoryEntryData(InventoryEntryData&& a_rhs) :
		object(std::move(a_rhs.object)),
		extraLists(std::move(a_rhs.extraLists)),
		countDelta(std::move(a_rhs.countDelta)),
		pad14(0)
	{
		a_rhs.object = nullptr;
		a_rhs.extraLists = nullptr;
		a_rhs.countDelta = 0;
	}


	InventoryEntryData::InventoryEntryData(TESBoundObject* a_object, SInt32 a_countDelta) :
		object(a_object),
		extraLists(nullptr),
		countDelta(a_countDelta),
		pad14(0)
	{
		extraLists = new BSSimpleList<ExtraDataList*>;
	}


	InventoryEntryData::~InventoryEntryData()
	{
		delete extraLists;
	}


	InventoryEntryData& InventoryEntryData::operator=(const InventoryEntryData& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		object = a_rhs.object;

		delete extraLists;
		if (a_rhs.extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists);
		} else {
			extraLists = nullptr;
		}

		countDelta = a_rhs.countDelta;

		return *this;
	}


	InventoryEntryData& InventoryEntryData::operator=(InventoryEntryData&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		object = std::move(a_rhs.object);
		a_rhs.object = nullptr;

		delete extraLists;
		extraLists = std::move(a_rhs.extraLists);
		a_rhs.extraLists = nullptr;

		countDelta = std::move(a_rhs.countDelta);
		a_rhs.countDelta = 0;

		return *this;
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


	std::optional<double> InventoryEntryData::GetEnchantmentCharge() const
	{
		std::optional<double> result;

		if (extraLists) {
			auto obj = GetObject();
			auto ench = obj ? obj->As<TESEnchantableForm>() : nullptr;
			if (ench && ench->formEnchanting) {
				result.emplace(100.0);
			}

			for (auto& xList : *extraLists) {
				if (xList) {
					auto xCharge = xList->GetByType<ExtraCharge>();
					if (xCharge) {
						auto xEnch = xList->GetByType<ExtraEnchantment>();
						if (xEnch && xEnch->enchantment) {
							result.emplace((static_cast<double>(xCharge->charge) /
											   static_cast<double>(xEnch->charge)) *
										   100.0);
							break;
						} else if (ench && ench->formEnchanting) {
							result.emplace((static_cast<double>(xCharge->charge) /
											   static_cast<double>(ench->amountofEnchantment)) *
										   100.0);
							break;
						}
					}
				}
			}
		}

		return result;
	}


	const char* InventoryEntryData::GetDisplayName()
	{
		const char* name = nullptr;
		if (extraLists && !extraLists->empty()) {
			name = extraLists->front()->GetDisplayName(object);
		} else if (object) {
			name = object->GetName();
		}

		if (!name || name[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst ? gmst->GetSetting("sMissingName") : nullptr;
			name = sMissingName ? sMissingName->GetString() : "";
		}

		return name;
	}


	TESBoundObject* InventoryEntryData::GetObject()
	{
		return object;
	}


	const TESBoundObject* InventoryEntryData::GetObject() const
	{
		return object;
	}


	TESForm* InventoryEntryData::GetOwner()
	{
		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (xList) {
					return xList->GetOwner();
				}
			}
		}
		return nullptr;
	}


	SOUL_LEVEL InventoryEntryData::GetSoulLevel() const
	{
		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (xList) {
					auto lvl = xList->GetSoulLevel();
					if (lvl > SOUL_LEVEL::kNone) {
						return lvl;
					}
				}
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
		using func_t = decltype(&InventoryEntryData::GetValue);
		REL::Offset<func_t> func(Offset::InventoryEntryData::GetValue);
		return func(this);
	}


	float InventoryEntryData::GetWeight() const
	{
		return object ? object->GetWeight() : -1.0F;
	}


	bool InventoryEntryData::IsEnchanted() const
	{
		if (object) {
			auto ench = object->As<TESEnchantableForm>();
			if (ench && ench->formEnchanting) {
				return true;
			}
		}

		if (extraLists) {
			for (auto& xList : *extraLists) {
				auto xEnch = xList->GetByType<ExtraEnchantment>();
				if (xEnch && xEnch->enchantment) {
					return true;
				}
			}
		}

		return false;
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_testOwner, bool a_defaultTo)
	{
		return IsOwnedBy(a_testOwner, GetOwner(), a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo)
	{
		return IsOwnedBy_Impl(a_testOwner, a_itemOwner, a_defaultTo);
	}


	bool InventoryEntryData::IsOwnedBy_Impl(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo)
	{
		using func_t = decltype(&InventoryEntryData::IsOwnedBy_Impl);
		REL::Offset<func_t> func(Offset::InventoryEntryData::IsOwnedBy);
		return func(this, a_testOwner, a_itemOwner, a_defaultTo);
	}


	bool InventoryEntryData::IsQuestObject() const
	{
		using func_t = decltype(&InventoryEntryData::IsQuestObject);
		REL::Offset<func_t> func = REL::ID(15767);
		return func(this);
	}
}
