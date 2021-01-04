#pragma once

namespace RE
{
	class TESChildCell
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESChildCell;

		virtual ~TESChildCell();  // 00

		// add
		virtual TESObjectCELL* GetSaveParentCell() = 0;	 // 01
	};
	static_assert(sizeof(TESChildCell) == 0x8);
}
