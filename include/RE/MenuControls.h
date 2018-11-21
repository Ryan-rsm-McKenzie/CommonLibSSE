#pragma once

#include "skse64/GameEvents.h"  // BSTEventSink, MenuModeChangeEvent
#include "skse64/GameTypes.h"  // tArray
#include "skse64/PapyrusEvents.h"  // MenuModeChangeEvent

#include "RE/BSTSingleton.h"  // BSTSingletonSDM

class InputEvent;


namespace RE
{
	class MenuEventHandler;


	class MenuControls :
		public BSTEventSink<InputEvent*>,
		public BSTEventSink<MenuModeChangeEvent>,
		public BSTSingletonSDM<MenuControls>
	{
	public:
		virtual ~MenuControls();

		static MenuControls*	GetSingleton();

		void					RegisterHandler(MenuEventHandler* a_handler);
		void					RemoveHandler(MenuEventHandler* a_handler);


		// members
		tArray<MenuEventHandler>	handlers;		// 18
		tArray<void*>				regBuffer;		// 30
		void*						unk48;			// 48
		void*						unk50;			// 50
		void*						unk58;			// 58
		void*						unk60;			// 60
		void*						unk68;			// 68
		void*						unk70;			// 70
		void*						unk78;			// 78
		bool						nowProcessing;	// 80
		UInt8						pad81;			// 81
		bool						remapMode;		// 82
		UInt8						pad83;			// 83

	private:
		typedef void _RegisterHandler_Impl_t(MenuControls* a_this, MenuEventHandler* a_handler);
		static RelocAddr<_RegisterHandler_Impl_t*> _RegisterHandler_Impl;

		typedef void _RemoveHandler_Impl_t(MenuControls* a_this, MenuEventHandler* a_handler);
		static RelocAddr<_RemoveHandler_Impl_t*> _RemoveHandler_Impl;
	};
	STATIC_ASSERT(offsetof(MenuControls, handlers) == 0x18);
	STATIC_ASSERT(offsetof(MenuControls, remapMode) == 0x82);
}
