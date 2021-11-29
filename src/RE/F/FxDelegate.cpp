#include "RE/F/FxDelegate.h"

#include "RE/A/AddCallbackVisitor.h"
#include "RE/F/FxDelegateArgs.h"
#include "RE/F/FxResponseArgsBase.h"
#include "RE/G/GFxMovieView.h"
#include "RE/G/GFxValue.h"
#include "RE/R/RemoveCallbackVisitor.h"

namespace RE
{
	UPInt FxDelegate::CallbackHashFunctor::operator()(const GString& a_data) const
	{
		return GString::BernsteinHashFunction(a_data.c_str(), a_data.length());
	}

	void FxDelegate::Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, std::uint32_t a_argCount)
	{
		auto cbDef = callbacks.GetAlt(a_methodName);
		if (cbDef) {
			FxDelegateArgs params(a_args[0], cbDef->handler.get(), a_movieView, &a_args[1], a_argCount - 1);
			cbDef->callback(params);
		}
	}

	void FxDelegate::Invoke(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args)
	{
		assert(a_movieView);
		GFxValue*           values = nullptr;
		const std::uint32_t numValues = a_args.GetValues(&values);
		if (values) {
			values[0] = a_methodName;
			a_movieView->InvokeNoReturn("call", values, numValues);
		}
	}

	void FxDelegate::Invoke2(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args)
	{
		assert(a_movieView);
		GFxValue*           values = nullptr;
		const std::uint32_t numValues = a_args.GetValues(&values);
		if (values) {
			a_movieView->Invoke(a_methodName, nullptr, values + 1, numValues - 1);
		}
	}

	void FxDelegate::RegisterHandler(FxDelegateHandler* a_callback)
	{
		assert(a_callback);
		AddCallbackVisitor reg(a_callback, &callbacks);
		a_callback->Accept(&reg);
	}

	void FxDelegate::UnregisterHandler(FxDelegateHandler* a_callback)
	{
		assert(a_callback);
		RemoveCallbackVisitor reg(&callbacks);
		a_callback->Accept(&reg);
	}
}
