#pragma once

namespace RE
{
	//=====================================================
	// BSTSingletonExplicit
	//=====================================================

	template <class T>
	struct BSTSingletonExplicit
	{};

	//=====================================================
	// BSTSingletonImplicit
	//=====================================================

	template <class T>
	struct BSTSingletonImplicit
	{};

	//=====================================================
	// BSTSingletonSDM
	//=====================================================

	template <class>
	struct BSTSingletonSDMBase;

	template <class T>
	struct BSTSingletonSDMOpStaticBuffer
	{};

	template <class T, class Alloc = BSTSingletonSDMOpStaticBuffer<T>>
	struct BSTSDMTraits
	{
		using Type = T;
		using Allocator = Alloc;
	};

	template <class Traits>
	struct BSTSingletonSDMBase :
		public Traits,
		public Traits::Allocator
	{
		using Type = typename Traits::Type;
		using Allocator = typename Traits::Allocator;
	};

	template <class T, template <class> class Singleton = BSTSingletonSDMOpStaticBuffer>
	struct BSTSingletonSDM : public BSTSingletonSDMBase<BSTSDMTraits<T, Singleton<T>>>
	{};
}
