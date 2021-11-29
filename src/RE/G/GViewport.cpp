#include "RE/G/GViewport.h"

namespace RE
{
	GViewport::GViewport() :
		bufferWidth(0),
		bufferHeight(0),
		left(0),
		top(0),
		width(1),
		height(1),
		scissorLeft(0),
		scissorTop(0),
		scissorWidth(0),
		scissorHeight(0),
		scale(1.0),
		aspectRatio(1.0),
		flags(Flag::kNone),
		pad34(0)
	{}

	GViewport::GViewport(const GViewport& a_rhs) :
		bufferWidth(a_rhs.bufferWidth),
		bufferHeight(a_rhs.bufferHeight),
		left(a_rhs.left),
		top(a_rhs.top),
		width(a_rhs.width),
		height(a_rhs.height),
		scissorLeft(a_rhs.scissorLeft),
		scissorTop(a_rhs.scissorTop),
		scissorWidth(a_rhs.scissorWidth),
		scissorHeight(a_rhs.scissorHeight),
		scale(a_rhs.scale),
		aspectRatio(a_rhs.aspectRatio),
		flags(a_rhs.flags),
		pad34(0)
	{}

	GViewport::GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH, Flag a_flags) :
		bufferWidth(a_bufW),
		bufferHeight(a_bufH),
		left(a_left),
		top(a_top),
		width(a_width),
		height(a_height),
		scissorLeft(a_scLeft),
		scissorTop(a_scTop),
		scissorWidth(a_scW),
		scissorHeight(a_scH),
		scale(1.0),
		aspectRatio(1.0),
		flags(a_flags),
		pad34(0)
	{}

	GViewport::GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH, float a_scale, float a_ratio, Flag a_flags) :
		bufferWidth(a_bufW),
		bufferHeight(a_bufH),
		left(a_left),
		top(a_top),
		width(a_width),
		height(a_height),
		scissorLeft(a_scLeft),
		scissorTop(a_scTop),
		scissorWidth(a_scW),
		scissorHeight(a_scH),
		scale(a_scale),
		aspectRatio(a_ratio),
		flags(a_flags, Flag::kUseScissorRect),
		pad34(0)
	{}

	GViewport::GViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, Flag a_flags) :
		bufferWidth(a_bufW),
		bufferHeight(a_bufH),
		left(a_left),
		top(a_top),
		width(a_width),
		height(a_height),
		scissorLeft(0),
		scissorTop(0),
		scissorWidth(0),
		scissorHeight(0),
		scale(1.0),
		aspectRatio(1.0),
		flags(a_flags),
		pad34(0)
	{}

	void GViewport::SetViewport(std::int32_t a_bufW, std::int32_t a_bufH, std::int32_t a_left, std::int32_t a_top, std::int32_t a_width, std::int32_t a_height, Flag a_flags)
	{
		bufferWidth = a_bufW;
		bufferHeight = a_bufH;
		left = a_left;
		top = a_top;
		width = a_width;
		height = a_height;
		flags = a_flags;
		scissorLeft = 0;
		scissorTop = 0;
		scissorWidth = 0;
		scissorHeight = 0;
		scale = 1.0;
		aspectRatio = 1.0;
	}

	void GViewport::SetScissorRect(std::int32_t a_scLeft, std::int32_t a_scTop, std::int32_t a_scW, std::int32_t a_scH)
	{
		scissorLeft = a_scLeft;
		scissorTop = a_scTop;
		scissorWidth = a_scW;
		scissorHeight = a_scH;
		flags.set(Flag::kUseScissorRect);
	}
}
