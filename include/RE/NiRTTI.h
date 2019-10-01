#pragma once

#include <type_traits>

#include "RE/NiObject.h"  // NiObject
#include "REL/Relocation.h"


namespace RE
{
	class NiRTTI
	{
	public:
		const char*		GetName() const;
		const NiRTTI*	GetBaseRTTI() const;


		// members
		const char*		name;		// 00
		const NiRTTI*	baseRTTI;	// 08
	};
	STATIC_ASSERT(sizeof(NiRTTI) == 0x10);


	namespace Ni_Impl
	{
		template <class T> using remove_cvpr_t = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>;

		template <class... Args> struct types_are_valid : std::conjunction<std::is_base_of<RE::NiObject, remove_cvpr_t<Args>>...> {};

		template <class To, class From> struct types_are_compat : std::false_type {};
		template <class To, class From> struct types_are_compat<To&, From> : std::is_lvalue_reference<std::remove_cv_t<From>> {};
		template <class To, class From> struct types_are_compat<To*, From> : std::is_pointer<std::remove_cv_t<From>> {};

		template <class To, class From> struct cast_is_valid : std::conjunction<types_are_compat<To, From>, types_are_valid<To, From>> {};
	}
}


template <class To, class From, typename std::enable_if_t<RE::Ni_Impl::cast_is_valid<To, const From*>::value, int> = 0>
To netimmerse_cast(const From* a_from)
{
	REL::Offset<const RE::NiRTTI*> to(reinterpret_cast<std::uintptr_t>(RE::Ni_Impl::remove_cvpr_t<To>::Ni_RTTI));

	const RE::NiRTTI* toRTTI = to.GetType();
	const RE::NiRTTI* fromRTTI = a_from->GetRTTI();
	while (fromRTTI) {
		if (fromRTTI == toRTTI) {
			return static_cast<To>(const_cast<From*>(a_from));
		}
		fromRTTI = fromRTTI->GetBaseRTTI();
	}

	return nullptr;
}
