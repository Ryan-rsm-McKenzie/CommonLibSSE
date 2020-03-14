#include "RE/TESObjectBOOK.h"


namespace RE
{
	auto OBJ_BOOK::GetSanitizedType() const
		-> Flag
	{
		if ((flags & Flag::kTeachesSpell) != Flag::kNone) {
			return Flag::kTeachesSpell;
		} else if ((flags & Flag::kAdvancesActorValue) != Flag::kNone) {
			return Flag::kAdvancesActorValue;
		} else {
			return Flag::kNone;
		}
	}


	bool TESObjectBOOK::TeachesSkill() const
	{
		return (data.flags & OBJ_BOOK::Flag::kAdvancesActorValue) != OBJ_BOOK::Flag::kNone;
	}


	bool TESObjectBOOK::TeachesSpell() const
	{
		return (data.flags & OBJ_BOOK::Flag::kTeachesSpell) != OBJ_BOOK::Flag::kNone;
	}


	bool TESObjectBOOK::IsRead() const
	{
		return (data.flags & OBJ_BOOK::Flag::kHasBeenRead) != OBJ_BOOK::Flag::kNone;
	}


	bool TESObjectBOOK::CanBeTaken() const
	{
		return (data.flags & OBJ_BOOK::Flag::kCantTake) == OBJ_BOOK::Flag::kNone;
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
