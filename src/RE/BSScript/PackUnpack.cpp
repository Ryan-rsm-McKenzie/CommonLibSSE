#include "RE/BSScript/PackUnpack.h"

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectBindPolicy.h"
#include "RE/BSScript/ObjectTypeInfo.h"
#include "RE/BSScript/Variable.h"


namespace RE
{
	namespace BSScript
	{
		TypeInfo::RawType GetTypeFromFormType(VMTypeID a_formType)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<ObjectTypeInfo> classPtr;
			if (vm->GetScriptClassByTypeID(a_formType, classPtr)) {
				return classPtr->GetType();
			} else {
				_ERROR("Failed to get vm type id for class!\n");
				return TypeInfo::RawType::kNone;
			}
		}


		void BindID(BSTSmartPointer<Object>& a_objectPtr, const TESForm* a_srcData, VMTypeID a_formType)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			VMTypeID id = 0;
			BSTSmartPointer<ObjectTypeInfo> typeInfo(a_objectPtr->GetTypeInfo());
			if (vm->GetFormTypeID(typeInfo->GetName(), id)) {
				auto policy = vm->GetObjectHandlePolicy();
				auto handle = policy->GetHandleForObject(a_formType, a_srcData);

				// if handle is of expected type and not invalid
				if (policy->GetHandleIsType(id, handle) && handle != policy->EmptyHandle()) {
					vm->GetObjectBindPolicy()->BindObject(a_objectPtr, handle);
				}
			}
		}


		void PackHandle(Variable* a_dst, const TESForm* a_src, VMTypeID a_formType)
		{
			a_dst->SetNone();

			if (!a_src) {
				return;
			}

			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<ObjectTypeInfo> classPtr;
			vm->GetScriptClassByTypeID(a_formType, classPtr);
			if (!classPtr) {
				return;
			}

			auto policy = vm->GetObjectHandlePolicy();
			auto handle = policy->GetHandleForObject(a_formType, a_src);

			BSTSmartPointer<Object> objectPtr;
			if (!vm->FindBoundObject(handle, classPtr->GetName(), objectPtr)) {
				// when cannot be resolved, then create new objectPtr
				if (vm->CreateObject(classPtr->GetName(), objectPtr) && objectPtr) {
					// create handle and bind it to the new objectPtr
					BindID(objectPtr, a_src, a_formType);
				}
			}

			if (objectPtr) {
				a_dst->SetObject(objectPtr.get(), classPtr->GetType());
			}
		}


		void* UnpackHandle(Variable* a_src, VMTypeID a_formType)
		{
			auto object = a_src->GetObject();
			return object ? object->Resolve(a_formType) : 0;
		}
	}
}
