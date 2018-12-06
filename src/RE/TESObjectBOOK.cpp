#include "RE/TESObjectBOOK.h"


namespace RE
{
	TESObjectBOOK::Data::Flag TESObjectBOOK::Data::GetSanitizedType()
	{
		typedef Flag _GetSanitizedType_t(TESObjectBOOK::Data* a_this);
		_GetSanitizedType_t* _GetSanitizedType = reinterpret_cast<_GetSanitizedType_t*>(GetFnAddr(&::TESObjectBOOK::Data::GetSanitizedType));
		return _GetSanitizedType(this);
	}


	bool TESObjectBOOK::TeachesSkill() const
	{
		return (data.flags & Data::Flag::kFlag_Skill) != 0;
	}


	bool TESObjectBOOK::TeachesSpell() const
	{
		return (data.flags & Data::Flag::kFlag_Spell) != 0;
	}


	bool TESObjectBOOK::IsRead() const
	{
		return (data.flags & Data::Flag::kFlag_Read) != 0;
	}


	bool TESObjectBOOK::CanBeTaken() const
	{
		return (data.flags & Data::Flag::kFlag_CantBeTaken) == 0;
	}
}
