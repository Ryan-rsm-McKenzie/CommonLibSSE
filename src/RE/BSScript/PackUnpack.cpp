#include "RE/BSScript/PackUnpack.h"

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/Class.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectBindPolicy.h"
#include "RE/BSScript/Variable.h"


namespace RE
{
	namespace BSScript
	{
		VMTypeID GetTypeIDFromFormType(FormType32 a_formType)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<Class> classPtr;
			if (vm->GetScriptClassByTypeID(a_formType, classPtr)) {
				return classPtr->GetTypeID();
			} else {
				_ERROR("[ERROR] Failed to get vm type id for class!\n");
				return VMTypeID::kNone;
			}
		}


		void BindID(BSTSmartPointer<Object>& a_objectPtr, const TESForm* a_srcData, FormType32 a_formType)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			FormType32 id = 0;
			BSTSmartPointer<Class> classPtr(a_objectPtr->GetClass());
			if (vm->GetFormTypeID(classPtr->GetName(), id)) {
				auto policy = vm->GetHandlePolicy();
				auto handle = policy->GetHandle(a_formType, a_srcData);

				// if handle is of expected type and not invalid
				if (policy->IsType(id, handle) && handle != policy->GetInvalidHandle()) {
					vm->GetObjectBindPolicy()->BindObject(a_objectPtr, handle);
				}
			}
		}


		void PackHandle(Variable* a_dst, const TESForm* a_src, FormType32 a_formType)
		{
			a_dst->SetNone();

			if (!a_src) {
				return;
			}

			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<Class> classPtr;
			vm->GetScriptClassByTypeID(a_formType, classPtr);
			if (!classPtr) {
				return;
			}

			auto policy = vm->GetHandlePolicy();
			auto handle = policy->GetHandle(a_formType, a_src);

			BSTSmartPointer<Object> objectPtr;
			if (!vm->ResolveScriptObject(handle, classPtr->GetName(), objectPtr)) {
				// when cannot be resolved, then create new objectPtr
				if (vm->CreateScriptObject(classPtr->GetName(), objectPtr) && objectPtr) {
					// create handle and bind it to the new objectPtr
					BindID(objectPtr, a_src, a_formType);
				}
			}

			if (objectPtr) {
				a_dst->SetObject(objectPtr.get(), classPtr->GetTypeID());
			}
		}


		void* UnpackHandle(Variable* a_src, FormType32 a_formType)
		{
			auto object = a_src->GetObject();
			return object ? object->Resolve(a_formType) : 0;
		}
	}
}
