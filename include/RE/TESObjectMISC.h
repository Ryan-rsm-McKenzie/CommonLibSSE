#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSKeywordForm.h"
#include "RE/BGSMessageIcon.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	class TESObjectMISC :
		public TESBoundObject,			   // 000
		public TESFullName,				   // 030
		public TESModelTextureSwap,		   // 040
		public TESIcon,					   // 078
		public TESValueForm,			   // 088
		public TESWeightForm,			   // 098
		public BGSDestructibleObjectForm,  // 0A8
		public BGSMessageIcon,			   // 0B8
		public BGSPickupPutdownSounds,	   // 0D0
		public BGSKeywordForm			   // 0E8
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObjectMISC;
		inline static constexpr auto FORMTYPE = FormType::Misc;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESObjectMISC();  // 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;				   // 06
		virtual void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void InitItemImpl() override;					   // 13

		// override (BGSKeywordForm)
		virtual BGSKeyword* GetDefaultKeyword() const override;	 // 05

		// add
		virtual void SaveImpl();								  // 53 - { return; }
		virtual void LoadImpl(TESFile* a_mod, UInt32 a_chunkID);  // 54 - { return; }
		virtual void InitImpl();								  // 55 - { return; }
	};
	STATIC_ASSERT(sizeof(TESObjectMISC) == 0x100);
}
