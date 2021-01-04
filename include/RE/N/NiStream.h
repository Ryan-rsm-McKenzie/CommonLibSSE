#pragma once

namespace RE
{
	class NiStream
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiStream;

		virtual ~NiStream();  // 00

		// add
		virtual void Unk_01(void);							  // 01
		virtual void Unk_02(void);							  // 02
		virtual void Unk_03(void);							  // 03
		virtual void Unk_04(void);							  // 04
		virtual void Unk_05(void);							  // 05
		virtual void Unk_06(void);							  // 06
		virtual void Unk_07(void);							  // 07
		virtual void Unk_08(void);							  // 08
		virtual bool RegisterSaveObject(NiObject* a_object);  // 09
		virtual void Unk_0A(void);							  // 0A
		virtual void Unk_0B(void);							  // 0B
		virtual void Unk_0C(void);							  // 0C
		virtual void Unk_0D(void);							  // 0D
		virtual void Unk_0E(void);							  // 0E
		virtual void Unk_0F(void);							  // 0F
		virtual void Unk_10(void);							  // 10
		virtual void Unk_11(void);							  // 11
		virtual void Unk_12(void);							  // 12
		virtual void Unk_13(void);							  // 13
		virtual void Unk_14(void);							  // 14
		virtual void Unk_15(void);							  // 15
		virtual void Unk_16(void);							  // 16
		virtual void Unk_17(void);							  // 17

		// members
		std::uint8_t unk008[0x618];
	};
	static_assert(sizeof(NiStream) == 0x620);
}
