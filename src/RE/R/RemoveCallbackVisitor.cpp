#include "RE/R/RemoveCallbackVisitor.h"

namespace RE
{
	RemoveCallbackVisitor::RemoveCallbackVisitor(FxDelegate::CallbackHash* a_hash) :
		hash(a_hash)
	{}

	void RemoveCallbackVisitor::Process(const GString& a_methodName, FxDelegateHandler::CallbackFn)
	{
		hash->Remove(a_methodName);
	}
}
