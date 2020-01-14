#pragma once

#include "RE/BSPointerHandleManagerInterface.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	template <class T>
	class BSPointerHandleSmartPointer : public NiPointer<typename T::value_type>
	{
	public:
	};


	class Actor;
	using ActorHandlePtr = BSPointerHandleSmartPointer<BSPointerHandleManagerInterface<Actor>>;
	STATIC_ASSERT(sizeof(ActorHandlePtr) == 0x8);
}
