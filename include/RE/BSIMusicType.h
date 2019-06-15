#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSIMusicType

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // BGSMusicTrackFormWrapper


namespace RE
{
	class BSIMusicType
	{
	public:
		inline static const void* RTTI = RTTI_BSIMusicType;


		enum class Flag : UInt32	// FNAM
		{
			kNone = 0,
			kPlaysOneSelection = 1 << 0,
			kAbruptTransition = 1 << 1,
			kCycleTracks = 1 << 2,
			kMaintainTrackOrder = 1 << 3,
			kDucksCurrentTrack = 1 << 5,
			kDoesntQueue = 1 << 6
		};


		struct Data	// PNAM
		{
			float GetDucking() const;


			UInt16	priority;	// 0
			UInt16	ducking;	// 2 - ck value * 100 as a UInt16
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		// add
		virtual void	Unk_00(void) = 0;	// 00
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
		virtual void	Unk_04(void);		// 04 - { return; }
		virtual void	Unk_05(void);		// 05 - { return; }
		virtual void	Unk_06(void);		// 06 - { return; }

		virtual ~BSIMusicType();			// 07


		// members
		Flag								flags;			// 08 - FNAM
		Data								data;			// 0C - PNAM
		float								fadeDuration;	// 10 - WNAM
		UInt32								unk14;			// 14
		BSTArray<void*>						unk18;			// 18
		BSTArray<BGSMusicTrackFormWrapper*>	musicTracks;	// 30 - TNAM
		UInt64								unk48;			// 48
	};
	STATIC_ASSERT(sizeof(BSIMusicType) == 0x50);
}
