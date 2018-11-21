#include "RE/IMenu.h"


namespace RE
{
	IMenu::IMenu() :
		view(0),
		menuDepth(3),
		flags(kFlag_None),
		context(InputManager::kContext_Invalid),
		unk18(0)
	{}


	IMenu::~IMenu()
	{
		typedef void _IMenu_dtor_t(IMenu* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_dtor_GetPtr());
		static _IMenu_dtor_t* _IMenu_dtor = reinterpret_cast<_IMenu_dtor_t*>(*ptr);
		_IMenu_dtor(this);
	}


	void IMenu::Accept(CallbackProcessor* a_processor)
	{}


	void IMenu::OnOpen()
	{}


	void IMenu::Unk_03(void)
	{}


	UInt32 IMenu::ProcessMessage(UIMessage* a_message)
	{
		typedef UInt32 _ProcessMessage_t(IMenu* a_this, UIMessage* a_message);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_ProcessMessage_internal_GetPtr());
		static _ProcessMessage_t* _ProcessMessage = reinterpret_cast<_ProcessMessage_t*>(*ptr);
		return _ProcessMessage(this, a_message);
	}


	void IMenu::NextFrame(UInt32 a_arg1, UInt32 a_arg2)
	{
		typedef void _NextFrame_t(IMenu* a_this, UInt32 a_arg1, UInt32 a_arg2);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_NextFrame_internal_GetPtr());
		static _NextFrame_t* _NextFrame = reinterpret_cast<_NextFrame_t*>(*ptr);
		_NextFrame(this, a_arg1, a_arg2);
	}


	void IMenu::Render()
	{
		if (view) {
			view->Display();
		}
	}


	void IMenu::Unk_07(void)
	{}


	void IMenu::InitMovie()
	{
		typedef void _InitMovie_t(IMenu* a_this, GFxMovieView* a_view);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::IMenu*>(this)->_InitMovie_internal_GetPtr());
		static _InitMovie_t* _InitMovie = reinterpret_cast<_InitMovie_t*>(*ptr);
		_InitMovie(this, view);
	}


	bool IMenu::PausesGame()
	{
		return (flags & kFlag_PauseGame) != 0;
	}


	bool IMenu::DeletesOnClose()
	{
		return (flags & kFlag_DoNotDeleteOnClose) == 0;
	}


	bool IMenu::ShowsCursor()
	{
		return (flags & kFlag_ShowCursor) != 0;
	}


	bool IMenu::HasFlag0008()
	{
		return (flags & kFlag_Unk0008) != 0;
	}


	bool IMenu::IsModal()
	{
		return (flags & kFlag_Modal) != 0;
	}


	bool IMenu::StopsDrawingWorld()
	{
		return (flags & kFlag_StopDrawingWorld) != 0;
	}


	bool IMenu::IsOpen()
	{
		return (flags & kFlag_Open) != 0;
	}


	bool IMenu::PreventsGameLoad()
	{
		return (flags & kFlag_PreventGameLoad) != 0;
	}


	bool IMenu::HasFlag0100()
	{
		return (flags & kFlag_Unk0100) != 0;
	}


	bool IMenu::HidesOtherMenus()
	{
		return (flags & kFlag_HideOther) != 0;
	}


	bool IMenu::HasFlag0400()
	{
		return (flags & kFlag_Unk0400) != 0;
	}


	bool IMenu::PreventsGameSave()
	{
		return (flags & kFlag_DoNotPreventGameSave) == 0;
	}


	bool IMenu::HasFlag1000()
	{
		return (flags & kFlag_Unk1000) != 0;
	}


	bool IMenu::IsItemMenu()
	{
		return (flags & kFlag_ItemMenu) != 0;
	}


	bool IMenu::StopsCrosshairUpdates()
	{
		return (flags & kFlag_StopCrosshairUpdate) != 0;
	}


	bool IMenu::HasFlag8000()
	{
		return (flags & kFlag_Unk8000) != 0;
	}


	bool IMenu::HasFlag10000()
	{
		return (flags & kFlag_Unk10000) != 0;
	}
}
