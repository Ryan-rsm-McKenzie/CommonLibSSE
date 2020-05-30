#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/FormComponents/Components/DoNothingUnhandledPolicy.h"
#include "RE/FormComponents/Components/IHandlerFunctor.h"


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
