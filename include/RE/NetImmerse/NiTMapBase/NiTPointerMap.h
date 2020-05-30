#pragma once

#include "RE/NiTMapBase.h"
#include "RE/NiTPointerAllocator.h"


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


		NiTPointerMap(UInt32 a_hashSize = 37) :
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
	STATIC_ASSERT(sizeof(NiTPointerMap<UInt32, UInt64>) == 0x20);
}
