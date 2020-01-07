#include "RE/ExtraReferenceHandle.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraReferenceHandle::ExtraReferenceHandle() :
		ExtraReferenceHandle(ObjectRefHandle())
	{}


	ExtraReferenceHandle::ExtraReferenceHandle(ObjectRefHandle a_originalRef) :
		BSExtraData(),
		originalRef(a_originalRef),
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
		return originalRef != rhs->originalRef;
	}


	NiPointer<TESObjectREFR> ExtraReferenceHandle::GetOriginalReference()
	{
		return originalRef.get();
	}
}
