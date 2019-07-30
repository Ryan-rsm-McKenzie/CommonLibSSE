#pragma once

#include "skse64/GameRTTI.h"  // RTTI_IMenu

#include "RE/FxDelegate.h"  // FxDelegate
#include "RE/FxDelegateHandler.h"  // FxDelegateHandler
#include "RE/GFxMovieView.h"  // GFxMovieView
#include "RE/GPtr.h"  // GPtr
#include "RE/InputMappingManager.h"  // InputMappingManager::Context


namespace RE
{
	class CallbackProcessor;
	class UIMessage;


	class IMenu : public FxDelegateHandler
	{
	private:
		using Context = InputMappingManager::Contexts::Context;

	public:
		inline static const void* RTTI = RTTI_IMenu;


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
			kTryShowCursor = 1 << 10,
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
		virtual ~IMenu() = default;											// 00

		// override (FxDelegateHandler)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01 - { return; }

		// add
		virtual void	OnOpen();											// 02 - { return; }
		virtual void	Unk_03(void);										// 03 - { return; }
		virtual Result	ProcessMessage(UIMessage* a_message);				// 04
		virtual void	NextFrame(float a_arg1, UInt32 a_currentTime);		// 05
		virtual void	Render();											// 06
		virtual void	Unk_07(void);										// 07 - { return; }
		virtual void	InitMovie();										// 08

		bool	PausesGame() const;
		bool	DeletesOnClose() const;
		bool	ShowsCursor() const;
		bool	HasFlag0008() const;
		bool	IsModal() const;
		bool	StopsDrawingWorld() const;
		bool	IsOpen() const;
		bool	PreventsGameLoad() const;
		bool	HasFlag0100() const;
		bool	HidesOtherMenus() const;
		bool	TriesToShowCursor() const;
		bool	PreventsGameSave() const;
		bool	HasFlag1000() const;
		bool	IsItemMenu() const;
		bool	StopsCrosshairUpdates() const;
		bool	HasFlag8000() const;
		bool	HasFlag10000() const;


		// members
		GPtr<GFxMovieView>	view;		// 10
		UInt8				menuDepth;	// 18
		UInt8				pad19;		// 19
		UInt16				pad20;		// 1A
		Flag				flags;		// 1C
		Context				context;	// 20
		UInt32				pad24;		// 24
		GPtr<FxDelegate>	fxDelegate;	// 28
	};
	STATIC_ASSERT(offsetof(IMenu, view) == 0x10);
	STATIC_ASSERT(sizeof(IMenu) == 0x30);
}
