#pragma once

#include "RE/GRefCountBase.h"  // GRefCountBase
#include "RE/GStats.h"  // GStatGroups


namespace RE
{
	class GFxValue;
	class GFxMovie;


	class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		struct Params
		{
			GFxValue*	retVal;				// 00
			GFxMovie*	movie;				// 08
			GFxValue*	thisPtr;			// 10
			GFxValue*	argsWithThisRef;	// 18
			GFxValue*	args;				// 20
			UInt32		argCount;			// 28
			UInt32		pad2C;				// 2C
			void*		userData;			// 30
		};
		STATIC_ASSERT(sizeof(Params) == 0x38);


		virtual ~GFxFunctionHandler();					// 00

		// add
		virtual void Call(const Params& a_params) = 0;	// 01
	};


	typedef GFxFunctionHandler GFxFunctionContext;
}
