#pragma once

#include "RE/G/GString.h"

namespace RE
{
	class GMemoryHeap;
	class GStatBag;

	class GFxResourceReport
	{
	public:
		virtual ~GFxResourceReport()  // 00
		{}

		// add
		virtual GString GetResourceName()  // 01
		{
			return GString();
		}

		virtual GMemoryHeap* GetResourceHeap() const  // 02
		{
			return nullptr;
		}

		virtual void GetStats([[maybe_unused]] GStatBag* a_bag, [[maybe_unused]] bool a_reset = true)  // 03
		{}
	};
	static_assert(sizeof(GFxResourceReport) == 0x8);
}
