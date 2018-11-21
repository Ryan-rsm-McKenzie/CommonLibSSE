#include "RE/GFxLoader.h"

#include "skse64/ScaleformLoader.h"  // GFxLoader


namespace RE
{
	GFxLoader* GFxLoader::GetSingleton()
	{
		typedef GFxLoader* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::GFxLoader::GetSingleton));
		return _GetSingleton();
	}


	bool GFxLoader::LoadMovie(IMenu* a_menu, GFxMovieView*& a_viewOut, const char* a_swfName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha)
	{
		typedef bool _LoadMovie_t(GFxLoader* a_this, IMenu* a_menu, GFxMovieView*& a_viewOut, const char* a_swfName, GFxMovieView::ScaleModeType a_mode, float a_backGroundAlpha);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::GFxLoader*>(this)->_LoadMovie_GetPtr());
		static _LoadMovie_t* _LoadMovie = reinterpret_cast<_LoadMovie_t*>(*ptr);
		return _LoadMovie(this, a_menu, a_viewOut, a_swfName, a_mode, a_backGroundAlpha);
	}
}
