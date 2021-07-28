#pragma once

#include "RE/B/BSScriptObjectBindPolicy.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	namespace SkyrimScript
	{
		class ObjectBindPolicy : public BSScript::ObjectBindPolicy
		{
		public:
			inline static constexpr auto RTTI = RTTI_SkyrimScript__ObjectBindPolicy;

			~ObjectBindPolicy() override;  // 00

			// override (BSScript::ObjectBindPolicy)
			void Unk_01() override;  // 01
			void Unk_02() override;  // 02
			void Unk_03() override;  // 03
			void Unk_04() override;  // 04
			void Unk_05() override;  // 05
			void Unk_06() override;  // 06
			void Unk_07() override;  // 07
			void Unk_08() override;  // 08
			void Unk_09() override;  // 09
			void Unk_0A() override;  // 0A
			void Unk_0B() override;  // 0B
			void Unk_0C() override;  // 0C

			// members
			std::uint64_t                unk50;  // 50
			std::uint64_t                unk58;  // 58
			BSTHashMap<UnkKey, UnkValue> unk60;  // 60
			std::uint64_t                unk90;  // 90
			std::uint64_t                unk98;  // 98
			std::uint64_t                unkA0;  // A0
			BSTHashMap<UnkKey, UnkValue> unkA8;  // A8
		};
		static_assert(sizeof(ObjectBindPolicy) == 0xD8);
	}
}
