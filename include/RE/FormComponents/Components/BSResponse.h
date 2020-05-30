#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTSmartPointer.h"
#include "RE/DoNothingUnhandledPolicy.h"
#include "RE/IHandlerFunctor.h"


namespace RE
{
	template <class Event, class Target, class T, template <class> class Parent>
	class BSResponse :
		public Parent<T>,
		public BSIntrusiveRefCounted
	{
	public:
		virtual ~BSResponse();	// 00


		BSTHashMap<Event, BSTSmartPointer<IHandlerFunctor<Target, Event>>> handlerMap;		// ??
		BSTSmartPointer<BSResponse<Event, Target, T, Parent>>			   backupResponse;	// ??
	};


	class Actor;
	using AnimResponseBase = BSResponse<BSFixedString, Actor, BSFixedString, DoNothingUnhandledPolicy>;
	STATIC_ASSERT(sizeof(AnimResponseBase) == 0x48);
}
