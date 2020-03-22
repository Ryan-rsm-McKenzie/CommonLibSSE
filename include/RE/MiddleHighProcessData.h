#pragma once

#include "RE/ActorPackage.h"
#include "RE/BGSPerkEntry.h"
#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSResponse.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/FormTypes.h"
#include "RE/MagicSystem.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class ActiveEffect;
	class BGSAttackData;
	class BGSPerkEntry;
	class bhkCharacterController;
	class bhkRagdollPenetrationUtil;
	class BSAnimationGraphManager;
	class BSFaceGenAnimationData;
	class BSFaceGenNiNode;
	class BSLightingShaderProperty;
	class ExtraDataList;
	class InventoryEntryData;
	class MagicItem;
	class NiAVObject;
	class NiNode;
	class QueuedFile;
	class TESBoundObject;
	struct AnimationVariableData;
	struct BSAnimationGraphVariableCache;


	enum class RESET_3D_FLAGS : UInt8
	{
		kNone = 0,
		kModel = 1 << 0,
		kSkin = 1 << 1,
		kHead = 1 << 2,
		kFace = 1 << 3,
		kScale = 1 << 4,
		kSkeleton = 1 << 5,
		kInitDefault = 1 << 6,
		kSkyCellSkin = (UInt8)1 << 7
	};


	struct CommandedActorData
	{
		ActorHandle	  commandedActor;  // 00
		UInt32		  pad04;		   // 04
		ActiveEffect* activeEffect;	   // 10
	};
	STATIC_ASSERT(sizeof(CommandedActorData) == 0x10);


	struct ObjectEquipParams
	{
		ExtraDataList*		extraDataList;	  // 00
		SInt32				count;			  // 08
		UInt32				pad0C;			  // 0C
		const BGSEquipSlot* equipSlot;		  // 10
		void*				unk18;			  // 18
		bool				playEquipSounds;  // 20
		bool				forceEquip;		  // 21
		bool				showMessage;	  // 22
		bool				unk23;			  // 23
		bool				unk24;			  // 24
		UInt8				pad25;			  // 25
		UInt16				pad26;			  // 26
	};
	STATIC_ASSERT(sizeof(ObjectEquipParams) == 0x28);


	class QueuedItem
	{
	public:
		QueuedItem*			  next;			// 00
		TESBoundObject*		  object;		// 08
		ObjectEquipParams	  equipParams;	// 10
		NiPointer<QueuedFile> queuedFiles;	// 38
		bool				  equip;		// 40
		UInt8				  pad41;		// 41
		UInt16				  pad42;		// 42
		UInt32				  pad44;		// 44
	};
	STATIC_ASSERT(sizeof(QueuedItem) == 0x48);


	class HitData
	{
	public:
		enum class Flag
		{
			kBlocked = 1 << 0,
			kBlockWithWeapon = 1 << 1,
			kBlockCandidate = 1 << 2,
			kCritical = 1 << 3,
			kCriticalOnDeath = 1 << 4,
			kFatal = 1 << 5,
			kDismemberLimb = 1 << 6,
			kExplodeLimb = 1 << 7,
			kCrippleLimb = 1 << 8,
			kDisarm = 1 << 9,
			kDisableWeapon = 1 << 10,
			kSneakAttack = 1 << 11,
			kIgnoreCritical = 1 << 12,
			kPredictDamage = 1 << 13,
			kPredictBaseDamage = 1 << 14,
			kBash = 1 << 15,
			kTimedBash = 1 << 16,
			kPowerAttack = 1 << 17,
			kMeleeAttack = 1 << 18,
			kRicochet = 1 << 19,
			kExplosion = 1 << 20
		};


		// members
		NiPoint3				 unk00;					  // 00
		NiPoint3				 unk0C;					  // 0C
		ActorHandle				 aggressor;				  // 18
		ActorHandle				 target;				  // 1C
		ObjectRefHandle			 sourceRef;				  // 20
		UInt32					 pad24;					  // 24
		NiPointer<BGSAttackData> attackData;			  // 28
		TESObjectWEAP*			 weapon;				  // 30
		UInt64					 unk38;					  // 38
		UInt64					 unk40;					  // 40
		UInt32					 unk48;					  // 48
		float					 healthDamage;			  // 4C
		float					 totalDamage;			  // 50
		float					 physicalDamage;		  // 54
		float					 targetedLimbDamage;	  // 58
		float					 percentBlocked;		  // 5C
		float					 resistedPhysicalDamage;  // 60
		float					 resistedTypedDamage;	  // 64
		UInt32					 stagger;				  // 68
		float					 sneakAttackBonus;		  // 6C
		float					 bonusHealthDamageMult;	  // 70
		float					 pushBack;				  // 74
		float					 reflectedDamage;		  // 78
		float					 criticalDamageMult;	  // 7C
		Flag					 flags;					  // 80
		UInt32					 equipIndex;			  // 84
		UInt32					 material;				  // 88
		UInt32					 damageLimb;			  // 8C
	};
	STATIC_ASSERT(sizeof(HitData) == 0x90);


	struct DeferredHideLimb
	{
		float			  dismemberTimer;		// 00
		UInt32			  limbIndex;			// 04
		NiPointer<NiNode> dismemberedLimbRoot;	// 08
		NiPointer<NiNode> replacementLimb;		// 10
		DeferredHideLimb* next;					// 18
		bool			  explosion;			// 20
		UInt8			  pad21;				// 21
		UInt16			  pad22;				// 22
		UInt32			  pad24;				// 24
	};
	STATIC_ASSERT(sizeof(DeferredHideLimb) == 0x28);


	struct AIPerkData
	{
		BSTArray<BGSPerkEntry*>& at(BGSEntryPoint::ENTRY_POINT a_pos)
		{
			return operator[](a_pos);
		}


		BSTArray<BGSPerkEntry*>& operator[](BGSEntryPoint::ENTRY_POINT a_pos)
		{
			assert(a_pos < BGSEntryPoint::ENTRY_POINT::kTotal);
			return perkEntryArrays[to_underlying(a_pos)];
		}


		// members
		BSTArray<BGSPerkEntry*> perkEntryArrays[BGSEntryPoint::ENTRY_POINTS::kTotal];  // 000
	};
	STATIC_ASSERT(sizeof(AIPerkData) == 0x8A0);


	struct MiddleHighProcessData
	{
	public:
		BSTEventSource<void*>					   unk000;					// 000
		ActorPackage							   runOncePackage;			// 058
		BSTArray<ActorHandle>					   deadDetectList;			// 088
		BSSimpleList<TESObjectREFR*>			   refListChairBed;			// 0A0
		NiPoint3								   rotation;				// 0B0
		NiPoint3								   rotationSpeed;			// 0BC
		NiPoint3								   actorMountPosition;		// 0C8
		NiPoint3								   furniturePathPoint;		// 0D4
		NiPoint3								   lastSeenPosition;		// 0E0
		UInt32									   bleedoutAttacker;		// 0EC
		MagicSystem::WardState					   wardState;				// 0F0
		UInt32									   pad0F4;					// 0F4
		BSTSmartPointer<AnimResponseBase>		   animResponse;			// 0F8
		BSTArray<CommandedActorData>			   commandedActors;			// 100
		NiNode*									   damageRootNode[6];		// 118
		UInt64									   unk148;					// 148
		NiNode*									   weaponBone;				// 150
		NiAVObject*								   headNode;				// 158
		NiAVObject*								   torsoNode;				// 160
		NiAVObject*								   faceTargetSourceNode;	// 168
		BSFaceGenNiNode*						   faceNodeSkinned;			// 170
		NiPointer<BSLightingShaderProperty>		   lightingProperty;		// 178
		UInt64									   unk180;					// 180
		QueuedItem*								   itemstoEquipUnequip;		// 188
		HitData*								   lastHitData;				// 190
		DeferredHideLimb*						   headDeferredHideLimb;	// 198
		BSSimpleList<ActiveEffect*>*			   activeEffects;			// 1A0
		BSTSmartPointer<BSAnimationGraphManager>   animationGraphManager;	// 1A8
		BSAnimationGraphVariableCache*			   animationVariableCache;	// 1B0
		BSTArray<void*>							   unk1B8;					// 1B8
		BSTArray<void*>							   unk1D0;					// 1D0
		mutable BSSpinLock						   unk1E8;					// 1E8
		void*									   unk1F0;					// 1F0 - smart ptr
		UInt16									   unk1F8;					// 1F8
		UInt16									   unk1FA;					// 1FA
		UInt32									   unk1FC;					// 1FC
		UInt32									   unk200;					// 200
		float									   headHeightOffset;		// 204
		ObjectRefHandle							   currentFurniture;		// 208
		ObjectRefHandle							   occupiedFurniture;		// 20C
		UInt64									   unk210;					// 210
		UInt32									   unk218;					// 218
		UInt32									   pad21C;					// 21C
		InventoryEntryData*						   leftHand;				// 220
		TESIdleForm*							   currentIdle;				// 228
		void*									   unk230;					// 230 - smart ptr
		UInt64									   unk238;					// 238
		UInt64									   unk240;					// 240
		UInt64									   unk248;					// 248
		NiPointer<bhkCharacterController>		   charController;			// 250
		BSTSmartPointer<bhkRagdollPenetrationUtil> penetrationDetectUtil;	// 258
		InventoryEntryData*						   rightHand;				// 260
		InventoryEntryData*						   bothHands;				// 268
		NiPointer<QueuedFile>					   bodyPartPreload;			// 270
		void*									   unk278;					// 278
		UInt64									   unk280;					// 280
		AIPerkData*								   perkData;				// 288
		UInt32									   unk290;					// 290
		float									   unk294;					// 294
		float									   unk298;					// 298
		float									   unk29C;					// 29C
		float									   unk2A0;					// 2A0
		float									   unk2A4;					// 2A4
		float									   unk2A8;					// 2A8
		float									   unk2AC;					// 2AC
		float									   unk2B0;					// 2B0
		float									   unk2B4;					// 2B4
		float									   unk2B8;					// 2B8
		float									   unk2BC;					// 2BC
		float									   unk2C0;					// 2C0
		float									   unk2C4;					// 2C4
		float									   alphaMult;				// 2C8
		float									   scriptRefractPower;		// 2CC
		float									   unk2D0;					// 2D0
		float									   deferredKillTimer;		// 2D4
		float									   killMoveTimer;			// 2D8
		float									   unk2DC;					// 2DC
		UInt32									   unk2E0;					// 2E0
		UInt32									   unk2E4;					// 2E4
		UInt32									   unk2E8;					// 2E8
		UInt32									   unk2EC;					// 2EC
		UInt64									   unk2F0;					// 2F0
		UInt32									   unk2F8;					// 2F8
		UInt32									   unk2FC;					// 2FC
		UInt32									   unk300;					// 300
		UInt16									   unk304;					// 304
		UInt16									   unk306;					// 306
		UInt64									   unk308;					// 308
		UInt8									   unk310;					// 310
		RESET_3D_FLAGS							   update3DModel;			// 311
		UInt16									   unk312;					// 312
		UInt16									   unk314;					// 314
		bool									   unk316;					// 316
		bool									   unk317;					// 317
		bool									   unk318;					// 318
		bool									   unk319;					// 319
		bool									   unk31A;					// 31A
		bool									   pickPocketed;			// 31B
		bool									   unk31C;					// 31C
		bool									   unk31D;					// 31D
		bool									   unk31E;					// 31E
		bool									   unk31F;					// 31F
		bool									   unk320;					// 320
		bool									   unk321;					// 321
		bool									   beenAttacked;			// 322
		bool									   unk323;					// 323
		bool									   unk324;					// 324
		bool									   unk325;					// 325
		bool									   unk326;					// 326
		bool									   unk327;					// 327
		bool									   unk328;					// 328
		bool									   unk329;					// 329
		bool									   unk32A;					// 32A
		bool									   unk32B;					// 32B
		bool									   unk32C;					// 32C
		bool									   unk32D;					// 32D
		bool									   unk32E;					// 32E
		bool									   unk32F;					// 32F
		bool									   unk330;					// 330
		bool									   unk331;					// 331
		bool									   unk332;					// 332
		bool									   pad333;					// 333
		UInt32									   pad334;					// 334
	};
	STATIC_ASSERT(sizeof(MiddleHighProcessData) == 0x338);
}
