#pragma once

#include "RE/AITimeStamp.h"
#include "RE/BGSAnimationSequencer.h"
#include "RE/BSFixedString.h"
#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTList.h"
#include "RE/BSTSmartPointer.h"
#include "RE/BSTTuple.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESShout.h"


namespace RE
{
	class ActorKnowledge;
	class BGSAttackData;
	class DialogueItem;
	class IAnimationSetCallbackFunctor;
	class NiBillboardNode;
	class NiRefObject;
	class StandardDetectionListener;
	struct Crime;
	struct QueuedDialogueType;


	enum class VOICE_STATE : UInt32
	{
		kNone = 0,
		kRequest = 1,
		kStart = 2,
		kContinue = 3,
		kPrecast = 4,
		kPostcast = 5,
		kFail = 6
	};


	struct DetectionEvent
	{
		UInt32			actionValue;  // 00
		NiPoint3		location;	  // 00
		AITimeStamp		timeStamp;	  // 10
		ObjectRefHandle ref;		  // 10
	};
	STATIC_ASSERT(sizeof(DetectionEvent) == 0x18);


	struct HighProcessData
	{
	public:
		enum class FADE_STATE : UInt32
		{
			kNormal = 0,
			kIn = 1,
			kOut = 2,
			kTeleportIn = 3,
			kTeleportOut = 4,
			kOutDisable = 5,
			kOutDelete = 6
		};


		struct Data190 : public BSIntrusiveRefCounted
		{
			struct Data
			{
				struct UnkData
				{
					UInt64 unk00;  // 00
					UInt64 unk08;  // 08
					UInt64 unk10;  // 10
					UInt64 unk18;  // 18
					UInt64 unk20;  // 20
					UInt64 unk28;  // 28
					UInt64 unk30;  // 30
					UInt64 unk38;  // 38
					UInt64 unk40;  // 40
					UInt64 unk48;  // 48
					UInt64 unk50;  // 50
					UInt64 unk58;  // 58
					UInt64 unk60;  // 60
					UInt64 unk68;  // 68
					UInt64 unk70;  // 70
					UInt64 unk78;  // 78
				};
				STATIC_ASSERT(sizeof(UnkData) == 0x80);


				UnkData* unk00;	 // 00
				UInt64	 unk08;	 // 08
			};
			STATIC_ASSERT(sizeof(Data) == 0x10);


			UInt32				unk04;	// 00
			BSTSmallArray<Data> unk08;	// 08
			UInt64				unk28;	// 28
		};
		STATIC_ASSERT(sizeof(Data190) == 0x30);


		struct Data208
		{
			UInt64	 unk00;	 // 00
			UInt64	 unk08;	 // 08
			UInt64	 unk10;	 // 10
			UInt64	 unk18;	 // 18
			UInt64	 unk20;	 // 20
			UInt64	 unk28;	 // 28
			Data208* next;	 // 30
		};
		STATIC_ASSERT(sizeof(Data208) == 0x38);


		struct Data3C8
		{
			UInt64				   unk00;  // 00
			UInt64				   unk08;  // 08
			NiPointer<NiRefObject> unk10;  // 10
			NiPointer<NiRefObject> unk18;  // 18
			NiPointer<NiRefObject> unk20;  // 20
			UInt64				   unk28;  // 28
			UInt64				   unk30;  // 30
			UInt64				   unk38;  // 38
		};
		STATIC_ASSERT(sizeof(Data3C8) == 0x40);


		VOICE_STATE											  voiceState;					  // 000
		UInt32												  pad004;						  // 004
		TESShout*											  currentShout;					  // 008
		TESShout::VariationID								  currentShoutVariation;		  // 010
		float												  voiceTimeElapsed;				  // 014
		float												  voiceRecoveryTime;			  // 018
		float												  healthRegenDelay;				  // 01C
		float												  staminaRegenDelay;			  // 020
		float												  magickaRegenDelay;			  // 024
		float												  unk028;						  // 028
		UInt32												  unk02C;						  // 02C
		BSTArray<ActorHandle>								  lastSpokenToArray;			  // 030
		UInt64												  unk048;						  // 048
		BGSAnimationSequencer								  animSequencer;				  // 050
		NiPoint3											  pathingCurrentMovementSpeed;	  // 088
		NiPoint3											  pathingCurrentRotationSpeed;	  // 094
		NiPoint3											  pathingDesiredPosition;		  // 0A0
		NiPoint3											  pathingDesiredOrientation;	  // 0AC
		NiPoint3											  pathingDesiredMovementSpeed;	  // 0B8
		NiPoint3											  pathingDesiredRotationSpeed;	  // 0C4
		UInt64												  unk0D0;						  // 0D0
		ObjectRefHandle										  lastExtDoorActivated;			  // 0D8
		float												  activationHeight;				  // 0DC
		RefHandle											  unk0E0;						  // 0E0
		UInt32												  unk0E4;						  // 0E4
		UInt64												  unk0E8;						  // 0E8
		BSFixedString										  voiceSubtitle;				  // 0F0
		float												  unk0F8;						  // 0F8
		float												  unk0FC;						  // 0FC
		float												  unk100;						  // 100
		float												  unk104;						  // 104
		float												  unk108;						  // 108
		float												  unk10C;						  // 10C
		float												  unk110;						  // 110
		float												  unk114;						  // 114
		float												  unk118;						  // 118
		float												  unk11C;						  // 11C
		float												  unk120;						  // 120
		float												  unk124;						  // 124
		float												  unk128;						  // 128
		float												  unk12C;						  // 12C
		FADE_STATE											  fadeState;					  // 130
		UInt32												  unk134;						  // 134
		UInt64												  unk138;						  // 138
		UInt64												  unk140;						  // 140
		UInt64												  unk148;						  // 148
		UInt64												  unk150;						  // 150
		UInt64												  unk158;						  // 158
		float												  headTrackTargetTimer;			  // 160
		NiPoint3											  headTrackTargetOffset;		  // 164
		float												  headTrackHoldOffsetHoldTimer;	  // 170
		float												  headTrackTargetOffsetTimer;	  // 174
		ObjectRefHandle										  lastTarget;					  // 178
		ObjectRefHandle										  pathLookAtTarget;				  // 17C
		void*												  unk180;						  // 180 - smart ptr
		void*												  unk188;						  // 188 - smart ptr
		BSTSmartPointer<Data190>							  unk190;						  // 190
		BSTSmartPointer<Data190>							  unk198;						  // 198
		float												  unk1A0;						  // 1A0
		float												  unk1A4;						  // 1A4
		float												  unk1A8;						  // 1A8
		UInt32												  unk1AC;						  // 1AC
		UInt64												  unk1B0;						  // 1B0
		UInt64												  unk1B8;						  // 1B8
		UInt64												  unk1C0;						  // 1C0
		UInt64												  unk1C8;						  // 1C8
		UInt64												  unk1D0;						  // 1D0
		UInt64												  unk1D8;						  // 1D8
		float												  unk1E0;						  // 1E0
		float												  cachedActorHeight;			  // 1E4
		NiPointer<NiRefObject>								  unk1E8;						  // 1E8
		UInt32												  unk1F0;						  // 1F0
		float												  unk1F4;						  // 1F4
		UInt32												  unk1F8;						  // 1F8
		float												  unk1FC;						  // 1FC
		float												  unk200;						  // 200
		UInt32												  pad204;						  // 204
		Data208*											  unk208;						  // 208
		UInt64												  unk210;						  // 210
		BSFixedString										  unk218;						  // 218
		BSTArray<BSTTuple<FormID, NiPointer<ActorKnowledge>>> knowledgeArray;				  // 220
		mutable BSReadWriteLock								  knowledgeLock;				  // 238
		BSTArray<QueuedDialogueType*>						  queueofGreetings;				  // 240
		NiPointer<BGSAttackData>							  attackData;					  // 258
		NiPoint3											  locationOffsetByWaterPoint;	  // 260
		UInt32												  unk26C;						  // 26C
		UInt64												  unk270;						  // 270
		float												  unk278;						  // 278
		NiPoint3											  deathForceDirection;			  // 27C
		float												  deathForce;					  // 288
		float												  unk28C;						  // 28C
		float												  unk290;						  // 290
		float												  unk294;						  // 294
		float												  unk298;						  // 298
		float												  clearTalkToListTimer;			  // 29C
		float												  maxAlpha;						  // 2A0
		float												  unk2A4;						  // 2A4
		UInt64												  unk2A8;						  // 2A8
		float												  unk2B0;						  // 2B0 - fAISocialTimerForConversationsMin
		UInt32												  unk2B4;						  // 2B4
		UInt64												  unk2B8;						  // 2B8
		UInt64												  unk2C0;						  // 2C0
		UInt64												  unk2C8;						  // 2C8
		UInt64												  unk2D0;						  // 2D0
		UInt32												  unk2D8;						  // 2D8
		NiPoint3											  leftWeaponLastPos;			  // 2DC
		NiPoint3											  rightWeaponLastPos;			  // 2E8
		ObjectRefHandle										  greetActor;					  // 2F4
		float												  soundDelay;					  // 2F8
		BSSoundHandle										  soundHandles[2];				  // 2FC
		float												  greetingTimer;				  // 314
		float												  exclusiveTimer;				  // 318
		float												  idleTimer;					  // 31C
		float												  detectGreetTimer;				  // 320
		float												  breathTimer;					  // 324
		UInt64												  unk328;						  // 328
		UInt64												  unk330;						  // 330
		UInt64												  unk338;						  // 338
		UInt64												  unk340;						  // 340
		UInt64												  unk348;						  // 348
		RefHandle											  unk350;						  // 350
		UInt32												  unk354;						  // 354
		UInt64												  unk358;						  // 358
		BSTSmartPointer<DialogueItem>						  greetTopic;					  // 360
		UInt32												  unk368;						  // 368
		RefHandle											  unk36C;						  // 36C
		void*												  unk370;						  // 370
		UInt64												  unk378;						  // 378
		NiPointer<NiBillboardNode>							  healthBarNode;				  // 380
		float												  unk388;						  // 388
		UInt32												  unk38C;						  // 38C
		UInt32												  numberGuardsPursuing;			  // 390
		float												  reEquipArmorTimer;			  // 394
		BSSimpleList<SpellItem*>*							  leveledSpellList;				  // 398
		float												  detectionModifier;			  // 3A0
		float												  detectionModifierTimer;		  // 3A4
		float												  lightLevel;					  // 3A8
		float												  sceneHeadTrackTimer;			  // 3AC
		float												  pCapVoiceFailsafeTimer;		  // 3B0
		UInt32												  pad3B4;						  // 3B4
		void*												  unk3B8;						  // 3B8
		UInt64												  unk3C0;						  // 3C0
		Data3C8*											  unk3C8;						  // 3C8
		UInt32												  unk3D0;						  // 3D0
		UInt32												  pad3D4;						  // 3D4
		DetectionEvent*										  actorsGeneratedDetectionEvent;  // 3D8
		NiPointer<StandardDetectionListener>				  detectionListener;			  // 3E0
		UInt64												  unk3E8;						  // 3E8
		void*												  unk3F0;						  // 3F0 - smart ptr
		UInt64												  unk3F8;						  // 3F8
		BSTSmallArray<UInt64>								  unk400;						  // 400
		NiPoint3											  animationDelta;				  // 418
		NiPoint3											  animationAngleMod;			  // 424
		BSTSmartPointer<IAnimationSetCallbackFunctor>		  unk430;						  // 430
		UInt64												  unk438;						  // 438
		Crime*												  crimeToReactTo;				  // 440
		UInt64												  unk448;						  // 448
		UInt64												  unk450;						  // 450
		UInt8												  unk458;						  // 458
		bool												  inCommandState;				  // 459
		UInt8												  unk45A;						  // 45A
		UInt8												  unk45B;						  // 45B
		UInt32												  unk45C;						  // 45C
		UInt16												  unk460;						  // 460
		bool												  arrested;						  // 462
		bool												  unk463;						  // 463
		bool												  unk464;						  // 464
		bool												  unk465;						  // 465
		bool												  unk466;						  // 466
		bool												  unk467;						  // 467
		bool												  farGeometry;					  // 468
		bool												  unk469;						  // 469
		bool												  unk46A;						  // 46A
		bool												  unk46B;						  // 46B
		bool												  unk46C;						  // 46C
		bool												  unk46D;						  // 46D
		bool												  unk46E;						  // 46E
		bool												  unk46F;						  // 46F
		bool												  unk470;						  // 470
		bool												  unk471;						  // 471
		bool												  unk472;						  // 472
		UInt8												  pad473;						  // 473
		UInt32												  pad474;						  // 474
	};
	STATIC_ASSERT(sizeof(HighProcessData) == 0x478);
}
