#pragma once

#include "skse64/GameRTTI.h"

#include <typeinfo>  // bad_cast
#include <type_traits>

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace
{
	template <class T> using remove_cvpr_t = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>;

	template <class T> struct target_is_valid : std::disjunction<std::is_polymorphic<remove_cvpr_t<T>>, std::is_same<void*, std::remove_cv_t<T>>> {};

	template <class To, class From> struct types_are_compat : std::false_type {};
	template <class To, class From> struct types_are_compat<To&, From> : std::is_lvalue_reference<std::remove_cv_t<From>> {};
	template <class To, class From> struct types_are_compat<To*, From> : std::is_pointer<std::remove_cv_t<From>> {};

	template <class To, class From> struct cast_is_valid : std::conjunction<types_are_compat<To, From>, target_is_valid<To>> {};
}


namespace RE
{
	template <class T = PVOID>
	inline T RTDynamicCast(PVOID a_inptr, LONG a_vfDelta, PVOID a_srcType, PVOID a_targetType, BOOL a_isReference)
	{
		using func_t = function_type_t<decltype(&RTDynamicCast<T>)>;
		REL::Offset<func_t*> func(::RE::Offset::RTDynamicCast);
		return func(a_inptr, a_vfDelta, a_srcType, a_targetType, a_isReference);
	}
}


template <class To, class From, typename std::enable_if_t<cast_is_valid<To, const From*>::value, int> = 0>
To skyrim_cast(const From* a_from)
{
	REL::Offset<PVOID> from(reinterpret_cast<std::uintptr_t>(remove_cvpr_t<From>::RTTI));
	REL::Offset<PVOID> to(reinterpret_cast<std::uintptr_t>(remove_cvpr_t<To>::RTTI));
	return RE::RTDynamicCast<To>((PVOID)a_from, 0, from.GetType(), to.GetType(), false);
}


template <class To, class From, typename std::enable_if_t<cast_is_valid<To, const From&>::value, int> = 0>
To skyrim_cast(const From& a_from)	// throw(std::bad_cast)
{
	REL::Offset<PVOID> from(reinterpret_cast<std::uintptr_t>(remove_cvpr_t<From>::RTTI));
	REL::Offset<PVOID> to(reinterpret_cast<std::uintptr_t>(remove_cvpr_t<To>::RTTI));
	return RE::RTDynamicCast<To>((PVOID)&a_from, 0, from.GetType(), to.GetType(), true);
}
