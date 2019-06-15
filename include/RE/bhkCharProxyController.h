#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkCharProxyController

#include "RE/bhkCharacterController.h"  // bhkCharacterController
#include "RE/bhkCharacterProxy.h"  // bhkCharacterProxy
#include "RE/hkpCharacterProxyListener.h"  // hkpCharacterProxyListener


namespace RE
{
	class bhkCharProxyController :
		public hkpCharacterProxyListener,		// 000
		public bhkCharacterController			// 010
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharProxyController;


		virtual ~bhkCharProxyController();																																					// 00

		// override (hkpCharacterProxyListener)
		virtual void	ProcessConstraintsCallback(const hkpCharacterProxy* a_proxy, const hkArray<hkpRootCdPoint>& a_manifold, hkpSimplexSolverInput& a_input) override;					// 01
		virtual void	ContactPointAddedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point) override;																// 02
		virtual void	ContactPointRemovedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point) override;																// 03
		virtual void	CharacterInteractionCallback(hkpCharacterProxy* a_proxy, hkpCharacterProxy* a_otherProxy, const hkContactPoint& a_contact) override;								// 04
		virtual void	ObjectInteractionCallback(hkpCharacterProxy* a_proxy, const hkpCharacterObjectInteractionEvent& a_input, hkpCharacterObjectInteractionResult& a_output) override;	// 05

		// override (bhkCharacterController)
		virtual void	GetLinearVelocity(hkVector4& a_velOut) const override;																												// 06
		virtual void	SetLinearVelocity(const hkVector4& a_vel) override;																													// 07


		// members
		bhkCharacterProxy	characterProxy;	// 340
		UInt64				unk5A0;			// 5A0
		UInt64				unk5A8;			// 5A8
	};
	STATIC_ASSERT(sizeof(bhkCharProxyController) == 0x5B0);
}
