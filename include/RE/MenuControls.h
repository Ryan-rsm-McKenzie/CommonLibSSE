#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	class InputEvent;
	class MenuEventHandler;
	class MenuModeChangeEvent;


	class MenuControls :
		public BSTEventSink<InputEvent*>,			// 00
		public BSTSingletonSDM<MenuControls>,		// 10
		public BSTEventSink<MenuModeChangeEvent>	// 08
	{
	public:
		virtual ~MenuControls();	// 00

		static MenuControls* GetSingleton();

		void	RegisterHandler(MenuEventHandler* a_handler);
		void	RemoveHandler(MenuEventHandler* a_handler);


		// members
		BSTArray<MenuEventHandler>	handlers;		// 18
		BSTArray<void*>				regBuffer;		// 30
		void*						unk48;			// 48
		void*						unk50;			// 50
		void*						unk58;			// 58
		void*						unk60;			// 60
		void*						unk68;			// 68
		void*						unk70;			// 70
		void*						unk78;			// 78
		bool						nowProcessing;	// 80
		bool						unk81;			// 81
		bool						remapMode;		// 82
		UInt8						unk83;			// 83
		UInt32						unk84;			// 84
		UInt64						unk88;			// 88
	};
	STATIC_ASSERT(offsetof(MenuControls, handlers) == 0x18);
	STATIC_ASSERT(offsetof(MenuControls, remapMode) == 0x82);
	STATIC_ASSERT(sizeof(MenuControls) == 0x90);
}
