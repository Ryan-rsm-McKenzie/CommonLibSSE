#pragma once

#include "RE/G/GridArray.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESObjectCELL;

	class GridCellArray : public GridArray
	{
	public:
		inline static constexpr auto RTTI = RTTI_GridCellArray;

		~GridCellArray() override;  // 00

		// override (GridArray)
		void Unk_02() override;  // 02
		void Unk_03() override;  // 03
		void Unk_05() override;  // 05
		void Unk_06() override;  // 06
		void Unk_07() override;  // 07
		void Unk_08() override;  // 08

		[[nodiscard]] TESObjectCELL* GetCell(std::uint32_t a_x, std::uint32_t a_y) const noexcept
		{
			return (a_x < length && a_y < length) ?
                       cells[(a_x * length) + a_y] :
                       nullptr;
		};

		// members
		TESObjectCELL** cells;  // 18 - (memory allocated using 0x8 * numGrids * numGrids)
		NiPoint3        unk20;  // 20
		bool            unk2C;  // 2C
	};
	static_assert(sizeof(GridCellArray) == 0x30);
};
