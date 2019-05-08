#pragma once

#include "RE/NiTDefaultAllocator.h"  // NiTDefaultAllocator
#include "RE/NiTMapBase.h"  // NiTMapBase


namespace RE
{
	template <class Key, class T>
	class NiTMap : public NiTMapBase<NiTDefaultAllocator<NiTMapItem<Key, T>>, Key, T>
	{
	private:
		using Base = NiTMapBase<NiTDefaultAllocator<NiTMapItem<Key, T>>, Key, T>;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;
		using Base::clear;
		using Base::_allocator;


		NiTMap(UInt32 a_hashSize = 37) :
			Base(a_hashSize)
		{}


		virtual ~NiTMap()
		{}

	protected:
		// override (NiTMapBase)
		virtual value_type* malloc_value() override
		{
			return static_cast<value_type*>(_allocator.Allocate());
		}


		virtual void free_value(value_type* a_value) override
		{
			a_value->~value_type();
			_allocator.Deallocate(a_value);
		}
	};
}
