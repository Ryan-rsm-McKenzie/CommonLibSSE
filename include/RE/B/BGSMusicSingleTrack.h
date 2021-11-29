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

		struct LoopData  // LNAM
		{
			float         loopBegin;  // 0
			float         loopEnd;    // 4
			std::uint32_t loopCount;  // 8
		};
		static_assert(sizeof(LoopData) == 0xC);

		~BGSMusicSingleTrack() override;  // 00

		// override (BGSMusicTrack)
		void      DoUpdate() override;                                    // 01
		void      DoPlay() override;                                      // 02
		void      DoPause() override;                                     // 03
		void      DoFinish(bool a_arg1, float a_arg2) override;           // 04
		float     GetDurationImpl() const override;                       // 05
		TrackType GetType() const override;                               // 06 - "BGSMusicSingleTrack"
		void      DoSetDuckingAttenuation(std::uint16_t a_val) override;  // 09
		void      DoClearDucking() override;                              // 0A
		void      Load(TESFile* a_mod) override;                          // 0C

		// members
		BSResource::ID  trackID;                    // 20 - ANAM
		BSResource::ID  finaleID;                   // 2C - BNAM
		BSTArray<float> cuePoints;                  // 38 - FNAM
		std::uint32_t   nextCuePoint;               // 50
		std::uint32_t   loopsRemaining;             // 54
		std::uint32_t   lastKnownPlaybackPosition;  // 58
		std::uint32_t   pad5C;                      // 5C
		LoopData*       loopData;                   // 60 - LNAM
		BSSoundHandle   trackHandle;                // 68
		BSSoundHandle   finaleHandle;               // 78
	};
	static_assert(sizeof(BGSMusicSingleTrack) == 0x80);
}
