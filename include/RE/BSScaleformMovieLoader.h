#pragma once

#include <optional>  // optional
#include <string>  // string
#include <tuple>  // tuple

#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/GFxMovieView.h"  // GFxMovieView::ScaleModeType
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class BSScaleformImageLoader;
	class GFxDrawTextManager;
	class GFxLoader;
	class IMenu;


	class BSScaleformMovieLoader : public BSTSingletonSDM<BSScaleformMovieLoader>
	{
	public:
		static BSScaleformMovieLoader* GetSingleton();

		bool	LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha);
		bool	LoadMovieStd(RE::IMenu* a_menu, RE::GPtr<RE::GFxMovieView>& a_viewOut, const char* a_fileName, RE::GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha);


		// members
		UInt8					pad01;				// 01
		UInt16					pad02;				// 02
		UInt32					pad04;				// 04
		GFxLoader*				gfxLoader;			// 08
		void*					unk10;				// 10
		GFxDrawTextManager*		drawTextManager;	// 18
		BSScaleformImageLoader*	imageLoader;		// 20
		const char*				unk28;				// 28
		UInt32					unk30;				// 30
		UInt32					unk34;				// 34
		UInt64					unk38;				// 38

	private:
		std::optional<std::string> BuildFilePath(const char* a_fileName);
		std::tuple<float, float, SInt32, SInt32> CollectDisplayInfo();
		bool FileExists(const char* a_fileName);
	};
	STATIC_ASSERT(sizeof(BSScaleformMovieLoader) == 0x40);
}
