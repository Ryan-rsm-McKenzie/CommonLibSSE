#include "RE/BSScriptObject.h"

#include "RE/IObjectHandlePolicy.h"  // IObjectHandlePolicy
#include "RE/Offsets.h"
#include "RE/VirtualMachine.h"  // Internal::VirtualMachine


namespace RE
{
	namespace BSScript
	{
		BSScriptClass* BSScriptObject::GetClass()
		{
			return classPtr.get();
		}


		const BSScriptClass* BSScriptObject::GetClass() const
		{
			return classPtr.get();
		}


		void* BSScriptObject::Resolve(UInt32 a_typeID) const
		{
			auto policy = Internal::VirtualMachine::GetSingleton()->GetHandlePolicyBS();
			if (policy->IsType(a_typeID, handle) && policy->IsValidHandle(handle)) {
				return policy->Resolve(a_typeID, handle);
			} else {
				return 0;
			}
		}


		void BSScriptObject::IncRefCount()
		{
			using func_t = function_type_t<decltype(&BSScriptObject::IncRefCount)>;
			RelocUnrestricted<func_t*> func(Offset::BSScriptObject::IncRefCount);
			return func(this);
		}


		SInt32 BSScriptObject::DecRefCount()
		{
			using func_t = function_type_t<decltype(&BSScriptObject::DecRefCount)>;
			RelocUnrestricted<func_t*> func(Offset::BSScriptObject::DecRefCount);
			return func(this);
		}
	}
}
