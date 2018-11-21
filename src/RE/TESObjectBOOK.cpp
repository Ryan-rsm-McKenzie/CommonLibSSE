#include "RE/TESObjectBOOK.h"


namespace RE
{
	UInt32 TESObjectBOOK::Data::GetSanitizedType()
	{
		typedef UInt32 _GetSanitizedType_t(TESObjectBOOK::Data* a_this);
		static _GetSanitizedType_t* _GetSanitizedType = reinterpret_cast<_GetSanitizedType_t*>(GetFnAddr(&::TESObjectBOOK::Data::GetSanitizedType));
		return _GetSanitizedType(this);
	}


	bool TESObjectBOOK::IsRead() const
	{
		return (data.flags & Data::kType_Read) != 0;
	}
}
