#pragma once

#include "skse64/GameFormComponents.h"  // BGSOverridePackCollection

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // BGSColorForm, BGSTextureSet, BGSHeadPart, TESClass, BGSOutfit, TESFaction, BGSHeadPart
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESRaceForm.h"  // TESRaceForm


namespace RE
{
	class BGSTextureSet;
	class BSFaceGenNiNode;
	class MenuOpenCloseEvent;
	class NiColorA;
	class TESRace;
	class TintMask;


	class TESNPC :
		public TESActorBase,					// 000
		public TESRaceForm,						// 150
		public BGSOverridePackCollection,		// 160
		public BSTEventSink<MenuOpenCloseEvent>	// 188
	{
	public:
		enum { kTypeID = FormType::NPC };


		struct FaceMorphs
		{
			enum
			{
				kNumOptions = 19,
				kNumPresets = 4,
			};


			float	option[kNumOptions];
			UInt32	presets[kNumPresets];
		};


		struct HeadData
		{
			BGSColorForm*	hairColor;		// 00
			BGSTextureSet*	headTexture;	// 08 - Only seems to apply to the player
		};
		STATIC_ASSERT(sizeof(HeadData) == 0x10);


		struct MorphAction
		{
			BSFaceGenNiNode*	faceNode;	// 00
			TESNPC*				npc;		// 08
			const char**		morphName;	// 10
			float				value;		// 18
			UInt32				pad1C;		// 1C
		};
		STATIC_ASSERT(sizeof(MorphAction) == 0x20);


		// override (TESActorBase)
		virtual const char*		GetAliasName(const BSFixedString& a_alias) override;																				// 2E - alias: "Pronoun" "PronounObj" "PronounPos" "PronounPosObj" "PronounRef" "PronounInt" "Race" "Gender" "ShortName". see http://www.creationkit.com/Text_Replacement
		virtual void			CopyFrom(TESForm* a_srcForm) override;																								// 2F - { return; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37
		virtual BGSVoiceType*	GetVoiceType() const override;																										// 4A - { return 0; }
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																	// 4C
		virtual TESCombatStyle*	GetCombatStyle() override;																											// 55
		virtual void			SetCombatStyle(TESCombatStyle* a_arg) override;																						// 56

		char					GetSex();
		bool					HasOverlays();
		void					ChangeHeadPart(BGSHeadPart* a_target);
		void					UpdateNeck(BSFaceGenNiNode* a_faceNode);
		void					SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute, UInt32 a_unk4);
		void					SetFaceTexture(BGSTextureSet* a_textureSet);
		void					SetHairColor(BGSColorForm* a_hairColor);
		BGSHeadPart*			GetHeadPartByType(UInt32 a_type);
		BGSHeadPart*			GetHeadPartOverlayByType(UInt32 a_type);
		BGSHeadPart*			GetCurrentHeadPartByType(UInt32 a_type);
		TESNPC*					GetRootTemplate();
		TESRace*				GetRace();


		// members
		UInt64			unk190;					// 190
		UInt64			unk198;					// 198
		UInt64			unk1A0;					// 1A0
		UInt64			unk1A8;					// 1A8
		UInt64			unk1B0;					// 1B0
		UInt16			unk1B8;					// 1B8
		UInt16			unk1BA;					// 1BA
		UInt32			pad1BC;					// 1BC
		TESClass*		npcClass;				// 1C0
		HeadData*		headData;				// 1C8
		void*			unk1D0;					// 1D0
		TESCombatStyle*	combatStyle;			// 1D8
		UInt32			unk1E0;					// 1E0
		UInt32			pad1E4;					// 1E4
		TESRace*		overlayRace;			// 1E8
		TESNPC*			nextTemplate;			// 1F0
		float			height;					// 1F8
		float			weight;					// 1FC
		void*			unk200;					// 200
		BSFixedString	shortName;				// 208
		TESObjectARMO*	skinFar;				// 210
		BGSOutfit*		defaultOutfit;			// 218
		BGSOutfit*		sleepOutfit;			// 220
		void*			unk228;					// 228
		TESFaction*		faction;				// 230
		BGSHeadPart**	headparts;				// 238
		UInt8			numHeadParts;			// 240
		UInt8			unk241;					// 241
		UInt8			unk242;					// 242
		UInt8			unk243;					// 243
		UInt8			unk244;					// 244
		UInt8			unk245;					// 245
		Color			color;					// 246
		UInt16			pad24A;					// 24A
		UInt32			pad24C;					// 24C
		void*			unk250;					// 250
		FaceMorphs*		faceMorph;				// 258
		void*			unk260;					// 260
	};
	STATIC_ASSERT(offsetof(TESNPC, nextTemplate) == 0x1F0);
	STATIC_ASSERT(sizeof(TESNPC) == 0x268);
}
