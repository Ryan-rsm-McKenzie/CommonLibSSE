#include "RE/BSScript/ObjectBindPolicy.h"

#include "skse64/PapyrusInterfaces.h"  // ObjectBindPolicy


namespace RE
{
	namespace BSScript
	{
		void ObjectBindPolicy::BindObject(BSTSmartPointer<Object>& a_objectPtr, VMHandle a_handle)
		{
			using func_t = function_type_t<decltype(&ObjectBindPolicy::BindObject)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::ObjectBindPolicy, BindObject, func_t*);
			return func(this, a_objectPtr, a_handle);
		}
	}
}
