#include "RE/ExtraReferenceHandle.h"

#include "skse64/GameReferences.h"  // g_invalidRefHandle

#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	TESObjectREFR* ExtraReferenceHandle::GetReference()
	{
		TESObjectREFR* reference = 0;
		if (handle == *g_invalidRefHandle || handle == 0) {
			return 0;
		}

		TESObjectREFR::LookupByHandle(handle, reference);
		return reference;
	}
}
