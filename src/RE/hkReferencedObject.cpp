#include "RE/hkReferencedObject.h"


namespace RE
{
	hkReferencedObject::hkReferencedObject() :
		referenceCount(1)
	{}


	hkReferencedObject::~hkReferencedObject()
	{}


	SInt32 hkReferencedObject::GetAllocatedSize() const
	{
		return memSizeAndFlags & kMemSize;
	}


	SInt32 hkReferencedObject::GetReferenceCount() const
	{
		return referenceCount;
	}


	void hkReferencedObject::AddReference() const
	{
		InterlockedIncrement16(&referenceCount);
	}


	void hkReferencedObject::RemoveReference() const
	{
		InterlockedDecrement16(&referenceCount);
	}
}
