#pragma once

#include "RE/NiTMapBase.h"  // NiTMapBase
#include "RE/NiTPointerAllocator.h"  // NiTPointerAllocator


namespace RE
{
	// 20
	template <class Key, class T>
	class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<UInt32>, Key, T>
	{
	private:
		using Base = NiTMapBase<NiTPointerAllocator<UInt32>, Key, T>;

	public:
		using key_type = typename Base::key_type;
		using mapped_type = typename Base::mapped_type;
		using value_type = typename Base::value_type;
		using size_type = typename Base::size_type;
		using Base::clear;
		using Base::_allocator;


		NiTPointerMap(UInt32 a_hashSize = 37) :
			NiTMapBase(a_hashSize)
		{}


		~NiTPointerMap()
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
	namespace { using TestNiTPointerMap = NiTPointerMap<std::uint32_t, std::uint64_t>; }
	STATIC_ASSERT(sizeof(TestNiTPointerMap) == 0x20);
}
