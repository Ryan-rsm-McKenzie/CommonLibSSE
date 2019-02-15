#pragma once

#include "RE/FormTypes.h"  // FormType, BGSVoiceType
#include "RE/TESObjectACTI.h"  // TESObjectACTI


namespace RE
{
	class BGSTalkingActivator : public TESObjectACTI
	{
	public:
		enum { kTypeID = FormType::TalkingActivator };


		struct LocalFlags
		{
			enum LocalFlag : UInt32
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
		virtual void			InitDefaults() override;																											// 04
		virtual bool			LoadForm(TESFile* a_mod) override;																									// 06
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf) override;																						// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf) override;																						// 0F
		virtual void			InitItem() override;																												// 13
		virtual bool			GetFlag00020000() override;																											// 1B - { return 0; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37
		virtual void			SetVoiceType(BGSVoiceType* a_voiceType);																							// 48 - { voiceType = a_voiceType; }
		virtual BGSVoiceType*	GetVoiceType() const override;																										// 49 - { return unkD0; }

		// add
		virtual void			Unk_53(void);																														// 53 - { return 0; }


		// members
		UInt64			unkC8;		// C8
		BGSVoiceType*	voiceType;	// D0 - VNAM
	};
	STATIC_ASSERT(sizeof(BGSTalkingActivator) == 0xD8);
	// virtual UInt64	Unk_12(UInt64 a_arg1) override; - { if (((a_arg1 + 0x44) >> 23) & 1) unkC8 = 0; }
}
