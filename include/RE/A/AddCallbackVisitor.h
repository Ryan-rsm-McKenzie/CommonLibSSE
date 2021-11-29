#pragma once

#include "RE/F/FxDelegate.h"
#include "RE/F/FxDelegateHandler.h"

namespace RE
{
	class AddCallbackVisitor : public FxDelegateHandler::CallbackProcessor
	{
	public:
		inline static constexpr auto RTTI = RTTI_AddCallbackVisitor;

		AddCallbackVisitor(FxDelegateHandler* a_handler, FxDelegate::CallbackHash* a_hash);
		~AddCallbackVisitor() override = default;  // 00

		// override (FxDelegateHandler::CallbackProcessor)
		void Process(const GString& a_methodName, FxDelegateHandler::CallbackFn* a_method) override;  // 01

		// members
		FxDelegateHandler*        handler;  // 08
		FxDelegate::CallbackHash* hash;     // 10
	};
	static_assert(sizeof(AddCallbackVisitor) == 0x18);
}
