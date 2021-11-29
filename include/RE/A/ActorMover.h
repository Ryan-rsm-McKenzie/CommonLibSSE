#pragma once

namespace RE
{
	class Actor;

	class ActorMover
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorMover;

		virtual ~ActorMover();  // 00

		// add
		virtual void Unk_01(void);  // 01 - { return; }
		virtual void Unk_02(void);  // 02 - { return 0; }
		virtual void Unk_03(void);  // 03 - { return 0; }

		// members
		Actor* actor;  // 08
	};
	static_assert(sizeof(ActorMover) == 0x10);
}
