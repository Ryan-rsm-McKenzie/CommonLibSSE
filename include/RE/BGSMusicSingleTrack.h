#pragma once

#include "RE/BGSMusicTrack.h"
#include "RE/BSResource/ID.h"
#include "RE/BSSoundHandle.h"
#include "RE/BSTArray.h"


namespace RE
{
	class BGSMusicSingleTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicSingleTrack;


		struct LoopData	 // LNAM
		{
			float  loopBegin;  // 0
			float  loopEnd;	   // 4
			UInt32 loopCount;  // 8
		};
		STATIC_ASSERT(sizeof(LoopData) == 0xC);


		virtual ~BGSMusicSingleTrack();	 // 00

		// override (BGSMusicTrack)
		virtual void	  DoUpdate() override;							   // 01
		virtual void	  DoPlay() override;							   // 02
		virtual void	  DoPause() override;							   // 03
		virtual void	  DoFinish(bool a_arg1, float a_arg2) override;	   // 04
		virtual float	  GetDurationImpl() const override;				   // 05
		virtual TrackType GetType() const override;						   // 06 - "BGSMusicSingleTrack"
		virtual void	  DoSetDuckingAttenuation(UInt16 a_val) override;  // 09
		virtual void	  DoClearDucking() override;					   // 0A
		virtual void	  Load(TESFile* a_mod) override;				   // 0C


		// members
		BSResource::ID	trackID;					// 20 - ANAM
		BSResource::ID	finaleID;					// 2C - BNAM
		BSTArray<float> cuePoints;					// 38 - FNAM
		UInt32			nextCuePoint;				// 50
		UInt32			loopsRemaining;				// 54
		UInt32			lastKnownPlaybackPosition;	// 58
		UInt32			pad5C;						// 5C
		LoopData*		loopData;					// 60 - LNAM
		BSSoundHandle	trackHandle;				// 68
		BSSoundHandle	finaleHandle;				// 78
	};
	STATIC_ASSERT(sizeof(BGSMusicSingleTrack) == 0x80);
}
