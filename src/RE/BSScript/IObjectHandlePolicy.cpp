#include "RE/BSScript/IObjectHandlePolicy.h"


namespace RE
{
	namespace BSScript
	{
		bool IObjectHandlePolicy::IsType(FormType a_typeID, VMHandle a_handle)
		{
			return IsType(static_cast<UInt32>(a_typeID), a_handle);
		}


		VMHandle IObjectHandlePolicy::GetHandle(FormType a_typeID, const TESForm* a_srcData)
		{
			return GetHandle(static_cast<UInt32>(a_typeID), a_srcData);
		}


		void* IObjectHandlePolicy::Resolve(FormType a_typeID, VMHandle a_handle)
		{
			return Resolve(static_cast<UInt32>(a_typeID), a_handle);
		}
	}
}
