#include "RE/GRenderer.h"

#include <cassert>


namespace RE
{
	GRenderer::Stats::Stats() :
		triangles(0),
		lines(0),
		primitives(0),
		masks(0),
		filters(0)
	{}


	void GRenderer::Stats::Clear()
	{
		triangles = 0;
		lines = 0;
		primitives = 0;
		masks = 0;
		filters = 0;
	}


	GRenderer::CachedData::CachedData() :
		renderer(0),
		data(0)
	{}


	GRenderer::CachedData::~CachedData()
	{
		assert(renderer == 0);
	}


	GRenderer* GRenderer::CachedData::GetRenderer() const
	{
		return renderer;
	}


	auto GRenderer::CachedData::GetRendererData() const
		-> Handle
	{
		return data;
	}


	void GRenderer::CachedData::SetRendererData(Handle a_handle)
	{
		data = a_handle;
	}


	void GRenderer::CachedData::ReleaseData(CachedDataType a_type)
	{
		if (renderer) {
			renderer->ReleaseCachedData(this, a_type);
		}

		ReleaseDataByRenderer();
	}


	void GRenderer::CachedData::ReleaseDataByRenderer()
	{
		renderer = 0;
		data = 0;
	}


	GRenderer::CacheProvider::CacheProvider(CachedData* a_cache) :
		data(a_cache),
		discardSharedData(false),
		pad11(0),
		pad12(0),
		pad14(0)
	{}


	auto GRenderer::CacheProvider::GetCachedData(GRenderer* a_renderer)
		-> CachedData*
	{
		return (a_renderer && (a_renderer == data->renderer)) ? data : 0;
	}


	auto GRenderer::CacheProvider::CreateCachedData(CachedDataType a_type, GRenderer* a_renderer, bool a_keepSharedData)
		-> CachedData*
	{
		assert(a_renderer && (data->renderer != a_renderer));

		if (data->renderer != a_renderer) {
			data->ReleaseData(a_type);
		}

		data->renderer = a_renderer;
		discardSharedData = !a_keepSharedData;
		return data;
	}


	GRenderer::Cxform::Cxform() :
		matrix{ 0.0 }
	{}


	bool GRenderer::Cxform::operator==(const Cxform& a_rhs) const
	{
		return matrix[kR][kMult] == a_rhs.matrix[kR][kMult] &&
			matrix[kG][kMult] == a_rhs.matrix[kG][kMult] &&
			matrix[kB][kMult] == a_rhs.matrix[kB][kMult] &&
			matrix[kA][kMult] == a_rhs.matrix[kA][kMult] &&
			matrix[kR][kAdd] == a_rhs.matrix[kR][kAdd] &&
			matrix[kG][kAdd] == a_rhs.matrix[kG][kAdd] &&
			matrix[kB][kAdd] == a_rhs.matrix[kB][kAdd] &&
			matrix[kA][kAdd] == a_rhs.matrix[kA][kAdd];
	}


	bool GRenderer::CacheProvider::CanDiscardData()
	{
		return discardSharedData;
	}


	GRenderer::StereoParams::StereoParams() :
		displayWidthCm(0),
		distortion(0.75),
		displayDiagInches(52.0),
		displayAspectRatio(9.0 / 16.0),
		eyeSeparationCm(6.4)
	{}


	GRenderer::UserData::UserData() :
		string(0),
		flt(0),
		matrix(0),
		matrixSize(0),
		propFlags(UserDataPropertyFlag::kNone)
	{}


	void GRenderer::BeginFrame()
	{}


	void GRenderer::ReleaseTempRenderTargets(UInt32 a_keepArea)
	{}


	bool GRenderer::PushUserData(UserData* a_data)
	{
		return false;
	}


	void GRenderer::PopUserData()
	{}


	void GRenderer::SetStereoParams(StereoParams a_params)
	{
		s3DParams = a_params;
		if (s3DParams.displayWidthCm == 0) {
			s3DParams.displayWidthCm = a_params.displayDiagInches / std::sqrt(1.0f + 1.0 / a_params.displayAspectRatio * 1.0 / a_params.displayAspectRatio) * 2.54;
		}
	}


	void GRenderer::SetStereoDisplay(StereoDisplay a_display, bool a_setstate)
	{}


	void GRenderer::DrawDistanceFieldBitmaps(BitmapDesc* a_bitmapList, SInt32 a_listSize, SInt32 a_startIndex, SInt32 a_count, const GTexture* a_texture, const Matrix& a_matrix, const DistanceFieldParams& a_params, CacheProvider* a_cache)
	{}


	void GRenderer::FillStyleBitmap(GTexture* a_texture, const Matrix& a_matrix, BitmapWrapMode a_wrapMode, BitmapSampleMode a_sampleMode)
	{
		FillTexture ft;
		ft.texture = a_texture;
		ft.textureMatrix = a_matrix;
		ft.wrapMode = a_wrapMode;
		ft.sampleMode = a_sampleMode;
		FillStyleBitmap(&ft);
	}
}
