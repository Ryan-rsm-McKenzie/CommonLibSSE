#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSFaceGenAnimationData;
	class NiNode;

	class BSFaceGenNiNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenNiNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFaceGenNiNode;

		virtual ~BSFaceGenNiNode();	 // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;													// 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;						// 17
		virtual void		  UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;	// 2C

		// add
		virtual void FixSkinInstances(NiNode* a_skeleton, bool a_arg2);	 // 3E

		// members
		NiMatrix3						  baseRotation;	  // 128
		std::uint32_t					  pad14C;		  // 14C
		NiPointer<BSFaceGenAnimationData> animationData;  // 150
		float							  lastTime;		  // 158
		ActorHandle						  unk15C;		  // 15C
		std::uint16_t					  flags;		  // 160
		std::uint16_t					  pad162;		  // 162
		std::uint32_t					  pad164;		  // 164
	};
	static_assert(sizeof(BSFaceGenNiNode) == 0x168);
}
