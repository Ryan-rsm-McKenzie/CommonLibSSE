#include "RE/BSScript/PackUnpack.h"

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectBindPolicy.h"
#include "RE/BSScript/ObjectTypeInfo.h"
#include "RE/BSScript/Variable.h"


namespace RE
{
	namespace BSScript
	{
		TypeInfo::RawType GetRawTypeFromVMType(VMTypeID a_typeID)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<ObjectTypeInfo> classPtr;
			if (vm && vm->GetScriptObjectType(a_typeID, classPtr)) {
				return classPtr->GetRawType();
			} else {
				_ERROR("Failed to get vm type id for class!\n");
				return TypeInfo::RawType::kNone;
			}
		}


		void BindID(BSTSmartPointer<Object>& a_objectPtr, const TESForm* a_srcData, VMTypeID a_typeID)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			VMTypeID id = 0;
			BSTSmartPointer<ObjectTypeInfo> typeInfo(a_objectPtr->GetTypeInfo());
			if (vm && vm->GetTypeIDForScriptObject(typeInfo->GetName(), id)) {
				auto policy = vm->GetObjectHandlePolicy();
				if (policy) {
					auto handle = policy->GetHandleForObject(a_typeID, a_srcData);

					// if handle is of expected type and not invalid
					if (policy->HandleIsType(id, handle) && handle != policy->EmptyHandle()) {
						vm->GetObjectBindPolicy()->BindObject(a_objectPtr, handle);
					}
				}
			}
		}


		void PackHandle(Variable* a_dst, const TESForm* a_src, VMTypeID a_typeID)
		{
			a_dst->SetNone();

			if (!a_src) {
				return;
			}

			auto vm = Internal::VirtualMachine::GetSingleton();
			if (!vm) {
				return;
			}

			BSTSmartPointer<ObjectTypeInfo> classPtr;
			vm->GetScriptObjectType(a_typeID, classPtr);
			if (!classPtr) {
				return;
			}

			auto policy = vm->GetObjectHandlePolicy();
			if (!policy) {
				return;
			}

			auto handle = policy->GetHandleForObject(a_typeID, a_src);

			BSTSmartPointer<Object> objectPtr;
			if (!vm->FindBoundObject(handle, classPtr->GetName(), objectPtr)) {
				// when cannot be resolved, then create new objectPtr
				if (vm->CreateObject(classPtr->GetName(), objectPtr) && objectPtr) {
					// create handle and bind it to the new objectPtr
					BindID(objectPtr, a_src, a_typeID);
				}
			}

			if (objectPtr) {
				a_dst->SetObject(objectPtr.get(), classPtr->GetRawType());
			}
		}


		void* UnpackHandle(const Variable* a_src, VMTypeID a_typeID)
		{
			const auto* object = a_src->GetObject();
			return object ? object->Resolve(a_typeID) : nullptr;
		}
	}
}
