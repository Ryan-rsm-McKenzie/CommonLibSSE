#pragma once

#include "RE/N/NiTMapBase.h"
#include "RE/N/NiTPointerAllocator.h"

namespace RE
{
	template <class Key, class T>
	class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<std::uintptr_t>, Key, T>
	{
	private:
		using Base = NiTMapBase<NiTPointerAllocator<std::uintptr_t>, Key, T>;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;

		NiTPointerMap(std::uint32_t a_hashSize = 37) :
			NiTMapBase(a_hashSize)
		{}

		virtual ~NiTPointerMap()  // 00
		{}

	protected:
		using Base::_allocator;

		// override (NiTMapBase)
		virtual value_type* malloc_value() override	 // 05
		{
			return static_cast<value_type*>(_allocator.Allocate());
		}

		virtual void free_value(value_type* a_value) override  // 06
		{
			a_value->~value_type();
			_allocator.Deallocate(a_value);
		}
	};
	static_assert(sizeof(NiTPointerMap<std::uint32_t, std::uint64_t>) == 0x20);
}
