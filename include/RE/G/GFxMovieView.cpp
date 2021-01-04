#include "RE/G/GFxMovieView.h"

namespace RE
{
	void GFxMovieView::SetViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, GViewport::Flag a_flags)
	{
		SetViewport({ a_bufW, a_bufH, a_left, a_top, a_width, a_height, a_flags });
	}

	void GFxMovieView::InvokeNoReturn(const char* a_methodName, const GFxValue* a_args, std::uint32_t a_numArgs)
	{
		using func_t = decltype(&GFxMovieView::InvokeNoReturn);
		REL::Relocation<func_t> func{ Offset::GFxMovieView::InvokeNoReturn };
		return func(this, a_methodName, a_args, a_numArgs);
	}
}
