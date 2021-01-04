#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	struct FavoritesHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_FavoritesHandler;

		virtual ~FavoritesHandler();  // 00

		// add
		virtual bool CanProcess(InputEvent* a_event) override;		// 01
		virtual bool ProcessKinect(KinectEvent* a_event) override;	// 02
		virtual bool ProcessButton(ButtonEvent* a_event) override;	// 05
	};
	static_assert(sizeof(FavoritesHandler) == 0x10);
}
