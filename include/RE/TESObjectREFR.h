#pragma once

#include "skse64/GameForms.h"  // TESForm
#include "skse64/NiTypes.h"  // NiPoint3

#include "Offsets.h"

#include "RE/BaseExtraList.h"  // BaseExtraList
#include "RE/IAnimationGraphManagerHolder.h"  // IAnimationGraphManagerHolder

class ActorWeightModel;
class BaseExtraList;
class BSAnimNoteReceiver;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class MagicCaster;
class TESObjectCELL;


namespace RE
{
	class InventoryChanges;
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
	class TESFaction;
	class TESNPC;
	struct LockState;


	MAKE_NI_POINTER(TESObjectREFR);


	class TESObjectREFR :
		public TESForm,
		public BSHandleRefObject,
		public BSTEventSink<BSAnimationGraphEvent>,
		public IAnimationGraphManagerHolder
	{
	public:
		enum { kTypeID = kFormType_Reference };


		enum RemoveType : UInt32
		{
			kRemoveType_Remove,
			kRemoveType_Steal,
			kRemoveType_Trade,
			kRemoveType_Drop,
			kRemoveType_Take,
			kRemoveType_Unk05
		};


		enum TESFormFlag : UInt32
		{
			kTESFormFlag_MarkedForDeletion	= 1 << 5,
			kTESFormFlag_Disabled			= 1 << 11,
			kTESFormFlag_Harvested			= 1 << 13,
			kTESFormFlag_IgnoreFriendlyHits	= 1 << 20,
			kTESFormFlag_Destroyed			= 1 << 23
		};


		struct LoadedState
		{
			UInt8	todo[0x68];	// 00
			NiNode*	node;		// 68
			// ... probably more
		};


		virtual void					Unk_39(void);																																												// 39
		virtual void					Unk_3A(void);																																												// 3A
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
		virtual UInt32*					RemoveItem(UInt32* a_droppedItemHandle, TESForm* a_akItem, UInt32 a_aiCount, RemoveType a_mode, BaseExtraList* a_extraList, TESObjectREFR* a_moveToRef, UInt32 a_unk7, UInt32 a_unk8);	// 56
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
		virtual void					Unk_A1(void);																																												// A1
		virtual void					Unk_A2(void);																																												// A2


		float							GetBaseScale();
		bool							IsOffLimits();
		float							GetWeight();
		const char*						GetReferenceName();
		TESWorldSpace*					GetWorldspace();
		UInt32							CreateRefHandle();

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
		bool							IsIgnoringFriendlyHits();
		bool							SetDisplayName(const BSFixedString& name, bool force);
		static bool						LookupByHandle(UInt32& a_refHandle, TESObjectREFRPtr& a_refrOut);
		static bool						LookupByHandle(UInt32& a_refHandle, TESObjectREFR*& a_refrOut);
		bool							IsLocked();
		UInt32							GetNumItems(bool a_unk1, bool a_unk2);
		UInt32							ActivateRefChildren(TESObjectREFR* a_activator);
		void							PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_unk);
		bool							HasInventoryChanges();
		InventoryChanges*				GetInventoryChanges();


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

	private:
		typedef TESForm* _GetOwner_Impl_t(TESObjectREFR* a_this);
		static RelocAddr<_GetOwner_Impl_t*> _GetOwner_Impl;

		typedef LockState* _GetLockState_Impl_t(TESObjectREFR* a_this);
		static RelocAddr<_GetLockState_Impl_t*> _GetLockState_Impl;

		typedef UInt32 _GetNumItems_t(TESObjectREFR* a_this, bool a_unk1, bool a_unk2);
		static RelocAddr<_GetNumItems_t*> _GetNumItems;

		typedef UInt32 _ActivateRefChildren_t(TESObjectREFR* a_this, TESObjectREFR* a_activator);
		static RelocAddr<_ActivateRefChildren_t*> _ActivateRefChildren;

		typedef void _PlayAnimation_t(TESObjectREFR* a_this, NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_unk);
		static RelocAddr<_PlayAnimation_t*> _PlayAnimation;

		typedef InventoryChanges* _GetInventoryChanges_t(TESObjectREFR* a_this);  // Creates inventory changes if none found
		static RelocAddr<_GetInventoryChanges_t*> _GetInventoryChanges;
	};
	STATIC_ASSERT(sizeof(TESObjectREFR) == 0x98);
	STATIC_ASSERT(offsetof(TESObjectREFR, extraData) == 0x70);
	STATIC_ASSERT(offsetof(TESObjectREFR, loadedState) == 0x68);
	STATIC_ASSERT(offsetof(TESObjectREFR::LoadedState, node) == 0x68);
};
