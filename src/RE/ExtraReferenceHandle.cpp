#include "RE/ExtraReferenceHandle.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraReferenceHandle::ExtraReferenceHandle() :
		ExtraReferenceHandle(ObjectRefHandle())
	{}


	ExtraReferenceHandle::ExtraReferenceHandle(ObjectRefHandle a_containerRef) :
		BSExtraData(),
		containerRef(a_containerRef),
		pad14(0)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraReferenceHandle::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}


	ExtraDataType ExtraReferenceHandle::GetType() const
	{
		return ExtraDataType::kReferenceHandle;
	}


	bool ExtraReferenceHandle::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraReferenceHandle*>(a_rhs);
		return containerRef != rhs->containerRef;
	}


	NiPointer<TESObjectREFR> ExtraReferenceHandle::GetOriginalReference()
	{
		return containerRef.get();
	}
}
