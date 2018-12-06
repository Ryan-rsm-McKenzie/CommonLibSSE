#include "RE/MenuControls.h"

#include "skse64/GameInput.h"  // MenuControls

#include "RE/Offsets.h"


namespace RE
{
	MenuControls* MenuControls::GetSingleton()
	{
		typedef MenuControls* _GetSingleton_t();
		static _GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::MenuControls::GetSingleton));
		return _GetSingleton();
	}


	void MenuControls::RegisterHandler(MenuEventHandler* a_handler)
	{
		typedef void _RegisterHandler_Impl_t(MenuControls* a_this, MenuEventHandler* a_handler);
		static RelocAddr<_RegisterHandler_Impl_t*> _RegisterHandler_Impl(MENU_CONTROLS_REGISTER_HANDLER_IMPL);
		_RegisterHandler_Impl(this, a_handler);
	}


	void MenuControls::RemoveHandler(MenuEventHandler* a_handler)
	{
		typedef void _RemoveHandler_Impl_t(MenuControls* a_this, MenuEventHandler* a_handler);
		static RelocAddr<_RemoveHandler_Impl_t*> _RemoveHandler_Impl(MENU_CONTROLS_REMOVE_HANDLER_IMPL);
		_RemoveHandler_Impl(this, a_handler);
	}
}
