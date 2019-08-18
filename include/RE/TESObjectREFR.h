#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectREFR

#include "RE/BaseExtraList.h"  // BaseExtraList
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSHandleRefObject.h"  // BSHandleRefObject
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/FormTypes.h"  // FormTypes
#include "RE/IAnimationGraphManagerHolder.h"  // IAnimationGraphManagerHolder
#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/NiSmartPointer.h"  // NiSmartPointer
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BaseExtraList;
	class BSAnimNoteReceiver;
	class BSFaceGenAnimationData;
	class BSFaceGenNiNode;
	class BSFlattenedBoneTree;
	class InventoryChanges;
	class MagicCaster;
	class MagicTarget;
	class NiAVObject;
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
	class TESBoundObject;
	class TESContainer;
	struct Biped;
	struct BSAnimationGraphEvent;
	struct LockState;


	NiSmartPointer(TESObjectREFR);


	class TESObjectREFR :
		public TESForm,								// 00
		public BSHandleRefObject,					// 20
		public BSTEventSink<BSAnimationGraphEvent>,	// 30
		public IAnimationGraphManagerHolder			// 38
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectREFR;


		enum { kTypeID = FormType::Reference };


		enum class RemoveType : UInt32
		{
			kRemove,
			kSteal,
			kTrade,
			kDrop,
			kTake,
			kUnk05
		};


		enum class MotionType : UInt32
		{
			kDynamic = 1,
			kSphereInertia = 2,
			kBoxInertia = 3,
			kKeyframed = 4,
			kFixed = 5,
			kThinBoxInertia = 6,
			kCharacter = 7
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kFlag4 = 1 << 4,
				kIsGroundPiece = kFlag4,
				kCollisionsDisabled = kFlag4,

				kDeleted = 1 << 5,
				kHiddenFromLocalMap = 1 << 6,	// TESObjectSTAT
				kTurnOffFire = 1 << 7,

				kFlag8 = 1 << 8,
				kInaccessible = kFlag8,	// TESObjectDOOR
				kLODRespectsEnableState = kFlag8,	// TESObjectSTAT
				kStartsDead = kFlag8,	// TESNPC
				kDoesntLightWater = kFlag8,

				kMotionBlur = 1 << 9,	// TESObjectSTAT
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,

				kFlag13 = 1 << 13,
				kStartUnconscious = kFlag13,	// TESNPC
				kSkyMarker = kFlag13,
				kHarvested = kFlag13,	// TESObjectTREE

				kIsFullLOD = 1 << 16,

				kFlag17 = 1 << 17,
				kNeverFades = kFlag17,	// TESObjectLIGH
				kDoesntLightLandscape = kFlag17,

				kNoAIAcquire = 1 << 25,
				kCollisionGeometry_Filter = 1 << 26,
				kCollisionGeometry_BoundingBox = 1 << 27,
				kReflectedByAutoWater = 1 << 28,

				kDontHavokSettle = 1 << 29,

				kFlag30 = 1 << 30,
				kGround = kFlag30,
				kRespawns = kFlag30,

				kMultibound = (UInt32)1 << 31
			};
		};


		struct LoadedState
		{
			UInt8	todo[0x68];	// 00
			NiNode*	node;		// 68
			// ... probably more
		};
		STATIC_ASSERT(offsetof(LoadedState, node) == 0x68);


		virtual ~TESObjectREFR();																																																	// 00

		// override (TESForm)
		virtual void					InitDefaults() override;																																									// 04
		virtual void					ReleaseManagedData() override;																																								// 05
		virtual bool					LoadForm(TESFile* a_mod) override;																																							// 06
		virtual TESForm*				DupulicateForm(void* a_arg1, void* a_arg2) override;																																		// 09
		virtual bool					PreSaveBuffer(BGSSaveFormBuffer* a_buf) override;																																			// 0D
		virtual void					SaveBuffer(BGSSaveFormBuffer* a_buf) override;																																				// 0E
		virtual void					LoadBuffer(BGSLoadFormBuffer* a_buf) override;																																				// 0F
		virtual void					Unk_10(void) override;																																										// 10
		virtual void					Unk_11(void) override;																																										// 11
		virtual void					Unk_12(void) override;																																										// 12
		virtual void					InitItem() override;																																										// 13
		virtual FormType				GetFormType() override;																																										// 15
		virtual void					GetFormDesc(char* a_buf, UInt32 a_bufLen) override;																																			// 16
		virtual bool					GetFlag00010000() override;																																									// 18 - { return baseForm->GetFlag00010000(); }
		virtual bool					NeverFades() override;																																										// 1A - { return baseForm->formType == FormType::Light ? (flags & RecordFlags::kNeverFades) != 0 : false; }
		virtual bool					GetFlag00020000() override;																																									// 1B - { return baseForm->GetFlag00020000(); }
		virtual bool					GetFlag02000000() override;																																									// 1D - { return baseForm ? baseForm->GetFlag02000000() : false; }
		virtual bool					GetFlag00000200() override;																																									// 1F - { return (flags >> 9) & 1 && baseForm->GetFlag00000200(); }
		virtual bool					GetFlag00000100() const override;																																							// 20 - { return baseForm->GetFlag00000100(); }
		virtual void					SetFlag00000200(bool a_set) override;																																						// 21
		virtual bool					IgnoredBySandbox() const override;																																							// 22
		virtual void					SetFlag00000020(bool a_set) override;																																						// 23
		virtual void					SetFlag00000002(bool a_set) override;																																						// 24
		virtual bool					IsWaterActivator() override;																																								// 2A - { return baseForm ? baseForm->IsWaterActivator() : false; }
		virtual void					Unk_2B(void) override;																																										// 2B - { return this; }
		virtual TESObjectREFR*			GetReference() const override;																																								// 2C - { return this; }
		virtual void					Unk_30(void) override;																																										// 30
		virtual void					Unk_31(void) override;																																										// 31
		virtual const char*				GetEditorID() override;																																										// 32

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual EventResult				ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_dispatcher) override;																					// 01

		// override (IAnimationGraphManagerHolder)
		virtual bool					GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) override;																											// 02
		virtual bool					ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;																												// 05

		// add
		virtual void					Unk_3B(void);																																												// 3B
		virtual BGSLocation*			GetStartingLocation();																																										// 3C
		virtual bool					GetStartingData(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_veryRarelyUsedFallback);																// 3D
		virtual void					SetStartingLocation(BGSLocation* a_location);																																				// 3E
		virtual void					Unk_3F(void);																																												// 3F
		virtual void					SayQueuedDialogue();																																										// 40
		virtual void					Unk_41(void);																																												// 41
		virtual void					Unk_42(void);																																												// 42
		virtual void					Unk_43(void);																																												// 43 - checks flag 17 if this != ACHR && baseform != LIGH
		virtual void					Unk_44(void);																																												// 44
		virtual void					Unk_45(void);																																												// 45
		virtual void					Unk_46(void);																																												// 46 - { return 1; }
		virtual void					Unk_47(void);																																												// 47 - { return 1; }
		virtual bool					HasKeyword(BGSKeyword* a_keyword);																																							// 48
		virtual void					Unk_49(void);																																												// 49 - { return 0; }
		virtual BGSScene*				GetCurrentScene() const;																																									// 4A
		virtual void					SetCurrentScene(BGSScene* a_scene);																																							// 4B
		virtual void					Unk_4C(void);																																												// 4C
		virtual void					Unk_4D(void);																																												// 4D - getter for ExtraSayTopicInfo
		virtual void					Unk_4E(void);																																												// 4E - setter for ExtraSayTopicInfo
		virtual void					Unk_4F(void);																																												// 4F
		virtual void					SetActorCause(void* a_cause);																																								// 50
		virtual void*					GetActorCause() const;																																										// 51
		virtual void					GetStartingRotation(NiPoint3& a_rotation);																																					// 52
		virtual void					GetStartingPosition(NiPoint3& a_position);																																					// 53
		virtual void					Unk_54(void);																																												// 54
		virtual void					Unk_55(void);																																												// 55
		virtual RefHandle&				RemoveItem(RefHandle& a_dropHandle, TESForm* a_item, SInt32 a_count, RemoveType a_mode, BaseExtraList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0);		// 56
		virtual bool					EquipItem(TESForm* a_item, SInt32 a_count, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5);																										// 57
		virtual void					Unk_58(void);																																												// 58 - { return; }
		virtual void					Unk_59(void);																																												// 59 - { return; }
		virtual void					AddItem(TESForm* a_item, BaseExtraList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr);																							// 5A
		virtual void					GetMarkerPosition(NiPoint3& a_pos);																																							// 5B
		virtual MagicCaster*			GetMagicCaster(UInt32 a_slot) const;																																						// 5C
		virtual MagicTarget*			GetMagicTarget() const;																																										// 5D
		virtual bool					IsChild() const;																																											// 5E - { return false; }
		virtual void					Unk_5F(void);																																												// 5F - { return 0; }
		virtual void					Unk_60(void);																																												// 60 - { return; }
		virtual BSFaceGenNiNode*		GetFaceGenNiNode();																																											// 61 - { return 0; }
		virtual void					Unk_62(void);																																												// 62 - { return GetFaceGenNiNode(); }
		virtual BSFaceGenAnimationData*	GetFaceGenAnimationData();																																									// 63 - { return 0; }
		virtual void					Unk_64(void);																																												// 64
		virtual void					Unk_65(void);																																												// 65
		virtual void					Unk_66(void);																																												// 66
		virtual void					Unk_67(void);																																												// 67 - { return; }
		virtual void					Unk_68(void);																																												// 68 - { return; }
		virtual void					Unk_69(void);																																												// 69 - { return; }
		virtual void					Unk_6A(void);																																												// 6A
		virtual void					Unk_6B(void);																																												// 6B
		virtual void					Unk_6C(void);																																												// 6C
		virtual void					SetNiNode(NiNode* a_root, UInt32 a_arg2);																																					// 6D - NULL, 1?
		virtual void					Unk_6E(void);																																												// 6E - { return; }
		virtual NiNode*					GetNiRootNode(UInt32 a_firstPerson);																																						// 6F - { return GetNiNode(); }
		virtual NiNode*					GetNiNode() const;																																											// 70
		virtual void					Unk_71(void);																																												// 71 - { return 1; }
		virtual void					Unk_72(void);																																												// 72
		virtual NiPoint3*				GetBoundLeftFrontBottom(NiPoint3& a_out) const;																																				// 73
		virtual NiPoint3*				GetBoundRightBackTop(NiPoint3& a_out) const;																																				// 74
		virtual void					Unk_75(void);																																												// 75 - { return 0; }
		virtual void					Unk_76(void);																																												// 76
		virtual void					Unk_77(void);																																												// 77
		virtual void					Unk_78(void);																																												// 78
		virtual void					Unk_79(void);																																												// 79 - { return; }
		virtual void					Unk_7A(void);																																												// 7A
		virtual void					Unk_7B(void);																																												// 7B
		virtual void					Unk_7C(void);																																												// 7C - { return 1; }
		virtual void					Unk_7D(void);																																												// 7D
		virtual Biped*					GetBiped(bool a_large);																																										// 7E - { return GetSmallBiped(); }
		virtual Biped*					GetSmallBiped();																																											// 7F
		virtual void					Unk_80(void);																																												// 80 - { return GetSmallBiped(); }
		virtual void					Unk_81(void);																																												// 81 - { return; }
		virtual void					Unk_82(void);																																												// 82 - { return; }
		virtual void					Unk_83(void);																																												// 83 - { return; }
		virtual void					SetBaseForm(TESBoundObject* a_object);																																						// 84 - sets flag 24 if the object has destructibles
		virtual void					Unk_85(void);																																												// 85
		virtual void					Unk_86(void);																																												// 86
		virtual void					Unk_87(void);																																												// 87 - { return; }
		virtual void					Unk_88(void);																																												// 88 - { return; }
		virtual void					Disable();																																													// 89
		virtual void					ResetInventory(bool a_regenerate);																																							// 8A
		virtual void					Unk_8B(void);																																												// 8B - { return 0; }
		virtual void					Unk_8C(void);																																												// 8C - { return; }
		virtual void					Unk_8D(void);																																												// 8D - { return GetNiNode(); }
		virtual void					Unk_8E(void);																																												// 8E - { return 0; }
		virtual void					Unk_8F(void);																																												// 8F - { return 0; }
		virtual void					Unk_90(void);																																												// 90 - { return 1; }
		virtual void					Unk_91(void);																																												// 91 - { return; }
		virtual void					Unk_92(void);																																												// 92 - { return; }
		virtual void					Unk_93(void);																																												// 93 - { return 0; }
		virtual void					Unk_94(void);																																												// 94 - { return; }
		virtual void					Unk_95(void);																																												// 95 - { return; }
		virtual void					Unk_96(void);																																												// 96 - related to lockpicking
		virtual TESObjectCELL*			GetParentOrPersistentCell();																																								// 97
		virtual void					Unk_98(void);																																												// 98
		virtual bool					IsDead(bool a_bleedout);																																									// 99
		virtual BSAnimNoteReceiver*		CreateAnimNoteReceiver();																																									// 9A
		virtual BSAnimNoteReceiver*		GetAnimNoteReceiver();																																										// 9B
		virtual void					Unk_9C(void);																																												// 9C
		virtual void					Unk_9D(void);																																												// 9D - { return 0; }
		virtual void					Unk_9E(void);																																												// 9E - { return 0; }
		virtual void*					GetDecalGroup();																																											// 9F
		virtual void					Unk_A0(void);																																												// A0
		virtual void					UnequipItem(UInt64 a_arg1, TESForm* a_item);																																				// A1 - { return; }


		static bool LookupByHandle(const RefHandle& a_refHandle, TESObjectREFRPtr& a_refrOut);

		void				ActivateRefChildren(TESObjectREFR* a_activator);
		RefHandle			CreateRefHandle();
		TESNPC*				GetActorOwner() const;
		TESBoundObject*		GetBaseObject() const;
		float				GetBaseScale() const;
		TESContainer*		GetContainer() const;
		TESFaction*			GetFactionOwner() const;
		const char*			GetFullName() const;
		InventoryChanges*	GetInventoryChanges();	// Creates inventory changes if none found
		TESObjectREFR*		GetLinkedRef(BGSKeyword* a_keyword);
		SInt32				GetLockLevel() const;
		LockState*			GetLockState() const;
		NiAVObject*			GetNodeByName(const BSFixedString& a_nodeName);
		UInt32				GetNumItems(bool a_useDataHandlerChanges = false, bool a_arg2 = false);
		TESForm*			GetOwner() const;
		TESObjectCELL*		GetParentCell() const;
		float				GetPositionX() const;
		float				GetPositionY() const;
		float				GetPositionZ() const;
		const char*			GetReferenceName() const;
		float				GetWeight() const;
		TESWorldSpace*		GetWorldspace() const;
		bool				HasCollision() const;
		bool				HasInventoryChanges() const;
		bool				Is3DLoaded() const;
		bool				IsActivationBlocked() const;
		bool				IsDisabled() const;
		bool				IsLocked() const;
		bool				IsMarkedForDeletion() const;
		bool				IsOffLimits() const;
		bool				MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName);
		bool				MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node);
		void				PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4 = false);
		void				SetActivationBlocked(bool a_blocked);
		void				SetCollision(bool a_enable);
		bool				SetDisplayName(const BSFixedString& a_name, bool a_force);
		bool				SetMotionType(MotionType a_motionType, bool a_allowActivate = true);
		void				SetPosition(float a_x, float a_y, float a_z);
		void				SetPosition(NiPoint3 a_pos);


		// members
		TESBoundObject*	baseForm;		// 40
		NiPoint3		rot;			// 48
		NiPoint3		pos;			// 54
		TESObjectCELL*	parentCell;		// 60
		LoadedState*	loadedState;	// 68
		BaseExtraList	extraData;		// 70
		UInt64			unk88;			// 88
		UInt16			unk90;			// 90
		UInt8			unk92;			// 92
		UInt8			unk93;			// 93
		UInt32			pad94;			// 94

	private:
		static void CreateRefHandle_Impl(RefHandle& a_refHandle, TESObjectREFR* a_refrTo);

		void MoveTo_Impl(RefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, NiPoint3& a_position, NiPoint3& a_rotation);
	};
	STATIC_ASSERT(offsetof(TESObjectREFR, extraData) == 0x70);
	STATIC_ASSERT(offsetof(TESObjectREFR, loadedState) == 0x68);
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
};
