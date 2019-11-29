#include "RE/BSScript/Object.h"

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/Class.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		Object::~Object()
		{
			Dtor();
			memzero(this);
		}


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
			return pun_bits(variablesSet, flags2, initialized);
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
			constexpr auto INVALID = static_cast<UInt32>(-1);

			auto idx = INVALID;
			for (auto cls = classPtr.get(); cls && idx == INVALID; cls = cls->parent.get()) {
				idx = cls->GetPropertyIndex(a_name);
			}

			return idx != INVALID ? &variables[idx] : 0;
		}


		const Variable*	Object::GetProperty(const BSFixedString& a_name) const
		{
			constexpr auto INVALID = static_cast<UInt32>(-1);

			auto idx = INVALID;
			for (auto cls = classPtr.get(); cls && idx == INVALID; cls = cls->parent.get()) {
				idx = cls->GetPropertyIndex(a_name);
			}

			return idx != INVALID ? &variables[idx] : 0;
		}


		void Object::Dtor()
		{
			using func_t = function_type_t<decltype(&Object::Dtor)>;
			REL::Offset<func_t*> func(Offset::BSScript::Object::Dtor);
			return func(this);
		}
	}
}
