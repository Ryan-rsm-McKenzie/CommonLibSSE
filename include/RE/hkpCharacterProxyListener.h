#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCharacterProxyListener

#include "RE/hkArray.h"  // hkArray


namespace RE
{
	class hkContactPoint;
	class hkpCharacterProxy;
	struct hkpCharacterObjectInteractionEvent;
	struct hkpCharacterObjectInteractionResult;
	struct hkpRootCdPoint;
	struct hkpSimplexSolverInput;


	class hkpCharacterProxyListener
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterProxyListener;


		virtual ~hkpCharacterProxyListener();																																		// 00

		// add
		virtual void	ProcessConstraintsCallback(const hkpCharacterProxy* a_proxy, const hkArray<hkpRootCdPoint>& a_manifold, hkpSimplexSolverInput& a_input);					// 01 - { return; }
		virtual void	ContactPointAddedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point);																	// 02 - { return; }
		virtual void	ContactPointRemovedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point);																// 03 - { return; }
		virtual void	CharacterInteractionCallback(hkpCharacterProxy* a_proxy, hkpCharacterProxy* a_otherProxy, const hkContactPoint& a_contact);									// 04 - { return; }
		virtual void	ObjectInteractionCallback(hkpCharacterProxy* a_proxy, const hkpCharacterObjectInteractionEvent& a_input, hkpCharacterObjectInteractionResult& a_output);	// 05 - { return; }
	};
	STATIC_ASSERT(sizeof(hkpCharacterProxyListener) == 0x8);
}
