#include "RE/T/TESObjectBOOK.h"

namespace RE
{
	auto OBJ_BOOK::GetSanitizedType() const
		-> Flag
	{
		if (flags.all(Flag::kTeachesSpell)) {
			return Flag::kTeachesSpell;
		} else if (flags.all(Flag::kAdvancesActorValue)) {
			return Flag::kAdvancesActorValue;
		} else {
			return Flag::kNone;
		}
	}

	bool TESObjectBOOK::TeachesSkill() const
	{
		return data.flags.all(OBJ_BOOK::Flag::kAdvancesActorValue);
	}

	bool TESObjectBOOK::TeachesSpell() const
	{
		return data.flags.all(OBJ_BOOK::Flag::kTeachesSpell);
	}

	bool TESObjectBOOK::IsRead() const
	{
		return data.flags.all(OBJ_BOOK::Flag::kHasBeenRead);
	}

	bool TESObjectBOOK::CanBeTaken() const
	{
		return data.flags.none(OBJ_BOOK::Flag::kCantTake);
	}

	bool TESObjectBOOK::IsBookTome() const
	{
		return data.type == OBJ_BOOK::Type::kBookTome;
	}

	bool TESObjectBOOK::IsNoteScroll() const
	{
		return data.type == OBJ_BOOK::Type::kNoteScroll;
	}

	ActorValue TESObjectBOOK::GetSkill() const
	{
		return TeachesSkill() ? data.teaches.actorValueToAdvance : ActorValue::kNone;
	}

	SpellItem* TESObjectBOOK::GetSpell()
	{
		return TeachesSpell() ? data.teaches.spell : nullptr;
	}
}
