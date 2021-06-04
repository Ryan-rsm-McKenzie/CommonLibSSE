#pragma once

namespace RE
{
	class NiRTTI
	{
	public:
		[[nodiscard]] constexpr const char*   GetName() const noexcept { return name; }
		[[nodiscard]] constexpr const NiRTTI* GetBaseRTTI() const noexcept { return baseRTTI; }

		[[nodiscard]] constexpr bool IsKindOf(const NiRTTI* a_rtti) const noexcept
		{
			for (auto iter = this; iter; iter = iter->GetBaseRTTI()) {
				if (iter == a_rtti) {
					return true;
				}
			}
			return false;
		}

		// members
		const char*   name;      // 00
		const NiRTTI* baseRTTI;  // 08
	};
	static_assert(sizeof(NiRTTI) == 0x10);

	namespace Ni_Impl
	{
		template <class T>
		using remove_cvpr_t =
			std::remove_pointer_t<
				std::remove_reference_t<
					std::remove_cv_t<T>>>;

		template <class To, class From>
		struct types_are_compat :
			std::false_type
		{};

		template <class To, class From>
		struct types_are_compat<To&, From> :
			std::is_lvalue_reference<
				std::remove_cv_t<From>>
		{};

		template <class To, class From>
		struct types_are_compat<To*, From> :
			std::is_pointer<
				std::remove_cv_t<From>>
		{};

		template <class Base, class Derived>
		struct is_base_of_no_cvpr :
			std::is_base_of<
				remove_cvpr_t<Base>,
				remove_cvpr_t<Derived>>
		{};

		template <class T, class Enable = void>
		struct _has_rtti :
			std::false_type
		{};

		template <class T>
		struct _has_rtti<T, std::void_t<decltype(T::Ni_RTTI)>> :
			std::true_type
		{};

		template <class T>
		struct has_rtti :
			_has_rtti<remove_cvpr_t<T>>
		{};

		template <class To, class From>
		struct cast_is_valid :
			std::conjunction<
				types_are_compat<To, From>,
				is_base_of_no_cvpr<From, To>,
				has_rtti<To>,
				has_rtti<From>>
		{};

		template <class To, class From>
		inline constexpr bool cast_is_valid_v = cast_is_valid<To, From>::value;
	}
}

// downcast
template <
	class To,
	class From,
	std::enable_if_t<
		RE::Ni_Impl::cast_is_valid_v<
			To,
			const From*>,
		int> = 0>
To netimmerse_cast(const From* a_from)
{
	if (!a_from) {
		return nullptr;
	}

	REL::Relocation<const RE::NiRTTI*> to{ RE::Ni_Impl::remove_cvpr_t<To>::Ni_RTTI };

	const RE::NiRTTI* toRTTI = to.get();
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
template <
	class To,
	class From,
	std::enable_if_t<
		RE::Ni_Impl::cast_is_valid_v<
			const From*,
			To>,
		int> = 0>
To netimmerse_cast(const From* a_from)
{
	return static_cast<To>(const_cast<From*>(a_from));
}
