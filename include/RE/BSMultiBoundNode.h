#pragma once

#include "RE/BSCullingProcess.h"
#include "RE/BSNiNode.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSMultiBound;


	class BSMultiBoundNode : public BSNiNode
	{
	public:
		inline static const void* RTTI = RTTI_BSMultiBoundNode;
		inline static const void* Ni_RTTI = NiRTTI_BSMultiBoundNode;


		virtual ~BSMultiBoundNode();	// 00

		// override (BSNiNode)
		virtual const NiRTTI*		GetRTTI() const override;											// 02
		virtual BSMultiBoundNode*	GetAsBSMultiBoundNode();											// 06 - { return this; }
		virtual NiObject*			CreateClone(NiCloningProcess& a_cloning);							// 17
		virtual void				LoadBinary(NiStream& a_stream);										// 18
		virtual void				LinkObject(NiStream& a_stream);										// 19
		virtual bool				RegisterStreamables(NiStream& a_stream);							// 1A
		virtual void				SaveBinary(NiStream& a_stream);										// 1B
		virtual bool				IsEqual(NiObject* a_object);										// 1C
		virtual void				UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);	// 2C
		virtual void				UpdateWorldBound();													// 2F
		virtual void				Unk_34(void);														// 34
		virtual void				UpdateUpwardPass();													// 3D

		// add
		virtual void				Unk_3E(void);														// 3E - { return 0; }
		virtual void				Unk_3F(void);														// 3F
		virtual void				Unk_40(void);														// 40
		virtual void				Unk_41(void);														// 41


		// members
		NiPointer<BSMultiBound>				multiBound;		// 128
		BSCullingProcess::BSCPCullingType	cullingMode;	// 130
		FLOAT								lastAccumTime;	// 134
	};
	STATIC_ASSERT(sizeof(BSMultiBoundNode) == 0x138);
}
