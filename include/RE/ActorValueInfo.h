#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ActorValueInfo

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESDescription.h"  // TESDescription
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon


namespace RE
{
	class BGSSkillPerkTreeNode;


	class ActorValueInfo :
		public TESForm,			// 000
		public TESFullName,		// 020
		public TESDescription,	// 030
		public TESIcon			// 040
	{
	public:
		inline static const void* RTTI = RTTI_ActorValueInfo;


		enum { kTypeID = FormType::ActorValueInfo };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Skill	// AVSK
		{
			float	useMult;		// 00
			float	offsetMult;		// 04
			float	improveMult;	// 08
			float	improveOffset;	// 0C
		};
		STATIC_ASSERT(sizeof(Skill) == 0x10);


		virtual ~ActorValueInfo();							// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		const char*				unk050;			// 050
		BSFixedString			abbreviation;	// 058 - ANAM
		UInt32					unk060;			// 060
		UInt32					unk064;			// 064
		UInt64					unk068;			// 068
		UInt32					unk070;			// 070
		UInt32					unk074;			// 074
		UInt32					unk078;			// 078
		UInt32					unk07C;			// 07C
		UInt32					unk080;			// 080
		UInt32					unk084;			// 084
		UInt32					unk088;			// 088
		UInt32					unk08C;			// 08C
		UInt32					unk090;			// 090
		UInt32					unk094;			// 094
		UInt32					unk098;			// 098
		UInt32					unk09C;			// 09C
		UInt32					unk0A0;			// 0A0
		UInt32					unk0A4;			// 0A4
		UInt32					unk0A8;			// 0A8
		UInt32					unk0AC;			// 0AC
		UInt64					unk0B0;			// 0B0
		UInt64					unk0B8;			// 0B8
		UInt64					unk0C0;			// 0C0
		UInt64					unk0C8;			// 0C8
		UInt64					unk0D0;			// 0D0
		UInt64					unk0D8;			// 0D8
		UInt64					unk0E0;			// 0E0
		UInt64					unk0E8;			// 0E8
		UInt64					unk0F0;			// 0F0
		UInt64					unk0F8;			// 0F8
		UInt64					unk100;			// 100
		Skill*					skill;			// 108 - AVSK
		UInt32					unk110;			// 110
		UInt32					unk114;			// 114
		BGSSkillPerkTreeNode*	perkTree;		// 118
		UInt32					unk120;			// 120
		UInt32					unk124;			// 124 - CNAM
	};
	STATIC_ASSERT(sizeof(ActorValueInfo) == 0x128);
}
