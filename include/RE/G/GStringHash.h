#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GHash.h"
#include "RE/G/GString.h"

namespace RE
{
	template <class U, class Allocator = GAllocatorGH<U>>
	class GStringHash : public GHash<GString, U, GString::NoCaseHashFunctor, Allocator>
	{
	public:
		using BaseType = GHash<GString, U, GString::NoCaseHashFunctor, Allocator>;
		using SelfType = GStringHash<U, Allocator>;
	};
}
