#include "RE/B/BSScaleformManager.h"

#include "RE/F/FxDelegate.h"
#include "RE/G/GFxLoader.h"
#include "RE/I/IMenu.h"
#include "RE/M/Misc.h"
#include "RE/S/Setting.h"
#include "RE/S/State.h"

namespace RE
{
	BSScaleformManager* BSScaleformManager::GetSingleton()
	{
		REL::Relocation<BSScaleformManager**> singleton{ REL::ID(516573) };
		return *singleton;
	}

	bool BSScaleformManager::LoadMovie(IMenu* a_menu, GPtr<GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode, float a_backGroundAlpha)
	{
		using func_t = decltype(&BSScaleformManager::LoadMovie);
		REL::Relocation<func_t> func{ REL::ID(80302) };
		return func(this, a_menu, a_viewOut, a_fileName, a_mode, a_backGroundAlpha);
	}

	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, std::function<void(GFxMovieDef*)> a_callback)
	{
		return LoadMovieEx(a_menu, a_fileName, ScaleModeType::kShowAll, 0.0F, a_callback);
	}

	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, std::function<void(GFxMovieDef*)> a_callback)
	{
		return LoadMovieEx(a_menu, a_fileName, a_mode, 0.0F, a_callback);
	}

	bool BSScaleformManager::LoadMovieEx(IMenu* a_menu, std::string_view a_fileName, ScaleModeType a_mode, float a_backGroundAlpha, std::function<void(GFxMovieDef*)> a_callback)
	{
		using LoadConstants = GFxLoader::LoadConstants;

		if (!loader) {
			return false;
		}

		const auto filePath = BuildFilePath(a_fileName);
		if (!filePath) {
			return false;
		}

		const auto def = loader->CreateMovie(filePath->c_str(), LoadConstants::kLoadKeepBindData | LoadConstants::kLoadWaitFrame1);
		if (!def) {
			return false;
		}

		a_callback(def);

		auto& view = a_menu->uiMovie;
		view.reset(def->CreateInstance());
		if (!view) {
			delete def;
			return false;
		}
		view->Release();

		view->SetViewScaleMode(a_mode);
		view->SetBackgroundAlpha(a_backGroundAlpha);

		const auto [safeZoneX, safeZoneY, width, height] = CollectDisplayInfo();

		const auto visibleRect = view->GetVisibleFrameRect();
		GRectF	   safeRect;
		safeRect.left = safeZoneX;
		safeRect.top = safeZoneY;
		safeRect.right = (visibleRect.right - visibleRect.left) - safeZoneX;
		safeRect.bottom = (visibleRect.bottom - visibleRect.top) - safeZoneY;
		view->SetSafeRect(safeRect);

		GViewport viewPort;
		viewPort.bufferWidth = width;
		viewPort.bufferHeight = height;
		viewPort.width = width;
		viewPort.height = height;
		view->SetViewport(viewPort);

		view->Advance(0.0F);

		if (view->IsAvailable("_root.InitExtensions")) {
			view->Invoke("_root.InitExtensions", nullptr, nullptr, 0);
		}
		a_menu->RefreshPlatform();

		return true;
	}

	bool BSScaleformManager::LoadMovie_Impl(IMenu* a_menu, GPtr<RE::GFxMovieView>& a_viewOut, const char* a_fileName, ScaleModeType a_mode, float a_backGroundAlpha)
	{
		using LoadConstants = GFxLoader::LoadConstants;
		using StateType = GFxState::StateType;

		if (!loader) {
			return false;
		}

		const auto filePath = BuildFilePath(a_fileName);
		if (!filePath) {
			return false;
		}

		const auto def = loader->CreateMovie(filePath->c_str(), LoadConstants::kLoadKeepBindData | LoadConstants::kLoadWaitFrame1);
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

		const auto [safeZoneX, safeZoneY, width, height] = CollectDisplayInfo();

		const auto visibleRect = a_viewOut->GetVisibleFrameRect();
		GRectF	   safeRect;
		safeRect.left = safeZoneX;
		safeRect.top = safeZoneY;
		safeRect.right = (visibleRect.right - visibleRect.left) - safeZoneX;
		safeRect.bottom = (visibleRect.bottom - visibleRect.top) - safeZoneY;
		a_viewOut->SetSafeRect(safeRect);

		GViewport viewPort;
		viewPort.bufferWidth = width;
		viewPort.bufferHeight = height;
		viewPort.width = width;
		viewPort.height = height;
		a_viewOut->SetViewport(viewPort);

		a_menu->fxDelegate = make_gptr<FxDelegate>();
		a_menu->fxDelegate->RegisterHandler(a_menu);
		a_viewOut->SetState(StateType::kExternalInterface, a_menu->fxDelegate.get());

		a_viewOut->Advance(0.0F);

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
		return filePath;
	}

	std::tuple<float, float, std::int32_t, std::int32_t> BSScaleformManager::CollectDisplayInfo()
	{
		const auto* const state = RE::BSGraphics::State::GetSingleton();
		if (!state) {
			return { 0.0F, 0.0F, 0, 0 };
		}

		const auto [safeZoneX, safeZoneY] = [=] {
			const auto aspectRatio =
				static_cast<double>(state->screenWidth) /
				static_cast<double>(state->screenHeight);
			if (aspectRatio > 4.0 / 3.0) {
				REL::Relocation<const Setting*> fSafeZoneXWide{ REL::ID(512509) };
				REL::Relocation<const Setting*> fSafeZoneYWide{ REL::ID(512511) };

				return std::make_pair(fSafeZoneXWide->GetFloat(), fSafeZoneYWide->GetFloat());
			} else {
				REL::Relocation<const Setting*> fSafeZoneX{ REL::ID(512513) };
				REL::Relocation<const Setting*> fSafeZoneY{ REL::ID(512515) };

				return std::make_pair(fSafeZoneX->GetFloat(), fSafeZoneY->GetFloat());
			}
		}();

		const auto [width, height] = state->frameBufferViewport;

		return { safeZoneX, safeZoneY, static_cast<std::int32_t>(width), static_cast<std::int32_t>(height) };
	}

	bool BSScaleformManager::FileExists(const char* a_fileName)
	{
		using func_t = decltype(&BSScaleformManager::FileExists);
		REL::Relocation<func_t> func{ REL::ID(80087) };
		return func(a_fileName);
	}
}
