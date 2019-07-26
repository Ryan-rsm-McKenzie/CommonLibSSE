#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESNPC

#include <type_traits>  // underlying_type_t

#include "RE/BGSOverridePackCollection.h"  // BGSOverridePackCollection
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // BGSColorForm, BGSTextureSet, BGSHeadPart, TESClass, BGSOutfit, TESFaction, BGSHeadPart, TESRace
#include "RE/SoundLevels.h"  // SoundLevel8
#include "RE/TESActorBase.h"  // TESActorBase
#include "RE/TESRaceForm.h"  // TESRaceForm


namespace RE
{
	class BSFaceGenNiNode;
	class MenuOpenCloseEvent;
	class NiColorA;
	class TintMask;


	class TESNPC :
		public TESActorBase,					// 000
		public TESRaceForm,						// 150
		public BGSOverridePackCollection,		// 160
		public BSTEventSink<MenuOpenCloseEvent>	// 188
	{
	public:
		inline static const void* RTTI = RTTI_TESNPC;


		enum { kTypeID = FormType::NPC };


		enum class Sex : UInt8
		{
			kError = static_cast<std::underlying_type_t<Sex>>(-1),
			kMale = 0,
			kFemale = 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCompressed = 1 << 18,
				kBleedoutOverride = 1 << 29
			};
		};


		struct Skills
		{
			enum
			{
				kOneHanded = 0,
				kTwoHanded = 1,
				kMarksman = 2,
				kBlock = 3,
				kSmithing = 4,
				kHeavyArmor = 5,
				kLightArmor = 6,
				kPickpocket = 7,
				kLockpicking = 8,
				kSneak = 9,
				kAlchemy = 10,
				kSpecchcraft = 11,
				kAlteration = 12,
				kConjuration = 13,
				kDestruction = 14,
				kIllusion = 15,
				kRestoration = 16,
				kEnchanting = 17,

				kTotal
			};


			UInt8	values[kTotal];			// 00
			UInt8	offsets[kTotal];		// 12
			UInt16	health;					// 24
			UInt16	magicka;				// 26
			UInt16	stamina;				// 28
			UInt16	pad2A;					// 2A
			float	farawayModelDistance;	// 2C
		};
		STATIC_ASSERT(sizeof(Skills) == 0x30);


		struct HeadData
		{
			BGSColorForm*	hairColor;		// 00 - HCLF
			BGSTextureSet*	headTexture;	// 08 - FTST
		};
		STATIC_ASSERT(sizeof(HeadData) == 0x10);


		struct FaceData
		{
			struct Morphs
			{
				enum
				{
					kNose_LongShort = 0,
					kNose_UpDown = 1,
					kJaw_UpDown = 2,
					kJaw_NarrowWide = 3,
					kJaw_ForwardBack = 4,
					kCheeks_UpDown = 5,
					kCheeks_ForwardBack = 6,
					kEyes_UpDown = 7,
					kEyes_InOut = 8,
					kBrows_UpDown = 9,
					kBrows_InOut = 10,
					kBrows_ForwardBack = 11,
					kLips_UpDown = 12,
					kLips_InOut = 13,
					kChin_NarrowWide = 14,
					kChin_UpDown = 15,
					kChin_UnderbiteOverbite = 16,
					kEyes_ForwardBack = 17,
					kUnk = 18,

					kTotal = 19
				};
			};


			struct Parts
			{
				enum
				{
					kNose = 0,
					kUnknown = 1,
					kEyes = 2,
					kMouth = 3,

					kTotal = 4
				};
			};


			enum
			{
				kDefault = 0x7F7FFFFF,
				kTotalPresets = 4
			};


			float	morphs[Morphs::kTotal];	// 00 - NAM9
			SInt32	parts[Parts::kTotal];	// 4C - NAMA
		};
		STATIC_ASSERT(sizeof(FaceData) == 0x5C);


		struct Layer
		{
			float GetInterpolationValue() const;


			Color	tintColor;			// 00 - TINC
			UInt16	tintIndex;			// 04 - TINI
			UInt16	preset;				// 06 - TIAS
			UInt16	interpolationValue;	// 08 - TINV - CK value * 100 as an int
			UInt16	pad0A;				// 0A
			UInt32	pad0C;				// 0C
		};
		STATIC_ASSERT(sizeof(Layer) == 0x10);


		virtual ~TESNPC();																																					// 00

		// override (TESActorBase)
		virtual void			InitDefaults() override;																													// 04
		virtual void			ReleaseManagedData() override;																												// 05
		virtual bool			LoadForm(TESFile* a_mod) override;																											// 06
		virtual void			Unk_0C(void)  override;																														// 0C
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf) override;																								// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf) override;																								// 0F
		virtual void			Unk_12(void) override;																														// 12
		virtual void			InitItem() override;																														// 13
		virtual const char*		GetAliasName(const BSFixedString& a_alias) override;																						// 2E
		virtual void			CopyFrom(TESForm* a_srcForm) override;																										// 2F
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void			Unk_41(void) override;																														// 41
		virtual void			SetVoiceType(BGSVoiceType* a_voiceType) override;																							// 48 - { TESActorBaseData::voice = a_voiceType; }
		virtual BGSVoiceType*	GetVoiceType() const override;																												// 49
		virtual void			Unk_4A(void) override;																														// 4A
		virtual bool			GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C
		virtual void			Unk_4D(void) override;																														// 4D
		virtual TESCombatStyle*	GetCombatStyle() override;																													// 54 - { return combatStyle; }
		virtual void			SetCombatStyle(TESCombatStyle* a_combatStyle) override;																						// 55 - { combatStyle = a_combatStyle; }

		Sex				GetSex();
		bool			HasOverlays();
		void			ChangeHeadPart(BGSHeadPart* a_target);
		void			UpdateNeck(BSFaceGenNiNode* a_faceNode);
		void			SetSkinFromTint(NiColorA* a_result, TintMask* a_tintMask, UInt32 a_compute);
		void			SetFaceTexture(BGSTextureSet* a_textureSet);
		void			SetHairColor(BGSColorForm* a_hairColor);
		BGSHeadPart*	GetHeadPartByType(UInt32 a_type);
		BGSHeadPart*	GetHeadPartOverlayByType(UInt32 a_type);
		BGSHeadPart*	GetCurrentHeadPartByType(UInt32 a_type);
		TESNPC*			GetRootTemplate();
		TESRace*		GetRace();


		// members
		Skills						playerSkills;		// 190 - DNAM
		TESClass*					npcClass;			// 1C0 - CNAM
		HeadData*					headData;			// 1C8
		BGSListForm*				giftFilter;			// 1D0 - GNAM
		TESCombatStyle*				combatStyle;		// 1D8 - ZNAM
		Color						unk1E0;				// 1E0
		UInt32						pad1E4;				// 1E4
		TESRace*					overlayRace;		// 1E8
		TESNPC*						nextTemplate;		// 1F0
		float						height;				// 1F8 - NAM6
		float						weight;				// 1FC - NAM7
		TESNPC*						inheritsSoundsFrom;	// 200 - CSCR
		BSFixedString				shortName;			// 208 - SHRT
		TESObjectARMO*				farAwayModel;		// 210 - ANAM
		BGSOutfit*					defaultOutfit;		// 218 - DOFT
		BGSOutfit*					sleepingOutfit;		// 220 - SOFT
		BGSListForm*				defaultPackageList;	// 228 - DPLT
		TESFaction*					crimeFaction;		// 230 - CRIF
		BGSHeadPart**				headparts;			// 238 - PNAM
		UInt8						numHeadParts;		// 240
		UInt8						unk241;				// 241
		UInt8						unk242;				// 242
		UInt8						unk243;				// 243
		UInt8						unk244;				// 244
		SoundLevel8					soundLevel;			// 245 - NAM8
		Color						textureLighting;	// 246 - QNAM
		UInt16						pad24A;				// 24A
		UInt32						pad24C;				// 24C
		BSTArray<BGSRelationship*>*	relationships;		// 250
		FaceData*					faceData;			// 258
		BSTArray<Layer*>*			tintLayers;			// 260
	};
	STATIC_ASSERT(sizeof(TESNPC) == 0x268);
}
