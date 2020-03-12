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
			UInt64					unk00;		// 00
			UInt64					unk08;		// 08
			UInt64					unk10;		// 10
			UInt64					unk18;		// 18
			UInt64					unk20;		// 20
			UInt64					unk28;		// 28
			UInt64					unk30;		// 30
			UInt64					unk38;		// 38
			hkMoppBvTreeShapeBase** treeShape;	// 40
		};
	};
}
