#pragma once

#include "RE/N/NiTDefaultAllocator.h"
#include "RE/N/NiTMapBase.h"

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

		NiTMap(std::uint32_t a_hashSize = 37) :
			Base(a_hashSize)
		{}

		~NiTMap() override  // 00
		{}

	protected:
		using Base::_allocator;

		// override (NiTMapBase)
		value_type* malloc_value() override  // 05
		{
			return static_cast<value_type*>(_allocator.Allocate());
		}

		void free_value(value_type* a_value) override  // 06
		{
			if (a_value) {
				a_value->~value_type();
				_allocator.Deallocate(a_value);
			}
		}
	};
	static_assert(sizeof(NiTMap<void*, void*>) == 0x20);
}
