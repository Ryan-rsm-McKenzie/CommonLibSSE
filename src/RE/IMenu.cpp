#include "RE/IMenu.h"

#include "skse64/GameMenus.h"  // IMenu


namespace RE
{
	IMenu::IMenu() :
		view(0),
		menuDepth(3),
		pad19(0),
		pad20(0),
		flags(Flag::kNone),
		context(Context::kInvalid),
		pad24(0),
		fxDelegate(0)
	{}


	IMenu::~IMenu()
	{
		dtor_Internal();
	}


	void IMenu::Accept(CallbackProcessor* a_processor)
	{}


	void IMenu::OnOpen()
	{}


	void IMenu::Unk_03(void)
	{}


	IMenu::Result IMenu::ProcessMessage(UIMessage* a_message)
	{
		using func_t = function_type_t<decltype(&IMenu::ProcessMessage)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::IMenu, ProcessMessage_internal, func_t*);
		return func(this, a_message);
	}


	void IMenu::NextFrame(UInt32 a_arg1, UInt32 a_arg2)
	{
		using func_t = function_type_t<decltype(&IMenu::NextFrame)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::IMenu, NextFrame_internal, func_t*);
		return func(this, a_arg1, a_arg2);
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
		InitMovie_Internal(view);
	}


	bool IMenu::PausesGame() const
	{
		return (flags & Flag::kPauseGame) != Flag::kNone;
	}


	bool IMenu::DeletesOnClose() const
	{
		return (flags & Flag::kDoNotDeleteOnClose) == Flag::kNone;
	}


	bool IMenu::ShowsCursor() const
	{
		return (flags & Flag::kShowCursor) != Flag::kNone;
	}


	bool IMenu::HasFlag0008() const
	{
		return (flags & Flag::kUnk0008) != Flag::kNone;
	}


	bool IMenu::IsModal() const
	{
		return (flags & Flag::kModal) != Flag::kNone;
	}


	bool IMenu::StopsDrawingWorld() const
	{
		return (flags & Flag::kStopDrawingWorld) != Flag::kNone;
	}


	bool IMenu::IsOpen() const
	{
		return (flags & Flag::kOpen) != Flag::kNone;
	}


	bool IMenu::PreventsGameLoad() const
	{
		return (flags & Flag::kPreventGameLoad) != Flag::kNone;
	}


	bool IMenu::HasFlag0100() const
	{
		return (flags & Flag::kUnk0100) != Flag::kNone;
	}


	bool IMenu::HidesOtherMenus() const
	{
		return (flags & Flag::kHideOther) != Flag::kNone;
	}


	bool IMenu::HasFlag0400() const
	{
		return (flags & Flag::kUnk0400) != Flag::kNone;
	}


	bool IMenu::PreventsGameSave() const
	{
		return (flags & Flag::kDoNotPreventGameSave) == Flag::kNone;
	}


	bool IMenu::HasFlag1000() const
	{
		return (flags & Flag::kUnk1000) != Flag::kNone;
	}


	bool IMenu::IsItemMenu() const
	{
		return (flags & Flag::kItemMenu) != Flag::kNone;
	}


	bool IMenu::StopsCrosshairUpdates() const
	{
		return (flags & Flag::kStopCrosshairUpdate) != Flag::kNone;
	}


	bool IMenu::HasFlag8000() const
	{
		return (flags & Flag::kUnk8000) != Flag::kNone;
	}


	bool IMenu::HasFlag10000() const
	{
		return (flags & Flag::kUnk10000) != Flag::kNone;
	}


	void IMenu::InitMovie_Internal(GFxMovieView* a_view)
	{
		using func_t = function_type_t<decltype(&IMenu::InitMovie_Internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::IMenu, InitMovie_internal, func_t*);
		return func(this, view);
	}


	void IMenu::dtor_Internal()
	{
		using func_t = function_type_t<decltype(&IMenu::dtor_Internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::IMenu, dtor, func_t*);
		return func(this);
	}
}
