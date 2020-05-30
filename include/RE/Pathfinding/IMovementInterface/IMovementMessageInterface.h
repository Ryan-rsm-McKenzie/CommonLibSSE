#pragma once

#include "RE/IMovementInterface.h"


namespace RE
{
	class IMovementMessageInterface : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementMessageInterface;


		virtual ~IMovementMessageInterface();  // 00

		// add
		virtual void Unk_01(void) = 0;	// 01
		virtual void Unk_02(void) = 0;	// 02
		virtual void Unk_03(void) = 0;	// 03
	};
	STATIC_ASSERT(sizeof(IMovementMessageInterface) == 0x8);
}
