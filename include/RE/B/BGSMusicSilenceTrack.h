#pragma once

#include "RE/B/BGSMusicTrack.h"

namespace RE
{
	class BGSMusicSilenceTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicSilenceTrack;

		~BGSMusicSilenceTrack() override;  // 00

		// override (BGSMusicTrack)
		void      DoUpdate(void) override;                       // 01
		void      DoPlay() override;                             // 02
		void      DoPause() override;                            // 03
		void      DoFinish(bool a_arg1, float a_arg2) override;  // 04
		float     GetDurationImpl() const override;              // 05 - { return duration; }
		TrackType GetType() const override;                      // 06 - "BGSMusicSilenceTrack"
		void      Load(TESFile* a_mod) override;                 // 0C

		// members
		float         duration;   // 20 - FLTV
		std::uint32_t pad24;      // 24
		std::uint64_t playTime;   // 28
		std::uint64_t pauseTime;  // 30
	};
	static_assert(sizeof(BGSMusicSilenceTrack) == 0x38);
}
