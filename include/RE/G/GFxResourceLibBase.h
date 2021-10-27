#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxResource;

	class GFxResourceLibBase : public GRefCountBase<GFxResourceLibBase, GStatGroups::kGStat_Default_Mem>
	{
	public:
		// add
		virtual void RemoveResourceOnRelease(GFxResource* a_res) = 0;  // 01
		virtual void PinResource(GFxResource* a_res) = 0;              // 02
		virtual void UnpinResource(GFxResource* a_res) = 0;            // 03
	};
	static_assert(sizeof(GFxResourceLibBase) == 0x10);
}
