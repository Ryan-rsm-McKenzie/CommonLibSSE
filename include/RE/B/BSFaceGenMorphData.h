#pragma once

namespace RE
{
	class BSFaceGenMorphData : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenMorphData;

		// members
		void* unk10;  // 10
	};
	static_assert(sizeof(BSFaceGenMorphData) == 0x18);
}
