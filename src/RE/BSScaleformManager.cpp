#include "RE/BSScaleformManager.h"

#include <string>

#include "RE/BSResourceNiBinaryStream.h"
#include "RE/FxDelegate.h"
#include "RE/GFxLoader.h"
#include "RE/IMenu.h"
#include "RE/Misc.h"
#include "RE/Setting.h"
#include "REL/Relocation.h"


namespace RE
{
	BSScaleformManager* BSScaleformManager::GetSingleton()
	{
		REL::Offset<BSScaleformManager**> singleton = REL::ID(516573);
		return *singleton;
	}


	bool BSScaleformManager::LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode, float a_backGroundAlpha)
	{
		using func_t = decltype(&BSScaleformManager::LoadMovie);
		REL::Offset<func_t> func = REL::ID(80302);
		return func(this, a_menu, a_viewOut, a_fileName, a_mode, a_backGroundAlpha);
	}


	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, llvm::function_ref<void(GFxMovieDef*)> a_callback)
	{
		return LoadMovieEx(a_menu, a_fileName, ScaleModeType::kShowAll, 0.0, a_callback);
	}


	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, llvm::function_ref<void(GFxMovieDef*)> a_callback)
	{
		return LoadMovieEx(a_menu, a_fileName, a_mode, 0.0, a_callback);
	}


	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, float a_backGroundAlpha, llvm::function_ref<void(GFxMovieDef*)> a_callback)
	{
		using LoadConstants = GFxLoader::LoadConstants;

		if (!loader) {
			return false;
		}

		auto filePath = BuildFilePath(a_fileName);
		if (!filePath) {
			return false;
		}

		auto def = loader->CreateMovie(filePath->c_str(), LoadConstants::kLoadKeepBindData | LoadConstants::kLoadWaitFrame1);
		if (!def) {
			return false;
		}

		a_callback(def);

		auto& view = a_menu->view;
		view.reset(def->CreateInstance());
		if (!view) {
			delete def;
			return false;
		}
		view->Release();

		view->SetViewScaleMode(a_mode);
		view->SetBackgroundAlpha(a_backGroundAlpha);

		auto [safeZoneX, safeZoneY, sizeW, sizeH] = CollectDisplayInfo();

		const auto visibleRect = view->GetVisibleFrameRect();
		GRectF safeRect;
		safeRect.left = safeZoneX;
		safeRect.top = safeZoneY;
		safeRect.right = (visibleRect.right - visibleRect.left) - safeZoneX;
		safeRect.bottom = (visibleRect.bottom - visibleRect.top) - safeZoneY;
		view->SetSafeRect(safeRect);

		GViewport viewPort;
		viewPort.bufferWidth = sizeW;
		viewPort.bufferHeight = sizeH;
		viewPort.width = sizeW;
		viewPort.height = sizeH;
		view->SetViewport(viewPort);

		view->Advance(0.0);

		if (view->IsAvailable("_root.InitExtensions")) {
			view->Invoke("_root.InitExtensions", nullptr, nullptr, 0);
		}
		a_menu->RefreshPlatform();

		return true;
	}


	bool BSScaleformManager::LoadMovieStd(IMenu* a_menu, const char* a_fileName, llvm::function_ref<void(GFxMovieDef*)> a_callback, ScaleModeType a_mode, float a_backGroundAlpha)
	{
		return LoadMovieEx(a_menu, a_fileName, a_mode, a_backGroundAlpha, a_callback);
	}


	bool BSScaleformManager::LoadMovie_Impl(IMenu* a_menu, GPtr<RE::GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode, float a_backGroundAlpha)
	{
		using LoadConstants = GFxLoader::LoadConstants;
		using StateType = GFxState::StateType;

		if (!loader) {
			return false;
		}

		auto filePath = BuildFilePath(a_fileName);
		if (!filePath) {
			return false;
		}

		auto def = loader->CreateMovie(filePath->c_str(), LoadConstants::kLoadKeepBindData | LoadConstants::kLoadWaitFrame1);
		if (!def) {
			return false;
		}

		a_viewOut.reset(def->CreateInstance());
		if (!a_viewOut) {
			delete def;
			return false;
		}
		a_viewOut->Release();

		a_viewOut->SetViewScaleMode(a_mode);
		a_viewOut->SetBackgroundAlpha(a_backGroundAlpha);

		auto [safeZoneX, safeZoneY, sizeW, sizeH] = CollectDisplayInfo();

		const auto visibleRect = a_viewOut->GetVisibleFrameRect();
		GRectF safeRect;
		safeRect.left = safeZoneX;
		safeRect.top = safeZoneY;
		safeRect.right = (visibleRect.right - visibleRect.left) - safeZoneX;
		safeRect.bottom = (visibleRect.bottom - visibleRect.top) - safeZoneY;
		a_viewOut->SetSafeRect(safeRect);

		GViewport viewPort;
		viewPort.bufferWidth = sizeW;
		viewPort.bufferHeight = sizeH;
		viewPort.width = sizeW;
		viewPort.height = sizeH;
		a_viewOut->SetViewport(viewPort);

		a_menu->fxDelegate.reset(new FxDelegate());
		a_menu->fxDelegate->Release();
		a_menu->fxDelegate->RegisterHandler(a_menu);
		a_viewOut->SetState(StateType::kExternalInterface, a_menu->fxDelegate.get());

		a_viewOut->Advance(0.0);

		if (a_viewOut->IsAvailable("_root.InitExtensions")) {
			a_viewOut->Invoke("_root.InitExtensions", nullptr, nullptr, 0);
		}
		a_menu->RefreshPlatform();

		return true;
	}


	std::optional<std::string> BSScaleformManager::BuildFilePath(std::string_view a_fileName)
	{
		std::string filePath;
		filePath = "Interface/";
		filePath += a_fileName;
		filePath += ".swf";
		if (!FileExists(filePath.c_str())) {
			filePath = "Interface/Exported/";
			filePath += a_fileName;
			filePath += ".gfx";
			if (!FileExists(filePath.c_str())) {
				return std::nullopt;
			}
		}
		return std::make_optional(filePath);
	}


	std::tuple<float, float, SInt32, SInt32> BSScaleformManager::CollectDisplayInfo()
	{
		static Setting* fSafeZoneX = nullptr;
		if (!fSafeZoneX) {
			fSafeZoneX = GetINISetting("fSafeZoneX:Interface");
		}
		float safeZoneX = fSafeZoneX ? fSafeZoneX->GetFloat() : 0.0;

		static Setting* fSafeZoneY = nullptr;
		if (!fSafeZoneY) {
			fSafeZoneY = GetINISetting("fSafeZoneY:Interface");
		}
		float safeZoneY = fSafeZoneY ? fSafeZoneY->GetFloat() : 0.0;

		static Setting* iSizeW = nullptr;
		if (!iSizeW) {
			iSizeW = GetINISetting("iSize W:Display");
		}
		SInt32 sizeW = iSizeW ? iSizeW->GetSInt() : 0;

		static Setting* iSizeH = nullptr;
		if (!iSizeH) {
			iSizeH = GetINISetting("iSize H:Display");
		}
		SInt32 sizeH = iSizeH ? iSizeH->GetSInt() : 0;

		return std::make_tuple(safeZoneX, safeZoneY, sizeW, sizeH);
	}


	bool BSScaleformManager::FileExists(std::string_view a_fileName)
	{
		BSResourceNiBinaryStream file(a_fileName.data());
		return file.good();
	}
}
