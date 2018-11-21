#include "RE/NiObjectNET.h"


namespace RE
{
	void NiObjectNET::AddExtraData(NiExtraData* a_extraData)
	{
		typedef void _AddExtraData_t(NiObjectNET* a_this, NiExtraData* a_extraData);
		static _AddExtraData_t* _AddExtraData = reinterpret_cast<_AddExtraData_t*>(GetFnAddr(&::NiObjectNET::AddExtraData));
		_AddExtraData(this, a_extraData);
	}


	bool NiObjectNET::RemoveExtraData(NiExtraData* a_extraData)
	{
		typedef bool _RemoveExtraData_t(NiObjectNET* a_this, NiExtraData* a_extraData);
		static _RemoveExtraData_t* _RemoveExtraData = reinterpret_cast<_RemoveExtraData_t*>(GetFnAddr(&::NiObjectNET::RemoveExtraData));
		return _RemoveExtraData(this, a_extraData);
	}


	SInt32 NiObjectNET::GetIndexOf(NiExtraData* a_extraData)
	{
		typedef SInt32 _GetIndexOf_t(NiObjectNET* a_this, NiExtraData* a_extraData);
		static _GetIndexOf_t* _GetIndexOf = reinterpret_cast<_GetIndexOf_t*>(GetFnAddr(&::NiObjectNET::GetIndexOf));
		return _GetIndexOf(this, a_extraData);
	}


	NiExtraData* NiObjectNET::GetExtraData(BSFixedString a_name)
	{
		typedef NiExtraData* _GetExtraData_t(NiObjectNET* a_this, BSFixedString a_name);
		static _GetExtraData_t* _GetExtraData = reinterpret_cast<_GetExtraData_t*>(GetFnAddr(&::NiObjectNET::GetExtraData));
		return _GetExtraData(this, a_name);
	}


	NiTimeController* NiObjectNET::GetController() const
	{
		return m_controller;
	}
}
