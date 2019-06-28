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
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
	class TESBoundObject;
	class TESContainer;
	struct BSAnimationGraphEvent;
	struct DialogueData;
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


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kIsGroundPiece = 1 << 4,
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


		struct WeightData : BSIntrusiveRefCounted
		{
			UInt64 unk0008[(0x2778 - 0x8) >> 3];	// 08
		};
		STATIC_ASSERT(sizeof(WeightData) == 0x2778);


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
		virtual bool					GetFlag00010000() override;																																									// 18
		virtual bool					NeverFades() override;																																										// 1A
		virtual bool					GetFlag00020000() override;																																									// 1B
		virtual bool					GetFlag02000000() override;																																									// 1D
		virtual bool					GetFlag00000200() override;																																									// 1F
		virtual bool					GetFlag00000100() override;																																									// 20
		virtual void					SetFlag00000200(bool a_set) override;																																						// 21
		virtual bool					IgnoredBySandbox() const override;																																							// 22
		virtual void					SetFlag00000020(bool a_set) override;																																						// 23
		virtual void					SetFlag00000002(bool a_set) override;																																						// 24
		virtual bool					IsWaterActivator() override;																																								// 2A
		virtual void					Unk_2B(void) override;																																										// 2B
		virtual TESObjectREFR*			GetReference() override;																																									// 2C - { return this; }
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
		virtual BGSLocation*			GetEditorLocation();																																										// 3C
		virtual bool					GetEditorCoordinates(NiPoint3* a_outPos, NiPoint3* a_outRot, void*& a_outWorldOrCell, TESObjectCELL* a_veryRarelyUsedFallback);																// 3D
		virtual void					Unk_3E(void);																																												// 3E
		virtual void					Unk_3F(void);																																												// 3F
		virtual void					Unk_40(void);																																												// 40
		virtual void					Unk_41(void);																																												// 41
		virtual void					Unk_42(void);																																												// 42
		virtual void					Unk_43(void);																																												// 43
		virtual void					Unk_44(void);																																												// 44
		virtual void					Unk_45(void);																																												// 45
		virtual void					Unk_46(void);																																												// 46
		virtual void					Unk_47(void);																																												// 47
		virtual bool					HasKeyword(BGSKeyword* a_keyword);																																							// 48
		virtual void					Unk_49(void);																																												// 49
		virtual BGSScene*				GetCurrentScene() const;																																									// 4A
		virtual void					SetCurrentScene(BGSScene* a_scene);																																							// 4B
		virtual void					Unk_4C(void);																																												// 4C
		virtual void					Unk_4D(void);																																												// 4D
		virtual void					Unk_4E(void);																																												// 4E
		virtual void					Unk_4F(void);																																												// 4F
		virtual void					SetActorCause(RefHandle& a_cause);																																							// 50
		virtual RefHandle&				GetActorCause() const;																																										// 51
		virtual void					Unk_52(void);																																												// 52
		virtual void					Unk_53(void);																																												// 53
		virtual void					Unk_54(void);																																												// 54
		virtual void					Unk_55(void);																																												// 55
		virtual RefHandle&				RemoveItem(RefHandle& a_dropHandle, TESForm* a_item, SInt32 a_count, RemoveType a_mode, BaseExtraList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0);		// 56
		virtual bool					EquipItem(TESForm* a_akItem, SInt32 a_count, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5);																									// 57
		virtual void					Unk_58(void);																																												// 58
		virtual void					Unk_59(void);																																												// 59
		virtual void					AddItem(TESForm* a_item, BaseExtraList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr);																							// 5A
		virtual void					GetMarkerPosition(NiPoint3* a_pos);																																							// 5B
		virtual MagicCaster*			GetMagicCaster(UInt32 a_slot) const;																																						// 5C
		virtual MagicTarget*			GetMagicTarget() const;																																										// 5D
		virtual bool					IsChild() const;																																											// 5E
		virtual void					Unk_5F(void);																																												// 5F - { return 0; }
		virtual void					Unk_60(void);																																												// 60
		virtual BSFaceGenNiNode*		GetFaceGenNiNode();																																											// 61
		virtual void					Unk_62(void);																																												// 62
		virtual BSFaceGenAnimationData*	GetFaceGenAnimationData();																																									// 63
		virtual void					Unk_64(void);																																												// 64
		virtual void					Unk_65(void);																																												// 65
		virtual void					Unk_66(void);																																												// 66
		virtual void					Unk_67(void);																																												// 67
		virtual void					Unk_68(void);																																												// 68
		virtual void					Unk_69(void);																																												// 69
		virtual void					Unk_6A(void);																																												// 6A
		virtual void					Unk_6B(void);																																												// 6B
		virtual void					Unk_6C(void);																																												// 6C
		virtual void					SetNiNode(NiNode* a_root, UInt32 a_arg2);																																					// 6D - NULL, 1?
		virtual void					Unk_6E(void);																																												// 6E
		virtual NiNode*					GetNiRootNode(UInt32 a_firstPerson);																																						// 6F
		virtual NiNode*					GetNiNode() const;																																											// 70 - Root of the skeleton (Get3D)
		virtual void					Unk_71(void);																																												// 71
		virtual void					Unk_72(void);																																												// 72
		virtual NiPoint3*				GetBoundLeftFrontBottom(NiPoint3* a_out) const;																																				// 73
		virtual NiPoint3*				GetBoundRightBackTop(NiPoint3* a_out) const;																																				// 74
		virtual void					Unk_75(void);																																												// 75
		virtual void					Unk_76(void);																																												// 76
		virtual void					Unk_77(void);																																												// 77
		virtual void					Unk_78(void);																																												// 78
		virtual void					Unk_79(void);																																												// 79
		virtual void					Unk_7A(void);																																												// 7A
		virtual void					Unk_7B(void);																																												// 7B
		virtual void					Unk_7C(void);																																												// 7C
		virtual void					Unk_7D(void);																																												// 7D
		virtual WeightData*				GetWeightData(bool a_large);																																								// 7E - { return GetSmallWeightData(); }
		virtual WeightData*				GetSmallWeightData();																																										// 7F
		virtual void					Unk_80(void);																																												// 80
		virtual void					Unk_81(void);																																												// 81
		virtual void					Unk_82(void);																																												// 82
		virtual void					Unk_83(void);																																												// 83
		virtual void					Unk_84(void);																																												// 84
		virtual void					Unk_85(void);																																												// 85
		virtual void					Unk_86(void);																																												// 86
		virtual void					Unk_87(void);																																												// 87
		virtual void					Unk_88(void);																																												// 88
		virtual void					Disable();																																													// 89
		virtual void					ResetInventory(bool a_regenerate);																																							// 8A
		virtual void					Unk_8B(void);																																												// 8B
		virtual void					Unk_8C(void);																																												// 8C
		virtual void					Unk_8D(void);																																												// 8D
		virtual void					Unk_8E(void);																																												// 8E
		virtual void					Unk_8F(void);																																												// 8F
		virtual void					Unk_90(void);																																												// 90
		virtual void					Unk_91(void);																																												// 91
		virtual void					Unk_92(void);																																												// 92
		virtual void					Unk_93(void);																																												// 93
		virtual void					Unk_94(void);																																												// 94
		virtual void					Unk_95(void);																																												// 95
		virtual void					Unk_96(void);																																												// 96
		virtual TESObjectCELL*			GetParentOrPersistentCell();																																								// 97
		virtual void					Unk_98(void);																																												// 98
		virtual bool					IsDead(bool a_isActor);																																										// 99
		virtual void					Unk_9A(void);																																												// 9A
		virtual BSAnimNoteReceiver*		CreateAnimNoteReceiver();																																									// 9B
		virtual BSAnimNoteReceiver*		GetAnimNoteReceiver();																																										// 9C
		virtual void					Unk_9D(void);																																												// 9D
		virtual void					Unk_9E(void);																																												// 9E
		virtual void					Unk_9F(void);																																												// 9F
		virtual void*					GetDecalGroup();																																											// A0
		virtual bool					SendEquipEvent(UInt64 a_arg1, UInt64 a_arg2);																																				// A1


		static bool						LookupByHandle(RefHandle& a_refHandle, TESObjectREFRPtr& a_refrOut);

		float							GetBaseScale() const;
		bool							IsOffLimits() const;
		float							GetWeight() const;
		const char*						GetReferenceName() const;
		TESWorldSpace*					GetWorldspace() const;
		RefHandle						GetRefHandle() const;
		RefHandle						CreateRefHandle();
		RefHandle						GetOrCreateRefHandle();
		TESNPC*							GetActorOwner() const;
		TESForm*						GetBaseObject() const;
		TESContainer*					GetContainer() const;
		const char*						GetFullName() const;
		TESFaction*						GetFactionOwner() const;
		TESForm*						GetOwner() const;
		TESObjectCELL*					GetParentCell() const;
		float							GetPositionX() const;
		float							GetPositionY() const;
		float							GetPositionZ() const;
		bool							Is3DLoaded() const;
		bool							IsMarkedForDeletion() const;
		bool							IsDisabled() const;
		bool							IsActivationBlocked() const;
		void							SetActivationBlocked(bool a_blocked);
		bool							IsLocked() const;
		LockState*						GetLockState() const;
		SInt32							GetLockLevel() const;
		UInt32							GetNumItems(bool a_useDataHandlerChanges = false, bool a_arg2 = false);
		bool							HasInventoryChanges() const;
		InventoryChanges*				GetInventoryChanges();	// Creates inventory changes if none found
		bool							SetDisplayName(const BSFixedString& name, bool force);
		UInt32							ActivateRefChildren(TESObjectREFR* a_activator);
		void							PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4 = false);


		// members
		TESBoundObject*	baseForm;		// 40
		NiPoint3		rot;			// 48
		NiPoint3		pos;			// 54
		TESObjectCELL*	parentCell;		// 60
		LoadedState*	loadedState;	// 68
		BaseExtraList	extraData;		// 70
		UInt64			unk88;			// 88 - New in SE
		UInt16			unk90;			// 90 - init'd to 100
		UInt8			unk92;			// 92
		UInt8			unk93;			// 93
		UInt32			pad94;			// 94

	private:
		static void CreateRefHandle_Internal(UInt32& a_refHandle, TESObjectREFR* a_refrTo);
	};
	STATIC_ASSERT(offsetof(TESObjectREFR, extraData) == 0x70);
	STATIC_ASSERT(offsetof(TESObjectREFR, loadedState) == 0x68);
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
};
