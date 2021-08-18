#include "RE/I/ItemList.h"

#include "RE/P/PlayerCharacter.h"

namespace RE
{
	auto ItemList::GetSelectedItem()
		-> Item*
	{
		if (unk50) {
			return nullptr;
		}

		GFxValue selectedIndex;
		auto     success = root.GetMember("selectedIndex", &selectedIndex);
		if (!success || !selectedIndex.IsNumber()) {
			return nullptr;
		}

		auto idx = static_cast<std::int32_t>(selectedIndex.GetNumber());
		if (idx < 0 || static_cast<std::size_t>(idx) >= items.size()) {
			return nullptr;
		}

		return items[idx];
	}

	void ItemList::Update()
	{
		auto player = RE::PlayerCharacter::GetSingleton();
		Update(player);
	}

	void ItemList::Update(TESObjectREFR* a_owner)
	{
		Update_Impl(a_owner);
	}

	void ItemList::Update_Impl(TESObjectREFR* a_owner)
	{
		using func_t = decltype(&ItemList::Update_Impl);
		REL::Relocation<func_t> func{ Offset::ItemList::Update };
		return func(this, a_owner);
	}
}
