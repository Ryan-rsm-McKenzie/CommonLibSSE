#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiAVObject

#include "RE/NiObjectNET.h"  // NiObjectNET
#include "RE/NiTransform.h"  // NiTransform


namespace RE
{
	class BSFixedString;
	class NiNode;
	class NiPoint3;
	class NiProperty;


	class NiAVObject : public NiObjectNET
	{
	public:
		inline static const void* RTTI = RTTI_NiAVObject;


		enum class Flag : UInt32
		{
			kNone = 0,
			kAppCulled = 1 << 0,
			kSelectiveUpdate = 1 << 1,
			kSelectiveXForms = 1 << 2,
			kSelectivePropController = 1 << 3,
			kSelectiveRigid = 1 << 4,
			kDisplayObject = 1 << 5,
			kDisableSorting = 1 << 6,
			kSelectiveXFormsOverride = 1 << 7,
			kIsNode = 1 << 8
		};


		struct ControllerUpdateContext
		{
			enum class Flag : UInt32
			{
				kDirty = 1 << 0,
			};


			float	delta;	// 0
			Flag	flags;	// 4
		};
		STATIC_ASSERT(sizeof(ControllerUpdateContext) == 0x8);


		virtual ~NiAVObject();																									// 00

		// override (NiObjectNET)
		virtual NiRTTI*		GetRTTI() override;																					// 02
		virtual void		LoadBinary(NiStream* a_stream) override;															// 18
		virtual void		LinkObject(NiStream* a_stream) override;															// 19
		virtual bool		RegisterStreamables(NiStream* a_stream) override;													// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;															// 1B
		virtual bool		IsEqual(NiObject* a_object) override;																// 1C
		virtual void		ProcessClone(NiCloningProcess& a_cloning) override;													// 1D

		// add
		virtual void		UpdateControllers(ControllerUpdateContext* a_ctx);													// 25
		virtual void		UpdateNodeBound(ControllerUpdateContext* a_ctx);													// 26
		virtual void		ApplyTransform(const NiMatrix3& a_mtx, const NiPoint3& a_translate, bool a_onLeft);					// 27 - { return; }
		virtual void		SetMaterialNeedsUpdate(bool a_needsUpdate);															// 28 - { return; }
		virtual void		SetDefaultMaterialNeedsUpdateFlag(bool a_flag);														// 29 - { return; }
		virtual NiAVObject*	GetObjectByName(const BSFixedString& a_name);														// 2A
		virtual void		SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);	// 2B
		virtual void		UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);									// 2C
		virtual void		UpdateSelectedDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);							// 2D
		virtual void		UpdateRigidDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);								// 2E
		virtual void		UpdateWorldBound();																					// 2F - { return; }
		virtual void		UpdateWorldData(ControllerUpdateContext* a_ctx);													// 30
		virtual void		UpdateNoControllers(ControllerUpdateContext* a_ctx);												// 31
		virtual void		UpdateDownwardPassTempParent(NiNode* a_parent, ControllerUpdateContext* a_ctx);						// 32
		virtual void		Unk_33(void);																						// 33
		virtual void		Unk_34(void);																						// 34 - { return; }

		void UpdateNode(ControllerUpdateContext* a_ctx);


		// members
		NiNode*		parent;				// 030
		UInt32		unk038;				// 038
		UInt32		pad03C;				// 03C
		NiAVObject*	unk040;				// 040
		NiTransform	localTransform;		// 048
		NiTransform	worldTransform;		// 07C
		NiTransform	oldWorldTransform;	// 0B0
		float		unkE4;				// 0E4
		float		unkE8;				// 0E8
		float		unkEC;				// 0EC
		float		unkF0;				// 0F0
		UInt32		flags;				// 0F4 - bitfield
		float		unkF8;				// 0F8
		UInt32		unkFC;				// 0FC
		float		unk100;				// 100
		UInt32		unk104;				// 104
		UInt8		unk108;				// 108
		UInt8		unk109;				// 109 - bitfield
		UInt16		pad10A;				// 10A
		UInt32		pad10C;				// 10C
	};
	STATIC_ASSERT(sizeof(NiAVObject) == 0x110);
}
