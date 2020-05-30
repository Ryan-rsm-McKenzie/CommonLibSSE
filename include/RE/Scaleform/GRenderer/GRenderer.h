#pragma once

#include "RE/GColor.h"
#include "RE/GMatrix2D.h"
#include "RE/GPoint.h"
#include "RE/GRect.h"
#include "RE/GRefCountBase.h"
#include "RE/GRendererEventHandler.h"
#include "RE/GTexture.h"


namespace RE
{
	class GImageBase;
	class GMatrix3D;
	class GRenderTarget;
	class GViewport;


	class GRenderer : public GRefCountBase<GRenderer, GStatRenderer::kMem>
	{
	public:
		using Handle = void*;
		using Matrix = GMatrix2D;
		using Point = GPointF;
		using Rect = GRectF;


		enum class BlendType : UInt32
		{
			kNone = 0,
			kNormal = 1,
			kLayer = 2,
			kMultiply = 3,
			kScreen = 4,
			kLighten = 5,
			kDarken = 6,
			kDifference = 7,
			kAdd = 8,
			kSubtract = 9,
			kInvert = 10,
			kAlpha = 11,
			kErase = 12,
			kOverlay = 13,
			kHardLight = 14
		};


		enum class ResizeImageType : UInt32
		{
			kRGBToRGB,
			kRGBAToRGBA,
			kRGBToRGBA,
			kGray
		};


		enum class VertexFormat : UInt32
		{
			kNone = 0,
			kXY16i = 1 << 1,
			kXY32f = 1 << 2,
			kXY16iC32 = 1 << 3,
			kXY16iCF32 = 1 << 4
		};

		enum class IndexFormat : UInt32
		{
			kNone = 0,
			k16 = 1,
			k32 = 2
		};


		enum class RenderCapBits : UInt32
		{
			kNone = 0,

			kCacheDataUse = 1 << 0,

			kIndex16 = 1 << 2,
			kIndex32 = 1 << 3,
			kRenderStats = 1 << 4,
			kRenderTargets = 1 << 5,
			kRenderTargetPrePass = 1 << 6,
			kRenderTargetNonPow2 = 1 << 7,
			kFillGouraud = 1 << 8,
			kFillGouraudTex = 1 << 9,

			kCxformAdd = 1 << 12,
			kNestedMasks = 1 << 13,
			kTexNonPower2 = 1 << 14,
			kTexNonPower2Wrap = 1 << 15,
			kCanLoseData = 1 << 16,
			kKeepVertexData = 1 << 17,
			kNoTexOverwrite = 1 << 18,
			kTexNonPower2Mip = 1 << 19,
			kThreadedTextureCreation = 1 << 20,
			kRenderTargetMip = 1 << 21,
			kFilter_Blurs = 1 << 22,
			kFilter_ColorMatrix = 1 << 23,
		};


		enum class StereoDisplay : UInt32
		{
			kStereoCenter,
			kStereoLeft,
			kStereoRight
		};


		enum class CachedDataType : UInt32
		{
			kVertex = 1,
			kIndex = 2,
			kBitmapList = 3
		};


		enum class UserDataPropertyFlag : UInt8
		{
			kNone,
			kHasString,
			kHasFloat,
			kHasMatrix
		};


		enum class BitmapWrapMode : UInt32
		{
			kRepeat,
			kClamp
		};


		enum class BitmapSampleMode : UInt32
		{
			kPoint,
			kLinear
		};


		enum class GouraudFillType : UInt32
		{
			kColor,
			k1Texture,
			k1TextureColor,
			k2Texture,
			k2TextureColor,
			k3Texture
		};


		enum class SubmitMaskMode : UInt32
		{
			kClear,
			kIncrement,
			kDecrement
		};


		enum class FilterModes : UInt32
		{
			kBlur = 1 << 0,
			kShadow = 1 << 1,
			kHighlight = 1 << 2,

			Filter_Knockout = 1 << 8,
			Filter_Inner = 1 << 9,
			Filter_HideObject = 1 << 10,

			Filter_UserModes = 0xFFFF,
			Filter_SkipLastPass = 1 << 16,
			Filter_LastPassOnly = 1 << 17
		};


		enum class FilterSupport : UInt32
		{
			kNone = 0,
			kOk = 1 << 0,
			kMultipass = 1 << 1,
			kSlow = 1 << 2,
		};


		class Stats
		{
		public:
			Stats();

			void Clear();


			// members
			UInt32 triangles;	// 00
			UInt32 lines;		// 04
			UInt32 primitives;	// 08
			UInt32 masks;		// 0C
			UInt32 filters;		// 10
		};
		STATIC_ASSERT(sizeof(Stats) == 0x14);


		class CachedData
		{
		public:
			CachedData();
			~CachedData();

			GRenderer* GetRenderer() const;
			Handle	   GetRendererData() const;
			void	   SetRendererData(Handle a_handle);
			void	   ReleaseData(CachedDataType a_type);
			void	   ReleaseDataByRenderer();


			// members
			GRenderer* renderer;  // 00
			Handle	   data;	  // 08
		};
		STATIC_ASSERT(sizeof(CachedData) == 0x10);


		class CacheProvider
		{
		public:
			CacheProvider(CachedData* a_cache);
			~CacheProvider() = default;

			CachedData* GetCachedData(GRenderer* a_renderer);
			CachedData* CreateCachedData(CachedDataType a_type, GRenderer* a_renderer, bool a_keepSharedData = true);
			bool		CanDiscardData();


			// members
			CachedData* data;				// 00
			bool		discardSharedData;	// 10
			UInt8		pad11;				// 11
			UInt16		pad12;				// 12
			UInt32		pad14;				// 14
		};
		STATIC_ASSERT(sizeof(CacheProvider) == 0x10);


		class Cxform
		{
		public:
			enum
			{
				kR,
				kG,
				kB,
				kA,
				kRGBA
			};


			enum
			{
				kMult,
				kAdd,
				kMultAdd
			};


			Cxform();

			bool operator==(const Cxform& a_rhs) const;


			// members
			float matrix[kRGBA][kMultAdd];	// 00
		};
		STATIC_ASSERT(sizeof(Cxform) == 0x20);


		struct StereoParams
		{
			StereoParams();


			// members
			float displayWidthCm;	   // 00
			float distortion;		   // 04
			float displayDiagInches;   // 08
			float displayAspectRatio;  // 0C
			float eyeSeparationCm;	   // 10
		};
		STATIC_ASSERT(sizeof(StereoParams) == 0x14);


		struct RenderCaps
		{
			RenderCapBits capBits;		   // 00
			UInt32		  vertexFormats;   // 04
			UInt32		  blendModes;	   // 08
			UInt32		  maxTextureSize;  // 0C
		};
		STATIC_ASSERT(sizeof(RenderCaps) == 0x10);


		struct UserData
		{
			UserData();


			// members
			const char*			 string;	  // 00
			float*				 flt;		  // 08
			float*				 matrix;	  // 10
			UInt32				 matrixSize;  // 18
			UserDataPropertyFlag propFlags;	  // 1C
			UInt8				 pad1D;		  // 1D
			UInt16				 pad1E;		  // 1E
		};
		STATIC_ASSERT(sizeof(UserData) == 0x20);


		struct FillTexture
		{
			GTexture*		 texture;		 // 00
			Matrix			 textureMatrix;	 // 08
			BitmapWrapMode	 wrapMode;		 // 20
			BitmapSampleMode sampleMode;	 // 24
		};
		STATIC_ASSERT(sizeof(FillTexture) == 0x28);


		struct VertexXY16i
		{
			SInt16 x;  // 0
			SInt16 y;  // 2
		};
		STATIC_ASSERT(sizeof(VertexXY16i) == 0x4);


		struct VertexXY16iC32
		{
			enum
			{
				kVFormat = VertexFormat::kXY16iC32
			};


			// members
			SInt16 x;	   // 0
			SInt16 y;	   // 2
			UInt32 color;  // 4
		};
		STATIC_ASSERT(sizeof(VertexXY16iC32) == 0x8);


		struct VertexXY16iCF32
		{
			enum
			{
				kVFormat = VertexFormat::kXY16iCF32
			};


			// members
			SInt16 x;		 // 0
			SInt16 y;		 // 2
			UInt32 color;	 // 4
			UInt32 factors;	 // 8
		};
		STATIC_ASSERT(sizeof(VertexXY16iCF32) == 0xC);


		struct BitmapDesc
		{
			Rect   Coords;		   // 00
			Rect   TextureCoords;  // 10
			GColor Color;		   // 20
		};
		STATIC_ASSERT(sizeof(BitmapDesc) == 0x24);


		struct DistanceFieldParams
		{
			float	width;		   // 00
			float	shadowWidth;   // 04
			GColor	shadowColor;   // 08
			GPointF shadowOffset;  // 0C
			GColor	glowColor;	   // 14
			float	glowSize[2];   // 18
		};
		STATIC_ASSERT(sizeof(DistanceFieldParams) == 0x20);


		struct BlurFilterParams
		{
			UInt32	mode;	   // 00
			float	blurX;	   // 04
			float	blurY;	   // 08
			UInt32	passes;	   // 0C
			GPointF offset;	   // 10
			GColor	color;	   // 18
			GColor	color2;	   // 1C
			float	strength;  // 20
			Cxform	cxform;	   // 24
		};
		STATIC_ASSERT(sizeof(BlurFilterParams) == 0x44);


		virtual ~GRenderer();  // 00

		// add
		virtual bool		   GetRenderCaps(RenderCaps* a_caps) = 0;																																															// 01
		virtual GTexture*	   CreateTexture() = 0;																																																				// 02
		virtual GTexture*	   CreateTextureYUV() = 0;																																																			// 03
		virtual void		   BeginFrame();																																																					// 04
		virtual void		   EndFrame();																																																						// 05
		virtual GRenderTarget* CreateRenderTarget() = 0;																																																		// 06
		virtual void		   SetDisplayRenderTarget(GRenderTarget* a_renderTarget, bool a_setstate = true) = 0;																																				// 07
		virtual void		   PushRenderTarget(const GRectF& a_frameRect, GRenderTarget* a_renderTarget) = 0;																																					// 08
		virtual void		   PopRenderTarget() = 0;																																																			// 09
		virtual GTexture*	   PushTempRenderTarget(const GRectF& a_frameRect, UInt32 a_targetW, UInt32 a_targetH) = 0;																																			// 0A
		virtual void		   ReleaseTempRenderTargets(UInt32 a_keepArea);																																														// 0B
		virtual void		   BeginDisplay(GColor a_backgroundColor, const GViewport& a_viewport, float a_x0, float a_x1, float a_y0, float a_y1) = 0;																											// 0C
		virtual void		   EndDisplay() = 0;																																																				// 0D
		virtual void		   SetMatrix(const Matrix& a_matrix) = 0;																																															// 0E
		virtual void		   SetUserMatrix(const Matrix& a_matrix) = 0;																																														// 0F
		virtual void		   SetCxform(const Cxform& a_cxForm) = 0;																																															// 10
		virtual void		   PushBlendMode(BlendType a_mode) = 0;																																																// 11
		virtual void		   PopBlendMode() = 0;																																																				// 12
		virtual bool		   PushUserData(UserData* a_data);																																																	// 13
		virtual void		   PopUserData();																																																					// 14
		virtual void		   SetPerspective3D(const GMatrix3D& a_projMatIn) = 0;																																												// 15
		virtual void		   SetView3D(const GMatrix3D& a_viewMatIn) = 0;																																														// 16
		virtual void		   SetWorld3D(const GMatrix3D* a_worldMatIn) = 0;																																													// 17
		virtual void		   MakeViewAndPersp3D(const GRectF& a_visFrameRectInTwips, GMatrix3D& a_matView, GMatrix3D& a_matPersp, float a_perspFOV, bool a_InvertY = false);																					// 18
		virtual void		   SetStereoParams(StereoParams a_params);																																															// 19
		virtual void		   SetStereoDisplay(StereoDisplay a_display, bool a_setstate = false);																																								// 1A
		virtual void		   SetVertexData(const void* a_vertices, SInt32 a_numVertices, VertexFormat a_vtxFmt, CacheProvider* a_cache = 0) = 0;																												// 1B
		virtual void		   SetIndexData(const void* a_indices, SInt32 a_numIndices, IndexFormat a_idxFmt, CacheProvider* a_cache = 0) = 0;																													// 1C
		virtual void		   ReleaseCachedData(CachedData* a_data, CachedDataType a_type) = 0;																																								// 1D
		virtual void		   DrawIndexedTriList(SInt32 a_baseVertexIndex, SInt32 a_minVertexIndex, SInt32 a_numVertices, SInt32 a_startIndex, SInt32 a_triangleCount) = 0;																					// 1E
		virtual void		   DrawLineStrip(SInt32 a_baseVertexIndex, SInt32 a_lineCount) = 0;																																									// 1F
		virtual void		   LineStyleDisable() = 0;																																																			// 20
		virtual void		   LineStyleColor(GColor a_color) = 0;																																																// 21
		virtual void		   FillStyleDisable() = 0;																																																			// 22
		virtual void		   FillStyleColor(GColor a_color) = 0;																																																// 23
		virtual void		   FillStyleBitmap(const FillTexture* a_fill) = 0;																																													// 24
		virtual void		   FillStyleGouraud(GouraudFillType a_fillType, const FillTexture* a_texture0 = 0, const FillTexture* a_texture1 = 0, const FillTexture* a_texture2 = 0) = 0;																		// 25
		virtual void		   DrawBitmaps(BitmapDesc* a_bitmapList, SInt32 a_listSize, SInt32 a_startIndex, SInt32 a_count, const GTexture* a_texture, const Matrix& a_matrix, CacheProvider* a_cache = 0) = 0;												// 26
		virtual void		   DrawDistanceFieldBitmaps(BitmapDesc* a_bitmapList, SInt32 a_listSize, SInt32 a_startIndex, SInt32 a_count, const GTexture* a_texture, const Matrix& a_matrix, const DistanceFieldParams& a_params, CacheProvider* a_cache = 0);	// 27
		virtual void		   BeginSubmitMask(SubmitMaskMode a_maskMode = SubmitMaskMode::kClear) = 0;																																							// 28
		virtual void		   EndSubmitMask() = 0;																																																				// 29
		virtual void		   DisableMask() = 0;																																																				// 2A
		virtual UInt32		   CheckFilterSupport(const BlurFilterParams& a_params) = 0;																																										// 2B
		virtual void		   DrawBlurRect(GTexture* a_srcIn, const GRectF& a_inSrcRect, const GRectF& a_inDstRect, const BlurFilterParams& a_params) = 0;																										// 2C
		virtual void		   DrawColorMatrixRect(GTexture* a_srcIn, const GRectF& a_inSrcRect, const GRectF& a_dstRect, const float* a_matrix) = 0;																											// 2D
		virtual void		   GetRenderStats(Stats* a_stats, bool a_resetStats = 0) = 0;																																										// 2E
		virtual void		   GetStats(GStatBag* a_bag, bool a_reset = true) = 0;																																												// 2F
		virtual void		   ReleaseResources() = 0;																																																			// 30
		virtual bool		   AddEventHandler(GRendererEventHandler* a_handler);																																												// 31
		virtual void		   RemoveEventHandler(GRendererEventHandler* a_handler);																																											// 32
		void				   CallHandlers(GRendererEventHandler::EventType a_event);																																											// 33
		static void			   ResizeImage(UInt8* a_dst, SInt32 a_dstWidth, SInt32 a_dstHeight, SInt32 a_dstPitch, const UInt8* a_src, SInt32 a_srcWidth, SInt32 a_srcHeight, SInt32 a_srcPitch, ResizeImageType a_type);										// 34

		GTexture* CreateTextureFromImage(GImageBase* a_image, GTexture::ImageTexUsage a_usage = GTexture::ImageTexUsage::kWrap);
		void	  FillStyleBitmap(GTexture* a_texture, const Matrix& a_matrix, BitmapWrapMode a_wrapMode, BitmapSampleMode a_sampleMode);


		// members
		GList<GRendererEventHandler> handlers;	  // 10
		StereoParams				 s3DParams;	  // 20
		StereoDisplay				 s3DDisplay;  // 34
	};
	STATIC_ASSERT(sizeof(GRenderer) == 0x38);
}
