#pragma once


namespace RE
{
	class IMovementTweenerAgent
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementTweenerAgent;

		virtual ~IMovementTweenerAgent(); // 00

		// add
		virtual void Unk01(void);  // 01
		virtual void Unk02(void);  // 01
		virtual void Unk03(void);  // 01
	};
	static_assert(sizeof(IMovementTweenerAgent) == 0x8);
}
