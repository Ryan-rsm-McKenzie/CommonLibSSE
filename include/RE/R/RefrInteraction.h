#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/S/SyncQueueObj.h"

namespace RE
{
	class RefrInteraction : public SyncQueueObj
	{
	public:
		inline static constexpr auto RTTI = RTTI_RefrInteraction;

		~RefrInteraction() override;  // 00

		// add
		virtual void Unk_02(void);      // 02 - { a_arg1 = g_invalidRefHandle; }
		virtual void Unk_03(void) = 0;  // 03
		virtual void Unk_04(void) = 0;  // 04
		virtual void Unk_05(void);      // 05 - { return 0xFFFFFFFF; }
		virtual void Unk_06(void);      // 06 - { return; }
		virtual void Unk_07(void);      // 07 - { return 1; }
		virtual void Unk_08(void);      // 08 - { unk18 = 1; return 0; }
		virtual void Unk_09(void);      // 09 - { unk18 = 0; return 1; }
		virtual void Unk_0A(void);      // 0A - { return; }
		virtual void Unk_0B(void);      // 0B - { return 1; }
		virtual void Unk_0C(void);      // 0C - { return; }
		virtual void Unk_0D(void) = 0;  // 0D
		virtual void Unk_0E(void) = 0;  // 0E
		virtual void Unk_0F(void) = 0;  // 0F

		// members
		ActorHandle     actor;       // 10
		ObjectRefHandle targetRefr;  // 14
		bool            synced;      // 18
		std::uint8_t    pad19;       // 19
		std::uint16_t   pad1A;       // 1A
		std::uint32_t   pad1C;       // 1C
	};
	static_assert(sizeof(RefrInteraction) == 0x20);
}
