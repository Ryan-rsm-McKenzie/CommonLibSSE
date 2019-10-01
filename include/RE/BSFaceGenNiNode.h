#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSFaceGenNiNode
#include "skse64/NiRTTI.h"  // NiRTTI_BSFaceGenNiNode

#include "RE/NiNode.h"  // NiNode


namespace RE
{
	class BSFaceGenNiNode : public NiNode
	{
	public:
		inline static const void* RTTI = RTTI_BSFaceGenNiNode;
		inline static const void* Ni_RTTI = NiRTTI_BSFaceGenNiNode;


		virtual ~BSFaceGenNiNode();																			// 00

		// override (NiNode)
		virtual const NiRTTI*	GetRTTI() const override;													// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;							// 17
		virtual void			UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;	// 2C

		// add
		virtual void			Unk_3E(void);																// 3E


		// members
		float		unk128;	// 128
		UInt32		unk12C;	// 12C
		UInt64		unk130;	// 130
		float		unk138;	// 138
		UInt32		unk13C;	// 13C
		UInt64		unk140;	// 140
		float		unk148;	// 148
		UInt32		unk14C;	// 14C
		void*		unk150;	// 150 - smart ptr
		float		unk158;	// 158
		RefHandle	unk15C;	// 15C
		UInt64		unk160;	// 160
	};
	STATIC_ASSERT(sizeof(BSFaceGenNiNode) == 0x168);
}
