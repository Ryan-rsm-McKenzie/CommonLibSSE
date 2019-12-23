#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"


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


		virtual ~BGSAcousticSpace();					// 00

		// override (TESBoundObject)
		virtual void	InitializeData() override;		// 04
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13
		virtual void	Unk_41(void) override;			// 41
		virtual void	Unk_4A(void) override;			// 4A - { return 0; }


		// members
		BGSSoundDescriptorForm*	ambientSound;		// 30 - SNAM
		TESRegion*				useSoundFromRegion;	// 38 - RDAT - interiors only
		BGSReverbParameters*	environmentType;	// 40 - BNAM
	};
	STATIC_ASSERT(sizeof(BGSAcousticSpace) == 0x48);
}
