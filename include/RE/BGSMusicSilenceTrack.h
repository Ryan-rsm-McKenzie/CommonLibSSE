#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicSilenceTrack

#include "RE/BGSMusicTrack.h"  // BGSMusicTrack


namespace RE
{
	class BGSMusicSilenceTrack : public BGSMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicSilenceTrack;


		virtual ~BGSMusicSilenceTrack();						// 00

		// override (BGSMusicTrack)
		virtual void		Unk_01(void) override;				// 01
		virtual UInt32		Play() override;					// 02
		virtual void		Unk_03(void) override;				// 03
		virtual void		Unk_04(void) override;				// 04
		virtual float		GetDuration() const override;		// 05 - { return duration; }
		virtual TrackType	GetTrackType() const override;		// 06 - "BGSMusicSilenceTrack"
		virtual bool		LoadTrack(TESFile* a_mod) override;	// 0C


		// members
		float	duration;	// 20 - FLTV
		UInt32	unk24;		// 24
		UInt64	unk28;		// 28
		UInt64	unk30;		// 30
	};
	STATIC_ASSERT(sizeof(BGSMusicSilenceTrack) == 0x38);
}
