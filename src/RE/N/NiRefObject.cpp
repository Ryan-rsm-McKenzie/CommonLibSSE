#include "RE/N/NiRefObject.h"

namespace RE
{
	NiRefObject::NiRefObject()
	{
		stl::atomic_ref objectCount{ *GetTotalObjectCount() };
		++objectCount;
	}

	NiRefObject::~NiRefObject()
	{
		stl::atomic_ref objectCount{ *GetTotalObjectCount() };
		--objectCount;
	}

	void NiRefObject::DeleteThis()
	{
		delete this;
	}

	void NiRefObject::IncRefCount()
	{
		stl::atomic_ref myRefCount{ _refCount };
		++myRefCount;
	}

	void NiRefObject::DecRefCount()
	{
		stl::atomic_ref myRefCount{ _refCount };
		if (--myRefCount == 0) {
			DeleteThis();
		}
	}

	volatile std::uint32_t* NiRefObject::GetTotalObjectCount()
	{
		static REL::Relocation<volatile std::uint32_t*> totalObjectCount{ Offset::NiRefObject::TotalObjectCount };
		return totalObjectCount.get();
	}
}
