#pragma once

#include "RE/B/bhkCharacterController.h"
#include "RE/B/bhkCharacterProxy.h"
#include "RE/H/hkpCharacterProxyListener.h"

namespace RE
{
	class hkpCharacterProxy;

	class bhkCharProxyController :
		public hkpCharacterProxyListener,  // 000
		public bhkCharacterController      // 010
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCharProxyController;

		~bhkCharProxyController() override;  // 00

		// override (hkpCharacterProxyListener)
		void ProcessConstraintsCallback(const hkpCharacterProxy* a_proxy, const hkArray<hkpRootCdPoint>& a_manifold, hkpSimplexSolverInput& a_input) override;                  // 01
		void ContactPointAddedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point) override;                                                               // 02
		void ContactPointRemovedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point) override;                                                             // 03
		void CharacterInteractionCallback(hkpCharacterProxy* a_proxy, hkpCharacterProxy* a_otherProxy, const hkContactPoint& a_contact) override;                               // 04
		void ObjectInteractionCallback(hkpCharacterProxy* a_proxy, const hkpCharacterObjectInteractionEvent& a_input, hkpCharacterObjectInteractionResult& a_output) override;  // 05

		// override (bhkCharacterController)
		void GetLinearVelocityImpl(hkVector4& a_velocity) const override;  // 06
		void SetLinearVelocityImpl(const hkVector4& a_velocity) override;  // 07

		hkpCharacterProxy* GetCharacterProxy() const;

		// members
		bhkCharacterProxy proxy;   // 340
		void*             unk5A0;  // 5A0 - smart ptr
		std::uint64_t     unk5A8;  // 5A8
	};
	static_assert(sizeof(bhkCharProxyController) == 0x5B0);
}
