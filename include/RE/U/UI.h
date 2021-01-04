#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTimer.h"
#include "RE/G/GPtr.h"

namespace RE
{
	class GFxMovieView;
	class IMenu;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;

	namespace UIImpl
	{
		template <class, class = void>
		struct _has_menu_name :
			std::false_type
		{};

		template <class T>
		struct _has_menu_name<
			T,
			std::void_t<decltype(T::MENU_NAME)>> :
			std::true_type
		{};

		template <class T>
		struct has_menu_name :
			_has_menu_name<
				std::remove_cv_t<T>>
		{};

		template <class T>
		inline constexpr bool has_menu_name_v = has_menu_name<T>::value;

		template <class T>
		struct is_menu_ptr :
			std::is_convertible<
				std::remove_cv_t<T>,
				IMenu*>
		{};

		template <class T>
		inline constexpr bool is_menu_ptr_v = is_menu_ptr<T>::value;
	}

	class UI :
		public BSTSingletonSDM<UI>,					 // 000
		public BSTEventSource<MenuOpenCloseEvent>,	 // 008
		public BSTEventSource<MenuModeChangeEvent>,	 // 060
		public BSTEventSource<void*>				 // 0B8 MenuModeCounterChangedEvent/TutorialEvent
	{
	public:
		using Create_t = IMenu*();

		struct UIMenuEntry
		{
		public:
			// members
			GPtr<IMenu> menu;	 // 00
			Create_t*	create;	 // 08
		};
		static_assert(sizeof(UIMenuEntry) == 0x10);

		static UI* GetSingleton();

		template <class T>
		void AddEventSink(BSTEventSink<T>* a_sink);
		bool GameIsPaused();
		template <class T>
		BSTEventSource<T>* GetEventSource();
		GPtr<IMenu>		   GetMenu(const std::string_view& a_menuName);
		GPtr<GFxMovieView> GetMovieView(const std::string_view& a_menuName);
		bool			   IsApplicationMenuOpen() const;
		bool			   IsCursorHiddenWhenTopmost() const;
		bool			   IsItemMenuOpen() const;
		bool			   IsMenuOpen(const std::string_view& a_menuName);
		bool			   IsModalMenuOpen() const;
		bool			   IsPauseMenuDisabled() const;
		bool			   IsSavingAllowed() const;
		bool			   IsShowingMenus() const;
		bool			   IsUsingCustomRendering() const;
		void			   Register(const std::string_view& a_menuName, Create_t* a_creator);

		template <class T>
		void RemoveEventSink(BSTEventSink<T>* a_sink);
		void ShowMenus(bool a_show);

		template <
			class T,
			std::enable_if_t<
				std::conjunction_v<
					UIImpl::is_menu_ptr<T*>,
					UIImpl::has_menu_name<T>>,
				int> = 0>
		GPtr<T> GetMenu()
		{
			return GPtr<T>(static_cast<T*>(GetMenu(T::MENU_NAME).get()));
		}

		template <
			class T,
			std::enable_if_t<
				UIImpl::is_menu_ptr_v<T*>,
				int> = 0>
		GPtr<T> GetMenu(const std::string_view& a_menuName)
		{
			return GPtr<T>(static_cast<T*>(GetMenu(a_menuName).get()));
		}

		// members
		BSTArray<GPtr<IMenu>>				   menuStack;					  // 110
		BSTHashMap<BSFixedString, UIMenuEntry> menuMap;						  // 128
		mutable BSSpinLock					   processMessagesLock;			  // 158
		std::uint32_t						   numPausesGame;				  // 160 (= 0) += 1 if (imenu->flags & 0x00001)
		std::uint32_t						   numItemMenus;				  // 164 (= 0) += 1 if (imenu->flags & 0x02000)
		std::uint32_t						   numDisablePauseMenu;			  // 168 (= 0) += 1 if (imenu->flags & 0x00080)
		std::uint32_t						   numAllowSaving;				  // 16C (= 0) += 1 if (imenu->flags & 0x00800)
		std::uint32_t						   numDontHideCursorWhenTopmost;  // 170 (= 0) += 1 if (imenu->flags & 0x04000)
		std::uint32_t						   numCustomRendering;			  // 174 (= 0) += 1 if (imenu->flags & 0x08000)
		std::uint32_t						   numApplicationMenus;			  // 178 (= 0) += 1 if (imenu->flags & 0x20000)
		bool								   modal;						  // 17C (= 0)  = 1 if (imenu->flags & 0x00010)
		std::uint8_t						   pad17D;						  // 17D
		std::uint16_t						   pad17E;						  // 17E
		BSTimer								   uiTimer;						  // 180
		bool								   menuSystemVisible;			  // 1C0
		bool								   closingAllMenus;				  // 1C1
		std::uint16_t						   pad1C2;						  // 1C2
		std::uint32_t						   pad1C4;						  // 1C4
	};
	static_assert(sizeof(UI) == 0x1C8);

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
