#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObjectMISC

#include "RE/BGSDestructibleObjectForm.h"  // BGSDestructibleObjectForm
#include "RE/BGSKeywordForm.h"  // BGSKeywordForm
#include "RE/BGSMessageIcon.h"  // BGSMessageIcon
#include "RE/BGSPickupPutdownSounds.h"  // BGSPickupPutdownSounds
#include "RE/FormTypes.h"  // FormType
#include "RE/TESBoundObject.h"  // TESBoundObject
#include "RE/TESFullName.h"  // TESFullName
#include "RE/TESIcon.h"  // TESIcon
#include "RE/TESModelTextureSwap.h"  // TESModelTextureSwap
#include "RE/TESValueForm.h"  // TESValueForm
#include "RE/TESWeightForm.h"  // TESWeightForm


namespace RE
{
	class TESObjectMISC :
		public TESBoundObject,				// 000
		public TESFullName,					// 030
		public TESModelTextureSwap,			// 040
		public TESIcon,						// 078
		public TESValueForm,				// 088
		public TESWeightForm,				// 098
		public BGSDestructibleObjectForm,	// 0A8
		public BGSMessageIcon,				// 0B8
		public BGSPickupPutdownSounds,		// 0D0
		public BGSKeywordForm				// 0E8
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectMISC;


		enum { kTypeID = FormType::Misc };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESObjectMISC();													// 00

		// override (TESBoundObject)
		virtual bool		LoadForm(TESFile* a_mod) override;						// 06
		virtual void		SaveBuffer(BGSSaveFormBuffer* a_buf) override;			// 0E
		virtual void		LoadBuffer(BGSLoadFormBuffer* a_buf) override;			// 0F
		virtual void		InitItem() override;									// 13

		// override (BGSKeywordForm)
		virtual BGSKeyword*	GetDefaultKeyword() override;							// 05 - { return BGSDefaultObjectManager::GetSingleton()->objects[193]; } - this index is a nullptr

		// add
		virtual void		Unk_53(void);											// 53 - { return; }
		virtual void		LoadRecordByType(TESFile* a_mod, UInt32 a_recordType);	// 54 - { return; }
		virtual void		Unk_55(void);											// 55 - { return; }
	};
	STATIC_ASSERT(sizeof(TESObjectMISC) == 0x100);
}
