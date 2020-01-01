#pragma once

#include "RE/BSIMusicTrack.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSMusicTrack;


	class BGSMusicTrackFormWrapper :
		public TESForm,			// 00
		public BSIMusicTrack	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicTrackFormWrapper;


		enum { kTypeID = FormType::MusicTrack };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMusicTrackFormWrapper();			// 00

		// override (TESForm)
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		BGSMusicTrack* track;	// 30
	};
	STATIC_ASSERT(sizeof(BGSMusicTrackFormWrapper) == 0x38);
}
