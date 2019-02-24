#pragma once


namespace RE
{
	//=====================================================
	// BSTSingletonExplicit
	//=====================================================

	template<class Ty>
	struct BSTSingletonExplicit
	{};


	//=====================================================
	// BSTSingletonImplicit
	//=====================================================

	template<class Ty>
	struct BSTSingletonImplicit
	{};


	//=====================================================
	// BSTSingletonSDM
	//=====================================================

	template <class> struct BSTSingletonSDMBase;


	template <class Ty>
	struct BSTSingletonSDMOpStaticBuffer
	{};


	template <class Ty, class Alloc = BSTSingletonSDMOpStaticBuffer<Ty>>
	struct BSTSDMTraits
	{
		typedef Ty Type;
		typedef Alloc Allocator;
	};


	template <class Traits>
	struct BSTSingletonSDMBase : public Traits, public Traits::Allocator
	{
		typedef typename Traits::Type Type;
		typedef typename Traits::Allocator Allocator;
	};


	template <class Ty, template <class> class _SingletonT = BSTSingletonSDMOpStaticBuffer>
	struct BSTSingletonSDM : BSTSingletonSDMBase<BSTSDMTraits<Ty, _SingletonT<Ty>>>
	{};
}
