#pragma once


namespace RE
{
	class IMovementInterface
	{
	public:
		virtual ~IMovementInterface();
	};
	STATIC_ASSERT(sizeof(IMovementInterface) == 0x8);
}
