#pragma once

namespace RE
{
	class type_info;

	namespace RTTI
	{
		template <class T>
		class RVA
		{
		public:
			using value_type = T;
			using pointer = value_type*;
			using reference = value_type&;

			RVA() :
				_rva(0)
			{}

			RVA(std::uint32_t a_rva) :
				_rva(a_rva)
			{}

			~RVA() = default;

			[[nodiscard]] pointer	get() const { return is_good() ? REL::Relocation<T*>{ _rva }.type() : nullptr; }
			[[nodiscard]] reference operator*() const { return *get(); }
			[[nodiscard]] pointer	operator->() const { return get(); }
			[[nodiscard]] pointer	operator[](std::ptrdiff_t a_idx) const { return get() + a_idx; }
			[[nodiscard]] explicit	operator bool() const noexcept { return is_good(); }

		protected:
			[[nodiscard]] bool is_good() const noexcept { return _rva != 0; }

			// members
			std::uint32_t _rva;	 // 00
		};
		static_assert(sizeof(RVA<void*>) == 0x4);

		struct TypeDescriptor
		{
		public:
			// members
			type_info* typeInfo;  // 00
			void*	   spare;	  // 08
			const char name[1];	  // 10
		};
		static_assert(sizeof(TypeDescriptor) == 0x18);	// can be larger

		struct PMD
		{
		public:
			// members
			std::int32_t mDisp;	 // 0
			std::int32_t pDisp;	 // 4
			std::int32_t vDisp;	 // 8
		};
		static_assert(sizeof(PMD) == 0xC);

		struct BaseClassArray
		{
		public:
			enum class Attribute
			{
				kNone = 0
			};

			// members
			RVA<TypeDescriptor>						   typeDescriptor;	   // 00
			std::uint32_t							   numContainedBases;  // 04
			PMD										   pmd;				   // 08
			stl::enumeration<Attribute, std::uint32_t> attributes;		   // 14
		};
		static_assert(sizeof(BaseClassArray) == 0x18);

		struct ClassHierarchyDescriptor
		{
		public:
			enum class Attribute
			{
				kNoInheritance = 0,
				kMultipleInheritance = 1 << 0,
				kVirtualInheritance = 1 << 1,
				kAmbiguousInheritance = 1 << 2
			};

			// members
			std::uint32_t							   signature;		// 00
			stl::enumeration<Attribute, std::uint32_t> attributes;		// 04
			std::uint32_t							   numBaseClasses;	// 08
			RVA<BaseClassArray>						   baseClassArray;	// 0C
		};
		static_assert(sizeof(ClassHierarchyDescriptor) == 0x10);

		struct CompleteObjectLocator
		{
		public:
			enum class Signature
			{
				kX86 = 0,
				kX64 = 1
			};

			// members
			stl::enumeration<Signature, std::uint32_t> signature;		 // 00
			std::uint32_t							   offset;			 // 04
			std::uint32_t							   ctorDispOffset;	 // 08
			RVA<TypeDescriptor>						   typeDescriptor;	 // 0C
			RVA<ClassHierarchyDescriptor>			   classDescriptor;	 // 10
		};
		static_assert(sizeof(CompleteObjectLocator) == 0x14);

		struct BaseClassDescriptor
		{
		public:
			enum class Attribute
			{
				kNone = 0,
				kNotVisible = 1 << 0,
				kAmbiguous = 1 << 1,
				kPrivate = 1 << 2,
				kPrivateOrProtectedBase = 1 << 3,
				kVirtual = 1 << 4,
				kNonPolymorphic = 1 << 5,
				kHasHierarchyDescriptor = 1 << 6
			};

			// members
			RVA<TypeDescriptor>						   typeDescriptor;	   // 00
			std::uint32_t							   numContainedBases;  // 04
			PMD										   pmd;				   // 08
			stl::enumeration<Attribute, std::uint32_t> attributes;		   // 14
		};
		static_assert(sizeof(BaseClassDescriptor) == 0x18);

		void DumpTypeName(void* a_obj);
	}

	namespace SK_Impl
	{
		template <class T>
		using remove_cvpr_t =
			std::remove_pointer_t<
				std::remove_reference_t<
					std::remove_cv_t<T>>>;

		template <class T>
		struct target_is_valid :
			std::disjunction<
				std::is_polymorphic<
					remove_cvpr_t<T>>,
				std::is_same<
					void*,
					std::remove_cv_t<T>>>
		{};

		template <class To, class From>
		struct types_are_compat :
			std::false_type
		{};

		template <class To, class From>
		struct types_are_compat<To&, From> :
			std::is_lvalue_reference<
				std::remove_cv_t<
					From>>
		{};

		template <class To, class From>
		struct types_are_compat<To*, From> :
			std::is_pointer<
				std::remove_cv_t<
					From>>
		{};

		template <class To, class From>
		struct cast_is_valid :
			std::conjunction<
				types_are_compat<
					To,
					From>,
				target_is_valid<
					To>>
		{};

		template <class To, class From>
		inline constexpr bool cast_is_valid_v = cast_is_valid<To, From>::value;
	}

	inline void* RTDynamicCast(void* a_inptr, std::int32_t a_vfDelta, void* a_srcType, void* a_targetType, std::int32_t a_isReference)
	{
		using func_t = decltype(&RTDynamicCast);
		REL::Relocation<func_t> func{ REL::ID(102238) };
		return func(a_inptr, a_vfDelta, a_srcType, a_targetType, a_isReference);
	}
}

template <
	class To,
	class From,
	std::enable_if_t<
		RE::SK_Impl::cast_is_valid_v<
			To,
			const From*>,
		int> = 0>
inline To skyrim_cast(const From* a_from)
{
	REL::Relocation<void*> from{ RE::SK_Impl::remove_cvpr_t<From>::RTTI };
	REL::Relocation<void*> to{ RE::SK_Impl::remove_cvpr_t<To>::RTTI };
	return static_cast<To>(
		RE::RTDynamicCast(
			const_cast<void*>(
				static_cast<const volatile void*>(a_from)),
			0,
			from.get(),
			to.get(),
			false));
}
