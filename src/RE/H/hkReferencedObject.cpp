#include "RE/H/hkReferencedObject.h"

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
		REL::Relocation<func_t> func{ Offset::hkReferencedObject::AddReference };
		return func(this);
	}

	std::int32_t hkReferencedObject::GetAllocatedSize() const
	{
		return memSizeAndFlags & kMemSize;
	}

	std::int32_t hkReferencedObject::GetReferenceCount() const
	{
		return referenceCount;
	}

	void hkReferencedObject::RemoveReference() const
	{
		using func_t = decltype(&hkReferencedObject::RemoveReference);
		REL::Relocation<func_t> func{ Offset::hkReferencedObject::RemoveReference };
		return func(this);
	}
}
