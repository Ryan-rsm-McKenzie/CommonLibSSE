#include "RE/G/GFxRenderConfig.h"

namespace RE
{
	bool GFxRenderConfig::IsUsingEdgeAA() const
	{
		return renderFlags.all(RenderFlag::kEdgeAA) && IsEdgeAATextured();
	}

	bool GFxRenderConfig::IsEdgeAATextured() const
	{
		return rendererCapBits.all(RenderCapBits::kFillGouraudTex);
	}

	bool GFxRenderConfig::IsOptimizingTriangles() const
	{
		return renderFlags.all(RenderFlag::kOptimizeTriangles);
	}

	bool GFxRenderConfig::HasCxformAddAlpha() const
	{
		return rendererCapBits.all(RenderCapBits::kCxformAdd);
	}

	bool GFxRenderConfig::HasVertexFormat(VertexFormat a_fmt) const
	{
		return rendererVtxFmts.all(a_fmt);
	}

	auto GFxRenderConfig::GetStrokeRenderFlags() const
		-> RenderFlag
	{
		return *(renderFlags & RenderFlag::kStrokeMask);
	}

	auto GFxRenderConfig::GetRendererCapBits() const
		-> RenderCapBits
	{
		return *rendererCapBits;
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
		return *renderFlags;
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
