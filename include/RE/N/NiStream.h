#pragma once

namespace RE
{
	class NiStream
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiStream;

		virtual ~NiStream();  // 00

		// add
		virtual void Unk_01();                            // 01
		virtual void Unk_02();                            // 02
		virtual void Unk_03();                            // 03
		virtual void Unk_04();                            // 04
		virtual void Unk_05();                            // 05
		virtual void Unk_06();                            // 06
		virtual void Unk_07();                            // 07
		virtual void Unk_08();                            // 08
		virtual bool RegisterSaveObject(NiObject* a_object);  // 09
		virtual void Unk_0A();                            // 0A
		virtual void Unk_0B();                            // 0B
		virtual void Unk_0C();                            // 0C
		virtual void Unk_0D();                            // 0D
		virtual void Unk_0E();                            // 0E
		virtual void Unk_0F();                            // 0F
		virtual void Unk_10();                            // 10
		virtual void Unk_11();                            // 11
		virtual void Unk_12();                            // 12
		virtual void Unk_13();                            // 13
		virtual void Unk_14();                            // 14
		virtual void Unk_15();                            // 15
		virtual void Unk_16();                            // 16
		virtual void Unk_17();                            // 17

		// members
		std::uint8_t unk008[0x618];
	};
	static_assert(sizeof(NiStream) == 0x620);
}
