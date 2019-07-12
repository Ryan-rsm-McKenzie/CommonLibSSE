#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiNode

#include "RE/NiAVObject.h"  // NiAVObject
#include "RE/NiTArray.h"  // NiTArray


namespace RE
{
	class NiNode : public NiAVObject
	{
	public:
		inline static const void* RTTI = RTTI_NiNode;


		virtual ~NiNode();																													// 00

		// override (NiAVObject)
		virtual NiRTTI*			GetRTTI() override;																							// 02
		virtual NiNode*			GetAsNiNode() override;																						// 03 - { return this; }
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner) override;															// 17
		virtual void			LoadBinary(NiStream* a_stream) override;																	// 18
		virtual void			LinkObject(NiStream* a_stream) override;																	// 19
		virtual bool			RegisterStreamables(NiStream* a_stream) override;															// 1A
		virtual void			SaveBinary(NiStream* a_stream) override;																	// 1B
		virtual bool			IsEqual(NiObject* a_object) override;																		// 1C
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;															// 1D
		virtual void			UpdateControllers(ControllerUpdateContext* a_ctx) override;													// 25
		virtual void			UpdateNodeBound(ControllerUpdateContext* a_ctx) override;													// 26
		virtual void			ApplyTransform(const NiMatrix3& a_mtx, const NiPoint3& a_translate, bool a_onLeft) override;				// 27
		virtual NiAVObject*		GetObjectByName(const BSFixedString& a_name) override;														// 2A
		virtual void			SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;	// 2B
		virtual void			UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;									// 2C
		virtual void			UpdateSelectedDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;							// 2D
		virtual void			UpdateRigidDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;								// 2E
		virtual void			UpdateWorldBound() override;																				// 2F
		virtual void			UpdateNoControllers(ControllerUpdateContext* a_ctx) override;												// 31

		// add
		virtual void			AttachChild(NiAVObject* a_child, bool a_firstAvail = false);												// 35
		virtual void			DetachChildAt(UInt32 a_idx, NiAVObject* a_child);															// 36
		virtual void			Unk_37(void);																								// 37
		virtual void			RemoveChild(NiAVObject* a_child);																			// 38
		virtual void			Unk_39(void);																								// 39
		virtual void			RemoveAt(UInt32 a_idx);																						// 3A
		virtual void			Unk_3B(void);																								// 3B
		virtual void			Unk_3C(void);																								// 3C
		virtual void			UpdateUpwardPass();																							// 3D

		static NiNode* Create(UInt32 a_arrBufLen = 0);

		bool SetMotionType(UInt32 a_motionType, UInt8 a_arg2, UInt8 a_arg3, bool a_allowActivate);


		// members
		NiTArray<NiAVObject*> children;	// 110
	};
	STATIC_ASSERT(sizeof(NiNode) == 0x128);
}
