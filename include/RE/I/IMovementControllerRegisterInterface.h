#pragma once

namespace RE
{
	class IMovementInterface;

	class IMovementControllerRegisterInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementControllerRegisterInterface;

		virtual ~IMovementControllerRegisterInterface();  // 00

		// add
		virtual void                Unk_01(void) = 0;                                       // 01
		virtual void                Unk_02(void) = 0;                                       // 02
		virtual IMovementInterface* GetMovementInterface(const BSFixedString& a_name) = 0;  // 03
		virtual void                Unk_04(void) = 0;                                       // 04
	};
	static_assert(sizeof(IMovementControllerRegisterInterface) == 0x8);
}
