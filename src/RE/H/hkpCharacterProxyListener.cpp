#include "RE/H/hkpCharacterProxyListener.h"

namespace RE
{
	hkpCharacterProxyListener::~hkpCharacterProxyListener()
	{}

	void hkpCharacterProxyListener::ProcessConstraintsCallback(const hkpCharacterProxy*, const hkArray<hkpRootCdPoint>&, hkpSimplexSolverInput&)
	{}

	void hkpCharacterProxyListener::ContactPointAddedCallback(const hkpCharacterProxy*, const hkpRootCdPoint&)
	{}

	void hkpCharacterProxyListener::ContactPointRemovedCallback(const hkpCharacterProxy*, const hkpRootCdPoint&)
	{}

	void hkpCharacterProxyListener::CharacterInteractionCallback(hkpCharacterProxy*, hkpCharacterProxy*, const hkContactPoint&)
	{}

	void hkpCharacterProxyListener::ObjectInteractionCallback(hkpCharacterProxy*, const hkpCharacterObjectInteractionEvent&, hkpCharacterObjectInteractionResult&)
	{}
}
