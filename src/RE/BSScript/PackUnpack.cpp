#include "RE/BSScript/PackUnpack.h"

#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectBindPolicy.h"
#include "RE/BSScript/ObjectTypeInfo.h"
#include "RE/BSScript/Variable.h"
#include "SKSE/Logger.h"


namespace RE
{
	namespace BSScript
	{
		TypeInfo::RawType GetRawTypeFromVMType(VMTypeID a_typeID)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<ObjectTypeInfo> classPtr;
			if (vm && vm->GetScriptObjectType(a_typeID, classPtr) && classPtr) {
				return classPtr->GetRawType();
			} else {
				_ERROR("Failed to get vm type id for class!");
				return TypeInfo::RawType::kNone;
			}
		}


		void BindID(BSTSmartPointer<Object>& a_objectPtr, const TESForm* a_src, VMTypeID a_typeID)
		{
			auto vm = Internal::VirtualMachine::GetSingleton();
			auto id = static_cast<VMTypeID>(0);
			BSTSmartPointer<ObjectTypeInfo> typeInfo(a_objectPtr->GetTypeInfo());
			if (vm && typeInfo && vm->GetTypeIDForScriptObject(typeInfo->GetName(), id)) {
				auto handlePolicy = vm->GetObjectHandlePolicy();
				if (handlePolicy) {
					auto handle = handlePolicy->GetHandleForObject(a_typeID, a_src);

					// if handle is of expected type and not invalid
					if (handlePolicy->HandleIsType(id, handle) && handlePolicy->IsHandleObjectAvailable(handle)) {
						auto bindPolicy = vm->GetObjectBindPolicy();
						if (bindPolicy) {
							bindPolicy->BindObject(a_objectPtr, handle);
						}
					}
				}
			}
		}


		void PackHandle(Variable* a_dst, const TESForm* a_src, VMTypeID a_typeID)
		{
			assert(a_dst);
			a_dst->SetNone();

			if (!a_src) {
				return;
			}

			auto vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<ObjectTypeInfo> classPtr;
			if (!vm || !vm->GetScriptObjectType(a_typeID, classPtr) || !classPtr) {
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
				a_dst->SetObject(objectPtr, classPtr->GetRawType());
			}
		}


		void* UnpackHandle(const Variable* a_src, VMTypeID a_typeID)
		{
			assert(a_src);
			const auto object = a_src->GetObject();
			return object ? object->Resolve(a_typeID) : nullptr;
		}
	}
}
