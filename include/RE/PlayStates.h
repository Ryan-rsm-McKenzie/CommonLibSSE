#pragma once


namespace RE
{
	// PlayState describes the play state of the movie clip. When set on a Movie, affects only the root movie clip.
	enum class PlayState
	{
		kPlaying,	// The movie is playing
		kStopped	// The movie is stopped at its current clip. Child clips may still be playing
	};
}
