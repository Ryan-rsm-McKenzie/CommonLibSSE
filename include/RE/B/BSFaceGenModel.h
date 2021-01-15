#pragma once

namespace RE
{
	class BSFaceGenMorphData;
	class NiAVObject;

	class BSFaceGenModel : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenModel;

		struct Data
		{
			std::uint32_t		unk00;	// 00
			std::uint32_t		pad04;	// 04
			NiAVObject*			unk08;	// 08
			NiAVObject*			unk10;	// 10
			void*				unk18;	// 18
			BSFaceGenMorphData* unk20;	// 20
		};

		// members
		Data*		  unk10;  // 10
		std::uint32_t unk18;  // 18
		std::uint32_t pad1C;  // 1C
	};
	static_assert(sizeof(BSFaceGenModel) == 0x20);
}
