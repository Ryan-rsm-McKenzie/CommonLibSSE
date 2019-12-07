#include "RE/ExtraReferenceHandle.h"

#include "skse64/GameReferences.h"

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraReferenceHandle::ExtraReferenceHandle() :
		ExtraReferenceHandle(*g_invalidRefHandle)
	{}


	ExtraReferenceHandle::ExtraReferenceHandle(RefHandle a_refHandle) :
		BSExtraData(),
		handle(a_refHandle),
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
		return handle != rhs->handle;
	}


	NiPointer<TESObjectREFR> ExtraReferenceHandle::GetReference()
	{
		return TESObjectREFR::LookupByHandle(handle);
	}
}
