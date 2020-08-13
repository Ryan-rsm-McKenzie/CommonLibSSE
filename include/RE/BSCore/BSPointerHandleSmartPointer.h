#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/NetImmerse/NiSmartPointer.h"


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
