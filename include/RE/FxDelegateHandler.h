#pragma once

#include "RE/GRefCountBase.h"  // GRefCountBase
#include "RE/GStats.h"  // GStatGroups


namespace RE
{
	class FxDelegateArgs;
	class GString;


	class FxDelegateHandler : public GRefCountBase<FxDelegateHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		using CallbackFn = void(const FxDelegateArgs& a_params);


		class CallbackProcessor
		{
		public:
			virtual ~CallbackProcessor();

			// add
			virtual void Process(const GString& a_methodName, CallbackFn* a_method) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(CallbackProcessor) == 0x8);


		virtual ~FxDelegateHandler();

		// add
		virtual void Accept(CallbackProcessor* a_cbReg) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(FxDelegateHandler) == 0x10);
}
