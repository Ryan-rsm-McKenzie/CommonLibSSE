#pragma once

#include <memory>
#include <string_view>
#include <unordered_map>
#include <utility>

#include "function_ref.h"

#include "RE/BSFixedString.h"
#include "RE/BSHandleRefObject.h"
#include "BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSmartPointer.h"
#include "RE/ExtraDataList.h"
#include "RE/FormTypes.h"
#include "RE/IAnimationGraphManagerHolder.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESForm.h"


namespace RE
{
	class ActorCause;
	class BSAnimNoteReceiver;
	class BSFaceGenAnimationData;
	class BSFaceGenNiNode;
	class BSFlattenedBoneTree;
	class InventoryChanges;
	class InventoryEntryData;
	class MagicCaster;
	class MagicTarget;
	class NiAVObject;
	class NiControllerManager;
	class NiControllerSequence;
	class NiObject;
	class Projectile;
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


		using Count = SInt32;
		using InventoryMap = std::unordered_map<TESBoundObject*, std::pair<Count, InventoryEntryData*>>;
		using DroppedInventoryMap = std::unordered_map<TESBoundObject*, std::pair<Count, std::unique_ptr<InventoryEntryData>>>;


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

				kIsFullLOD = 1 << 16,	// Actor

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


		class ObjRef
		{
		public:
			TESBoundObject*	objectReference;	// 00
			NiPoint3		angle;				// 08
			NiPoint3		location;			// 14
		};
		STATIC_ASSERT(sizeof(ObjRef) == 0x20);


		struct LoadedRefData
		{
			BSTSmallArray<void*>	unk00;					// 00 - BSModelDB::HandleListHead handleList?
			UInt64					unk18;					// 18 - TESWaterForm* currentWaterType?
			float					relevantWaterHeight;	// 20
			float					cachedRadius;			// 24
			UInt16					flags;					// 28
			SInt16					underwaterCount;		// 2A
			UInt32					pad2C;					// 2C
			UInt64					unk30;					// 30 - AIProcess::Data0B8
			UInt64					unk38;					// 38
			UInt64					unk40;					// 40
			UInt64					unk48;					// 48
			UInt64					unk50;					// 50
			UInt64					unk58;					// 58
			UInt64					unk60;					// 60
			NiPointer<NiAVObject>	data3D;					// 68
			void*					unk70;					// 70 - smart ptr
		};
		STATIC_ASSERT(sizeof(LoadedRefData) == 0x78);


		virtual ~TESObjectREFR();																																																	// 00

		// override (TESForm)
		virtual void					InitializeData() override;																																									// 04
		virtual void					ClearData() override;																																										// 05
		virtual bool					Load(TESFile* a_mod) override;																																								// 06
		virtual TESForm*				CreateDuplicateForm(void* a_arg1, void* a_arg2) override;																																	// 09
		virtual bool					CheckSaveGame(BGSSaveFormBuffer* a_buf) override;																																			// 0D
		virtual void					SaveGame(BGSSaveFormBuffer* a_buf) override;																																				// 0E
		virtual void					LoadGame(BGSLoadFormBuffer* a_buf) override;																																				// 0F
		virtual void					InitLoadGame(void* a_arg1) override;																																						// 10
		virtual void					FinishLoadGame(void* a_arg1) override;																																						// 11
		virtual void					Revert(void* a_arg1) override;																																								// 12
		virtual void					InitItemImpl() override;																																									// 13
		virtual FormType				GetSavedFormType() const override;																																							// 15
		virtual void					GetFormDetailedString(char* a_buf, UInt32 a_bufLen) override;																																// 16
		virtual bool					GetRandomAnim() const override;																																								// 18 - { return data.objectReference->GetRandomAnim(); }
		virtual bool					IsHeadingMarker() const override;																																							// 1A - { return data.objectReference->formType == FormType::Light ? (flags & RecordFlags::kNeverFades) != 0 : false; }
		virtual bool					GetDangerous() const override;																																								// 1B - { return data.objectReference->GetDangerous(); }
		virtual bool					GetObstacle() const override;																																								// 1D - { return data.objectReference ? data.objectReference->GetObstacle() : false; }
		virtual bool					GetOnLocalMap() const override;																																								// 1F - { return (flags >> 9) & 1 && data.objectReference->GetOnLocalMap(); }
		virtual bool					GetMustUpdate() const override;																																								// 20 - { return data.objectReference->GetMustUpdate(); }
		virtual void					SetOnLocalMap(bool a_set) override;																																							// 21
		virtual bool					GetIgnoredBySandbox() const override;																																						// 22
		virtual void					SetDelete(bool a_set) override;																																								// 23
		virtual void					SetAltered(bool a_set) override;																																							// 24
		virtual bool					IsWater() const override;																																									// 2A - { return data.objectReference ? data.objectReference->IsWater() : false; }
		virtual const TESObjectREFR*	AsReference() const override;																																								// 2B - { return this; }
		virtual TESObjectREFR*			AsReference() override;																																										// 2C - { return this; }
		virtual bool					BelongsInGroup(void) override;																																								// 30
		virtual void					CreateGroupData(void) override;																																								// 31
		virtual const char*				GetFormEditorID() override;																																									// 32

		// override (BSTEventSink<BSAnimationGraphEvent>)
		virtual EventResult				ReceiveEvent(BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_dispatcher) override;																					// 01

		// override (IAnimationGraphManagerHolder)
		virtual bool					GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) override;																											// 02
		virtual bool					SetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_in) override;																											// 03
		virtual bool					PopulateGraphNodesToTarget(void* a_arg1) override;																																			// 04
		virtual bool					ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;																												// 05
		virtual bool					SetupAnimEventSinks(BSTSmartPointer<BShkbAnimationGraph>& a_animGraph) override;																											// 08
		virtual void					PostChangeAnimationManager(void* a_arg1, void* a_arg2) override;																															// 0D

		// add
		virtual void					Predestroy();																																												// 3B
		virtual BGSLocation*			GetEditorLocation();																																										// 3C
		virtual bool					GetEditorLocation(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback);																			// 3D
		virtual void					ForceEditorLocation(BGSLocation* a_location);																																				// 3E
		virtual void					Update3DPosition(bool a_arg1);																																								// 3F
		virtual void					UpdateSoundCallBack();																																										// 40
		virtual void					SetDialoguewithPlayer(void);																																								// 41
		virtual void					Unk_42(void);																																												// 42
		virtual bool					GetFullLODRef() const;																																										// 43
		virtual void					SetFullLODRef(void);																																										// 44
		virtual void					GetSequencer(void);																																											// 45
		virtual bool					QCanUpdateSync(void);																																										// 46 - { return true; }
		virtual bool					GetAllowPromoteToPersistent(void);																																							// 47 - { return true; }
		virtual bool					HasKeywordHelper(BGSKeyword* a_keyword);																																					// 48
		virtual void					CheckForCurrentAliasPackage(void);																																							// 49 - { return 0; }
		virtual BGSScene*				GetCurrentScene() const;																																									// 4A
		virtual void					SetCurrentScene(BGSScene* a_scene);																																							// 4B
		virtual void					UpdateInDialogue(void);																																										// 4C
		virtual void*					GetExclusiveBranch();																																										// 4D
		virtual void					SetExclusiveBranch(void* a_branch);																																							// 4E
		virtual void					PauseCurrentDialogue();																																										// 4F
		virtual void					SetActorCause(ActorCause* a_cause);																																							// 50
		virtual ActorCause*				GetActorCause();																																											// 51
		virtual NiPoint3*				GetStartingAngle(NiPoint3& a_angle) const;																																					// 52
		virtual NiPoint3*				GetStartingLocation(NiPoint3& a_location) const;																																			// 53
		virtual void					SetStartingPosition(void);																																									// 54
		virtual void					UpdateRefLight();																																											// 55
		virtual RefHandle&				RemoveItem(RefHandle& a_dropHandle, TESBoundObject* a_item, SInt32 a_count, RemoveType a_mode, ExtraDataList* a_extraList, TESObjectREFR* a_moveToRef, void* a_arg7 = 0, void* a_arg8 = 0);	// 56
		virtual bool					AddWornItem(TESBoundObject* a_item, SInt32 a_count, bool a_arg3, UInt32 a_arg4, UInt32 a_arg5);																								// 57
		virtual void					DoTrap(void* a_arg1);																																										// 58 - { return; }
		virtual void					DoTrap(void* a_arg1, void* a_arg2);																																							// 59 - { return; }
		virtual void					AddItem(TESBoundObject* a_item, ExtraDataList* a_extraList, SInt32 a_count, TESObjectREFR* a_fromRefr);																						// 5A
		virtual NiPoint3*				GetLookingAtLocation(NiPoint3& a_location) const;																																			// 5B
		virtual MagicCaster*			GetMagicCaster(UInt32 a_slot);																																								// 5C
		virtual MagicTarget*			GetMagicTarget();																																											// 5D
		virtual bool					IsChild() const;																																											// 5E - { return false; }
		virtual void*					GetTemplateActorBase(void);																																									// 5F - { return 0; }
		virtual void					SetTemplateActorBase(void* a_template);																																						// 60 - { return; }
		virtual BSFaceGenNiNode*		GetFaceNodeSkinned();																																										// 61 - { return 0; }
		virtual BSFaceGenNiNode*		GetFaceNode();																																												// 62 - { return GetFaceNodeSkinned(); }
		virtual BSFaceGenAnimationData*	GetFaceGenAnimationData();																																									// 63 - { return 0; }
		virtual bool					ClampToGround();																																											// 64
		virtual bool					DetachHavok();																																												// 65
		virtual void					InitHavok();																																												// 66
		virtual void					Unk_67(void);																																												// 67 - { return; }
		virtual void					Unk_68(void);																																												// 68 - { return; }
		virtual void					Unk_69(void);																																												// 69 - { return; }
		virtual void					Load3D(bool a_arg1);																																										// 6A
		virtual void					Release3DRelatedData();																																										// 6B
		virtual void					Set3D(NiAVObject* a_root, UInt32 a_arg2 = 1);																																				// 6C
		virtual bool					ShouldBackgroundClone() const;																																								// 6D
		virtual void					Unk_6E(void);																																												// 6E - { return; }
		virtual NiAVObject*				Get3D(UInt32 a_firstPerson);																																								// 6F - { return Get3D(); }
		virtual NiAVObject*				Get3D() const;																																												// 70
		virtual bool					Is3rdPersonVisible();																																										// 71 - { return true; }
		virtual void					PopulateGraphProjectsToLoad(void);																																							// 72
		virtual NiPoint3*				GetBoundMin(NiPoint3& a_min) const;																																							// 73
		virtual NiPoint3*				GetBoundMax(NiPoint3& a_max) const;																																							// 74
		virtual void					Unk_75(void);																																												// 75 - { return 0; }
		virtual bool					InitNonNPCAnimation(NiObject* a_arg1);																																						// 76
		virtual bool					CheckAndFixSkinAndBoneOrder(void* a_arg1);																																					// 77
		virtual void					Unk_78(void);																																												// 78
		virtual void					ModifyAnimationUpdateData(void);																																							// 79 - { return; }
		virtual bool					ShouldSaveAnimationOnUnloading(void);																																						// 7A
		virtual bool					ShouldSaveAnimationOnSaving(void);																																							// 7B
		virtual bool					ShouldPerformRevert(void);																																									// 7C - { return true; }
		virtual void					UpdateAnimation(void);																																										// 7D
		virtual Biped*					GetBiped(bool a_large);																																										// 7E - { return GetBiped(); }
		virtual Biped*					GetBiped();																																													// 7F
		virtual Biped*					GetCurrentBiped();																																											// 80 - { return GetBiped(); }
		virtual void					Unk_81(void);																																												// 81 - { return; }
		virtual void					Unk_82(void);																																												// 82 - { return; }
		virtual void					Unk_83(void);																																												// 83 - { return; }
		virtual void					SetObjectReference(TESBoundObject* a_object);																																				// 84 - sets flag 24 if the object has destructibles
		virtual void					MoveHavok(bool a_arg1);																																										// 85
		virtual NiPoint3*				GetLinearVelocity(NiPoint3& a_velocity) const;																																				// 86
		virtual void					SetActionComplete(void);																																									// 87 - { return; }
		virtual void					SetMovementComplete(void);																																									// 88 - { return; }
		virtual void					Disable();																																													// 89
		virtual void					ResetInventory(bool a_regenerate);																																							// 8A
		virtual void					Unk_8B(void);																																												// 8B - { return 0; }
		virtual void					Unk_8C(void);																																												// 8C - { return; }
		virtual NiAVObject*				GetCurrent3D();																																												// 8D - { return Get3D(); }
		virtual void*					AsExplosion();																																												// 8E - { return 0; }
		virtual Projectile*				AsProjectile();																																												// 8F - { return 0; }
		virtual bool					OnAddCellPerformQueueReference(TESObjectCELL* a_cell) const;																																// 90 - { return true; }
		virtual void					DoMoveToHigh();																																												// 91 - { return; }
		virtual void					TryMoveToMiddleLow();																																										// 92 - { return; }
		virtual bool					TryChangeSkyCellActorsProcessLevel();																																						// 93 - { return false; }
		virtual void					Unk_94(void);																																												// 94 - { return; }
		virtual void					Unk_95(void);																																												// 95 - { return; }
		virtual void					Unk_96(void);																																												// 96 - related to lockpicking
		virtual TESObjectCELL*			GetParentOrPersistentCell() const;																																							// 97
		virtual void					Unk_98(void);																																												// 98
		virtual bool					IsDead(bool a_noDying = true);																																								// 99
		virtual BSAnimNoteReceiver*		CreateAnimNoteReceiver();																																									// 9A
		virtual BSAnimNoteReceiver*		GetAnimNoteReceiver();																																										// 9B
		virtual void					Unk_9C(void);																																												// 9C
		virtual void					Unk_9D(void);																																												// 9D - { return 0; }
		virtual void					Unk_9E(void);																																												// 9E - { return 0; }
		virtual void*					GetDecalGroup();																																											// 9F
		virtual void					Unk_A0(void);																																												// A0
		virtual void					UnequipItem(UInt64 a_arg1, TESBoundObject* a_item);																																			// A1 - { return; }


		static NiPointer<TESObjectREFR>	LookupByHandle(RefHandle a_refHandle);
		static bool						LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut);

		void					ActivateRefChildren(TESObjectREFR* a_activator);
		RefHandle				CreateRefHandle();
		TESNPC*					GetActorOwner();
		NiPoint3				GetAngle() const;
		float					GetAngleX() const;
		float					GetAngleY() const;
		float					GetAngleZ() const;
		TESBoundObject*			GetBaseObject();
		const TESBoundObject*	GetBaseObject() const;
		float					GetBaseScale() const;
		TESContainer*			GetContainer();
		DroppedInventoryMap		GetDroppedInventory();
		DroppedInventoryMap		GetDroppedInventory(llvm::function_ref<bool(TESBoundObject*)> a_filter);
		TESFaction*				GetFactionOwner();
		InventoryMap			GetInventory();
		InventoryMap			GetInventory(llvm::function_ref<bool(TESBoundObject*)> a_filter);
		InventoryChanges*		GetInventoryChanges();	// Creates inventory changes if none found
		TESObjectREFR*			GetLinkedRef(BGSKeyword* a_keyword);
		SInt32					GetLockLevel() const;
		LockState*				GetLockState();
		const LockState*		GetLockState() const;
		const char*				GetName() const;
		NiAVObject*				GetNodeByName(const BSFixedString& a_nodeName);
		UInt32					GetNumItems(bool a_useDataHandlerChanges = false, bool a_arg2 = false);
		TESForm*				GetOwner();
		TESObjectCELL*			GetParentCell();
		NiPoint3				GetPosition() const;
		float					GetPositionX() const;
		float					GetPositionY() const;
		float					GetPositionZ() const;
		UInt32					GetRefCount() const;
		const char*				GetReferenceName() const;
		float					GetWeight() const;
		TESWorldSpace*			GetWorldspace() const;
		bool					HasCollision() const;
		bool					HasInventoryChanges() const;
		bool					Is3DLoaded() const;
		bool					IsActivationBlocked() const;
		bool					IsDisabled() const;
		bool					IsLocked() const;
		bool					IsMarkedForDeletion() const;
		bool					IsOffLimits() const;
		bool					MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName);
		bool					MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node);
		void					PlayAnimation(std::string_view a_from, std::string_view a_to);
		void					PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq);
		void					SetActivationBlocked(bool a_blocked);
		void					SetCollision(bool a_enable);
		bool					SetDisplayName(const BSFixedString& a_name, bool a_force);
		bool					SetMotionType(MotionType a_motionType, bool a_allowActivate = true);
		void					SetPosition(float a_x, float a_y, float a_z);
		void					SetPosition(NiPoint3 a_pos);


		// members
		ObjRef			data;			// 40
		TESObjectCELL*	parentCell;		// 60
		LoadedRefData*	loadedData;		// 68
		ExtraDataList	extraData;		// 70
		UInt64			unk88;			// 88
		UInt16			refScale;		// 90
		UInt8			modelState;		// 92
		bool			preDestroyed;	// 93
		UInt32			pad94;			// 94

	private:
		const LockState*	GetLockState_Impl() const;
		void				MoveTo_Impl(RefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, NiPoint3& a_position, NiPoint3& a_rotation);
		void				PlayAnimation_Impl(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4 = false);
	};
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
};
