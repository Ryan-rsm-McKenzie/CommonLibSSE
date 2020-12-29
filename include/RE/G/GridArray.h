#pragma once


namespace RE
{
	class GridArray
	{
	public:
		inline static constexpr auto RTTI = RTTI_GridArray;

		virtual ~GridArray();  // 00

		// add
		virtual void Unk_01(void);		// 01
		virtual void Unk_02(void);		// 02
		virtual void Unk_03(void);		// 03
		virtual void Unk_04(void);		// 04
		virtual void Unk_05(void) = 0;	// 05
		virtual void Unk_06(void) = 0;	// 06
		virtual void Unk_07(void) = 0;	// 07
		virtual void Unk_08(void) = 0;	// 08


		// members
		std::uint32_t unk08;   // 08 - 1000
		std::uint32_t unk0C;   // 0C - 1000
		std::uint32_t length;  // 10 - takes value from uGridsToLoad
		std::uint32_t pad14;   // 14
	};
	static_assert(sizeof(GridArray) == 0x18);
};
