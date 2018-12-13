#include "RE/TESObjectBOOK.h"

#include "skse64/GameObjects.h"  // TESObjectBOOK


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
}
