#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundAnimObject.h"  // TESBoundAnimObject
#include "RE/TESLeveledList.h"  // TESLeveledList
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap


namespace RE
{
	class TESLevCharacter :
		public TESBoundAnimObject,	// 00
		public TESLeveledList,		// 30
		public TESModelTextureSwap	// 58
	{
	public:
		enum { kTypeID = FormType::LeveledCharacter };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLevCharacter();										// 00

		// override (TESBoundAnimObject)
		virtual bool	LoadForm(TESFile* a_mod) override;				// 06
		virtual void	SaveBuffer(BGSSaveFormBuffer* a_buf) override;	// 0E
		virtual void	LoadBuffer(BGSLoadFormBuffer* a_buf) override;	// 0F
		virtual void	Unk_12(void) override;							// 12
		virtual void	InitItem() override;							// 13
		virtual void	Unk_41(void) override;							// 4A - { return; }
		virtual void	Unk_4A(void) override;							// 4A - { return 0; }
	};
	STATIC_ASSERT(sizeof(TESLevCharacter) == 0x90);
}
