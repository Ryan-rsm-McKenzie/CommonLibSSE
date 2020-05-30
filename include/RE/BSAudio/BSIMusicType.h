#pragma once

#include "RE/BSTArray.h"
#include "RE/FormTypes.h"


namespace RE
{
	class BSIMusicTrack;


	class BSIMusicType
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIMusicType;


		enum class Flag : UInt32  // FNAM
		{
			kNone = 0,
			kPlaysOneSelection = 1 << 0,
			kAbruptTransition = 1 << 1,
			kCycleTracks = 1 << 2,
			kMaintainTrackOrder = 1 << 3,
			kDucksCurrentTrack = 1 << 5,
			kDoesntQueue = 1 << 6
		};


		enum class MUSIC_STATUS : UInt32
		{
			kInactive = 0,
			kPlaying = 1,
			kPaused = 2,
			kFinishing = 3,
			kFinished = 4
		};


		// add
		virtual void DoUpdate() = 0;							// 00
		virtual void DoPlay() = 0;								// 01
		virtual void DoPause() = 0;								// 02
		virtual void DoFinish(bool a_arg1) = 0;					// 03
		virtual void DoApplyDuckingAttenuation(UInt16 a_arg1);	// 04 - { return; }
		virtual void DoClearDucking();							// 05 - { return; }
		virtual void DoPrepare();								// 06 - { return; }

		virtual ~BSIMusicType();  // 07


		// members
		Flag					 flags;				 // 08 - FNAM
		SInt8					 priority;			 // 0C
		SInt8					 padding;			 // 0D
		UInt16					 ducksOtherMusicBy;	 // 0E - ck value * 100 as a UInt16
		float					 fadeTime;			 // 10 - WNAM
		UInt32					 currentTrackIndex;	 // 14
		BSTArray<UInt32>		 trackHistory;		 // 18
		BSTArray<BSIMusicTrack*> tracks;			 // 30 - TNAM
		MUSIC_STATUS			 typeStatus;		 // 48
		UInt32					 pad4C;				 // 4C
	};
	STATIC_ASSERT(sizeof(BSIMusicType) == 0x50);
}
