#pragma once

#include "RE/BGSMusicTrack.h"
#include "RE/BSTArray.h"


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
		SInt32					 playingIndexes[3];	 // 68
		float					 duration;			 // 74 - FLTV
		float					 fadeOutTime;		 // 78 - DNAM
		UInt32					 pad7C;				 // 7C
		UInt64					 playTime;			 // 80
		UInt64					 pauseTime;			 // 88
	};
	STATIC_ASSERT(sizeof(BGSMusicPaletteTrack) == 0x90);
}
