#pragma once

#include "skse64/ScaleformCallbacks.h"  // FxDelegateHandler

#include "RE/GFxMovieView.h"  // GFxMovieView
#include "RE/InputMappingManager.h"  // InputMappingManager::Context

class CallbackProcessor;
class GRefCountBase;
class UIMessage;


namespace RE
{
	class IMenu : public FxDelegateHandler
	{
	private:
		using Context = InputMappingManager::Context;

	public:
		enum class Flag : UInt32
		{
			kNone = 0,
			kPauseGame = 1 << 0,
			kDoNotDeleteOnClose = 1 << 1,
			kShowCursor = 1 << 2,
			kUnk0008 = 1 << 3,
			kModal = 1 << 4,
			kStopDrawingWorld = 1 << 5,
			kOpen = 1 << 6,
			kPreventGameLoad = 1 << 7,
			kUnk0100 = 1 << 8,
			kHideOther = 1 << 9,
			kUnk0400 = 1 << 10,
			kDoNotPreventGameSave = 1 << 11,
			kUnk1000 = 1 << 12,
			kItemMenu = 1 << 13,
			kStopCrosshairUpdate = 1 << 14,
			kUnk8000 = 1 << 15,
			kUnk10000 = 1 << 16  // ignore mouse cursor?
		};


		enum class Result : UInt32
		{
			kProcessed = 0,
			kAbort,
			kNotProcessed
		};


		IMenu();
		virtual ~IMenu();													// 00

		// override (FxDelegateHandler)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01 - {}

		// add
		virtual void	OnOpen();											// 02 - {}
		virtual void	Unk_03(void);										// 03 - {}
		virtual Result	ProcessMessage(UIMessage* a_message);				// 04
		virtual void	NextFrame(UInt32 a_arg1, UInt32 a_arg2);			// 05
		virtual void	Render();											// 06
		virtual void	Unk_07(void);										// 07 - {}
		virtual void	InitMovie();										// 08

		bool			PausesGame();
		bool			DeletesOnClose();
		bool			ShowsCursor();
		bool			HasFlag0008();
		bool			IsModal();
		bool			StopsDrawingWorld();
		bool			IsOpen();
		bool			PreventsGameLoad();
		bool			HasFlag0100();
		bool			HidesOtherMenus();
		bool			HasFlag0400();
		bool			PreventsGameSave();
		bool			HasFlag1000();
		bool			IsItemMenu();
		bool			StopsCrosshairUpdates();
		bool			HasFlag8000();
		bool			HasFlag10000();


		GFxMovieView*	view;		// 10 - init'd to 0, view->Release() called in dtor
		UInt8			menuDepth;	// 18 - init'd to 3
		UInt8			pad19[3];	// 19
		Flag			flags;		// 1C - init'd to 0
		Context			context;	// 20 - input context - init'd to 0x12 (kContext_Invalid)
		UInt32			pad24;		// 24
		GRefCountBase*	unk18;		// 28 - FxDelegate
	};
	STATIC_ASSERT(offsetof(IMenu, view) == 0x10);
	STATIC_ASSERT(sizeof(IMenu) == 0x30);
}
