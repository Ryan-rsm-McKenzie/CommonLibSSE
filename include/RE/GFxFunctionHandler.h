#pragma once

#include "RE/GRefCountBase.h"  // GRefCountBase


namespace RE
{
	class GFxValue;
	class GFxMovie;


	class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler>
	{
	public:
		struct Params
		{
			GFxValue*	a_retVal;			// 00
			GFxMovie*	a_movie;			// 08
			GFxValue*	a_this;				// 10
			GFxValue*	a_argsWithThisRef;	// 18
			GFxValue*	a_args;				// 20
			UInt32		argCount;			// 28
			UInt32		pad2C;				// 2C
			void*		userData;			// 30
		};
		STATIC_ASSERT(sizeof(Params) == 0x38);


		virtual ~GFxFunctionHandler();					// 00

		// add
		virtual void Call(const Params& a_params) = 0;	// 01
	};
}
