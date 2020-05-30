#pragma once

#include "RE/NiNode.h"


namespace RE
{
	class BSLeafAnimNode;
	class BSTreeNode;


	class BSFadeNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFadeNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFadeNode;


		virtual ~BSFadeNode();	// 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;													 // 02
		virtual BSFadeNode*	  AsFadeNode() override;													 // 05 - { return this; }
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;						 // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;									 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;									 // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;							 // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;									 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;										 // 1C
		virtual void		  UpdateSelectedDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;	 // 2D
		virtual void		  OnVisible(NiCullingProcess& a_process) override;							 // 34

		// add
		virtual BSTreeNode*		AsTreeNode();	   // 3E - { return 0; }
		virtual BSLeafAnimNode* AsLeafAnimNode();  // 3F - { return 0; }


		// members
		float  unk128;		 // 128
		float  unk12C;		 // 12C
		float  currentFade;	 // 130
		UInt32 unk134;		 // 134
		UInt32 unk138;		 // 138
		UInt32 unk13C;		 // 13C
		float  unk140;		 // 140
		UInt32 unk144;		 // 144
		UInt32 unk148;		 // 148
		float  unk14C;		 // 14C
		UInt16 unk150;		 // 150
		UInt8  unk152;		 // 152
		UInt8  unk153;		 // 153
		UInt8  unk154;		 // 154
		UInt8  unk155;		 // 155
		UInt16 unk156;		 // 156
	};
	STATIC_ASSERT(sizeof(BSFadeNode) == 0x158);
}
