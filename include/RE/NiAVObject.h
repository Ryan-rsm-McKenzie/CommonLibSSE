#pragma once

#include "RE/NiBound.h"
#include "RE/NiObjectNET.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTransform.h"


namespace RE
{
	class bhkCollisionObject;
	class BSFixedString;
	class NiColorA;
	class NiNode;
	class NiPoint3;
	class TESObjectREFR;


	class NiAVObject : public NiObjectNET
	{
	public:
		inline static const void* RTTI = RTTI_NiAVObject;
		inline static const void* Ni_RTTI = NiRTTI_NiAVObject;


		enum class Flag : UInt32
		{
			kNone = 0,
			kHidden = 1 << 0,
			kSelectiveUpdate = 1 << 1,
			kSelectiveUpdateTransforms = 1 << 2,
			kSelectiveUpdateController = 1 << 3,
			kSelectiveUpdateRigid = 1 << 4,
			kDisplayObject = 1 << 5,
			kDisableSorting = 1 << 6,
			kSelectiveUpdateTransformsOverride = 1 << 7,
			kSaveExternalGeometryData = 1 << 9,
			kNoDecals = 1 << 10,
			kAlwaysDraw = 1 << 11,
			kMeshLOD = 1 << 12,
			kFixedBound = 1 << 13,
			kTopFadeNode = 1 << 14,
			kIgnoreFade = 1 << 15,
			kNoAnimSyncX = 1 << 16,
			kNoAnimSyncY = 1 << 17,
			kNoAnimSyncZ = 1 << 18,
			kNoAnimSyncS = 1 << 19,
			kNoDismember = 1 << 20,
			kNoDismemberValidity = 1 << 21,
			kRenderUse = 1 << 22,
			kMaterialsApplied = 1 << 23,
			kHighDetail = 1 << 24,
			kForceUpdate = 1 << 25,
			kPreProcessedNode = 1 << 26
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


		virtual ~NiAVObject();																										// 00

		// override (NiObjectNET)
		virtual const NiRTTI*	GetRTTI() const override;																			// 02
		virtual void			LoadBinary(NiStream& a_stream) override;															// 18
		virtual void			LinkObject(NiStream& a_stream) override;															// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;													// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;															// 1B
		virtual bool			IsEqual(NiObject* a_object) override;																// 1C
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;													// 1D

		// add
		virtual void			UpdateControllers(ControllerUpdateContext* a_ctx);													// 25
		virtual void			UpdateNodeBound(ControllerUpdateContext* a_ctx);													// 26
		virtual void			ApplyTransform(const NiMatrix3& a_mtx, const NiPoint3& a_translate, bool a_onLeft);					// 27 - { return; }
		virtual void			SetMaterialNeedsUpdate(bool a_needsUpdate);															// 28 - { return; }
		virtual void			SetDefaultMaterialNeedsUpdateFlag(bool a_flag);														// 29 - { return; }
		virtual NiAVObject*		GetObjectByName(const BSFixedString& a_name);														// 2A
		virtual void			SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);	// 2B
		virtual void			UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);									// 2C
		virtual void			UpdateSelectedDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);							// 2D
		virtual void			UpdateRigidDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2);								// 2E
		virtual void			UpdateWorldBound();																					// 2F - { return; }
		virtual void			UpdateWorldData(ControllerUpdateContext* a_ctx);													// 30
		virtual void			UpdateNoControllers(ControllerUpdateContext* a_ctx);												// 31
		virtual void			UpdateDownwardPassTempParent(NiNode* a_parent, ControllerUpdateContext* a_ctx);						// 32
		virtual void			Unk_33(void);																						// 33
		virtual void			Unk_34(void);																						// 34 - { return; }

		bool	SetMotionType(UInt32 a_motionType, bool a_arg2 = true, bool a_arg3 = false, bool a_allowActivate = true);
		void	UpdateModelHair(NiColorA** a_color);
		void	UpdateModelSkin(NiColorA** a_color);
		void	UpdateNode(ControllerUpdateContext* a_ctx);


		// members
		NiNode*							parent;				// 030
		UInt64							unk038;				// 038
		NiPointer<bhkCollisionObject>	collisionObject;	// 040
		NiTransform						localTransform;		// 048
		NiTransform						worldTransform;		// 07C
		NiTransform						oldWorldTransform;	// 0B0
		NiBound 						worldBound;			// 0E4
		Flag							flags;				// 0F4
		TESObjectREFR*					userData;			// 0F8
		float							unk100;				// 100 - scale?
		UInt32							unk104;				// 104
		UInt8							unk108;				// 108
		UInt8							unk109;				// 109 - bitfield
		UInt16							pad10A;				// 10A
		UInt32							pad10C;				// 10C
	};
	STATIC_ASSERT(sizeof(NiAVObject) == 0x110);
}
