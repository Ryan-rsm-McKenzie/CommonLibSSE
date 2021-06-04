#pragma once

namespace RE
{
	namespace BSScript
	{
		class IStackCallbackSaveInterface
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IStackCallbackSaveInterface;

			virtual ~IStackCallbackSaveInterface();  // 00

			// add
			virtual void Unk_01(void) = 0;  // 01
			virtual void Unk_02(void) = 0;  // 02
		};
		static_assert(sizeof(IStackCallbackSaveInterface) == 0x8);
	}
}
