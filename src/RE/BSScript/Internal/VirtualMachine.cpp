#include "RE/BSScript/Internal/VirtualMachine.h"

#include <string>
#include <string_view>

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSFixedString.h"
#include "RE/Offsets.h"
#include "RE/SkyrimVM.h"
#include "RE/TESForm.h"
#include "REL/Relocation.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				auto vm = SkyrimVM::GetSingleton();
				return vm ? static_cast<VirtualMachine*>(vm->impl.get()) : 0;
			}


			bool VirtualMachine::AllocateArray(const TypeInfo::RawType& a_typeID, std::size_t a_size, BSTSmartPointer<Array>& a_array)
			{
				using func_t = function_type_t<decltype(&VirtualMachine::AllocateArray)>;
				REL::Offset<func_t*> func(Offset::BSScript::Internal::VirtualMachine::AllocateArray);
				return func(this, a_typeID, a_size, a_array);
			}


			void VirtualMachine::TraceStack(TESForm* a_form, const char* a_str, VMStackID a_stackID, Severity a_severity)
			{
				assert(a_str);

				BSFixedString name;
				if (a_form) {
					auto policy = GetObjectHandlePolicy();
					if (policy) {
						auto handle = policy->GetHandleForObject(a_form->formType, a_form);
						policy->ConvertHandleToString(handle, name);
					}
				}

				if (name.empty()) {
					name = "None";
				}

				std::string_view str(a_str);
				std::string message;
				message.reserve(name.length() + 2 + str.length());
				message += name;
				message += ": ";
				message += str;

				TraceStack(message.c_str(), a_stackID, a_severity);
			}
		}
	}
}
