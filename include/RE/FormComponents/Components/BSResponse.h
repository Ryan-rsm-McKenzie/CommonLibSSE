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
		using functor_type = IHandlerFunctor<Handler, Parameter>;

		BSResponse() = default;
		virtual ~BSResponse() = default;  // 00

		using BSIntrusiveRefCounted::operator new;
		using BSIntrusiveRefCounted::operator delete;

		[[nodiscard]] inline BSTSmartPointer<functor_type> GetHandler(const Type& a_type)
		{
			auto it = handlerMap.find(a_type);
			if (it != handlerMap.end()) {
				return it->second;
			} else if (backupResponse) {
				return backupResponse->GetHandler(a_type);
			} else {
				return nullptr;
			}
		}


		// members
		BSTHashMap<Type, BSTSmartPointer<functor_type>>				  handlerMap;	   // ??
		BSTSmartPointer<BSResponse<Type, Handler, Parameter, Parent>> backupResponse;  // ??
	};


	class Actor;
	using AnimResponseBase = BSResponse<BSFixedString, Actor, BSFixedString, DoNothingUnhandledPolicy>;
	STATIC_ASSERT(sizeof(AnimResponseBase) == 0x48);
}
