#pragma once


namespace RE
{
	class IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementInterface;


		virtual ~IMovementInterface();
	};
	STATIC_ASSERT(sizeof(IMovementInterface) == 0x8);
}
