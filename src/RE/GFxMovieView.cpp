#include "RE/GFxMovieView.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void GFxMovieView::SetViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, GViewport::Flag a_flags)
	{
		SetViewport({ a_bufW, a_bufH, a_left, a_top, a_width, a_height, a_flags });
	}


	void GFxMovieView::InvokeNoReturn(const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs)
	{
		using func_t = decltype(&GFxMovieView::InvokeNoReturn);
		REL::Offset<func_t> func(Offset::GFxMovieView::InvokeNoReturn);
		return func(this, a_methodName, a_args, a_numArgs);
	}
}
