#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTObjectDictionary.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/D/DoNothingUnhandledPolicy.h"
#include "RE/I/IHandlerFunctor.h"

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
		~BSResponse() override = default;  // 00

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
		BSTHashMap<Type, BSTSmartPointer<functor_type>>               handlerMap;      // ??
		BSTSmartPointer<BSResponse<Type, Handler, Parameter, Parent>> backupResponse;  // ??
	};

	template <class T, class Key>
	class ResponseDefinitionMissPolicy
	{
	public:
		virtual ~ResponseDefinitionMissPolicy();  // 00
	};
	//static_assert(sizeof(ResponseDefinitionMissPolicy) == 0x8);

	template <class T, class Key>
	class PreloadResponsesInitializationPolicy
	{
	public:
		virtual ~PreloadResponsesInitializationPolicy();  // 00
	};
	//static_assert(sizeof(PreloadResponsesInitializationPolicy) == 0x8);

	class Actor;
	using AnimResponse = BSResponse<BSFixedString, Actor, BSFixedString, DoNothingUnhandledPolicy>;
	static_assert(sizeof(AnimResponse) == 0x48);

	class ResponseDictionary :
		public BSTObjectDictionary<
			BSTSmartPointer<AnimResponse>,
			BSFixedString,
			ResponseDefinitionMissPolicy,
			PreloadResponsesInitializationPolicy>
	{
	public:
		static ResponseDictionary* GetSingleton();
	};
	static_assert(sizeof(ResponseDictionary) == 0x50);
}
