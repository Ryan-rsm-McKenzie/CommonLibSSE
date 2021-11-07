#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModelTextureSwap.h"
#include "RE/T/TESModelTri.h"

namespace RE
{
	class BGSHeadPart :
		public TESForm,             // 000
		public TESFullName,         // 020
		public TESModelTextureSwap  // 030
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSHeadPart;
		inline static constexpr auto VTABLE = VTABLE_BGSHeadPart;
		inline static constexpr auto FORMTYPE = FormType::HeadPart;

		enum class Flag  // DATA
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kMale = 1 << 1,
			kFemale = 1 << 2,
			kIsExtraPart = 1 << 3,
			kUseSolidTint = 1 << 4
		};

		enum class HeadPartType  // PNAM
		{
			kMisc = 0x0,
			kFace = 0x1,
			kEyes = 0x2,
			kHair = 0x3,
			kFacialHair = 0x4,
			kScar = 0x5,
			kEyebrows = 0x6,

			kTotal
		};

		struct MorphIndices
		{
			enum MorphIndex : std::uint32_t
			{
				kRaceMorph = 0,
				kDefaultMorph,
				kChargenMorph,

				kTotal
			};
		};
		using MorphIndex = MorphIndices::MorphIndex;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		~BGSHeadPart() override;  // 00

		// override (TESForm)
		void        InitializeData() override;                    // 04
		void        ClearData() override;                         // 05
		bool        Load(TESFile* a_mod) override;                // 06
		void        InitItemImpl() override;                      // 13
		const char* GetFormEditorID() const override;             // 32 - { return formEditorID.c_str(); }
		bool        SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; return true; }

		bool IsExtraPart();

		// members
		stl::enumeration<Flag, std::uint8_t>          flags;                         // 068 - DATA
		std::uint8_t                                  pad069;                        // 069
		std::uint16_t                                 pad06A;                        // 06A
		stl::enumeration<HeadPartType, std::uint32_t> type;                          // 06C - PNAM
		BSTArray<BGSHeadPart*>                        extraParts;                    // 070
		BGSTextureSet*                                textureSet;                    // 088 - TNAM
		TESModelTri                                   morphs[MorphIndices::kTotal];  // 090
		BGSColorForm*                                 color;                         // 108 - CNAM
		BGSListForm*                                  validRaces;                    // 110 - RNAM
		BSFixedString                                 formEditorID;                  // 118 - EDID
	};
	static_assert(sizeof(BGSHeadPart) == 0x120);
}
