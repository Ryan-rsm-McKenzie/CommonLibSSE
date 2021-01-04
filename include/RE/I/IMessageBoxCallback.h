#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class IMessageBoxCallback : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMessageBoxCallback;

		enum class Message
		{
			kUnk0 = 0,
			kUnk1 = 1,
			kUnk2 = 2
		};

		virtual ~IMessageBoxCallback() = default;  // 00

		// add
		virtual void Run(Message a_msg) = 0;  // 01

		// members
		std::uint32_t unk0C;  // 0C
	};
	static_assert(sizeof(IMessageBoxCallback) == 0x10);
}
