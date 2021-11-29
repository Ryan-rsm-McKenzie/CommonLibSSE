#pragma once

namespace RE
{
	class BSThread
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSThread;

		virtual ~BSThread();  // 00

		// add
		virtual void Unk_01(void);  // 01 - { return 0; }
		virtual void Unk_02(void);  // 02 - { return; }

		// members
		WinAPI::CRITICAL_SECTION lock;           // 08
		void*                    thread;         // 30
		void*                    ownerThread;    // 38
		std::uint32_t            threadID;       // 40
		std::uint32_t            ownerThreadID;  // 44
		bool                     initialized;    // 48
		std::uint8_t             pad49;          // 49
		std::uint16_t            pad4A;          // 4A
		std::uint32_t            pad4C;          // 4C
	};
	static_assert(sizeof(BSThread) == 0x50);
}
