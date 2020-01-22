#include "RE/bhkCharProxyController.h"

#include "RE/hkpCharacterProxy.h"


namespace RE
{
	hkpCharacterProxy* bhkCharProxyController::GetCharacterProxy() const
	{
		return static_cast<hkpCharacterProxy*>(proxy.referencedObject.get());
	}
}
