#include "RE/BSScript/IObjectHandlePolicy.h"


namespace RE
{
	namespace BSScript
	{
		bool IObjectHandlePolicy::GetHandleIsType(FormType a_typeID, VMHandle a_handle)
		{
			return GetHandleIsType(static_cast<UInt32>(a_typeID), a_handle);
		}


		VMHandle IObjectHandlePolicy::GetHandleForObject(FormType a_typeID, const TESForm* a_srcData)
		{
			return GetHandleForObject(static_cast<UInt32>(a_typeID), a_srcData);
		}


		void* IObjectHandlePolicy::GetObjectForHandle(FormType a_typeID, VMHandle a_handle)
		{
			return GetObjectForHandle(static_cast<UInt32>(a_typeID), a_handle);
		}
	}
}
