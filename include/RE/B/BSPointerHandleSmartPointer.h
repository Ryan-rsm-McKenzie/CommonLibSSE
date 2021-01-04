#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	template <class T>
	class BSPointerHandleSmartPointer : public NiPointer<typename T::value_type>
	{
	public:
	};

	class Actor;
	using ActorHandlePtr = BSPointerHandleSmartPointer<BSPointerHandleManagerInterface<Actor>>;
	static_assert(sizeof(ActorHandlePtr) == 0x8);
}
