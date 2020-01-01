#pragma once


namespace RE
{
	class TESChildCell
	{
	public:
		inline static const void* RTTI = RTTI_TESChildCell;


		virtual ~TESChildCell();						// 00

		// add
		virtual TESObjectCELL* GetSaveParentCell() = 0;	// 01
	};
	STATIC_ASSERT(sizeof(TESChildCell) == 0x8);
}
