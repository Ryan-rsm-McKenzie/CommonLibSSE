#include "RE/T/TESSpellList.h"

namespace RE
{
	TESSpellList::SpellData::SpellData() :
		spells(nullptr),
		levSpells(nullptr),
		shouts(nullptr),
		numSpells(0),
		numlevSpells(0),
		numShouts(0),
		pad24(0)
	{
	}

	bool TESSpellList::SpellData::AddLevSpell(TESLevSpell* a_levSpell)
	{
		if (!GetIndex(a_levSpell).has_value()) {
			auto oldData = levSpells;
			levSpells = calloc<TESLevSpell*>(++numlevSpells);
			if (oldData) {
				for (std::uint32_t i = 0; i < numlevSpells - 1; i++) {
					levSpells[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			levSpells[numlevSpells - 1] = a_levSpell;
			return true;
		}
		return false;
	}

	bool TESSpellList::SpellData::AddShout(TESShout* a_shout)
	{
		if (!GetIndex(a_shout).has_value()) {
			auto oldData = shouts;
			shouts = calloc<TESShout*>(++numShouts);
			if (oldData) {
				for (std::uint32_t i = 0; i < numShouts - 1; i++) {
					shouts[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			shouts[numShouts - 1] = a_shout;
			return true;
		}
		return false;
	}

	bool TESSpellList::SpellData::AddSpell(SpellItem* a_spell)
	{
		if (!GetIndex(a_spell).has_value()) {
			auto oldData = spells;
			spells = calloc<SpellItem*>(++numSpells);
			if (oldData) {
				for (std::uint32_t i = 0; i < numSpells - 1; i++) {
					spells[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			spells[numSpells - 1] = a_spell;
			return true;
		}
		return false;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(SpellItem* a_spell)
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (spells) {
			for (std::uint32_t i = 0; i < numSpells; i++) {
				if (spells[i] && spells[i] == a_spell) {
					index = i;
					break;
				}
			}
		}
		return index;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(TESLevSpell* a_lvlSpell)
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (levSpells) {
			for (std::uint32_t i = 0; i < numlevSpells; i++) {
				if (levSpells[i] && levSpells[i] == a_lvlSpell) {
					index = i;
					break;
				}
			}
		}
		return index;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(TESShout* a_shout)
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (shouts) {
			for (std::uint32_t i = 0; i < numShouts; i++) {
				if (shouts[i] && shouts[i] == a_shout) {
					index = i;
					break;
				}
			}
		}
		return index;
	}

	bool TESSpellList::SpellData::RemoveSpell(SpellItem* a_spell)
	{
		auto index = GetIndex(a_spell);
		if (index.has_value()) {
			auto oldData = spells;
			if (oldData) {
				spells = calloc<SpellItem*>(--numSpells);
				for (std::uint32_t i = 0; i < numSpells + 1; i++) {
					if (index != i) {
						spells[i] = oldData[i];
					}
				}
				free(oldData);
				oldData = nullptr;
				return true;
			}
		}
		return false;
	}
}
