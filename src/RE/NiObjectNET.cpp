#include "RE/NiObjectNET.h"

#include "skse64/NiObjects.h"  // NiObjectNET


namespace RE
{
	void NiObjectNET::AddExtraData(NiExtraData* a_extraData)
	{
		using func_t = function_type_t<decltype(&NiObjectNET::AddExtraData)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiObjectNET::AddExtraData);
		return func(this, a_extraData);
	}


	bool NiObjectNET::RemoveExtraData(NiExtraData* a_extraData)
	{
		using func_t = function_type_t<decltype(&NiObjectNET::RemoveExtraData)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiObjectNET::RemoveExtraData);
		return func(this, a_extraData);
	}


	SInt32 NiObjectNET::GetIndexOf(NiExtraData* a_extraData)
	{
		using func_t = function_type_t<decltype(&NiObjectNET::GetIndexOf)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiObjectNET::GetIndexOf);
		return func(this, a_extraData);
	}


	NiExtraData* NiObjectNET::GetExtraData(BSFixedString a_name)
	{
		using func_t = function_type_t<decltype(&NiObjectNET::GetExtraData)>;
		func_t* func = unrestricted_cast<func_t*>(&::NiObjectNET::GetExtraData);
		return func(this, a_name);
	}


	NiTimeController* NiObjectNET::GetController() const
	{
		return controllers.get();
	}
}
