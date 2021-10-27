#include "RE/G/GRenderer.h"

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
		renderer(nullptr),
		data(nullptr)
	{}

	GRenderer::CachedData::~CachedData()
	{
		assert(renderer == nullptr);
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
		renderer = nullptr;
		data = nullptr;
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
		return (a_renderer && (a_renderer == data->renderer)) ? data : nullptr;
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

	GRenderer::Cxform GRenderer::Cxform::Identity;

	GRenderer::Cxform::Cxform()
	{
		SetIdentity();
	}

	void GRenderer::Cxform::SetIdentity()
	{
		matrix[kR][kMult] = 1.0f;
		matrix[kR][kAdd] = 0.0f;
		matrix[kG][kMult] = 1.0f;
		matrix[kG][kAdd] = 0.0f;
		matrix[kB][kMult] = 1.0f;
		matrix[kB][kAdd] = 0.0f;
		matrix[kA][kMult] = 1.0f;
		matrix[kA][kAdd] = 0.0f;
	}

	bool GRenderer::Cxform::IsIdentity() const
	{
		return *this == Identity;
	}

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
		distortion(static_cast<float>(0.75)),
		displayDiagInches(static_cast<float>(52.0)),
		displayAspectRatio(static_cast<float>(9.0 / 16.0)),
		eyeSeparationCm(static_cast<float>(6.4))
	{}

	GRenderer::UserData::UserData() :
		string(nullptr),
		flt(nullptr),
		matrix(nullptr),
		matrixSize(0),
		propFlags(UserDataPropertyFlag::kNone),
		pad1D(0),
		pad1E(0)
	{}

	void GRenderer::BeginFrame()
	{}

	void GRenderer::ReleaseTempRenderTargets(std::uint32_t)
	{}

	bool GRenderer::PushUserData(UserData*)
	{
		return false;
	}

	void GRenderer::PopUserData()
	{}

	void GRenderer::SetStereoParams(StereoParams a_params)
	{
		s3DParams = a_params;
		if (s3DParams.displayWidthCm == 0) {
			s3DParams.displayWidthCm = a_params.displayDiagInches / std::sqrtf(1.0F + 1.0F / a_params.displayAspectRatio * 1.0F / a_params.displayAspectRatio) * static_cast<float>(2.54);
		}
	}

	void GRenderer::SetStereoDisplay(StereoDisplay, bool)
	{}

	void GRenderer::DrawDistanceFieldBitmaps(BitmapDesc*, std::int32_t, std::int32_t, std::int32_t, const GTexture*, const Matrix&, const DistanceFieldParams&, CacheProvider*)
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
