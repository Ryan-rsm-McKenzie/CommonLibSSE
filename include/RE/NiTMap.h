#pragma once

#include "RE/NiTDefaultAllocator.h"  // NiTDefaultAllocator
#include "RE/NiTMapBase.h"  // NiTMapBase


namespace RE
{
	template <class TKEY, class TVAL>
	class NiTMap : public NiTMapBase<NiTDefaultAllocator<NiTMapItem<TKEY, TVAL>>, TKEY, TVAL>
	{
	public:
		using key_type = typename NiTMapBase::key_type;
		using value_type = typename NiTMapBase::value_type;
		using item_type = typename NiTMapBase::item_type;


		NiTMap(unsigned int a_hashSize = 37) :
			NiTMapBase(a_hashSize)
		{}


		~NiTMap()
		{
			RemoveAll();
		}

	protected:
		// override (NiTMapBase)
		virtual item_type* NewItem() override
		{
			return (item_type*)_allocator.Allocate();
		}


		virtual void DeleteItem(item_type *item) override
		{
			item->~item_type();
			_allocator.Deallocate(item);
		}
	};
}
