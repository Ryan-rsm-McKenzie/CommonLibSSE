#pragma once

#include "RE/B/bhkSerializable.h"

namespace RE
{
	class bhkWorld : public bhkSerializable
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorld;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorld;

		~bhkWorld() override;  // 00

		// add
		virtual void Unk_32();  // 32
		virtual void Unk_33();  // 33
		virtual void Unk_34();  // 34
		virtual void Unk_35();  // 35
		virtual void Unk_36();  // 36

		// members
		std::uint8_t unk0020[0xC600 - 0x0020];  // 0020
	};
	static_assert(sizeof(bhkWorld) == 0xC600);
}
