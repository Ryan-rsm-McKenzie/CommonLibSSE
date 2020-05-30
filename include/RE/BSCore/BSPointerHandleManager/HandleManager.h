#pragma once

#include "RE/BSPointerHandleManager.h"
#include "RE/BSUntypedPointerHandle.h"


namespace RE
{
	class HandleManager : public BSPointerHandleManager<BSUntypedPointerHandle<>>
	{
	public:
	};
	STATIC_ASSERT(sizeof(HandleManager) == 0x1);
}
