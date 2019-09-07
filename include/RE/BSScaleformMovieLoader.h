#pragma once

#include <optional>  // optional
#include <string>  // string
#include <tuple>  // tuple

#include "function_ref.h"

#include "RE/BSString.h"  // BSString
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/GFxMovieView.h"  // GFxMovieView::ScaleModeType
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class BSScaleformImageLoader;
	class GFxDrawTextManager;
	class GFxLoader;
	class GFxMovieDef;
	class GFxRenderConfig;
	class IMenu;


	class BSScaleformMovieLoader : public BSTSingletonSDM<BSScaleformMovieLoader>
	{
	public:
		using ScaleModeType = GFxMovieView::ScaleModeType;


		struct Config
		{
			GPtr<GFxRenderConfig> renderConfig;	// 0
		};
		STATIC_ASSERT(sizeof(Config) == 0x8);


		static BSScaleformMovieLoader* GetSingleton();

		bool	LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);
		bool	LoadMovieStd(IMenu* a_menu, const char* a_fileName, llvm::function_ref<void(GFxMovieDef*)> a_callback, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);
		bool	LoadMovie_Impl(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode = ScaleModeType::kShowAll, float a_backGroundAlpha = 0.0);


		// members
		UInt8							pad01;				// 01
		UInt16							pad02;				// 02
		UInt32							pad04;				// 04
		GFxLoader*						gfxLoader;			// 08
		Config*							config;				// 10
		GPtr<GFxDrawTextManager>		drawTextManager;	// 18
		GPtr<BSScaleformImageLoader>	imageLoader;		// 20
		BSString						validNameChars;		// 28
		UInt64							unk38;				// 38

	private:
		std::optional<std::string>					BuildFilePath(const char* a_fileName);
		std::tuple<float, float, SInt32, SInt32>	CollectDisplayInfo();
		bool										FileExists(const char* a_fileName);
	};
	STATIC_ASSERT(sizeof(BSScaleformMovieLoader) == 0x40);
}
