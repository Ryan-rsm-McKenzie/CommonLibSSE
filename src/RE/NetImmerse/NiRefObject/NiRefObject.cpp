#include "RE/NetImmerse/NiRefObject/NiRefObject.h"


namespace RE
{
	NiRefObject::NiRefObject()
	{
		InterlockedIncrement(GetTotalObjectCount());
	}


	NiRefObject::~NiRefObject()
	{
		InterlockedDecrement(GetTotalObjectCount());
	}


	void NiRefObject::DeleteThis()
	{
		delete this;
	}


	void NiRefObject::IncRefCount()
	{
		InterlockedIncrement(std::addressof(_refCount));
	}


	void NiRefObject::DecRefCount()
	{
		if (InterlockedDecrement(std::addressof(_refCount)) == 0) {
			DeleteThis();
		}
	}


	volatile std::uint32_t* NiRefObject::GetTotalObjectCount()
	{
		static REL::Offset<volatile std::uint32_t*> totalObjectCount(Offset::NiRefObject::TotalObjectCount);
		return totalObjectCount.type();
	}
}
