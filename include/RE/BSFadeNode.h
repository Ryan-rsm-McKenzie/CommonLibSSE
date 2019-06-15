#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSFadeNode

#include "RE/NiNode.h"  // NiNode


namespace RE
{
	class BSFadeNode : public NiNode
	{
	public:
		inline static const void* RTTI = RTTI_BSFadeNode;


		virtual ~BSFadeNode();																						// 00

		// override (NiObject)
		virtual NiRTTI*			GetRTTI() override;																	// 02
		virtual BSFadeNode*		GetAsBSFadeNode() override;															// 05 - { return this; }
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner) override;									// 17
		virtual void			LoadBinary(NiStream* a_stream) override;											// 18
		virtual void			LinkObject(NiStream* a_stream) override;											// 19
		virtual bool			RegisterStreamables(NiStream* a_stream) override;									// 1A
		virtual void			SaveBinary(NiStream* a_stream) override;											// 1B
		virtual bool			IsEqual(NiObject* a_object) override;												// 1C
		virtual void			UpdateSelectedDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;	// 2D

		// override (NiAVObject)
		virtual void			Unk_34(void) override;																// 34

		// add
		virtual void			GetAsBSTreeNode();																	// 3E - { return 0; }
		virtual void			GetAsBSLeafAnimNode();																// 3F - { return 0; }


		// members
		UInt8	unk128;			// 128
		UInt8	unk129;			// 129
		UInt8	unk12A;			// 12A
		UInt8	unk12B;			// 12B
		UInt8	unk12C;			// 12C
		UInt8	unk12D;			// 12D
		UInt8	unk12E;			// 12E
		UInt8	unk12F;			// 12F
		float	currentFade;	// 130
		UInt32	pad134;			// 134
		UInt32	unk138;			// 138
		UInt32	unk13C;			// 13C
		float	unk140;			// 140
		UInt32	unk144;			// 144
		UInt32	unk148;			// 148
		float	unk14C;			// 14C
		UInt16	pad150;			// 150
		UInt8	unk152;			// 152
		UInt8	unk153;			// 153
		UInt32	unk154;			// 154
	};
	STATIC_ASSERT(offsetof(BSFadeNode, currentFade) == 0x130);
	STATIC_ASSERT(sizeof(BSFadeNode) == 0x158);
}
