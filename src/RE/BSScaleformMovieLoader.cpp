#include "RE/BSScaleformMovieLoader.h"

#include "skse64/ScaleformLoader.h"  // GFxLoader


namespace RE
{
	BSScaleformMovieLoader* BSScaleformMovieLoader::GetSingleton()
	{
		using func_t = function_type_t<decltype(&BSScaleformMovieLoader::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::GFxLoader::GetSingleton);
		return func();
	}


	bool BSScaleformMovieLoader::LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_swfName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha)
	{
		using func_t = function_type_t<decltype(&BSScaleformMovieLoader::LoadMovie)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::GFxLoader, LoadMovie, func_t*);
		return func(this, a_menu, a_viewOut, a_swfName, a_mode, a_backGroundAlpha);
	}
}
