#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicPaletteTrack

#include "RE/BGSMusicTrack.h"  // BGSMusicTrack
#include "RE/BSTArray.h"  // BSTArray


namespace RE
{
	class BGSMusicPaletteTrack : public BGSMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicPaletteTrack;


		struct Tracks	// SNAM
		{
			BSTArray<BSIMusicTrack*>	first;	// 00
			BSTArray<BSIMusicTrack*>	second;	// 18
			BSTArray<BSIMusicTrack*>	third;	// 30
		};
		STATIC_ASSERT(sizeof(Tracks) == 0x48);


		virtual ~BGSMusicPaletteTrack();						// 00

		// override (BGSMusicTrack)
		virtual void		Unk_01(void) override;				// 01
		virtual UInt32		Play() override;					// 02
		virtual void		Unk_03(void) override;				// 03
		virtual void		Unk_04(void) override;				// 04
		virtual float		GetDuration() const override;		// 05 - { return duration; }
		virtual TrackType	GetTrackType() const override;		// 06 - "BGSMusicPaletteTrack"
		virtual bool		InitTrack(TESFile* a_mod) override;	// 0B
		virtual bool		LoadTrack(TESFile* a_mod) override;	// 0C


		// members
		Tracks	tracks;		// 20 - SNAM - tracks are split based on null entries on the record
		UInt32	unk68;		// 68
		UInt32	unk6C;		// 6C
		UInt32	unk70;		// 70
		float	duration;	// 74 - FLTV
		float	fadeOut;	// 78 - DNAM
		UInt32	unk7C;		// 7C
		UInt64	unk80;		// 80
		UInt64	unk88;		// 88
	};
	STATIC_ASSERT(sizeof(BGSMusicPaletteTrack) == 0x90);
}
