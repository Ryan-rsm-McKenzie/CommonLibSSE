#pragma once

#include "skse64/GameFormComponents.h"  // ActorProcessManager, MiddleProcess
#include "skse64/GameTypes.h"  // UnkFormArray

class TESForm;


namespace RE
{
	class Actor;


	class ActorProcessManager
	{
	public:
		enum EquippedHand : UInt32
		{
			kEquippedHand_Left = 0,
			kEquippedHand_Right = 1
		};


		enum Flag : UInt8
		{
			kFlag_None		= 0,
			kFlag_Unk01		= 1 << 0,
			kFlag_Unk02		= 1 << 1,
			kFlag_Unk03		= 1 << 2,
			kFlag_DrawHead	= 1 << 3,
			kFlag_Mobile	= 1 << 4,
			kFlag_Reset		= 1 << 5
		};


		struct Data10
		{
			struct KnowledgeData
			{
				UInt32	formID;		// 0
				UInt32	pad4;		// 4
				void*	knowledge;	// 8 - ActorKnowledge*
			};

			UInt64						unk000;			// 000
			UInt64						unk008;			// 008
			float						unk010;			// 010
			UInt32						unk014;			// 014
			UInt64						unk018;			// 018
			UInt64						unk020;			// 020
			UInt64						unk028;			// 028
			UInt64						unk030;			// 030
			UInt32						unk038;			// 038
			float						unk03C;			// 03C
			UInt32						unk040;			// 040
			UInt32						unk044;			// 044
			UInt64						unk048;			// 048
			UInt32						unk050;			// 050
			UInt32						unk054;			// 054
			BSFixedString				unk058;			// 058
			UInt32						unk060;			// 060
			UInt32						unk064;			// 064
			UInt64						unk068;			// 068
			void*						unk070;			// 070
			void*						unk078;			// 078
			UInt64						unk080;			// 080
			UInt64						unk088;			// 088
			UInt64						unk090;			// 090
			UInt64						unk098;			// 098
			UInt64						unk0A0;			// 0A0
			UInt64						unk0A8;			// 0A8
			UInt64						unk0B0;			// 0B0
			UInt64						unk0B8;			// 0B8
			UInt64						unk0C0;			// 0C0
			UInt64						unk0C8;			// 0C8
			UInt64						unk0D0;			// 0D0
			UInt32						unk0D8;			// 0D8
			UInt32						unk0DC;			// 0DC
			UInt32						unk0E0;			// 0E0
			float						unk0E4;			// 0E4
			UInt64						unk0E8;			// 0E8
			BSFixedString				dialogueText;	// 0F0
			tArray<void*>				actorKnowledge;	// 0F8 - KnowledgeData?
			tArray<void*>				unk110;			// 110
			tArray<void*>				unk128;			// 128
			UInt64						unk140;			// 140
			UInt64						unk148;			// 148
			UInt64						unk150;			// 150
			UInt64						unk158;			// 158
			UInt64						unk160;			// 160
			UInt64						unk168;			// 168
			UInt64						unk170;			// 170
			UInt64						unk178;			// 178
			UInt64						unk180;			// 180
			UInt64						unk188;			// 188
			UInt64						unk190;			// 190
			UInt64						unk198;			// 198
			UInt64						unk1A0;			// 1A0
			UInt32						unk1A8;			// 1A8
			UInt32						unk1AC;			// 1AC
			UInt64						unk1B0;			// 1B0
			UInt64						unk1B8;			// 1B8
			void*						unk1C0;			// 1C0 - PathingCell*
			UInt64						unk1C8;			// 1C8
			void*						unk1D0;			// 1D0 - Navmesh*
			UInt64						unk1D8;			// 1D8
			UInt32						unk1E0;			// 1E0
			UInt32						unk1E4;			// 1E4
			UInt64						unk1E8;			// 1E8
			UInt64						unk1F0;			// 1F0
			UInt64						unk1F8;			// 1F8
			UInt64						unk200;			// 200
			UInt64						unk208;			// 208
			UInt64						unk210;			// 210
			UInt64						unk218;			// 218
			UInt64						unk220;			// 220
			UInt64						unk228;			// 228
			UInt64						unk230;			// 230
			UInt64						unk238;			// 238
			UInt64						unk240;			// 240
			UInt64						unk248;			// 248
			UInt32						unk250;			// 250
			UInt32						unk254;			// 254
			UInt64						unk258;			// 258
			UInt64						unk260;			// 260
			UInt64						unk268;			// 268
			UInt64						unk270;			// 270
			UInt64						unk278;			// 278
			UInt64						unk280;			// 280
			UInt64						unk288;			// 288
			UInt64						unk290;			// 290
			UInt64						unk298;			// 298
			UInt64						unk2A0;			// 2A0
			UInt64						unk2A8;			// 2A8
			UInt64						unk2B0;			// 2B0
			UInt64						unk2B8;			// 2B8
			UInt64						unk2C0;			// 2C0
			UInt64						unk2C8;			// 2C8
			UInt64						unk2D0;			// 2D0
			UInt64						unk2D8;			// 2D8
			UInt64						unk2E0;			// 2E0
			UInt64						unk2E8;			// 2E8
			UInt64						unk2F0;			// 2F0
			UInt64						unk2F8;			// 2F8
			UInt64						unk300;			// 300
			UInt64						unk308;			// 308
			UInt64						unk310;			// 310
			UInt64						unk318;			// 318
			UInt64						unk320;			// 320
			UInt64						unk328;			// 328
			UInt64						unk330;			// 330
			UInt64						unk338;			// 338
			UInt64						unk340;			// 340
			UInt64						unk348;			// 348
			UInt64						unk350;			// 350
			UInt64						unk358;			// 358
			UInt64						unk360;			// 360
			UInt64						unk368;			// 368
			UInt64						unk370;			// 370
			UInt64						unk378;			// 378
			UInt64						unk380;			// 380
			UInt64						unk388;			// 388
			UInt64						unk390;			// 390
			UInt64						unk398;			// 398
			UInt64						unk3A0;			// 3A0
			float						lightLevel;		// 3A8
			UInt32						unk3AC;			// 3AC
		};
		STATIC_ASSERT(offsetof(Data10, actorKnowledge) == 0x0F8);
		STATIC_ASSERT(offsetof(Data10, lightLevel) == 0x3A8);


		void	SetEquipFlag(Flag a_flag);
		void	UpdateEquipment(Actor* a_actor);
		void	SetDataFlag(float a_flag);
		void	UpdateEquipment_Hooked(Actor* a_actor);


		// members
		void*					unk00;					// 00
		MiddleProcess*			middleProcess;			// 08
		Data10*					unk10;					// 10
		MiddleProcess::Data58	unk18;					// 18
		float					unk48;					// 48 - init'd to -1
		UInt32					unk4C;					// 4C
		void*					unk50;					// 50
		UInt32					unk58;					// 58
		UInt32					pad5C;					// 5C
		UInt64					unk60;					// 60
		UInt64					unk68;					// 68
		UInt64					unk70;					// 70
		UInt64					unk78;					// 78
		UInt64					unk80;					// 80
		UInt64					unk88;					// 88
		UInt32					unk90;					// 90
		float					timeOfDeath;			// 94 - GetTimeDead = (GameDaysPassed*24) - timeOfDeath
		float					unk98;					// 98 - related with above
		UInt32					pad9C;					// 9C
		UnkFormArray			forms;					// A0  seen containing [left hand, equip slot, right hand, equip slot, right hand, equip slot)
		UInt64					unkB8[7];				// B8 2nd slot points back to this adress
		TESForm*				equippedObject[2];		// F0
		UInt8					unk100[0x136 - 0x100];	// 100
		UInt8					unk136;					// 136
		SInt8					unk137;					// 137 - init'd to 3
		UInt8					unk138;					// 138
		UInt8					unk139;					// 139
		UInt8					unk13A;					// 13A
		UInt8					unk13B;					// 13B
		UInt32					pad13C;					// 13C
	};
}
