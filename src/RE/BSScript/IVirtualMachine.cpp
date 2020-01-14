#include "RE/BSScript/IVirtualMachine.h"

#include <string>
#include <string_view>

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSFixedString.h"
#include "RE/TESForm.h"


namespace RE
{
	namespace BSScript
	{
		void IVirtualMachine::TraceStack(TESForm* a_form, const char* a_str, VMStackID a_stackID, Severity a_severity)
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
