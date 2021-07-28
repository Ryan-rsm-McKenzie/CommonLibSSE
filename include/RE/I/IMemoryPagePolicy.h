#pragma once

namespace RE
{
	namespace BSScript
	{
		struct IMemoryPagePolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__IMemoryPagePolicy;

			virtual ~IMemoryPagePolicy();  // 00

			// add
			virtual void Unk_01() = 0;  // 01
			virtual void Unk_02() = 0;  // 02
			virtual void Unk_03() = 0;  // 03
			virtual void Unk_04() = 0;  // 04
		};
		static_assert(sizeof(IMemoryPagePolicy) == 0x8);
	}
}
