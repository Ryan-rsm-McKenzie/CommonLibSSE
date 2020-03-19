#include "RE/BSScript/Object.h"

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/ObjectTypeInfo.h"
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


		ObjectTypeInfo* Object::GetTypeInfo()
		{
			return type.get();
		}


		const ObjectTypeInfo* Object::GetTypeInfo() const
		{
			return type.get();
		}


		UInt32 Object::GetNumProperties() const
		{
			return pun_bits(numProperties01, numProperties02, numProperties03, numProperties04, numProperties05, numProperties06, numProperties07, numProperties08, numProperties09, numProperties10, numProperties11, numProperties12, numProperties13, numProperties14, numProperties15, numProperties16, numProperties17, numProperties18, numProperties19);
		}


		bool Object::IsConstructed() const
		{
			return constructed;
		}


		bool Object::IsInitialized() const
		{
			return initialized;
		}


		bool Object::IsValid() const
		{
			return valid;
		}


		void* Object::Resolve(VMTypeID a_typeID) const
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy && policy->HandleIsType(a_typeID, handle) && policy->IsHandleObjectAvailable(handle)) {
				return policy->GetObjectForHandle(a_typeID, handle);
			} else {
				return nullptr;
			}
		}


		void Object::IncRef()
		{
			using func_t = decltype(&Object::IncRef);
			REL::Offset<func_t> func(Offset::BSScript::Object::IncRef);
			return func(this);
		}


		UInt32 Object::DecRef()
		{
			using func_t = decltype(&Object::DecRef);
			REL::Offset<func_t> func(Offset::BSScript::Object::DecRef);
			return func(this);
		}


		Variable* Object::GetProperty(const BSFixedString& a_name)
		{
			constexpr auto INVALID = static_cast<UInt32>(-1);

			auto idx = INVALID;
			for (auto cls = type.get(); cls && idx == INVALID; cls = cls->GetParent()) {
				idx = cls->GetPropertyIndex(a_name);
			}

			return idx != INVALID ? &variables[idx] : nullptr;
		}


		const Variable* Object::GetProperty(const BSFixedString& a_name) const
		{
			constexpr auto INVALID = static_cast<UInt32>(-1);

			auto idx = INVALID;
			for (auto cls = type.get(); cls && idx == INVALID; cls = cls->GetParent()) {
				idx = cls->GetPropertyIndex(a_name);
			}

			return idx != INVALID ? &variables[idx] : nullptr;
		}


		void Object::Dtor()
		{
			using func_t = decltype(&Object::Dtor);
			REL::Offset<func_t> func(Offset::BSScript::Object::Dtor);
			return func(this);
		}
	}
}
