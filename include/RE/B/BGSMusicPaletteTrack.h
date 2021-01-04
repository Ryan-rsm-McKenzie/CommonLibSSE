#pragma once

#include "RE/B/BGSMusicTrack.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSMusicPaletteTrack : public BGSMusicTrack
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMusicPaletteTrack;

		virtual ~BGSMusicPaletteTrack();  // 00

		// override (BGSMusicTrack)
		virtual void	  DoUpdate() override;							 // 01
		virtual void	  DoPlay() override;							 // 02
		virtual void	  DoPause() override;							 // 03
		virtual void	  DoFinish(bool a_arg1, float a_arg2) override;	 // 04
		virtual float	  GetDurationImpl() const override;				 // 05 - { return duration; }
		virtual TrackType GetType() const override;						 // 06 - "BGSMusicPaletteTrack"
		virtual void	  InitItem(TESForm* a_form) override;			 // 0B
		virtual void	  Load(TESFile* a_mod) override;				 // 0C

		// members
		BSTArray<BSIMusicTrack*> layers[3];			 // 20 - SNAM - tracks are split based on null entries on the record
		std::int32_t			 playingIndexes[3];	 // 68
		float					 duration;			 // 74 - FLTV
		float					 fadeOutTime;		 // 78 - DNAM
		std::uint32_t			 pad7C;				 // 7C
		std::uint64_t			 playTime;			 // 80
		std::uint64_t			 pauseTime;			 // 88
	};
	static_assert(sizeof(BGSMusicPaletteTrack) == 0x90);
}
