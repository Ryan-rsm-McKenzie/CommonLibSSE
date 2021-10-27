#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GFixedSizeHash.h"
#include "RE/G/GHash.h"
#include "RE/G/GHashNode.h"
#include "RE/G/GHashsetNodeEntry.h"

namespace RE
{
	template <
		class C,
		class U,
		class HashF = GFixedSizeHash<C>,
		class Allocator = GAllocatorGH<C>>
	class GHashUncached :
		public GHash<
			C,
			U,
			HashF,
			Allocator,
			GHashNode<C, U, HashF>,
			GHashsetNodeEntry<GHashNode<C, U, HashF>,
				typename GHashNode<C, U, HashF>::NodeHashF>>
	{
	public:
		using BaseType = GHash<
			C,
			U,
			HashF,
			Allocator,
			GHashNode<C, U, HashF>,
			GHashsetNodeEntry<GHashNode<C, U, HashF>,
				typename GHashNode<C, U, HashF>::NodeHashF>>;
		using SelfType = GHashUncached<C, U, HashF, Allocator>;

		GHashUncached()
		{}

		GHashUncached(std::int32_t a_sizeHint) :
			BaseType(a_sizeHint)
		{}

		GHashUncached(const SelfType& a_src) :
			BaseType(a_src)
		{}

		~GHashUncached()
		{}

		void operator=(const SelfType& a_src)
		{
			BaseType::operator=(a_src);
		}
	};
}
