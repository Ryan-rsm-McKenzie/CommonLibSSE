#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMusicSingleTrack

#include "RE/BGSMusicTrack.h"  // BGSMusicTrack
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FileHash.h"  // FileHash
#include "RE/SoundData.h"  // SoundData


namespace RE
{
	class BGSMusicSingleTrack : public BGSMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicSingleTrack;


		struct LoopData	// LNAM
		{
			float	loopBegin;	// 0
			float	loopEnd;	// 4
			UInt32	loopCount;	// 8
		};
		STATIC_ASSERT(sizeof(LoopData) == 0xC);


		virtual ~BGSMusicSingleTrack();							// 00

		// override (BGSMusicTrack)
		virtual void		Unk_01(void) override;				// 01
		virtual UInt32		Play() override;					// 02
		virtual void		Unk_03(void) override;				// 03
		virtual void		Unk_04(void) override;				// 04
		virtual float		GetDuration() const override;		// 05
		virtual TrackType	GetTrackType() const override;		// 06 - "BGSMusicSingleTrack"
		virtual void		Unk_08(void) override;				// 08
		virtual void		Unk_09(void) override;				// 09
		virtual bool		LoadTrack(TESFile* a_mod) override;	// 0C


		// members
		FileHash		track;		// 20 - ANAM
		FileHash		finale;		// 2C - BNAM
		BSTArray<float>	cuePoints;	// 38 - FNAM
		UInt32			unk50;		// 50
		UInt32			unk54;		// 54
		UInt64			unk58;		// 58
		LoopData*		loopData;	// 60 - LNAM
		SoundData		soundData;	// 68
		UInt64			unk78;		// 78
	};
	STATIC_ASSERT(sizeof(BGSMusicSingleTrack) == 0x80);
}
