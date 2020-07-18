#include "RE/NetImmerse/NiRefObject/NiRefObject.h"


namespace RE
{
	NiRefObject::NiRefObject() :
		_refCount(0),
		_pad0C(0)
	{
		InterlockedIncrement(&_refCount);
	}


	NiRefObject::~NiRefObject()
	{
		InterlockedDecrement(&_refCount);
	}


	void NiRefObject::DeleteThis()
	{
		delete this;
	}


	void NiRefObject::IncRefCount()
	{
		InterlockedIncrement(&_refCount);
	}


	void NiRefObject::DecRefCount()
	{
		if (InterlockedDecrement(&_refCount) == 0) {
			DeleteThis();
		}
	}


	std::uint32_t NiRefObject::GetRefCount() const
	{
		return _refCount;
	}


	volatile std::uint32_t& NiRefObject::GetTotalObjectCount()
	{
		static REL::Offset<volatile std::uint32_t*> totalObjectCount(Offset::NiRefObject::TotalObjectCount);
		return *totalObjectCount;
	}
}
