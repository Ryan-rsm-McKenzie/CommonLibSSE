#pragma once

#include "RE/FormTypes.h"
#include "RE/TESObjectACTI.h"


namespace RE
{
	class BGSTalkingActivator : public TESObjectACTI
	{
	public:
		inline static const void* RTTI = RTTI_BGSTalkingActivator;


		enum { kTypeID = FormType::TalkingActivator };


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kSpeaker = 1 << 23
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kHiddenFromLocalMap = 1 << 9,
				kIgnored = 1 << 12,
				kRandomAnimStart = 1 << 16,
				kRadioStation = 1 << 17
			};
		};


		virtual ~BGSTalkingActivator();																																// 00

		// override (TESObjectACTI)
		virtual void			InitializeData() override;																											// 04
		virtual bool			Load(TESFile* a_mod) override;																										// 06
		virtual void			SaveGame(BGSSaveFormBuffer* a_buf) override;																						// 0E
		virtual void			LoadGame(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void			Revert(void* a_arg1) override;																										// 12
		virtual void			InitItemImpl() override;																											// 13
		virtual bool			GetDangerous() const override;																										// 1B - { return 0; }
		virtual bool			Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void			SetVoiceType(BGSVoiceType* a_voiceType);																							// 48 - { voiceType = a_voiceType; }
		virtual BGSVoiceType*	GetVoiceType() const override;																										// 49 - { return unkD0; }

		// add
		virtual void			Unk_53(void);																														// 53 - { return 0; }


		// members
		UInt64			unkC8;		// C8
		BGSVoiceType*	voiceType;	// D0 - VNAM
	};
	STATIC_ASSERT(sizeof(BGSTalkingActivator) == 0xD8);
}
