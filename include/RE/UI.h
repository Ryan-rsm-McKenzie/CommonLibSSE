#pragma once

#include <string_view>
#include <type_traits>

#include "RE/BSFixedString.h"
#include "RE/BSLock.h"
#include "RE/BSTEvent.h"
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


	class UI :
		public BSTSingletonSDM<UI>,					// 000
		public BSTEventSource<MenuOpenCloseEvent>,	// 008
		public BSTEventSource<MenuModeChangeEvent>,	// 060
		public BSTEventSource<void*>				// 0B8 MenuModeCounterChangedEvent/TutorialEvent
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
			GPtr<IMenu>		menuInstance;		// 00
			CreatorFunc*	menuConstructor;	// 08
		};
		STATIC_ASSERT(sizeof(MenuTableItem) == 0x10);


		using MenuTable = BSTHashMap<BSFixedString, MenuTableItem>;


		struct Unknown3
		{
			UInt64	unk00;		// 00

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


		static UI* GetSingleton();

		template <class T> void					AddEventSink(BSTEventSink<T>* a_sink);
		bool									GameIsPaused();
		template <class T> BSTEventSource<T>*	GetEventSource();
		GPtr<IMenu>								GetMenu(const std::string_view& a_menuName);
		GPtr<GFxMovieView>						GetMovieView(const std::string_view& a_menuName);
		bool									IsApplicationMenuOpen() const;
		bool									IsCursorHiddenWhenTopmost() const;
		bool									IsItemMenuOpen() const;
		bool									IsMenuOpen(const std::string_view& a_menuName);
		bool									IsModalMenuOpen() const;
		bool									IsPauseMenuDisabled() const;
		bool									IsSavingAllowed() const;
		bool									IsShowingMenus() const;
		bool									IsUsingCustomRendering() const;
		void									Register(const std::string_view& a_menuName, CreatorFunc* a_creator);
		template <class T> void					RemoveEventSink(BSTEventSink<T>* a_sink);
		void									ShowMenus(bool a_show);

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


		// members
		BSTArray<GPtr<IMenu>>	menuStack;						// 110
		MenuTable				menuTable;						// 128
		BSUniqueLock			unk158;							// 158
		UInt32					numPausesGame;					// 160 (= 0) += 1 if (imenu->flags & 0x00001)
		UInt32					numItemMenus;					// 164 (= 0) += 1 if (imenu->flags & 0x02000)
		UInt32					numDisablePauseMenu;			// 168 (= 0) += 1 if (imenu->flags & 0x00080)
		UInt32					numAllowSaving;					// 16C (= 0) += 1 if (imenu->flags & 0x00800)
		UInt32					numDontHideCursorWhenTopmost;	// 170 (= 0) += 1 if (imenu->flags & 0x04000)
		UInt32					numCustomRendering;				// 174 (= 0) += 1 if (imenu->flags & 0x08000)
		UInt32					numApplicationMenus;			// 178 (= 0) += 1 if (imenu->flags & 0x20000)
		bool					modal;							// 17C (= 0)  = 1 if (imenu->flags & 0x00010)
		UInt8					pad17D;							// 17D
		UInt16					pad17E;							// 17E
		Unknown3				unk180;							// 180
		bool					showMenus;						// 1C0 (= 0)
		bool					unk1C1;							// 1C1 (= 0)
		UInt16					pad1C2;							// 1C2
		UInt32					pad1C4;							// 1C4
	};
	STATIC_ASSERT(sizeof(UI) == 0x1C8);


	template <class T>
	void UI::AddEventSink(BSTEventSink<T>* a_sink)
	{
		GetEventSource<T>()->AddEventSink(a_sink);
	}


	template <class T>
	BSTEventSource<T>* UI::GetEventSource()
	{
		return static_cast<BSTEventSource<T>*>(this);
	}


	template <class T>
	inline void UI::RemoveEventSink(BSTEventSink<T>* a_sink)
	{
		GetEventSource<T>()->RemoveEventSink(a_sink);
	}
}
