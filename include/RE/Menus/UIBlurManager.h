#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/DefaultObjectsReadyEvent.h"


namespace RE
{
	class TESImageSpaceModifier;


	class UIBlurManager :
		public BSTSingletonSDM<UIBlurManager>,				  // 08
		public BSTEventSink<DefaultObjectsReadyEvent::Event>  // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_UIBlurManager;


		virtual ~UIBlurManager();  // 00

		static UIBlurManager* GetSingleton();

		void DecrementBlurCount();
		void IncrementBlurCount();


		// members
		UInt8				   pad09;		// 09
		UInt16				   pad0A;		// 0A
		UInt32				   pad0C;		// 0C
		TESImageSpaceModifier* blurEffect;	// 10
		UInt32				   blurCount;	// 18
		UInt32				   pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(UIBlurManager) == 0x20);
}
