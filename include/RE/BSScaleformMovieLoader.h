#pragma once

#include <optional>  // optional
#include <string>  // string
#include <tuple>  // tuple

#include "RE/BSString.h"  // BSString
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/GFxMovieView.h"  // GFxMovieView::ScaleModeType
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class BSScaleformImageLoader;
	class GFxDrawTextManager;
	class GFxLoader;
	class GFxRenderConfig;
	class IMenu;


	class BSScaleformMovieLoader : public BSTSingletonSDM<BSScaleformMovieLoader>
	{
	public:
		struct Config
		{
			GPtr<GFxRenderConfig> renderConfig;	// 0
		};
		STATIC_ASSERT(sizeof(Config) == 0x8);


		static BSScaleformMovieLoader* GetSingleton();

		bool	LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha);
		bool	LoadMovieStd(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha);


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
