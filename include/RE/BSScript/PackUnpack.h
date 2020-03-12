#pragma once

#include "RE/BSScript/TypeTraits.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Object;


		TypeInfo::RawType GetRawTypeFromVMType(VMTypeID a_typeID);
		void			  BindID(BSTSmartPointer<Object>& a_object, const TESForm* a_srcData, VMTypeID a_typeID);
		void			  PackHandle(Variable* a_dst, const TESForm* a_src, VMTypeID a_typeID);
		void*			  UnpackHandle(const Variable* a_src, VMTypeID a_typeID);


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline TypeInfo::RawType GetRawType()
		{
			return GetRawTypeFromVMType(static_cast<VMTypeID>(remove_cvpr_t<T>::FORMTYPE));
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline TypeInfo::RawType GetRawType()
		{
			return GetRawTypeFromVMType(static_cast<VMTypeID>(remove_cvpr_t<remove_vm_array_t<T>>::FORMTYPE)) + TypeInfo::RawType::kObject;
		}


		template <class T, typename std::enable_if_t<is_builtin_type_no_cvr<T>::value, int> = 0>
		inline TypeInfo::RawType GetRawType()
		{
			return vm_type<remove_cvpr_t<T>>::value;
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline TypeInfo::RawType GetRawType()
		{
			return vm_type<remove_cvpr_t<remove_vm_array_t<T>>>::value + TypeInfo::RawType::kNoneArray;
		}


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			PackHandle(a_dst, std::forward<T>(a_src), static_cast<VMTypeID>(remove_cvpr_t<T>::FORMTYPE));
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			a_dst->SetData(a_src.data());
		}


		template <class T, typename std::enable_if_t<is_builtin_type_no_cvr<T>::value, int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			a_dst->SetData(std::forward<T>(a_src));
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			a_dst->SetData(a_src.data());
		}


		template <class T, typename std::enable_if_t<is_static_base_pointer<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return static_cast<T>(0);
		}


		template <class T, typename std::enable_if_t<is_sint32_compat<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetSInt();
		}


		template <class T, typename std::enable_if_t<is_uint32_compat<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetUInt();
		}


		template <class T, typename std::enable_if_t<is_float_compat<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetFloat();
		}


		template <class T, typename std::enable_if_t<is_bool_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetBool();
		}


		template <class T, typename std::enable_if_t<is_string_compat<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetString();
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetArray();
		}


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, static_cast<VMTypeID>(remove_cvpr_t<T>::FORMTYPE)));
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return a_src->GetArray();
		}


		template <class T>
		inline void Variable::Pack(T&& a_src)
		{
			PackValue<T>(this, std::forward<T>(a_src));
		}


		template <class T>
		inline T Variable::Unpack() const
		{
			return UnpackValue<T>(this);
		}


		template <class T>
		[[nodiscard]] BSTSmartPointer<Array> VMArray<T>::alloc(size_type a_count)
		{
			auto				   vm = Internal::VirtualMachine::GetSingleton();
			BSTSmartPointer<Array> arrPtr;
			TypeInfo			   typeInfo(GetRawType<value_type>());
			[[maybe_unused]] auto  allocSuccess = vm->CreateArray(typeInfo, a_count, arrPtr);
			assert(allocSuccess);  // alloc failed
			return arrPtr;
		}
	}
}
