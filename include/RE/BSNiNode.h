#pragma once

#include "RE/NiNode.h"


namespace RE
{
	class BSNiNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNiNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSNiNode;


		virtual ~BSNiNode();  // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
	};
	STATIC_ASSERT(sizeof(BSNiNode) == 0x128);
}
