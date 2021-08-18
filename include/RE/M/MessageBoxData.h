#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class IMessageBoxCallback;

	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_MessageBoxData;

		~MessageBoxData() override;  // 00

		void QueueMessage()
		{
			using func_t = decltype(&MessageBoxData::QueueMessage);
			REL::Relocation<func_t> func{ REL::ID(51422) };
			return func(this);
		}

		// members
		BSString                             bodyText;    // 10
		BSTArray<BSString>                   buttonText;  // 20
		std::uint32_t                        unk38;       // 38
		std::int32_t                         unk3C;       // 3C
		BSTSmartPointer<IMessageBoxCallback> callback;    // 40
		std::uint32_t                        unk48;       // 48
		std::uint8_t                         unk4C;       // 4C
		std::uint8_t                         unk4D;       // 4D
		std::uint8_t                         unk4E;       // 4E
		std::uint8_t                         unk4F;       // 4F
	};
	static_assert(sizeof(MessageBoxData) == 0x50);
}
