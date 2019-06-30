#include "RE/RemoveCallbackVisitor.h"


namespace RE
{
	RemoveCallbackVisitor::RemoveCallbackVisitor(FxDelegate::CallbackHash* a_hash) :
		hash(a_hash)
	{}


	void RemoveCallbackVisitor::Process(const GString& a_methodName, FxDelegateHandler::CallbackFn a_method)
	{
		hash->Remove(a_methodName);
	}
}
