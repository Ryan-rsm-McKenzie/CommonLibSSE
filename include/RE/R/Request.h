#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	namespace bgs
	{
		namespace saveload
		{
			class Request : public BSIntrusiveRefCounted
			{
			public:
				inline static constexpr auto RTTI = RTTI_bgs__saveload__Request;

				virtual ~Request();  // 00

				// members
				std::uint32_t unk0C;  // 0C
				std::uint32_t unk10;  // 10
				std::uint32_t pad14;  // 14
			};
			static_assert(sizeof(Request) == 0x18);
		}
	}
}
