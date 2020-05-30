#include "RE/GFxRenderConfig.h"


namespace RE
{
	bool GFxRenderConfig::IsUsingEdgeAA() const
	{
		return ((renderFlags & RenderFlag::kEdgeAA) != RenderFlag::kNone) && ((rendererCapBits & RenderCapBits::kFillGouraud) != RenderCapBits::kNone);
	}


	bool GFxRenderConfig::IsEdgeAATextured() const
	{
		return (rendererCapBits & RenderCapBits::kFillGouraudTex) != RenderCapBits::kNone;
	}


	bool GFxRenderConfig::IsOptimizingTriangles() const
	{
		return (renderFlags & RenderFlag::kOptimizeTriangles) != RenderFlag::kNone;
	}


	bool GFxRenderConfig::HasCxformAddAlpha() const
	{
		return (rendererCapBits & RenderCapBits::kCxformAdd) != RenderCapBits::kNone;
	}


	bool GFxRenderConfig::HasVertexFormat(VertexFormat a_fmt) const
	{
		return (rendererVtxFmts & a_fmt) != VertexFormat::kNone;
	}


	auto GFxRenderConfig::GetStrokeRenderFlags() const
		-> RenderFlag
	{
		return renderFlags & RenderFlag::kStrokeMask;
	}


	auto GFxRenderConfig::GetRendererCapBits() const
		-> RenderCapBits
	{
		return rendererCapBits;
	}


	GRenderer* GFxRenderConfig::GetRenderer() const
	{
		return renderer.get();
	}


	void GFxRenderConfig::SetRenderFlags(RenderFlag a_flags)
	{
		renderFlags = a_flags;
	}


	auto GFxRenderConfig::GetRenderFlags() const
		-> RenderFlag
	{
		return renderFlags;
	}


	void GFxRenderConfig::SetMaxCurvePixelError(float a_pixelError)
	{
		maxCurvePixelError = std::clamp<float>(a_pixelError, static_cast<float>(1e-6), static_cast<float>(1e6));
	}


	float GFxRenderConfig::GetMaxCurvePixelError() const
	{
		return maxCurvePixelError;
	}


	float GFxRenderConfig::GetStrokerAAWidth() const
	{
		return strokerAAWidth;
	}


	void GFxRenderConfig::SetStrokerAAWidth(float a_aawidth)
	{
		strokerAAWidth = a_aawidth;
	}
}
