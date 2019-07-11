#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSAcousticSpace

#include "RE/FormTypes.h"  // BGSSoundDescriptorForm, TESRegion, BGSReverbParameters
#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class BGSAcousticSpace : public TESBoundObject
	{
	public:
		inline static const void* RTTI = RTTI_BGSAcousticSpace;


		enum { kTypeID = FormType::AcousticSpace };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSAcousticSpace();						// 00

		// override (TESBoundObject)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13
		virtual void	Unk_41(void) override;				// 41
		virtual void	Unk_4A(void) override;				// 4A - { return 0; }


		// members
		BGSSoundDescriptorForm*	ambientSound;		// 30 - SNAM
		TESRegion*				useSoundFromRegion;	// 38 - RDAT - interiors only
		BGSReverbParameters*	environmentType;	// 40 - BNAM
	};
	STATIC_ASSERT(sizeof(BGSAcousticSpace) == 0x48);
}
