#include "RE/GFxMovieView.h"


namespace RE
{
	void GFxMovieView::SetViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, GViewport::Flag a_flags)
	{
		SetViewport({ a_bufW, a_bufH, a_left, a_top, a_width, a_height, a_flags });
	}
}
