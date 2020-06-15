#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"
#include "RE/FormComponents/Components/DoNothingUnhandledPolicy.h"
#include "RE/FormComponents/Components/IHandlerFunctor.h"


namespace RE
{
	template <class Type, class Handler, class Parameter, template <class> class Parent>
	class BSResponse :
		public Parent<Parameter>,
		public BSIntrusiveRefCounted
	{
	public:
		BSResponse() = default;
		virtual ~BSResponse() = default;  // 00

		using BSIntrusiveRefCounted::operator new;
		using BSIntrusiveRefCounted::operator delete;


		// members
		BSTHashMap<Type, BSTSmartPointer<IHandlerFunctor<Handler, Parameter>>> handlerMap;		// ??
		BSTSmartPointer<BSResponse<Type, Handler, Parameter, Parent>>		   backupResponse;	// ??
	};


	class Actor;
	using AnimResponseBase = BSResponse<BSFixedString, Actor, BSFixedString, DoNothingUnhandledPolicy>;
	STATIC_ASSERT(sizeof(AnimResponseBase) == 0x48);
}
