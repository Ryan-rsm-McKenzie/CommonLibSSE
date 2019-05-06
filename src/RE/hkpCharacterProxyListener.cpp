#include "RE/hkpCharacterProxyListener.h"


namespace RE
{
	hkpCharacterProxyListener::~hkpCharacterProxyListener()
	{}


	void hkpCharacterProxyListener::ProcessConstraintsCallback(const hkpCharacterProxy* a_proxy, const hkArray<hkpRootCdPoint>& a_manifold, hkpSimplexSolverInput& a_input)
	{}


	void hkpCharacterProxyListener::ContactPointAddedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point)
	{}


	void hkpCharacterProxyListener::ContactPointRemovedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point)
	{}


	void hkpCharacterProxyListener::CharacterInteractionCallback(hkpCharacterProxy* a_proxy, hkpCharacterProxy* a_otherProxy, const hkContactPoint& a_contact)
	{}


	void hkpCharacterProxyListener::ObjectInteractionCallback(hkpCharacterProxy* a_proxy, const hkpCharacterObjectInteractionEvent& a_input, hkpCharacterObjectInteractionResult& a_output)
	{}
}
