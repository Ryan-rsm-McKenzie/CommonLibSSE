#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMoviePlayer

#include "RE/BSTEvent.h"  // BSTEventSource, BSTEventSink
#include "RE/MoviePlayer.h"  // MoviePlayer


namespace RE
{
	class InputEvent;
	struct BSMusicEvent;


	class BGSMoviePlayer :
		public MoviePlayer,					// 00
		public BSTEventSink<InputEvent*>,	// 58
		public BSTEventSource<BSMusicEvent>	// 60
	{
	public:
		inline static const void* RTTI = RTTI_BGSMoviePlayer;


		virtual ~BGSMoviePlayer();				// 00

		// override (MoviePlayer)
		virtual void	Unk_01(void) override;	// 01
		virtual void	Unk_02(void) override;	// 02
		virtual void	Unk_03(void) override;	// 03
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_05(void) override;	// 05 - { return; }
		virtual void	Unk_06(void) override;	// 06 - { return; }
		virtual void	Unk_07(void) override;	// 07
		virtual void	Unk_08(void) override;	// 08
		virtual void	Unk_09(void) override;	// 09
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_0B(void) override;	// 0B
		virtual void	Unk_0C(void) override;	// 0C
		virtual void	Unk_0D(void) override;	// 0D


		// members
		UInt64 unkB8;	// B8
	};
	STATIC_ASSERT(sizeof(BGSMoviePlayer) == 0xC0);
}
