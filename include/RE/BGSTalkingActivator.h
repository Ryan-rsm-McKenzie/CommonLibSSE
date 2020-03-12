#pragma once

#include "RE/FormTypes.h"
#include "RE/TESObjectACTI.h"


namespace RE
{
	class BGSTalkingActivator : public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSTalkingActivator;
		inline static constexpr auto FORMTYPE = FormType::TalkingActivator;


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


		virtual ~BGSTalkingActivator();	 // 00

		// override (TESObjectACTI)
		virtual void		  InitializeData() override;																												 // 04
		virtual bool		  Load(TESFile* a_mod) override;																											 // 06
		virtual void		  SaveGame(BGSSaveFormBuffer* a_buf) override;																								 // 0E
		virtual void		  LoadGame(BGSLoadFormBuffer* a_buf) override;																								 // 0F
		virtual void		  Revert(BGSLoadFormBuffer* a_buf) override;																								 // 12
		virtual void		  InitItemImpl() override;																													 // 13
		virtual bool		  GetDangerous() const override;																											 // 1B - { return 0; }
		virtual bool		  Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, TESBoundObject* a_arg4, SInt32 a_targetCount) override;	 // 37
		virtual void		  SetObjectVoiceType(BGSVoiceType* a_voiceType) override;																					 // 48 - { voiceType = a_voiceType; }
		virtual BGSVoiceType* GetObjectVoiceType() const override;																										 // 49 - { return voiceType; }

		// add
		virtual bool GetReflectedByAutoWater();	 // 53 - { return false; }


		// members
		TESObjectREFR* tempRef;	   // C8
		BGSVoiceType*  voiceType;  // D0 - VNAM
	};
	STATIC_ASSERT(sizeof(BGSTalkingActivator) == 0xD8);
}
