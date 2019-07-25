#pragma once

#include "RE/BSLock.h"  // BSUniqueLock
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/FormTypes.h"  // TESPackage, TESIdleForm
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class ActiveEffect;
	class BGSEntryPointPerkEntry;
	class bhkCharacterController;
	class bhkRagdollPenetrationUtil;
	class BSAnimationGraphManager;
	class BSFaceGenNiNode;
	class BSLightingShaderProperty;
	class InventoryEntryData;
	class NiNode;
	class QueuedFile;
	struct AnimationVariableData;


	class MiddleProcess
	{
	public:
		struct Data
		{
			mutable BSUniqueLock	lock;		// 00
			TESPackage*				package;	// 08
			UInt64					unk10;		// 10
			float					unk18;		// 18 - shout cooldown?
			UInt32					unk1C;		// 1C - init'd to FFFFFFFF
			float					unk20;		// 20 - init'd to -1
			UInt32					unk24;		// 24
			UInt16					unk28;		// 28
			UInt8					unk2A;		// 2A
			UInt8					unk2B;		// 2B
			UInt32					pad2C;		// 2C
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		BSTArray<void*>						unk000;					// 000
		BSTArray<void*>						unk018;					// 018
		BSTArray<void*>						unk030;					// 030
		UInt64								unk048;					// 048
		void*								unk050;					// 050
		Data								unk058;					// 058
		BSTArray<void*>						unk088;					// 088
		UInt64								unk0A0;					// 0A0
		UInt64								unk0A8;					// 0A8
		float								unk0B0;					// 0B0
		float								unk0B4;					// 0B4
		float								unk0B8;					// 0B8
		float								unk0BC;					// 0BC
		float								unk0C0;					// 0C0
		float								unk0C4;					// 0C4
		float								unk0C8;					// 0C8
		float								unk0CC;					// 0CC
		float								unk0D0;					// 0D0
		float								unk0D4;					// 0D4
		float								unk0D8;					// 0D8
		float								unk0DC;					// 0DC
		float								unk0E0;					// 0E0
		float								unk0E4;					// 0E4
		float								unk0E8;					// 0E8
		UInt32								unk0EC;					// 0EC
		UInt32								unk0F0;					// 0F0
		UInt32								pad0F4;					// 0F4
		void*								unk0F8;					// 0F8 - BSResponse<BSFixedStringCI, Actor, BSFixedStringCI, DoNothingUnhandledPolicy>*
		BSTArray<void*>						unk100;					// 100
		NiNode*								unk118;					// 118
		NiNode*								unk120;					// 120
		NiNode*								unk128;					// 128
		UInt64								unk130;					// 130
		NiNode*								unk138;					// 138
		UInt64								unk140;					// 140
		UInt64								unk148;					// 148
		UInt64								unk150;					// 150
		NiNode*								unk158;					// 158
		NiNode*								unk160;					// 160
		UInt64								unk168;					// 168
		BSFaceGenNiNode*					unk170;					// 170
		BSLightingShaderProperty*			unk178;					// 178
		UInt64								unk180;					// 180
		UInt64								unk188;					// 188
		UInt64								unk190;					// 190
		UInt64								unk198;					// 198
		BSSimpleList<ActiveEffect*>*		effectList;				// 1A0
		NiPointer<BSAnimationGraphManager>*	animationGraphManager;	// 1A8
		BSTArray<AnimationVariableData>*	animVariables;			// 1B0
		void*								unk1B8;					// 1B8 - BSScrapArray<void*>*?
		UInt64								unk1C0;					// 1C0
		UInt64								unk1C8;					// 1C8
		BSTArray<void*>						unk1D0;					// 1D0
		UInt64								unk1E8;					// 1E8
		UInt32								unk1F0;					// 1F0
		UInt32								unk1F4;					// 1F4
		UInt16								unk1F8;					// 1F8 - init'd to FFFF
		UInt16								unk1FA;					// 1FA - init'd to FFFF
		UInt32								unk1FC;					// 1FC
		UInt32								unk200;					// 200
		UInt32								unk204;					// 204 - init'd to FF7FFFFF
		RefHandle							furnitureHandle;		// 208
		UInt32								pad20C;					// 20C
		UInt64								unk210;					// 210
		UInt32								unk218;					// 218
		UInt32								pad21C;					// 21C
		InventoryEntryData*					leftHand;				// 220
		TESIdleForm* 						currentIdle;			// 228
		UInt64								unk230;					// 230
		UInt64								unk238;					// 238
		UInt64								unk240;					// 240
		UInt64								unk248;					// 248
		bhkCharacterController*				characterController;	// 250
		bhkRagdollPenetrationUtil*			ragdollPenetrationUtil;	// 258
		InventoryEntryData*					rightHand;				// 260
		UInt64								unk268;					// 268
		QueuedFile*							unk270;					// 270
		UInt64								unk278;					// 278
		UInt64								unk280;					// 280
		BSTArray<BGSEntryPointPerkEntry*>*	unk288;					// 288
		UInt32								unk290;					// 290
		UInt32								unk294;					// 294
		float								unk298;					// 298 - init'd to -1
		UInt32								unk29C;					// 29C
		UInt32								unk2A0;					// 2A0
		UInt32								unk2A4;					// 2A4
		UInt32								unk2A8;					// 2A8
		UInt32								unk2AC;					// 2AC
		UInt32								unk2B0;					// 2B0
		UInt32								unk2B4;					// 2B4
		UInt32								unk2B8;					// 2B8
		float								unk2BC;					// 2BC - init'd to -1
		UInt32								unk2C0;					// 2C0
		UInt32								unk2C4;					// 2C4
		float								actorAlpha;				// 2C8 - init'd to 1
		UInt32								unk2CC;					// 2CC
		UInt64								unk2D0;					// 2D0
		UInt64								unk2D8;					// 2D8
		UInt64								unk2E0;					// 2E0
		UInt64								unk2E8;					// 2E8
		UInt64								unk2F0;					// 2F0
		UInt64								unk2F8;					// 2F8
		UInt64								unk300;					// 300
		UInt64								unk308;					// 308
		UInt64								unk310;					// 310
		UInt64								unk318;					// 318
		UInt64								unk320;					// 320
		UInt64								unk328;					// 328
		UInt64								unk330;					// 330
	};
	STATIC_ASSERT(offsetof(MiddleProcess, effectList) == 0x1A0);
	STATIC_ASSERT(offsetof(MiddleProcess, currentIdle) == 0x228);
	STATIC_ASSERT(offsetof(MiddleProcess, furnitureHandle) == 0x208);
	STATIC_ASSERT(offsetof(MiddleProcess, actorAlpha) == 0x2C8);
	STATIC_ASSERT(sizeof(MiddleProcess) == 0x338);
}
