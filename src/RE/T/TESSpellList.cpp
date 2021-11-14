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
		if (!GetIndex(a_levSpell)) {
			std::vector<TESLevSpell*> copiedData{ levSpells, levSpells + numlevSpells };
			copiedData.push_back(a_levSpell);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<TESLevSpell*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = levSpells;

			numlevSpells = newNum;
			levSpells = newData;

			free(oldData);

			return true;
		}

		return false;
	}

	bool TESSpellList::SpellData::AddShout(TESShout* a_shout)
	{
		if (!GetIndex(a_shout)) {
			std::vector<TESShout*> copiedData{ shouts, shouts + numShouts };
			copiedData.push_back(a_shout);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<TESShout*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = shouts;

			numShouts = newNum;
			shouts = newData;

			free(oldData);

			return true;
		}

		return false;
	}

	bool TESSpellList::SpellData::AddSpell(SpellItem* a_spell)
	{
		if (!GetIndex(a_spell)) {
			std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
			copiedData.push_back(a_spell);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<SpellItem*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = spells;

			numSpells = newNum;
			spells = newData;

			free(oldData);

			return true;
		}

		return false;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(SpellItem* a_spell)
	{
		if (spells) {
			for (std::uint32_t i = 0; i < numSpells; i++) {
				if (spells[i] == a_spell) {
					return i;
				}
			}
		}
		return std::nullopt;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(TESLevSpell* a_lvlSpell)
	{
		if (levSpells) {
			for (std::uint32_t i = 0; i < numlevSpells; i++) {
				if (levSpells[i] == a_lvlSpell) {
					return i;
				}
			}
		}
		return std::nullopt;
	}

	std::optional<std::uint32_t> TESSpellList::SpellData::GetIndex(TESShout* a_shout)
	{
		if (shouts) {
			for (std::uint32_t i = 0; i < numShouts; i++) {
				if (shouts[i] == a_shout) {
					return i;
				}
			}
		}
		return std::nullopt;
	}

	bool TESSpellList::SpellData::RemoveSpell(SpellItem* a_spell)
	{
		auto index = GetIndex(a_spell);
		if (index) {
			std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
			copiedData.erase(copiedData.cbegin() + *index);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<SpellItem*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = spells;

			numSpells = newNum;
			spells = newData;

			free(oldData);

			return true;
		}

		return false;
	}
}
