#include "RE/NiRefObject.h"

#include "skse64_common/Relocation.h"  // RelocPtr

#include "RE/Offsets.h"


namespace RE
{
	NiRefObject::NiRefObject()
	{
		_refCount = 0;
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
		if (Release()) {
			DeleteThis();
		}
	}


	bool NiRefObject::Release()
	{
		return InterlockedDecrement(&_refCount) == 0;
	}


	UInt32 NiRefObject::GetRefCount() const
	{
		return _refCount;
	}


	volatile UInt32& NiRefObject::GetTotalObjectCount()
	{
		static RelocPtr<volatile UInt32> totalObjectCount(Offset::NiRefObject::TotalObjectCount);
		return *totalObjectCount.GetPtr();
	}
}
