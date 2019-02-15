#pragma once

#include "Offsets.h"

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

class ActorWeightModel;
class BaseExtraList;
class BSAnimNoteReceiver;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class MagicCaster;


namespace RE
{
	class InventoryChanges;
	class MagicTarget;
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
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


		enum class TESFormFlag : UInt32
		{
			kMarkedForDeletion = 1 << 5,
			kDisabled = 1 << 11,
			kHarvested = 1 << 13,
			kIgnoreFriendlyHits = 1 << 20,
			kDestroyed = 1 << 23
		};


		struct LocalFlags
		{
			enum LocalFlag : UInt32
			{
				kDeleted = 1 << 5,
				kPersistent = 1 << 10,
				kInitiallyDisabled = 1 << 11,
				kIgnored = 1 << 12,
				kIsFullLOD = 1 << 16,
				kCollisionGeometry_Filter = 1 << 26,
				kCollisionGeometry_BoundingBox = 1 << 27,
				kReflectedByAutoWater = 1 << 28,
				kGround = 1 << 30,
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
		virtual bool					LoadForm(TESFile* a_mod) override;																																							// 06
		virtual TESForm*				DupulicateForm(uintptr_t a_arg1, void* a_arg2) override;																																	// 09
		virtual bool					PreSaveBuffer(BGSSaveFormBuffer* a_buf) override;																																			// 0D
		virtual void					SaveBuffer(BGSSaveFormBuffer* a_buf) override;																																				// 0E
		virtual void					LoadBuffer(BGSLoadFormBuffer* a_buf) override;																																				// 0F
		virtual void					InitItem() override;																																										// 13
		virtual FormType				GetFormType() override;																																										// 15
		virtual void					GetFormDesc(char* a_buf, UInt32 a_bufLen) override;																																			// 16
		virtual bool					GetFlag00010000() override;																																									// 18
		virtual bool					GetFlag00020000() override;																																									// 1B
		virtual bool					GetFlag02000000() override;																																									// 1D
		virtual bool					GetFlag00000200() override;																																									// 1F
		virtual bool					GetFlag00000100() override;																																									// 20
		virtual void					SetFlag00000200(bool a_set) override;																																						// 21
		virtual void					SetFlag00000020(bool a_set) override;																																						// 23
		virtual void					SetFlag00000002(bool a_set) override;																																						// 24
		virtual TESObjectREFR*			GetReference() override;																																									// 2C - { return this; }
		virtual const char*				GetName() override;																																											// 32

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual EventResult				ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_dispatcher) override;																					// 01

		// override (IAnimationGraphManagerHolder)
		virtual bool					GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) override;																											// 02
		virtual bool					ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;																												// 05

		// add
		virtual void					Unk_3B(void);																																												// 3B
		virtual BGSLocation*			GetEditorLocation();																																										// 3C
		virtual bool					GetEditorCoordinates(NiPoint3* a_outPos, NiPoint3* a_outRot, void** a_outWorldOrCell, TESObjectCELL* a_veryRarelyUsedFallback);																// 3D
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
		virtual void					Unk_50(void);																																												// 50
		virtual UInt32*					GetActorCause();																																											// 51
		virtual void					Unk_52(void);																																												// 52
		virtual void					Unk_53(void);																																												// 53
		virtual void					Unk_54(void);																																												// 54
		virtual void					Unk_55(void);																																												// 55
		virtual UInt32&					RemoveItem(UInt32& a_droppedItemHandle, TESForm* a_item, UInt32 a_count, RemoveType a_mode, BaseExtraList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0);	// 56
		virtual bool					EquipItem(TESForm* a_akItem, UInt32 a_aiCount, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5);																									// 57
		virtual void					Unk_58(void);																																												// 58
		virtual void					Unk_59(void);																																												// 59
		virtual void					Unk_5A(void);																																												// 5A
		virtual void					GetMarkerPosition(NiPoint3* a_pos);																																							// 5B
		virtual MagicCaster*			GetMagicCaster(UInt32 a_slot) const;																																						// 5C
		virtual MagicTarget*			GetMagicTarget() const;																																										// 5D
		virtual bool					IsChild() const;																																											// 5E
		virtual void					Unk_5F(void);																																												// 5F
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
		virtual void					SetNiNode(NiNode* a_root, UInt32 a_unk1);																																					// 6D - NULL, 1?
		virtual void					Unk_6E(void);																																												// 6E
		virtual NiNode*					GetNiRootNode(UInt32 a_firstPerson);																																						// 6F
		virtual NiNode*					GetNiNode(void);																																											// 70 - Root of the skeleton (Get3D)
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
		virtual ActorWeightModel*		GetWeightModel(UInt32 a_weightModel);																																						// 7E - 0 Small 1 Large
		virtual void					Unk_7F(void);																																												// 7F
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
		virtual void					ResetInventory(bool a_unk);																																									// 8A
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
		virtual bool					SendEquipEvent(uintptr_t a_arg1, uintptr_t a_arg2);																																			// A1


		float							GetBaseScale();
		bool							IsOffLimits();
		float							GetWeight();
		const char*						GetReferenceName();
		TESWorldSpace*					GetWorldspace();
		UInt32							GetRefHandle();
		UInt32							CreateRefHandle();
		UInt32							GetOrCreateRefHandle();
		TESNPC*							GetActorOwner();
		TESForm*						GetBaseObject();
		TESContainer*					GetContainer();
		const char*						GetFullName();
		TESFaction*						GetFactionOwner();
		TESForm*						GetOwner();
		TESObjectCELL*					GetParentCell();
		float							GetPositionX();
		float							GetPositionY();
		float							GetPositionZ();
		bool							Is3DLoaded();
		bool							IsMarkedForDeletion();
		bool							IsDisabled();
		bool							SetDisplayName(const BSFixedString& name, bool force);
		static bool						LookupByHandle(UInt32& a_refHandle, TESObjectREFRPtr& a_refrOut);
		LockState*						GetLockState();
		bool							IsLocked();
		SInt32							GetLockLevel();
		UInt32							GetNumItems(bool a_unk1, bool a_unk2);
		UInt32							ActivateRefChildren(TESObjectREFR* a_activator);
		void							PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_unk);
		bool							HasInventoryChanges();
		InventoryChanges*				GetInventoryChanges();	// Creates inventory changes if none found


		// members
		TESForm*		baseForm;		// 40
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
	};
	STATIC_ASSERT(offsetof(TESObjectREFR, extraData) == 0x70);
	STATIC_ASSERT(offsetof(TESObjectREFR, loadedState) == 0x68);
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
};
