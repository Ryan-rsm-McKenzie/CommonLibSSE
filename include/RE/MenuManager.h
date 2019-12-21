#pragma once

#include <string_view>
#include <type_traits>

#include "RE/BSTEvent.h"
#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/BSTSingleton.h"
#include "RE/GPtr.h"


namespace RE
{
	class GFxMovieView;
	class IMenu;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;


	class MenuManager :
		public BSTSingletonSDM<MenuManager>,		// 000
		public BSTEventSource<MenuOpenCloseEvent>,	// 008
		public BSTEventSource<MenuModeChangeEvent>,	// 060
		public BSTEventSource<void*>				// 0B8
	{
	public:
		template <class T, class Enable = void> struct _has_menu_name : std::false_type {};
		template <class T> struct _has_menu_name<T, decltype((void)T::MENU_NAME)> : std::true_type {};
		template <class T> struct has_menu_name : _has_menu_name<std::remove_cv_t<T>> {};

		template <class T> struct _is_menu_ptr : std::is_convertible<T, IMenu*> {};
		template <class T> struct is_menu_ptr : _is_menu_ptr<std::remove_cv_t<T>> {};

		using CreatorFunc = IMenu*();


		struct MenuTableItem
		{
		public:
			GPtr<IMenu>		menuInstance;		// 00
			CreatorFunc*	menuConstructor;	// 08
		};
		STATIC_ASSERT(sizeof(MenuTableItem) == 0x10);


		using MenuTable = BSTHashMap<BSFixedString, MenuTableItem>;


		struct Unknown3
		{
			UInt64	unk00;		// 00 - New in SE. Not init'd?

			UInt32	freqLow;	// 08 (= Frequency.LowPart)
			UInt32	freqHigh;	// 0C (= Frequency.HighPart)

			UInt64	unk10;		// 10
			float	unk18;		// 18
			float	unk1C;		// 1C
			UInt32	unk20;		// 20
			UInt32	unk24;		// 24
			float	unk28;		// 28

			UInt32	unk2C;		// 2C
			UInt32	unk30;		// 30

			UInt32	unk34;		// 34
			UInt8	unk38;		// 38
			UInt8	unk39;		// 39
			UInt8	unk3A;		// 3A
			UInt8	pad3B;		// 3B
			UInt32	pad3C;		// 3C
		};
		STATIC_ASSERT(sizeof(Unknown3) == 0x40);


		static MenuManager* GetSingleton();

		template <class T> void					AddEventSink(BSTEventSink<T>* a_sink);
		bool									CrosshairIsPaused();
		bool									GameIsPaused();
		template <class T> BSTEventSource<T>*	GetEventSource();

		GPtr<IMenu> GetMenu(const std::string_view& a_menuName);

		template <class T, typename std::enable_if_t<std::conjunction<is_menu_ptr<T*>, has_menu_name<T>>::value, int> = 0>
		GPtr<T> GetMenu()
		{
			return GPtr<T>(static_cast<T*>(GetMenu(T::MENU_NAME).get()));
		}

		template <class T, typename std::enable_if_t<std::conjunction<is_menu_ptr<T*>>::value, int> = 0>
		GPtr<T> GetMenu(const std::string_view& a_menuName)
		{
			return GPtr<T>(static_cast<T*>(GetMenu(a_menuName).get()));
		}

		GFxMovieView*			GetMovieView(const std::string_view& a_menuName);
		bool					IsMenuOpen(const std::string_view& a_menuName);
		bool					IsShowingMenus();
		void					Register(const std::string_view& a_menuName, CreatorFunc* a_creator);
		template <class T> void	RemoveEventSink(BSTEventSink<T>* a_sink);
		void					ShowMenus(bool a_show);


		// members
		BSTArray<IMenu*>	menuStack;					// 110
		MenuTable			menuTable;					// 128
		UInt64				unk158;						// 158
		UInt32				numPauseGame;				// 160 (= 0) += 1 if (imenu->flags & 0x00001)
		UInt32				numItemMenu;				// 164 (= 0) += 1 if (imenu->flags & 0x02000)
		UInt32				numPreventGameLoad;			// 168 (= 0) += 1 if (imenu->flags & 0x00080)
		UInt32				numDoNotPreventSaveGame;	// 16C (= 0) += 1 if (imenu->flags & 0x00800)
		UInt32				numStopCrosshairUpdate;		// 170 (= 0) += 1 if (imenu->flags & 0x04000)
		UInt32				numFlag8000;				// 174 (= 0) += 1 if (imenu->flags & 0x08000)
		UInt32				numFlag20000;				// 178 (= 0)  = 1 if (imenu->flags & 0x20000)
		UInt8				numModal;					// 17C (= 0)  = 1 if (imenu->flags & 0x00010)
		UInt8				pad17D[3];					// 17D
		Unknown3			unk180;						// 180
		bool				showMenus;					// 1C0 (= 0)
		bool				unk1C1;						// 1C1 (= 0)
		UInt16				pad1C2;						// 1C2
		UInt32				pad1C4;						// 1C4
	};
	STATIC_ASSERT(sizeof(MenuManager) == 0x1C8);


	template <class T>
	void MenuManager::AddEventSink(BSTEventSink<T>* a_sink)
	{
		GetEventSource<T>()->AddEventSink(a_sink);
	}


	template <class T>
	BSTEventSource<T>* MenuManager::GetEventSource()
	{
		return static_cast<BSTEventSource<T>*>(this);
	}


	template <class T>
	inline void MenuManager::RemoveEventSink(BSTEventSink<T>* a_sink)
	{
		GetEventSource<T>()->RemoveEventSink(a_sink);
	}
}
