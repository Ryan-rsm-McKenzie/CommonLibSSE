#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSString.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class BSUIMessageData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSUIMessageData;

		union Data
		{
			bool          b;
			std::uint32_t u;
			float         f;
			void*         p;
		};
		static_assert(sizeof(Data) == 0x8);

		~BSUIMessageData() override;  // 00

		// members
		BSString*     str;       // 10
		BSFixedString fixedStr;  // 18
		Data          data;      // 20
	};
	static_assert(sizeof(BSUIMessageData) == 0x28);
}
