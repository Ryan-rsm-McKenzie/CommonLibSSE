#pragma once

#include "RE/BSTEvent.h"  // BSTEventSource, BSTEventSink
#include "RE/MoviePlayer.h"  // MoviePlayer


namespace RE
{
	class InputEvent;
	struct BSMusicEvent;


	class BGSMoviePlayer :
		public MoviePlayer,						// 00
		public BSTEventSink<InputEvent*>,		// 58
		public BSTEventSource<BSMusicEvent>		// 60
	{
	public:
		virtual ~BGSMoviePlayer();	// 00


		// members
		UInt64 unkB8;	// B8
	};
	STATIC_ASSERT(sizeof(BGSMoviePlayer) == 0xC0);
}
