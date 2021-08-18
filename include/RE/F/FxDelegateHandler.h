#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class FxDelegateArgs;
	class GString;

	class FxDelegateHandler : public GRefCountBase<FxDelegateHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		inline static constexpr auto RTTI = RTTI_FxDelegateHandler;

		using CallbackFn = void(const FxDelegateArgs& a_params);

		class CallbackProcessor
		{
		public:
			inline static constexpr auto RTTI = RTTI_FxDelegateHandler__CallbackProcessor;

			virtual ~CallbackProcessor() = default;  // 00

			// add
			virtual void Process(const GString& a_methodName, CallbackFn* a_method) = 0;  // 01
		};
		static_assert(sizeof(CallbackProcessor) == 0x8);

		~FxDelegateHandler() override = default;  // 00

		// add
		virtual void Accept(CallbackProcessor* a_cbReg) = 0;  // 01
	};
	static_assert(sizeof(FxDelegateHandler) == 0x10);
}
