#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTSingleton.h"
#include "RE/G/GFxMovieView.h"
#include "RE/G/GPtr.h"

namespace RE
{
	class BSScaleformImageLoader;
	class GFxDrawTextManager;
	class GFxLoader;
	class GFxMovieDef;
	class GFxRenderConfig;
	class IMenu;

	struct BSScaleformRenderer
	{
	public:
		// members
		GPtr<GFxRenderConfig> config;  // 0
	};
	static_assert(sizeof(BSScaleformRenderer) == 0x8);

	class BSScaleformManager : public BSTSingletonSDM<BSScaleformManager>
	{
	public:
		using ScaleModeType = GFxMovieView::ScaleModeType;

		static BSScaleformManager* GetSingleton();
		static bool                FileExists(const char* a_fileName);

		bool LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);

		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, std::function<void(GFxMovieDef*)> a_callback);
		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, std::function<void(GFxMovieDef*)> a_callback);
		bool LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, float a_backGroundAlpha, std::function<void(GFxMovieDef*)> a_callback);

		bool LoadMovie_Impl(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);

		// members
		std::uint8_t                 pad01;           // 01
		std::uint16_t                pad02;           // 02
		std::uint32_t                pad04;           // 04
		GFxLoader*                   loader;          // 08
		BSScaleformRenderer*         renderer;        // 10
		GPtr<GFxDrawTextManager>     textManager;     // 18
		GPtr<BSScaleformImageLoader> imageLoader;     // 20
		BSString                     validNameChars;  // 28
		std::uint64_t                unk38;           // 38

	private:
		static std::optional<std::string>                           BuildFilePath(std::string_view a_fileName);
		static std::tuple<float, float, std::int32_t, std::int32_t> CollectDisplayInfo();
	};
	static_assert(sizeof(BSScaleformManager) == 0x40);
}
