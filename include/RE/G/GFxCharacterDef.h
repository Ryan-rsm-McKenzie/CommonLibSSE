#pragma once

#include "RE/G/GFxResource.h"
#include "RE/G/GFxResourceID.h"
#include "RE/G/GPoint.h"

namespace RE
{
	class GFxCharacter;

	class GFxCharacterDef : public GFxResource
	{
	public:
		// add
		virtual void          Unk_04(void);                                            // 04
		virtual bool          Unk_05(const GPointF& a_pt, bool a_arg2, void* a_arg3);  // 05 - { return false; }
		virtual void          Unk_06(void);                                            // 06
		virtual void          Unk_07(void);                                            // 07
		virtual std::uint32_t GetVersion();                                            // 08
		virtual GFxCharacter* CreateCharacter();                                       // 09

		// members
		GFxResourceID resourceId;  // 18
		std::uint32_t pad1C;       // 1C
	};
	static_assert(sizeof(GFxCharacterDef) == 0x20);
}
