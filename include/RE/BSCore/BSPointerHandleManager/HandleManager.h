#pragma once

#include "RE/BSCore/BSPointerHandleManager/BSPointerHandleManager.h"
#include "RE/BSCore/BSUntypedPointerHandle.h"


namespace RE
{
	class HandleManager : public BSPointerHandleManager<BSUntypedPointerHandle<>>
	{
	public:
	};
	static_assert(sizeof(HandleManager) == 0x1);
}
