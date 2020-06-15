#pragma once

#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
	template <class Handler, class Parameter>
	class IHandlerFunctor : public BSIntrusiveRefCounted
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
		UInt32 pad0C;  // 0C
	};
	STATIC_ASSERT(sizeof(IHandlerFunctor<void*, void*>) == 0x10);
}
