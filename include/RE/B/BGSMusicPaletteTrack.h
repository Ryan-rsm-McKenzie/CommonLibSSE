#pragma once

#include "RE/B/BGSMusicTrack.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSMusicPaletteTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicPaletteTrack;

		~BGSMusicPaletteTrack() override;  // 00

		// override (BGSMusicTrack)
		void      DoUpdate() override;                           // 01
		void      DoPlay() override;                             // 02
		void      DoPause() override;                            // 03
		void      DoFinish(bool a_arg1, float a_arg2) override;  // 04
		float     GetDurationImpl() const override;              // 05 - { return duration; }
		TrackType GetType() const override;                      // 06 - "BGSMusicPaletteTrack"
		void      InitItem(TESForm* a_form) override;            // 0B
		void      Load(TESFile* a_mod) override;                 // 0C

		// members
		BSTArray<BSIMusicTrack*> layers[3];          // 20 - SNAM - tracks are split based on null entries on the record
		std::int32_t             playingIndexes[3];  // 68
		float                    duration;           // 74 - FLTV
		float                    fadeOutTime;        // 78 - DNAM
		std::uint32_t            pad7C;              // 7C
		std::uint64_t            playTime;           // 80
		std::uint64_t            pauseTime;          // 88
	};
	static_assert(sizeof(BGSMusicPaletteTrack) == 0x90);
}
