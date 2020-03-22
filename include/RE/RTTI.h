#pragma once

#include <memory>
#include <type_traits>
#include <typeinfo>

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	class type_info;


	namespace RTTI
	{
		template <class T>
		class RVA
		{
		public:
			RVA();
			RVA(UInt32 a_rva);
			~RVA() = default;

			T*		 get() const;
			T&		 operator*() const;
			T*		 operator->() const;
			T*		 operator[](std::ptrdiff_t a_id) const;
			explicit operator bool() const;

		protected:
			bool is_good() const;


			// members
			UInt32 _rva;  // 00
		};
		STATIC_ASSERT(sizeof(RVA<void*>) == 0x4);


		template <class T>
		RVA<T>::RVA() :
			_rva(0)
		{}


		template <class T>
		RVA<T>::RVA(UInt32 a_rva) :
			_rva(a_rva)
		{}


		template <class T>
		T* RVA<T>::get() const
		{
			return is_good() ? REL::Offset<T*>(_rva).GetType() : nullptr;
		}


		template <class T>
		T& RVA<T>::operator*() const
		{
			return *get();
		}


		template <class T>
		T* RVA<T>::operator->() const
		{
			return get();
		}


		template <class T>
		T* RVA<T>::operator[](std::ptrdiff_t a_idx) const
		{
			return get() + a_idx;
		}


		template <class T>
		RVA<T>::operator bool() const
		{
			return is_good();
		}


		template <class T>
		bool RVA<T>::is_good() const
		{
			return _rva != 0;
		}


		struct TypeDescriptor
		{
			type_info* typeInfo;  // 00
			void*	   spare;	  // 08
			const char name[1];	  // 10
		};
		STATIC_ASSERT(sizeof(TypeDescriptor) == 0x18);	// can be larger


		struct PMD
		{
			SInt32 mDisp;  // 0
			SInt32 pDisp;  // 4
			SInt32 vDisp;  // 8
		};
		STATIC_ASSERT(sizeof(PMD) == 0xC);


		struct BaseClassArray
		{
			enum class Attribute : UInt32
			{
				kNone = 0
			};


			RVA<TypeDescriptor> typeDescriptor;		// 00
			UInt32				numContainedBases;	// 04
			PMD					pmd;				// 08
			Attribute			attributes;			// 14
		};
		STATIC_ASSERT(sizeof(BaseClassArray) == 0x18);


		struct ClassHierarchyDescriptor
		{
			enum class Attribute : UInt32
			{
				kNoInheritance = 0,
				kMultipleInheritance = 1 << 0,
				kVirtualInheritance = 1 << 1,
				kAmbiguousInheritance = 1 << 2
			};


			UInt32				signature;		 // 00
			Attribute			attributes;		 // 04
			UInt32				numBaseClasses;	 // 08
			RVA<BaseClassArray> baseClassArray;	 // 0C
		};
		STATIC_ASSERT(sizeof(ClassHierarchyDescriptor) == 0x10);


		struct CompleteObjectLocator
		{
			enum class Signature : UInt32
			{
				kX86 = 0,
				kX64 = 1
			};


			Signature					  signature;		// 00
			UInt32						  offset;			// 04
			UInt32						  ctorDispOffset;	// 08
			RVA<TypeDescriptor>			  typeDescriptor;	// 0C
			RVA<ClassHierarchyDescriptor> classDescriptor;	// 10
		};
		STATIC_ASSERT(sizeof(CompleteObjectLocator) == 0x14);


		struct BaseClassDescriptor
		{
			enum class Attribute : UInt32
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


			RVA<TypeDescriptor> typeDescriptor;		// 00
			UInt32				numContainedBases;	// 04
			PMD					pmd;				// 08
			Attribute			attributes;			// 14
		};
		STATIC_ASSERT(sizeof(BaseClassDescriptor) == 0x18);


		void DumpTypeName(void* a_obj);
	}


	namespace SK_Impl
	{
		template <class T>
		using remove_cvpr_t = std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<T>>>;


		template <class T>
		struct target_is_valid :
			std::disjunction<std::is_polymorphic<remove_cvpr_t<T>>, std::is_same<void*, std::remove_cv_t<T>>>
		{};


		template <class To, class From>
		struct types_are_compat :
			std::false_type
		{};

		template <class To, class From>
		struct types_are_compat<To&, From> :
			std::is_lvalue_reference<std::remove_cv_t<From>>
		{};

		template <class To, class From>
		struct types_are_compat<To*, From> :
			std::is_pointer<std::remove_cv_t<From>>
		{};


		template <class To, class From>
		struct cast_is_valid :
			std::conjunction<types_are_compat<To, From>, target_is_valid<To>>
		{};
	}


	template <class T = PVOID>
	inline T RTDynamicCast(PVOID a_inptr, LONG a_vfDelta, PVOID a_srcType, PVOID a_targetType, BOOL a_isReference)
	{
		using func_t = decltype(&RTDynamicCast<T>);
		REL::Offset<func_t> func(::RE::Offset::RTDynamicCast);
		return func(a_inptr, a_vfDelta, a_srcType, a_targetType, a_isReference);
	}
}


template <class To, class From, std::enable_if_t<RE::SK_Impl::cast_is_valid<To, const From*>::value, int> = 0>
inline To skyrim_cast(const From* a_from)
{
	REL::Offset<PVOID> from(RE::SK_Impl::remove_cvpr_t<From>::RTTI);
	REL::Offset<PVOID> to(RE::SK_Impl::remove_cvpr_t<To>::RTTI);
	return RE::RTDynamicCast<To>((PVOID)a_from, 0, from.GetType(), to.GetType(), false);
}


template <class To, class From, std::enable_if_t<RE::SK_Impl::cast_is_valid<To, const From&>::value, int> = 0>
inline To skyrim_cast(const From& a_from)  // throw(std::bad_cast)
{
	try {
		REL::Offset<PVOID> from(RE::SK_Impl::remove_cvpr_t<From>::RTTI);
		REL::Offset<PVOID> to(RE::SK_Impl::remove_cvpr_t<To>::RTTI);
		return RE::RTDynamicCast<To>((PVOID)std::addressof(a_from), 0, from.GetType(), to.GetType(), true);
	} catch (...) {
		throw std::bad_cast();
	}
}
