#include "RE/TESObjectBOOK.h"


namespace RE
{
	TESObjectBOOK::Data::Flag TESObjectBOOK::Data::GetSanitizedType() const
	{
		if ((flags & Flag::kTeachesSpell) != Flag::kNone) {
			return Flag::kTeachesSpell;
		} else if ((flags & Flag::kTeachesSkill) != Flag::kNone) {
			return Flag::kTeachesSkill;
		} else {
			return Flag::kNone;
		}
	}


	bool TESObjectBOOK::TeachesSkill() const
	{
		return (data.flags & Data::Flag::kTeachesSkill) != Data::Flag::kNone;
	}


	bool TESObjectBOOK::TeachesSpell() const
	{
		return (data.flags & Data::Flag::kTeachesSpell) != Data::Flag::kNone;
	}


	bool TESObjectBOOK::IsRead() const
	{
		return (data.flags & Data::Flag::kRead) != Data::Flag::kNone;
	}


	bool TESObjectBOOK::CanBeTaken() const
	{
		return (data.flags & Data::Flag::kCantBeTaken) == Data::Flag::kNone;
	}


	bool TESObjectBOOK::IsBookTome() const
	{
		return data.type == Data::Type::kBookTome;
	}


	bool TESObjectBOOK::IsNoteScroll() const
	{
		return data.type == Data::Type::kNoteScroll;
	}


	ActorValue TESObjectBOOK::GetSkill() const
	{
		return TeachesSkill() ? data.teaches.skill : ActorValue::kNone;
	}


	SpellItem* TESObjectBOOK::GetSpell()
	{
		return TeachesSpell() ? data.teaches.spell : 0;
	}
}
