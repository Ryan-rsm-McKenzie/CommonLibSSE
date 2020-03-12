#pragma once

#include "RE/GFxState.h"
#include "RE/GPtr.h"
#include "RE/GRenderer.h"


namespace RE
{
	class GRenderer;


	class GFxRenderConfig : public GFxState
	{
	public:
		using RenderCapBits = GRenderer::RenderCapBits;
		using VertexFormat = GRenderer::VertexFormat;


		enum class RenderFlag : UInt32
		{
			kNone = 0,

			kStrokeCorrect = 0,
			kStrokeNormal = 1 << 0,
			kStrokeHairline = 1 << 1,
			kStrokeMask = 0x03,

			kEdgeAA = 1 << 4,
			kOptimizeTriangles = 1 << 5,
			kNoViewCull = 1 << 8
		};


		bool		  IsUsingEdgeAA() const;
		bool		  IsEdgeAATextured() const;
		bool		  IsOptimizingTriangles() const;
		bool		  HasCxformAddAlpha() const;
		bool		  HasVertexFormat(VertexFormat a_fmt) const;
		RenderFlag	  GetStrokeRenderFlags() const;
		RenderCapBits GetRendererCapBits() const;
		GRenderer*	  GetRenderer() const;
		void		  SetRenderFlags(RenderFlag a_flags);
		RenderFlag	  GetRenderFlags() const;
		void		  SetMaxCurvePixelError(float a_pixelError);
		float		  GetMaxCurvePixelError() const;
		float		  GetStrokerAAWidth() const;
		void		  SetStrokerAAWidth(float a_aawidth);


		// members
		GPtr<GRenderer> renderer;			 // 18
		float			maxCurvePixelError;	 // 20
		RenderFlag		renderFlags;		 // 24
		float			strokerAAWidth;		 // 28
		RenderCapBits	rendererCapBits;	 // 2C
		VertexFormat	rendererVtxFmts;	 // 30
		UInt32			pad34;				 // 34
	};
	STATIC_ASSERT(sizeof(GFxRenderConfig) == 0x38);
}
