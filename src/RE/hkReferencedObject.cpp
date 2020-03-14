#include "RE/hkReferencedObject.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	hkReferencedObject::hkReferencedObject() :
		memSizeAndFlags(0),
		referenceCount(1),
		pad0C(0)
	{}


	const hkClass* hkReferencedObject::GetClassType() const
	{
		return nullptr;
	}


	void hkReferencedObject::CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const
	{
		return;
	}


	void hkReferencedObject::AddReference() const
	{
		using func_t = decltype(&hkReferencedObject::AddReference);
		REL::Offset<func_t> func(Offset::hkReferencedObject::AddReference);
		return func(this);
	}


	SInt32 hkReferencedObject::GetAllocatedSize() const
	{
		return memSizeAndFlags & kMemSize;
	}


	SInt32 hkReferencedObject::GetReferenceCount() const
	{
		return referenceCount;
	}


	void hkReferencedObject::RemoveReference() const
	{
		using func_t = decltype(&hkReferencedObject::RemoveReference);
		REL::Offset<func_t> func(Offset::hkReferencedObject::RemoveReference);
		return func(this);
	}
}
