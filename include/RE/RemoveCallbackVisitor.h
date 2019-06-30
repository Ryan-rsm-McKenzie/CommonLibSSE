#pragma once

#include "skse64/GameRTTI.h"  // RTTI_RemoveCallbackVisitor

#include "RE/FxDelegate.h"  // FxDelegate
#include "RE/FxDelegateHandler.h"  // FxDelegateHandler


namespace RE
{
	class RemoveCallbackVisitor : public FxDelegateHandler::CallbackProcessor
	{
	public:
		inline static const void* RTTI = RTTI_RemoveCallbackVisitor;


		RemoveCallbackVisitor(FxDelegate::CallbackHash* a_hash);
		virtual ~RemoveCallbackVisitor() = default;															// 00

		// override (FxDelegateHandler::CallbackProcessor)
		virtual void Process(const GString& a_methodName, FxDelegateHandler::CallbackFn a_method) override;	// 01


		// members
		FxDelegate::CallbackHash* hash;	// 08
	};
	STATIC_ASSERT(sizeof(RemoveCallbackVisitor) == 0x10);
}
