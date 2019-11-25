#pragma once


namespace RE
{
	class IMovementInterface
	{
	public:
		inline static const void* RTTI = RTTI_IMovementInterface;


		virtual ~IMovementInterface();
	};
	STATIC_ASSERT(sizeof(IMovementInterface) == 0x8);
}
