#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSIMusicTrack


namespace RE
{
	class BSIMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BSIMusicTrack;


		enum class TrackType : UInt32
		{
			kSilentTrack = 0xA1A9C4D5,
			kSingleTrack = 0x6ED7E048,
			kPalette = 0x23F678C3
		};


		virtual ~BSIMusicTrack();						// 00

		// add
		virtual void		Unk_01(void) = 0;			// 01
		virtual UInt32		Play() = 0;					// 02
		virtual void		Unk_03(void) = 0;			// 03
		virtual void		Unk_04(void) = 0;			// 04
		virtual float		GetDuration() const = 0;	// 05
		virtual TrackType	GetTrackType() const = 0;	// 06 - CRC32 hash of class name
		virtual bool		CanPlay();					// 07 - { return true; }
		virtual void		Unk_08(void);				// 08 - { return unk08; }
		virtual void		Unk_09(void);				// 09 - { return; }
		virtual void		Unk_0A(void);				// 0A - { return; }


		// members
		UInt64 unk08;	// 08
	};
	STATIC_ASSERT(sizeof(BSIMusicTrack) == 0x10);
}
