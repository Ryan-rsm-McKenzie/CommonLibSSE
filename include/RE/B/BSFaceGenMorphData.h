#pragma once

namespace RE
{
	class BSFaceGenMorphData : public RE::NiRefObject
	{
	public:
		void* unk10;  // 10
	};
	static_assert(sizeof(BSFaceGenMorphData) == 0x18);
}
