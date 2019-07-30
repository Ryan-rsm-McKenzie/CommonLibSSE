#pragma once

#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class GFxEvent;


	class BSUIScaleformData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_BSUIScaleformData;


		virtual ~BSUIScaleformData();	// 00


		// members
		GFxEvent* event;	// 10
	};
	STATIC_ASSERT(sizeof(BSUIScaleformData) == 0x18);
}
