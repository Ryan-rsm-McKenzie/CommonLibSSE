#pragma once

#include "RE/GFixedSizeHash.h"  // GFixedSizeHash
#include "RE/GHashAllocator.h"  // GAllocatorGH
#include "RE/GHashSetBase.h"  // GHashSetBase
#include "RE/GHashsetCachedEntry.h"  // GHashsetCachedEntry


namespace RE
{
	template <
		class C,
		class HashF = GFixedSizeHash<C>,
		class AltHashF = HashF,
		class Allocator = GAllocatorGH<C>,
		class Entry = GHashsetCachedEntry<C, HashF>
	> class GHashSet :
		public GHashSetBase<C, HashF, AltHashF, Allocator, Entry>
	{
	public:
		using BaseType = GHashSetBase<C, HashF, AltHashF, Allocator, Entry>;
		using SelfType = GHashSet<C, HashF, AltHashF, Allocator, Entry>;


		GHashSet()
		{}


		GHashSet(SInt32 a_sizeHint) :
			BaseType(a_sizeHint)
		{}


		explicit GHashSet(void* a_heap) :
			BaseType(a_heap)
		{}


		GHashSet(void* a_heap, SInt32 a_sizeHint) :
			BaseType(a_heap, a_sizeHint)
		{}


		GHashSet(const SelfType& a_src) :
			BaseType(a_src)
		{}


		~GHashSet()
		{}


		void operator=(const SelfType& a_src)
		{
			Assign(this, a_src);
		}


		template <class CRef>
		void Set(const CRef& a_key)
		{
			BaseType::Set(this, a_key);
		}


		template <class CRef>
		inline void Add(const CRef& a_key)
		{
			BaseType::Add(this, a_key);
		}


		void CheckExpand()
		{
			BaseType::CheckExpand(this);
		}


		void Resize(UPInt a_size)
		{
			BaseType::SetCapacity(this, a_size);
		}


		void SetCapacity(UPInt a_newSize)
		{
			BaseType::SetCapacity(this, a_newSize);
		}
	};
}
