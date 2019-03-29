#pragma once

#include "RE/BSScriptTypeTraits.h"
#include "RE/BSScriptVariable.h"  // BSScriptVariable
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class BSScriptObject;


		VMTypeID	GetTypeIDFromFormTypeID(UInt32 a_typeID);
		void		BindID(BSTSmartPointer<BSScriptObject>& a_object, const void* a_srcData, UInt32 a_typeID);
		void		PackHandle(BSScriptVariable* a_dst, const void* a_src, UInt32 a_typeID);
		void*		UnpackHandle(const BSScriptVariable* a_src, UInt32 a_typeID);


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return GetTypeIDFromFormTypeID(remove_cvpr_t<T>::kTypeID);
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return GetTypeIDFromFormTypeID(remove_cvpr_t<remove_vm_array_t<T>>::kTypeID) + VMTypeID::kObject;
		}


		template <class T, typename std::enable_if_t<is_builtin_type_no_cvr<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return vm_type<remove_cvpr_t<T>>::value;
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return vm_type<remove_cvpr_t<remove_vm_array_t<T>>>::value + VMTypeID::kNoneArray;
		}


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			PackHandle(a_dst, a_src, remove_cvpr_t<T>::kTypeID);
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetData(a_src.data());
		}


		template <class T, typename std::enable_if_t<is_builtin_type_no_cvr<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetData(a_src);
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetData(a_src.data());
		}


		template <class T, typename std::enable_if_t<is_static_base_pointer<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return static_cast<T>(0);
		}


		template <class T, typename std::enable_if_t<is_sint32_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetSInt();
		}


		template <class T, typename std::enable_if_t<is_uint32_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetUInt();
		}


		template <class T, typename std::enable_if_t<is_float_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetFloat();
		}


		template <class T, typename std::enable_if_t<is_bool_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetBool();
		}


		template <class T, typename std::enable_if_t<is_string_cref_compat<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetString();
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetArray();
		}


		template <class T, typename std::enable_if_t<is_form_pointer_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, remove_cvpr_t<T>::kTypeID));
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_no_cvr<T>::value, int> = 0>
		inline T UnpackValue(const BSScriptVariable* a_src)
		{
			return a_src->GetArray();
		}


		template <class T>
		inline void BSScriptVariable::Pack(const T a_src)
		{
			PackValue<T>(this, a_src);
		}


		template <class T>
		inline T BSScriptVariable::Unpack()
		{
			return UnpackValue<T>(this);
		}
	}
}
