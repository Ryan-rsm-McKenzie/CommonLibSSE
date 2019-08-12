#include "RE/BSScript/Object.h"

#include "RE/BSScript/Internal/VirtualMachine.h"  // BSScript::Internal::VirtualMachine
#include "RE/BSScript/Class.h"  // BSScript::Class
#include "RE/BSScript/IObjectHandlePolicy.h"  // BSScript::IObjectHandlePolicy
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Class* Object::GetClass()
		{
			return classPtr.get();
		}


		const Class* Object::GetClass() const
		{
			return classPtr.get();
		}


		UInt32 Object::GetFlags() const
		{
			return pun_bits(flags1, flags2, flags3);
		}


		UInt32 Object::GetNumProperties() const
		{
			return pun_bits(numProperties01, numProperties02, numProperties03, numProperties04, numProperties05, numProperties06, numProperties07, numProperties08, numProperties09, numProperties10, numProperties11, numProperties12, numProperties13, numProperties14, numProperties15, numProperties16, numProperties17, numProperties18, numProperties19);
		}


		void* Object::Resolve(FormType32 a_typeID) const
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			auto policy = vm->GetHandlePolicy();
			if (policy->IsType(a_typeID, handle) && policy->IsValidHandle(handle)) {
				return policy->Resolve(a_typeID, handle);
			} else {
				return 0;
			}
		}


		void Object::IncRefCount()
		{
			using func_t = function_type_t<decltype(&Object::IncRefCount)>;
			REL::Offset<func_t*> func(Offset::BSScript::Object::IncRefCount);
			return func(this);
		}


		SInt32 Object::DecRefCount()
		{
			using func_t = function_type_t<decltype(&Object::DecRefCount)>;
			REL::Offset<func_t*> func(Offset::BSScript::Object::DecRefCount);
			return func(this);
		}


		Variable* Object::GetProperty(const BSFixedString& a_name)
		{
			if (!classPtr) {
				return 0;
			}

			auto idx = classPtr->GetPropertyIndex(a_name);
			if (idx == static_cast<UInt32>(-1)) {
				return 0;
			}

			return &variables[idx];
		}


		const Variable*	Object::GetProperty(const BSFixedString& a_name) const
		{
			if (!classPtr) {
				return 0;
			}

			auto idx = classPtr->GetPropertyIndex(a_name);
			if (idx == static_cast<UInt32>(-1)) {
				return 0;
			}

			return &variables[idx];
		}
	}
}
