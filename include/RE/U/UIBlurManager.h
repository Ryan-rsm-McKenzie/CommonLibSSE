#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/D/DefaultObjectsReadyEvent.h"

namespace RE
{
	class TESImageSpaceModifier;

	class UIBlurManager :
		public BSTSingletonSDM<UIBlurManager>,                // 08
		public BSTEventSink<DefaultObjectsReadyEvent::Event>  // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_UIBlurManager;

		~UIBlurManager() override;  // 00

		static UIBlurManager* GetSingleton();

		void DecrementBlurCount();
		void IncrementBlurCount();

		// members
		std::uint8_t           pad09;       // 09
		std::uint16_t          pad0A;       // 0A
		std::uint32_t          pad0C;       // 0C
		TESImageSpaceModifier* blurEffect;  // 10
		std::uint32_t          blurCount;   // 18
		std::uint32_t          pad1C;       // 1C
	};
	static_assert(sizeof(UIBlurManager) == 0x20);
}
