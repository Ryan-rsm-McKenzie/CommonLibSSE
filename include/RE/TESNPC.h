#pragma once

#include "skse64/GameEvents.h"  // MenuOpenCloseEvent
#include "skse64/GameFormComponents.h"  // BGSOverridePackCollection
#include "skse64/GameTypes.h"  // BSFixedString

#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESRaceForm.h"  // TESRaceForm

class BGSColorForm;
class BGSHeadPart;
class BGSOutfit;
class BGSTextureSet;
class BSFaceGenNiNode;
class NiColorA;
class TESClass;
class TESCombatStyle;
class TESObjectARMO;


namespace RE
{
	class TESFaction;
	class TESRace;


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
			BGSColorForm*	hairColor;
			BGSTextureSet*	headTexture;	// Only seems to apply to the player
		};


		struct Color
		{
			// 797979 Transparent
			UInt8	red;	// 0
			UInt8	green;	// 1
			UInt8	blue;	// 2
		};


		struct MorphAction
		{
			BSFaceGenNiNode*	faceNode;
			TESNPC*				npc;
			const char**		morphName;
			float				value;
		};


		// override (TESActorBase)
		virtual const char*		GetAliasName(const BSFixedString& a_alias) override;																							// 2E - alias: "Pronoun" "PronounObj" "PronounPos" "PronounPosObj" "PronounRef" "PronounInt" "Race" "Gender" "ShortName". see http://www.creationkit.com/Text_Replacement
		virtual void			CopyFrom(TESForm* a_srcForm) override;																											// 2F - { return; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, uintptr_t a_arg3, uintptr_t a_arg4, uintptr_t a_arg5) override;	// 37
		virtual BGSVoiceType*	GetVoiceType() const override;																													// 4A - { return nullptr; }
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst, bool a_unk) override;																	// 4C
		virtual TESCombatStyle*	GetCombatStyle() override;																														// 55
		virtual void			SetCombatStyle(TESCombatStyle* a_arg) override;																									// 56

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
		UInt8			unk190[0x12];			// 190 - init'd to 5
		UInt8			unk1A2[0x12];			// 1A2 - init'd to 0
		UInt8			pad1B4[0x1BA - 0x1B4];	// 1B4
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
		float			height;					// 1F8 - init'd to 1
		float			weight;					// 1FC - init'd to 50
		void*			unk200;					// 200
		BSFixedString	shortName;				// 208
		TESObjectARMO*	skinFar;				// 210
		BGSOutfit*		defaultOutfit;			// 218
		BGSOutfit*		sleepOutfit;			// 220
		void*			unk228;					// 228
		TESFaction*		faction;				// 230
		BGSHeadPart**	headparts;				// 238
		UInt8			numHeadParts;			// 240
		UInt8			unk241;					// 241 - init'd to 1
		UInt8			unk242;					// 242 - New in SE?
		UInt8			unk243;					// 243
		UInt8			unk244;					// 244 - New in SE?
		UInt8			unk245;					// 245 - init'd to 1
		Color			color;					// 246
		UInt8			pad249[7];				// 249
		void*			unk250;					// 250
		FaceMorphs*		faceMorph;				// 258
		void*			unk260;					// 260
	};
	STATIC_ASSERT(offsetof(TESNPC, nextTemplate) == 0x1F0);
	STATIC_ASSERT(sizeof(TESNPC) == 0x268);
}
