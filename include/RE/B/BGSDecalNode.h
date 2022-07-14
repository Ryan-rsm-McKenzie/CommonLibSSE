#pragma once

#include "RE/N/NiNode.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSTempEffect;

	class BGSDecalNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDecalNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BGSDecalNode;

		~BGSDecalNode() override;  // 00

		// override (NiNode)
		const NiRTTI* GetRTTI() const override;                            // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;   // 17
		void          ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
		void          OnVisible(NiCullingProcess& a_process) override;     // 34

		// add
		virtual std::uint8_t Unk_3E();                                               // 3E - { return 1; }
		virtual void         AttachDecal(BSTempEffect* a_decal, bool a_firstAvail);  // 3F

		// members
		BSTArray<NiPointer<BSTempEffect>> decals;     // 128
		bool                              isSkinned;  // 140
	};
	static_assert(sizeof(BGSDecalNode) == 0x148);
}
