#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GFixedSizeHash.h"
#include "RE/G/GHashSet.h"
#include "RE/G/GHashsetEntry.h"

namespace RE
{
	template <
		class C,
		class HashF = GFixedSizeHash<C>,
		class AltHashF = HashF,
		class Allocator = GAllocatorGH<C>>
	class GHashSetUncached :
		public GHashSet<C, HashF, AltHashF, Allocator, GHashsetEntry<C, HashF>>
	{
	public:
		using BaseType = GHashSet<C, HashF, AltHashF, Allocator, GHashsetEntry<C, HashF>>;
		using SelfType = GHashSetUncached<C, HashF, AltHashF, Allocator>;

		GHashSetUncached()
		{}

		GHashSetUncached(std::int32_t a_sizeHint) :
			BaseType(a_sizeHint)
		{}

		GHashSetUncached(const SelfType& a_src) :
			BaseType(a_src)
		{}

		~GHashSetUncached()
		{}

		void operator=(const SelfType& a_src)
		{
			BaseType::operator=(a_src);
		}
	};
}
