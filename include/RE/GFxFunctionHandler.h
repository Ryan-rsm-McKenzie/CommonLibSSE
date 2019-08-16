#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GFxFunctionHandler

#include "RE/GRefCountBase.h"  // GRefCountBase
#include "RE/GStats.h"  // GStatGroups


namespace RE
{
	class GFxValue;
	class GFxMovie;


	class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		inline static const void* RTTI = RTTI_GFxFunctionHandler;


		struct Params
		{
			GFxValue* const	retVal;				// 00
			GFxMovie* const	movie;				// 08
			GFxValue* const	thisPtr;			// 10
			GFxValue* const	argsWithThisRef;	// 18
			GFxValue* const	args;				// 20
			const UInt32	argCount;			// 28
			const UInt32	pad2C;				// 2C
			void* const		userData;			// 30
		};
		STATIC_ASSERT(sizeof(Params) == 0x38);


		virtual ~GFxFunctionHandler() = default;	// 00

		// add
		virtual void Call(Params& a_params) = 0;	// 01
	};
}
