#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSPointerHandleManager/BSPointerHandleManager.h"


namespace RE
{
	class HandleManager : public BSPointerHandleManager<BSUntypedPointerHandle<>>
	{
	public:
	};
	static_assert(std::is_empty_v<HandleManager>);
}
