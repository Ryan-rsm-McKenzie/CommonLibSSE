#pragma once

#include "RE/B/BGSMusicTrack.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/I/ID.h"

namespace RE
{
	class BGSMusicSingleTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicSingleTrack;

		struct LoopData	 // LNAM
		{
			float		  loopBegin;  // 0
			float		  loopEnd;	  // 4
			std::uint32_t loopCount;  // 8
		};
		static_assert(sizeof(LoopData) == 0xC);

		virtual ~BGSMusicSingleTrack();	 // 00

		// override (BGSMusicTrack)
		virtual void	  DoUpdate() override;									  // 01
		virtual void	  DoPlay() override;									  // 02
		virtual void	  DoPause() override;									  // 03
		virtual void	  DoFinish(bool a_arg1, float a_arg2) override;			  // 04
		virtual float	  GetDurationImpl() const override;						  // 05
		virtual TrackType GetType() const override;								  // 06 - "BGSMusicSingleTrack"
		virtual void	  DoSetDuckingAttenuation(std::uint16_t a_val) override;  // 09
		virtual void	  DoClearDucking() override;							  // 0A
		virtual void	  Load(TESFile* a_mod) override;						  // 0C

		// members
		BSResource::ID	trackID;					// 20 - ANAM
		BSResource::ID	finaleID;					// 2C - BNAM
		BSTArray<float> cuePoints;					// 38 - FNAM
		std::uint32_t	nextCuePoint;				// 50
		std::uint32_t	loopsRemaining;				// 54
		std::uint32_t	lastKnownPlaybackPosition;	// 58
		std::uint32_t	pad5C;						// 5C
		LoopData*		loopData;					// 60 - LNAM
		BSSoundHandle	trackHandle;				// 68
		BSSoundHandle	finaleHandle;				// 78
	};
	static_assert(sizeof(BGSMusicSingleTrack) == 0x80);
}
