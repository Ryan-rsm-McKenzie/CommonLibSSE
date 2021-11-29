#pragma once

#include "RE/F/FxDelegate.h"
#include "RE/F/FxDelegateHandler.h"

namespace RE
{
	class RemoveCallbackVisitor : public FxDelegateHandler::CallbackProcessor
	{
	public:
		inline static constexpr auto RTTI = RTTI_RemoveCallbackVisitor;

		RemoveCallbackVisitor(FxDelegate::CallbackHash* a_hash);
		~RemoveCallbackVisitor() override = default;  // 00

		// override (FxDelegateHandler::CallbackProcessor)
		void Process(const GString& a_methodName, FxDelegateHandler::CallbackFn a_method) override;  // 01

		// members
		FxDelegate::CallbackHash* hash;  // 08
	};
	static_assert(sizeof(RemoveCallbackVisitor) == 0x10);
}
