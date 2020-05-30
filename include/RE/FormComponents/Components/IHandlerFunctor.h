#pragma once

#include "RE/BSIntrusiveRefCounted.h"


namespace RE
{
	template <class Target, class Event>
	class IHandlerFunctor : public BSIntrusiveRefCounted
	{
	public:
		virtual ~IHandlerFunctor();	 // 00

		// add
		virtual bool ExecuteHandler(Target* a_target, const Event* a_event);


		// members
		UInt32 pad0C;  // 0C
	};
	STATIC_ASSERT(sizeof(IHandlerFunctor<void*, void*>) == 0x10);
}
