#pragma once

#include <type_traits>

#include "REL/Relocation.h"


namespace RE
{
	class NiRTTI
	{
	public:
		const char*	  GetName() const;
		const NiRTTI* GetBaseRTTI() const;


		// members
		const char*	  name;		 // 00
		const NiRTTI* baseRTTI;	 // 08
	};
	STATIC_ASSERT(sizeof(NiRTTI) == 0x10);


	namespace Ni_Impl
	{
		template <class T>
		using remove_cvpr_t = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>;

		template <class To, class From>
		struct types_are_compat : std::false_type
		{};
		template <class To, class From>
		struct types_are_compat<To&, From> : std::is_lvalue_reference<std::remove_cv_t<From>>
		{};
		template <class To, class From>
		struct types_are_compat<To*, From> : std::is_pointer<std::remove_cv_t<From>>
		{};

		template <class Base, class Derived>
		struct is_base_of_no_cvpr : std::is_base_of<remove_cvpr_t<Base>, remove_cvpr_t<Derived>>
		{};

		namespace
		{
			template <class T, class Enable = void>
			struct _has_rtti : std::false_type
			{};
			template <class T>
			struct _has_rtti<T, std::void_t<decltype(T::Ni_RTTI)>> : std::true_type
			{};
		}
		template <class T>
		struct has_rtti : _has_rtti<remove_cvpr_t<T>>
		{};

		template <class To, class From>
		struct cast_is_valid : std::conjunction<types_are_compat<To, From>, is_base_of_no_cvpr<From, To>, has_rtti<To>, has_rtti<From>>
		{};
	}
}


// downcast
template <class To, class From, typename std::enable_if_t<RE::Ni_Impl::cast_is_valid<To, const From*>::value, int> = 0>
To netimmerse_cast(const From* a_from)
{
	if (!a_from) {
		return nullptr;
	}

	REL::Offset<const RE::NiRTTI*> to(RE::Ni_Impl::remove_cvpr_t<To>::Ni_RTTI);

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


// upcast
template <class To, class From, typename std::enable_if_t<RE::Ni_Impl::cast_is_valid<const From*, To>::value, int> = 0>
To netimmerse_cast(const From* a_from)
{
	return static_cast<To>(const_cast<From*>(a_from));
}
