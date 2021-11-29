#pragma once

namespace RE
{
	class hkMoppBvTreeShapeBase;

	class hkpMoppAabbCastVirtualMachine
	{
	public:
		struct hkpAabbCastInput
		{
		public:
			std::uint64_t           unk00;      // 00
			std::uint64_t           unk08;      // 08
			std::uint64_t           unk10;      // 10
			std::uint64_t           unk18;      // 18
			std::uint64_t           unk20;      // 20
			std::uint64_t           unk28;      // 28
			std::uint64_t           unk30;      // 30
			std::uint64_t           unk38;      // 38
			hkMoppBvTreeShapeBase** treeShape;  // 40
		};
	};
}
