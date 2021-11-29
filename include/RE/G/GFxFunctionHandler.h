#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxValue;
	class GFxMovie;

	class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		inline static constexpr auto RTTI = RTTI_GFxFunctionHandler;

		struct Params
		{
			GFxValue* const     retVal;           // 00
			GFxMovie* const     movie;            // 08
			GFxValue* const     thisPtr;          // 10
			GFxValue* const     argsWithThisRef;  // 18
			GFxValue* const     args;             // 20
			const std::uint32_t argCount;         // 28
			const std::uint32_t pad2C;            // 2C
			void* const         userData;         // 30
		};
		static_assert(sizeof(Params) == 0x38);

		virtual ~GFxFunctionHandler() = default;  // 00

		// add
		virtual void Call(Params& a_params) = 0;  // 01
	};
	static_assert(sizeof(GFxFunctionHandler) == 0x10);
}
