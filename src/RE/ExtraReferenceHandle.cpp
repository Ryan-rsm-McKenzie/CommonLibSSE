#include "RE/ExtraReferenceHandle.h"

#include "skse64/GameExtraData.h"  // s_ExtraReferenceHandleVtbl
#include "skse64/GameReferences.h"  // g_invalidRefHandle

#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	ExtraReferenceHandle::ExtraReferenceHandle() :
		BSExtraData(),
		handle(*g_invalidRefHandle),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraReferenceHandleVtbl.GetUIntPtr();
	}


	ExtraReferenceHandle::ExtraReferenceHandle(RefHandle a_refHandle) :
		BSExtraData(),
		handle(a_refHandle),
		pad14(0)
	{
		((std::uintptr_t*)this)[0] = s_ExtraReferenceHandleVtbl.GetUIntPtr();
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
		NiPointer<TESObjectREFR> ref;
		TESObjectREFR::LookupByHandle(handle, ref);
		return ref;
	}
}
