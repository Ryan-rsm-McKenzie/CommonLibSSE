#pragma once

#include "RE/GFxEvent.h"  // GFxEvent
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class BSUIScaleformData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_BSUIScaleformData;


		virtual ~BSUIScaleformData();	// 00


		// members
		GFxEvent	event;	// 10
		UInt32		pad14;	// 14
	};
	STATIC_ASSERT(sizeof(BSUIScaleformData) == 0x18);
}
