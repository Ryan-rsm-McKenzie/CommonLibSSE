#pragma once

#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	class OldMessageBoxCallback : public IMessageBoxCallback
	{
	public:
		inline static constexpr auto RTTI = RTTI___OldMessageBoxCallback;

		using Callback = void(Message);

		~OldMessageBoxCallback() override;  // 00

		// override (IMessageBoxCallback)
		void Run(Message a_msg) override;  // 01

		// members
		Callback* callback;  // 10
	};
	static_assert(sizeof(OldMessageBoxCallback) == 0x18);
}
