#pragma once

#include "RE/S/StreamBase.h"

namespace RE
{
	namespace BSResource
	{
		class AsyncStream : public StreamBase
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__AsyncStream;

			virtual ~AsyncStream() = default;  // 00

			// add
			virtual void Unk_05(void);  // 05
			virtual void Unk_06(void);  // 06
			virtual void Unk_07(void);  // 07
			virtual void Unk_08(void);  // 08
			virtual void Unk_09(void);  // 09
			virtual void Unk_0A(void);  // 0A

			// members
			std::uint32_t minPacketSize;  // 10
			std::uint32_t pad14;          // 14
		};
		static_assert(sizeof(AsyncStream) == 0x18);
	}
}
