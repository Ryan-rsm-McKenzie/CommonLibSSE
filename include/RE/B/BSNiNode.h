#pragma once

#include "RE/N/NiNode.h"

namespace RE
{
	class BSNiNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNiNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSNiNode;

		~BSNiNode() override;  // 00

		// override (NiNode)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
	};
	static_assert(sizeof(BSNiNode) == 0x128);
}
