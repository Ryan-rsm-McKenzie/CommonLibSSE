#include "RE/BSHavok/hkpCharacterProxyListener/bhkCharProxyController.h"

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpCharacterProxy/hkpCharacterProxy.h"


namespace RE
{
	hkpCharacterProxy* bhkCharProxyController::GetCharacterProxy() const
	{
		return static_cast<hkpCharacterProxy*>(proxy.referencedObject.get());
	}
}
