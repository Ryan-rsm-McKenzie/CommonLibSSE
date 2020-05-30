#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	struct CellAttachDetachEvent;


	class ICellAttachDetachEventSource :
		BSTSingletonExplicit<ICellAttachDetachEventSource>,	 // 08
		BSTEventSource<CellAttachDetachEvent>				 // 08
	{
	public:
		inline static constexpr auto RTTI = RTTI_ICellAttachDetachEventSource;


		virtual ~ICellAttachDetachEventSource();  // 00
	};
	STATIC_ASSERT(sizeof(ICellAttachDetachEventSource) == 0x60);
}
