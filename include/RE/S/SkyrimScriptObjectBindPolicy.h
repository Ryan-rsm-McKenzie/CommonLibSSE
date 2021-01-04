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

			virtual ~ObjectBindPolicy();  // 00

			// override (BSScript::ObjectBindPolicy)
			virtual void Unk_01(void) override;	 // 01
			virtual void Unk_02(void) override;	 // 02
			virtual void Unk_03(void) override;	 // 03
			virtual void Unk_04(void) override;	 // 04
			virtual void Unk_05(void) override;	 // 05
			virtual void Unk_06(void) override;	 // 06
			virtual void Unk_07(void) override;	 // 07
			virtual void Unk_08(void) override;	 // 08
			virtual void Unk_09(void) override;	 // 09
			virtual void Unk_0A(void) override;	 // 0A
			virtual void Unk_0B(void) override;	 // 0B
			virtual void Unk_0C(void) override;	 // 0C

			// members
			std::uint64_t				 unk50;	 // 50
			std::uint64_t				 unk58;	 // 58
			BSTHashMap<UnkKey, UnkValue> unk60;	 // 60
			std::uint64_t				 unk90;	 // 90
			std::uint64_t				 unk98;	 // 98
			std::uint64_t				 unkA0;	 // A0
			BSTHashMap<UnkKey, UnkValue> unkA8;	 // A8
		};
		static_assert(sizeof(ObjectBindPolicy) == 0xD8);
	}
}
