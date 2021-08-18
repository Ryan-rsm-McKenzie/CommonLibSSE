#include "RE/B/bhkCharProxyController.h"

#include "RE/H/hkpCharacterProxy.h"

namespace RE
{
	hkpCharacterProxy* bhkCharProxyController::GetCharacterProxy() const
	{
		return static_cast<hkpCharacterProxy*>(proxy.referencedObject.get());
	}
}
