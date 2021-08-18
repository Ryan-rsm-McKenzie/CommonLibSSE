#include "RE/I/IObjectHandlePolicy.h"

namespace RE
{
	namespace BSScript
	{
		bool IObjectHandlePolicy::HandleIsType(FormType a_typeID, VMHandle a_handle)
		{
			return HandleIsType(static_cast<VMTypeID>(a_typeID), a_handle);
		}

		VMHandle IObjectHandlePolicy::GetHandleForObject(FormType a_typeID, const TESForm* a_srcData)
		{
			return GetHandleForObject(static_cast<VMTypeID>(a_typeID), a_srcData);
		}

		TESForm* IObjectHandlePolicy::GetObjectForHandle(FormType a_typeID, VMHandle a_handle)
		{
			return static_cast<TESForm*>(GetObjectForHandle(static_cast<VMTypeID>(a_typeID), a_handle));
		}
	}
}
