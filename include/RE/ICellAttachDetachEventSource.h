#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ICellAttachDetachEventSource

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/BSTSingleton.h"  // BSTSingletonExplicit


namespace RE
{
	struct CellAttachDetachEvent;


	class ICellAttachDetachEventSource :
		BSTSingletonExplicit<ICellAttachDetachEventSource>,	// 08
		BSTEventSource<CellAttachDetachEvent>				// 08
	{
	public:
		inline static const void* RTTI = RTTI_ICellAttachDetachEventSource;


		virtual ~ICellAttachDetachEventSource();	// 00
	};
	STATIC_ASSERT(sizeof(ICellAttachDetachEventSource) == 0x60);
}
