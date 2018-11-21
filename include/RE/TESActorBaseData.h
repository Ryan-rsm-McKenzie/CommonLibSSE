#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

class BGSVoiceType;


namespace RE
{
	class TESFaction;


	class TESActorBaseData : public BaseFormComponent
	{
	public:
		enum Flag : UInt32
		{
			kFlag_Female					= 1 << 0,
			kFlag_Essential					= 1 << 1,
			kFlag_IsPreset					= 1 << 2,
			kFlag_Respawn					= 1 << 3,
			kFlag_AutoCalc					= 1 << 4,
			kFlag_Unique					= 1 << 5,
			kFlag_DontAffectStealthMeter	= 1 << 6,
			kFlag_PCLevelMult				= 1 << 7,
			kFlag_UsesTemplate				= 1 << 8,
			kFlag_Unk00000200				= 1 << 9,
			kFlag_Unk00000400				= 1 << 10,
			kFlag_Protected					= 1 << 11,
			kFlag_Unk00001000				= 1 << 12,
			kFlag_Unk00002000				= 1 << 13,
			kFlag_Summonable				= 1 << 14,
			kFlag_Unk00008000				= 1 << 15,
			kFlag_DoesntBleed				= 1 << 16,
			kFlag_Unk00020000				= 1 << 17,
			kFlag_BleedoutOverride			= 1 << 18,
			kFlag_OppositeGenderanims		= 1 << 19,
			kFlag_SimpleActor				= 1 << 20,
			kFlag_Unk00200000				= 1 << 21,
			kFlag_Unk00400000				= 1 << 22,
			kFlag_Unk00800000				= 1 << 23,
			kFlag_Unk01000000				= 1 << 24,
			kFlag_Unk02000000				= 1 << 25,
			kFlag_Unk04000000				= 1 << 26,
			kFlag_Unk08000000				= 1 << 27,
			kFlag_Unk10000000				= 1 << 28,
			kFlag_Ghost						= 1 << 29,
			kFlag_Unk40000000				= 1 << 30,
			kFlag_Invulnerable				= (UInt32)(1 << 31)
		};


		struct FactionInfo
		{
			TESFaction*	faction;	// 0
			SInt8		rank;		// 8
			UInt8		pad9[7];	// 9
		};


		virtual void			Unk_04(UInt32 arg);
		virtual bool			GetFlag20000000(void);
		virtual bool			GetFlag80000000(void);
		virtual bool			Unk_07(void);
		virtual BGSVoiceType*	GetVoiceType();

		bool					IsFemale();
		bool					IsPreset();
		bool					IsEssential();
		bool					Respawns();
		bool					UsesAutoCalc();
		bool					IsUnique();
		bool					AffectsStealthMeter();
		bool					HasPCLevelMult();
		bool					UsesTemplate();
		bool					Protected();
		bool					IsSummonable();
		bool					Bleeds();
		bool					HasBleedoutOverride();
		bool					UsesOppositeGenderAnims();
		bool					IsSimpleActor();
		bool					IsGhost();
		bool					IsInvulnerable();


		Flag				flags;		// 08 - init'd to 0
		UInt16				unk0C;		// 0C - init'd to 0
		UInt16				unk0E;		// 0E - init'd to 0
		UInt16				level;		// 10 - init'd to 1	(CK Multiplier * 1000 if PCLevelMult is true)
		UInt16				minLevel;	// 12 - init'd to 0
		UInt16				maxLevel;	// 14 - init'd to 0
		UInt16				unk16;		// 16 - init'd to 0x64 (100)
		UInt16				unk18;		// 18 - init'd to iBaseDisposition (35)
		UInt16				unk1A;		// 1A - init'd to 0
		UInt16				unk1C;		// 1C - init'd to 0
		UInt16				unk1E;		// 1E - init'd to 0
		void*				unk20;		// 20
		BGSVoiceType*		voiceType;	// 28
		UInt64				unk30;		// 30
		UInt32				unk38;		// 38 - init'd to 0
		UInt32				pad3C;		// 3C
		tArray<FactionInfo>	factions;	// 40
	};
	STATIC_ASSERT(sizeof(TESActorBaseData) == 0x58);
}
