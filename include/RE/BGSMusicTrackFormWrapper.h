#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicTrackFormWrapper

#include "RE/BSIMusicTrack.h"  // BSIMusicTrack
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


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


		virtual ~BGSMusicTrackFormWrapper();				// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BGSMusicTrack* musicTrack;	// 30
	};
	STATIC_ASSERT(sizeof(BGSMusicTrackFormWrapper) == 0x38);
}
