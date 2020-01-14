#pragma once

#include "RE/HandleManager.h"


namespace RE
{
	template <class T, class Manager = HandleManager>
	class BSPointerHandleManagerInterface
	{
	public:
		using value_type = T;
	};
}
