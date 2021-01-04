#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSPointerHandleManager.h"

namespace RE
{
	class HandleManager : public BSPointerHandleManager<BSUntypedPointerHandle<>>
	{
	public:
	};
	static_assert(std::is_empty_v<HandleManager>);
}
