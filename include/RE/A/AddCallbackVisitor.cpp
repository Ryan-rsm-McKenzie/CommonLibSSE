#include "RE/A/AddCallbackVisitor.h"

namespace RE
{
	AddCallbackVisitor::AddCallbackVisitor(FxDelegateHandler* a_handler, FxDelegate::CallbackHash* a_hash) :
		handler(a_handler),
		hash(a_hash)
	{}

	void AddCallbackVisitor::Process(const GString& a_methodName, FxDelegateHandler::CallbackFn* a_method)
	{
		FxDelegate::CallbackDefn cbDef;
		cbDef.handler.reset(handler);
		cbDef.callback = a_method;
		hash->Add(a_methodName, cbDef);
	}
}
