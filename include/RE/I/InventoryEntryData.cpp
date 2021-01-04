#include "RE/I/InventoryEntryData.h"

#include "RE/E/ExtraCharge.h"
#include "RE/E/ExtraDataList.h"
#include "RE/E/ExtraEnchantment.h"
#include "RE/E/ExtraLeveledItem.h"
#include "RE/E/ExtraTextDisplayData.h"
#include "RE/F/FormTraits.h"
#include "RE/G/GameSettingCollection.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESSoulGem.h"

namespace RE
{
	InventoryEntryData::InventoryEntryData(const InventoryEntryData& a_rhs) :
		object(a_rhs.object),
		countDelta(a_rhs.countDelta)
	{
		if (a_rhs.extraLists) {
			extraLists = new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists);
		}
	}

	InventoryEntryData::~InventoryEntryData()
	{
		delete extraLists;
	}

	InventoryEntryData& InventoryEntryData::operator=(const InventoryEntryData& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			object = a_rhs.object;

			delete extraLists;
			extraLists =
				a_rhs.extraLists ?
					  new BSSimpleList<ExtraDataList*>(*a_rhs.extraLists) :
					  nullptr;

			countDelta = a_rhs.countDelta;
		}
		return *this;
	}

	InventoryEntryData& InventoryEntryData::operator=(InventoryEntryData&& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			delete extraLists;

			object = std::exchange(a_rhs.object, nullptr);
			extraLists = std::exchange(a_rhs.extraLists, nullptr);
			countDelta = std::exchange(a_rhs.countDelta, 0);
		}
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
		auto				  obj = GetObject();
		auto				  ench = obj ? obj->As<TESEnchantableForm>() : nullptr;
		if (ench && ench->formEnchanting && ench->amountofEnchantment != 0) {
			result.emplace(100.0);
		}

		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (xList) {
					auto xCharge = xList->GetByType<ExtraCharge>();
					auto xEnch = xList->GetByType<ExtraEnchantment>();
					if (xEnch && xEnch->enchantment && xEnch->charge != 0) {
						if (xCharge) {
							result.emplace((static_cast<double>(xCharge->charge) /
											   static_cast<double>(xEnch->charge)) *
										   100.0);
						} else {
							result.emplace(100.0);
						}
						break;
					} else if (xCharge && ench && ench->formEnchanting && ench->amountofEnchantment != 0) {
						result.emplace((static_cast<double>(xCharge->charge) /
										   static_cast<double>(ench->amountofEnchantment)) *
									   100.0);
						break;
					}
				}
			}
		}

		return result;
	}

	const char* InventoryEntryData::GetDisplayName()
	{
		const char* name = nullptr;
		if (extraLists) {
			for (auto& xList : *extraLists) {
				if (xList) {
					name = xList->GetDisplayName(object);
				}
			}
		}

		if ((!name || name[0] == '\0') && object) {
			name = object->GetName();
		}

		if (!name || name[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst ? gmst->GetSetting("sMissingName") : nullptr;
			name = sMissingName ? sMissingName->GetString() : "";
		}

		return name;
	}

	TESForm* InventoryEntryData::GetOwner()
	{
		if (extraLists) {
			for (auto& xList : *extraLists) {
				auto owner = xList ? xList->GetOwner() : nullptr;
				if (owner) {
					return owner;
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
			for (const auto& xList : *extraLists) {
				const auto xEnch = xList->GetByType<ExtraEnchantment>();
				if (xEnch && xEnch->enchantment) {
					return true;
				}
			}
		}

		return false;
	}

	bool InventoryEntryData::IsLeveled() const
	{
		if (extraLists) {
			for (const auto& xList : *extraLists) {
				if (xList && xList->HasType<ExtraLeveledItem>()) {
					return true;
				}
			}
		}

		return false;
	}
}
