#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESLevSpell

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESLeveledList.h"  // TESLeveledList


namespace RE
{
	class TESLevSpell :
		public TESBoundObject,	// 00
		public TESLeveledList	// 30
	{
	public:
		inline static const void* RTTI = RTTI_TESLevSpell;


		enum { kTypeID = FormType::LeveledSpell };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLevSpell();											// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13
	};
	STATIC_ASSERT(sizeof(TESLevSpell) == 0x58);
}
