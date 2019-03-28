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


		template <class T, typename std::enable_if_t<is_form_pointer<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return GetTypeIDFromFormTypeID(remove_cvp_t<T>::kTypeID);
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_pointer<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return GetTypeIDFromFormTypeID(remove_cvp_t<remove_vm_array_t<T>>::kTypeID) + VMTypeID::kObject;
		}


		template <class T, typename std::enable_if_t<is_builtin_type<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return vm_type<T>::value;
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_pointer<T>::value, int> = 0>
		inline VMTypeID GetTypeID()
		{
			return vm_type<remove_cvp_t<remove_vm_array_t<T>>>::value + VMTypeID::kNoneArray;
		}


		template <class T, typename std::enable_if_t<is_form_pointer<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			PackHandle(a_dst, a_src, remove_cvp_t<T>::kTypeID);
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_pointer<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetArray(reinterpret_cast<const BSScriptArray*>(a_src), GetTypeID<T>());
		}


		template <class T, typename std::enable_if_t<is_builtin_type<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetData(a_src);
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_pointer<T>::value, int> = 0>
		inline void PackValue(BSScriptVariable* a_dst, const T& a_src)
		{
			a_dst->SetArray(reinterpret_cast<const BSScriptArray*>(a_src), GetTypeID<T>());
		}


		template <class T, typename std::enable_if_t<is_static_base_pointer<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return static_cast<T>(0);
		}


		template <class T, typename std::enable_if_t<is_sint32<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->data.i;
		}


		template <class T, typename std::enable_if_t<is_uint32<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->data.u;
		}


		template <class T, typename std::enable_if_t<is_float<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->data.f;
		}


		template <class T, typename std::enable_if_t<is_bool<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->data.b;
		}


		template <class T, typename std::enable_if_t<is_string<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->GetString();
		}


		template <class T, typename std::enable_if_t<is_vm_builtin_array_pointer<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->GetArray();
		}


		template <class T, typename std::enable_if_t<is_form_pointer<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, remove_cvp_t<T>::kTypeID));
		}


		template <class T, typename std::enable_if_t<is_vm_form_array_pointer<T>::value, int> = 0>
		inline T UnpackValue(BSScriptVariable* a_src)
		{
			return a_src->GetArray();
		}
	}
}
