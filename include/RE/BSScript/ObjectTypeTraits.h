#pragma once

#include "RE/BSScript/CommonTypeTraits.h"  // remove_cvr_t


namespace RE
{
	namespace BSScript
	{
		class Object;


		namespace
		{
			template <class T> struct _is_script_object_pointer : std::false_type {};
			template <> struct _is_script_object_pointer<Object*> : std::true_type {};
		}
		template <class T> struct is_script_object_pointer : _is_script_object_pointer<typename std::remove_cv_t<T>>::type {};
		template <class T> struct is_script_object_pointer_no_cvr : is_script_object_pointer<typename remove_cvr_t<T>> {};
	}
}
