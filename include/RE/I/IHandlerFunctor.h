#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTObjectDictionary.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	template <class Handler, class Parameter>
	class IHandlerFunctor :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		IHandlerFunctor() = default;
		virtual ~IHandlerFunctor() = default;  // 00

		// add
		virtual bool ExecuteHandler(Handler& a_handler, const Parameter& a_parameter) = 0;

		inline bool operator()(Handler& a_handler, const Parameter& a_parameter)
		{
			return ExecuteHandler(a_handler, a_parameter);
		}

		// members
		std::uint32_t pad0C;  // 0C
	};
	//static_assert(sizeof(IHandlerFunctor) == 0x10);

	class Actor;
	using AnimHandler = IHandlerFunctor<Actor, BSFixedString>;
	static_assert(sizeof(AnimHandler) == 0x10);

	template <class T, class Key>
	class HandlerCreationMissPolicy
	{
	public:
		virtual ~HandlerCreationMissPolicy();  // 00
	};
	//static_assert(sizeof(HandlerCreationMissPolicy) == 0x8);

	template <class T, class Key>
	class NoInitializationPolicy
	{
	public:
		virtual ~NoInitializationPolicy();  // 00
	};
	//static_assert(sizeof(NoInitializationPolicy) == 0x8);

	class HandlerDictionary :
		public BSTObjectDictionary<
			BSTSmartPointer<AnimHandler>,
			BSFixedString,
			HandlerCreationMissPolicy,
			NoInitializationPolicy>
	{
	public:
		static HandlerDictionary* GetSingleton();
	};
	static_assert(sizeof(HandlerDictionary) == 0x50);
}
