#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSHeadPart

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // BGSTextureSet, BGSListForm
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESModelTri.h"  // TESModelTri


namespace RE
{
	class BGSHeadPart :
		public TESForm,				// 000
		public TESFullName,			// 020
		public TESModelTextureSwap	// 030
	{
	public:
		inline static const void* RTTI = RTTI_BGSHeadPart;


		enum { kTypeID = FormType::HeadPart };


		enum class Flag : UInt8	// DATA
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kMale = 1 << 1,
			kFemale = 1 << 2,
			kIsExtraPart = 1 << 3,
			kUseSolidTint = 1 << 4
		};


		enum class Type : UInt32	// PNAM
		{
			kMisc = 0,
			kFace = 1,
			kEyes = 2,
			kHair = 3,
			kFacialHair = 4,
			kScar = 5,
			kEyebrows = 6
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Parts
		{
			enum
			{
				kRaceMorph,
				kTri,
				kChargenMorph,
				kTotal
			};
		};


		virtual ~BGSHeadPart();											// 00

		// override (TESForm)
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual void		InitItem() override;						// 13
		virtual const char*	GetEditorID() override;						// 32 - { return editorID.c_str() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;	// 33 - { editorID = a_str; return true; }

		bool				IsExtraPart();


		// members
		Flag					flags;					// 068 - DATA
		UInt8					pad069;					// 069
		UInt16					pad06A;					// 06A
		Type					type;					// 06C - PNAM
		BSTArray<BGSHeadPart*>	extraParts;				// 070
		BGSTextureSet*			textureSet;				// 088 - TNAM
		TESModelTri				parts[Parts::kTotal];	// 090
		BGSColorForm*			color;					// 108 - CNAM
		BGSListForm*			validRaces;				// 110 - RNAM
		BSFixedString			editorID;				// 118 - EDID
	};
	STATIC_ASSERT(sizeof(BGSHeadPart) == 0x120);
}
