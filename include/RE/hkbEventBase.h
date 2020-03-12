#pragma once

#include <type_traits>

#include "RE/hkRefPtr.h"


namespace RE
{
	class hkbEventPayload;


	class hkbEventBase
	{
	public:
		enum SystemEventIDs : UInt32
		{
			kNull = static_cast<std::underlying_type_t<SystemEventIDs>>(-1)
		};


		// members
		SystemEventIDs			  id;		// 00
		UInt32					  pad04;	// 04
		hkRefPtr<hkbEventPayload> payload;	// 08
	};
	STATIC_ASSERT(sizeof(hkbEventBase) == 0x10);
}
