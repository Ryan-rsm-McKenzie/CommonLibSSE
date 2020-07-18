#pragma once

#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSingleton.h"


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
	static_assert(sizeof(ICellAttachDetachEventSource) == 0x60);
}
