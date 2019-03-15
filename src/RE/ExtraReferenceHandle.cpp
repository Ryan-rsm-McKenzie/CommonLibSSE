#include "RE/ExtraReferenceHandle.h"

#include "skse64/GameReferences.h"  // g_invalidRefHandle

#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	TESObjectREFR* ExtraReferenceHandle::GetReference()
	{
		TESObjectREFRPtr refPtr;
		if (handle == *g_invalidRefHandle || handle == 0) {
			return 0;
		}

		TESObjectREFR::LookupByHandle(handle, refPtr);
		return refPtr.get();
	}
}
